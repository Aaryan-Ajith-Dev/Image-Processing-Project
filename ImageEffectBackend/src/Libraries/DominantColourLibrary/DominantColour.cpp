#include "DominantColour.h"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

double calculateDistance(vector<double>& centroid, Pixel& pixel)
{
    double distance = (centroid[0] - pixel.r) * (centroid[0] - pixel.r) +
                      (centroid[0] - pixel.g) * (centroid[0] - pixel.g) +
                      (centroid[0] - pixel.b) * (centroid[0] - pixel.b);

    return distance;
}

void dominantColourEffect(vector<vector<Pixel>>& imageVector)
{
    srand(time(0));

    int k = 6;
    vector<double> centroids[k];

    int i, j;
    int n = imageVector.size();
    int m = imageVector[0].size();

    for (i = 0; i < k; ++i)
    {
        int x = rand() % n;
        int y = rand() % m;

        centroids[i].push_back(imageVector[x][y].r);
        centroids[i].push_back(imageVector[x][y].g);
        centroids[i].push_back(imageVector[x][y].b);
    }

    int clusterNumber[n][m];

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            int cluster = 0;
            double minDistance = calculateDistance(centroids[0], imageVector[i][j]);

            for (int ii = 1; ii < k; ++ii)
            {
                double distance = calculateDistance(centroids[ii], imageVector[i][j]);

                if (distance < minDistance)
                {
                    cluster = ii;
                    minDistance = distance;
                }
            }

            clusterNumber[i][j] = cluster;
        }
    }

    double sum[k][3];
    int freq[k] = {0};

    for (i = 0; i < k; ++i)
        sum[i][0] = sum[i][1] = sum[i][2] = 0;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            int cluster = clusterNumber[i][j];
            sum[cluster][0] += imageVector[i][j].r;
            sum[cluster][1] += imageVector[i][j].g;
            sum[cluster][2] += imageVector[i][j].b;
            ++freq[cluster];
        }
    }

    for (i = 0; i < k; ++i)
    {
        double r = sum[i][0] / freq[i];
        double g = sum[i][1] / freq[i];
        double b = sum[i][2] / freq[i];

        centroids[i][0] = r;
        centroids[i][1] = g;
        centroids[i][2] = b;
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            int cluster = clusterNumber[i][j];

            imageVector[i][j].r = centroids[cluster][0];
            imageVector[i][j].g = centroids[cluster][1];
            imageVector[i][j].b = centroids[cluster][2];
        }
    }
}