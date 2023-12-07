#include "Rotation.h"
#include<bits/stdc++.h>

using namespace std;

void ninety(vector<vector<Pixel>>& image,vector<vector<Pixel>>& newImage, int value){
    int rows = min(image.size(),image[0].size());
    for(int i = 0; i <rows/2;i++)
        for(int j=i; j<rows-i-1;j++){
            newImage[i][j] = image[j][rows-i-1];
            newImage[j][rows-i-1] = image[rows-i-1][rows-1-j];
            newImage[rows-i-1][rows-j-1] = image[rows-1-j][i];
            newImage[rows-j-1][i] = image[i][j];
        }
}

void rotate(vector<vector<Pixel>>& image,vector<vector<Pixel>>& newImage, int value){
    int rows = min(image.size(),image[0].size());
    for(int i = 0; i <rows/2;i++)
        for(int j=i; j<rows-i-1;j++){
            int tempr = newImage[i][j].r;
            int tempg = newImage[i][j].g;
            int tempb = newImage[i][j].b;
            newImage[i][j] = image[j][rows-i-1];
            newImage[j][rows-i-1] = image[rows-i-1][rows-1-j];
            newImage[rows-i-1][rows-j-1] = image[rows-1-j][i];
            newImage[rows-j-1][i].r = tempr;
            newImage[rows-j-1][i].g = tempg;
            newImage[rows-j-1][i].b = tempb;
        }
}

vector<vector<Pixel>> applyRotation( vector<vector<Pixel>>& image, int value){
    int rows = min(image.size(),image[0].size());
    vector<vector<Pixel>> newImage(rows,vector<Pixel>(rows));

    if(value == 1){
        ninety(image, newImage,value);
    }
    else if(value==2){
        ninety(image, newImage,value);
        rotate(newImage, newImage,value);
    }
    else if(value==3){
        ninety(image, newImage,value);
        rotate(newImage, newImage,value);
        rotate(newImage, newImage,value);
    }
    else  return image;
    return newImage;
}