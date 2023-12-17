#include "DominantColour.h"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

void dominantColourEffect(vector<vector<Pixel>>& imageVector)
{
    srand(time(0));

    int k = 3;
    vector<int> centroids[k];

    int i, j;
    int n = imageVector.size();
    int m = imageVector[0].size();

    for (i = 0; i < k; ++i)
    {
        centroids[i].push_back(rand() % 256);
        centroids[i].push_back(rand() % 256);
        centroids[i].push_back(rand() % 256);
    }

    int clusterNumber[n][m];

    int freq[k] = {0};

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            int cluster = 0;
            int minDistance = (centroids[0][0] - imageVector[i][j].r) * (centroids[0][0] - imageVector[i][j].r) +
                               (centroids[0][1] - imageVector[i][j].g) * (centroids[0][1] - imageVector[i][j].g) +
                               (centroids[0][2] - imageVector[i][j].b) * (centroids[0][2] - imageVector[i][j].b);

            for (int ii = 1; ii < k; ++ii)
            {
                int distance = (centroids[0][0] - imageVector[i][j].r) * (centroids[0][0] - imageVector[i][j].r) +
                               (centroids[0][1] - imageVector[i][j].g) * (centroids[0][1] - imageVector[i][j].g) +
                               (centroids[0][2] - imageVector[i][j].b) * (centroids[0][2] - imageVector[i][j].b);

                if (distance < minDistance)
                {
                    cluster = ii;
                    minDistance = distance;
                }
            }

            clusterNumber[i][j] = cluster;
            freq[cluster]++;
        }
    }
}