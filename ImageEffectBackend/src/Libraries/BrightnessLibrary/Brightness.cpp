#include "Brightness.h"
#include<vector>
using namespace std;
void applyBrightness(vector<vector<Pixel>>& image, float amount){
    int n = image.size();
    int m = image[0].size();
    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++){
            image[i][j].r = image[i][j].r + amount  > 255 ? 255 : image[i][j].r + amount; 
            image[i][j].b = image[i][j].b + amount  > 255 ? 255 : image[i][j].b + amount; 
            image[i][j].g = image[i][j].g + amount  > 255 ? 255 : image[i][j].g + amount; 
        }
}