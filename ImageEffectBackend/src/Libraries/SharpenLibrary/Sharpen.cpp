#include "Sharpen.h"
#include <bits/stdc++.h>
#define factor 1

using namespace std;

int clip(int value) {
    return min(max(value, 0), 255);
}

void applySharpness(vector<vector<Pixel>>& image, float amount) {
    const int n = image.size();
    const int m = image[0].size();

    const int kernelSize = 3;
    int kernel[kernelSize][kernelSize] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};

    const float scalingFactor = amount*factor;

    vector<vector<Pixel>> tempImage(image);

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            float rtotal = 0, gtotal = 0, btotal = 0;

            for (int x = 0; x < kernelSize; ++x) {
                for (int y = 0; y < kernelSize; ++y) {
                    rtotal += kernel[x][y] * image[i + x - 1][j + y - 1].r;
                    gtotal += kernel[x][y] * image[i + x - 1][j + y - 1].g;
                    btotal += kernel[x][y] * image[i + x - 1][j + y - 1].b;
                }
            }

            tempImage[i][j].r = clip(image[i][j].r + static_cast<int>((scalingFactor * rtotal) / 16));
            tempImage[i][j].g = clip(image[i][j].g + static_cast<int>((scalingFactor * gtotal) / 16));
            tempImage[i][j].b = clip(image[i][j].b + static_cast<int>((scalingFactor * btotal) / 16));
        }
    }

    image = tempImage;

}