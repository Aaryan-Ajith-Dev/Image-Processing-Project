#include "GaussianBlur.h"
#include <iostream>
#include <vector>
#include <cmath>

#define scale 2


int clip(int value) {
    return min(max(value, 0), 255);
}

void applyGaussianBlur(vector<vector<Pixel>>& image, float radius) {
    int n = image.size();
    int m = image[0].size();

    // adjusting radius with a particular scaling factor (determined experimentally)
    radius /= scale;
    // size of matrix to convolve with
    int kernelSize = static_cast<int>(2 * radius + 1);

    if (kernelSize <= 1){
        return;
    }

    /*
        Here the kernel is a matrix kernel[x][y] = fx*fy where fx and fy are normal distributions
        we can use this fact to do the convolution (typically O(n^4)) in terms of 2 independent convolutions
        in x and y directions (O(n^3)). This reduces the time complexity significantly.

        the following is the math for it:

        we want the final result to be the convolution with the kernal, that is, 
        image[i][j] = sumOverX(sumOverY(image[i-y][j-x]*kernel[x][y]))

        we can split it into, image1[i][j] = sumOverY(image[i-y][j]kernel[y]), and
        image2[i][j] = sumOverX(image1[i][j-x]*kernel[x])
                     = sumOverX(sumOverY( image[i-y][j-x] * kernel[y]) * kernel[x])
                     = sumOverX(sumOverY( image[i-y][j-x] * kernel[y] * kernel[x]))
        Now, kernel[x][y] = kernel[x] * kernel[y]
        and therefore,
        image2[i][j] = sumOverX(sumOverY( image[i-y][j-x] * kernel[x][y])) = image[i][j] 

    */

    vector<float> kernel(kernelSize);
    float sigma = radius;
    float sum = 0.0;
    for (int x = 0; x < kernelSize; x++) {
        kernel[x] = exp(-(x - sigma) * (x - sigma) / (2 * sigma * sigma));
        sum += kernel[x];
    }

    float prefixSumArray[kernelSize] = {kernel[0]};
    for (int x = 1; x < kernelSize; x++){
        prefixSumArray[x] = kernel[x] + prefixSumArray[x-1];
    }

    // normalising the kernel
    for (int i = 0; i < kernelSize; i++)
        kernel[i] /= sum;

    vector<vector<Pixel>> tempImage(image);

    // convolving in x direction
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            float rtotal = 0.0, gtotal = 0.0, btotal = 0.0;

            // adjusts blurring at boundaries and appropriatly normalising the kernel
            if( j < kernelSize / 2){
                for (int x = kernelSize/2 - j; x < kernelSize; x++){
                    rtotal += kernel[x] * image[i][j + x - kernelSize / 2].r * sum / prefixSumArray[j + kernelSize / 2];
                    gtotal += kernel[x] * image[i][j + x - kernelSize / 2].g * sum / prefixSumArray[j + kernelSize / 2];
                    btotal += kernel[x] * image[i][j + x - kernelSize / 2].b * sum / prefixSumArray[j + kernelSize / 2];
                }
            } else if(j >= m-kernelSize / 2){
                for (int x = 0; x < m + kernelSize/2 - j; x++){
                    rtotal += kernel[x] * image[i][j + x - kernelSize / 2].r * sum / prefixSumArray[m - j - 1 + kernelSize / 2];
                    gtotal += kernel[x] * image[i][j + x - kernelSize / 2].g * sum / prefixSumArray[m - j - 1 + kernelSize / 2];
                    btotal += kernel[x] * image[i][j + x - kernelSize / 2].b * sum / prefixSumArray[m - j - 1 + kernelSize / 2];
                }
            } else
            for (int x = 0; x < kernelSize; x++)
            {
                rtotal += kernel[x] * image[i][j + x - kernelSize / 2].r;
                gtotal += kernel[x] * image[i][j + x - kernelSize / 2].g;
                btotal += kernel[x] * image[i][j + x - kernelSize / 2].b;
            }

            tempImage[i][j].r = clip(static_cast<int>(rtotal));
            tempImage[i][j].g = clip(static_cast<int>(gtotal));
            tempImage[i][j].b = clip(static_cast<int>(btotal));
        }
    }

    // convolving in y direction
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            float rtotal = 0.0, gtotal = 0.0, btotal = 0.0;
            // adjusts blurring at boundaries and appropriatly normalising the kernel
            if( i < kernelSize / 2){
                for (int y = kernelSize/2 - i; y < kernelSize; y++){
                    rtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].r * sum / prefixSumArray[i + kernelSize / 2];
                    gtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].g * sum / prefixSumArray[i + kernelSize / 2];
                    btotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].b * sum / prefixSumArray[i + kernelSize / 2];
                }
            }
            else if(i >= n - kernelSize / 2){
                for (int y = 0; y < n + kernelSize/2 - i; y++){
                    rtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].r * sum / prefixSumArray[n - i - 1 + kernelSize / 2];
                    gtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].g * sum / prefixSumArray[n - i - 1 + kernelSize / 2];
                    btotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].b * sum / prefixSumArray[n - i - 1 + kernelSize / 2];
                }
            } else 
            for (int y = 0; y < kernelSize; y++) {
                rtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].r;
                gtotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].g;
                btotal += kernel[y] * tempImage[i + y - kernelSize / 2][j].b;
            }

            image[i][j].r = clip(static_cast<int>(rtotal));
            image[i][j].g = clip(static_cast<int>(gtotal));
            image[i][j].b = clip(static_cast<int>(btotal));
        }
    }
}
