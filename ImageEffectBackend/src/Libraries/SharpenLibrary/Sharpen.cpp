#include "Sharpen.h"
#include <bits/stdc++.h>
#define factor 16 // figured out experimentally

using namespace std;

int clip(int value) {   // takes in a given value and brings it to the range 0 to 255.. if x<0 --> 0 | if x>255 --> 255
    return min(max(value, 0), 255);
}

void applySharpness(vector<vector<Pixel>>& image, float amount) {
    const int n = image.size(); // no of rows
    const int m = image[0].size();  // no of columns

    const int kernelSize = 3;
    int kernel[kernelSize][kernelSize] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}}; // kernel for edge detection

    const float scalingFactor = amount / factor;

    vector<vector<Pixel>> tempImage(image);

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            float rtotal = 0, gtotal = 0, btotal = 0;

            for (int x = 0; x < kernelSize; ++x) {
                for (int y = 0; y < kernelSize; ++y) {
                    // convolving the kernel with the original image
                    rtotal += kernel[x][y] * image[i + x - 1][j + y - 1].r;
                    gtotal += kernel[x][y] * image[i + x - 1][j + y - 1].g;
                    btotal += kernel[x][y] * image[i + x - 1][j + y - 1].b;
                }
            }

            // the sharpened image is obtained by adding the original image and the edge detection image
            tempImage[i][j].r = clip(image[i][j].r + static_cast<int>(scalingFactor * rtotal));
            tempImage[i][j].g = clip(image[i][j].g + static_cast<int>(scalingFactor * gtotal));
            tempImage[i][j].b = clip(image[i][j].b + static_cast<int>(scalingFactor * btotal));
        }
    }

    image = tempImage;

}