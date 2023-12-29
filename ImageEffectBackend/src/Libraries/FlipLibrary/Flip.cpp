#include "Flip.h"
#include <bits/stdc++.h>
#include"../Pixel.h"
using namespace std;
void applyHorizontalFlipEffect(vector<vector<Pixel>>&ImageVector){//does horizontal flip by reversing the columns
    int n=ImageVector.size();
    int m=ImageVector[0].size();
    for(int i=0;i<n;i++){
        reverse(ImageVector[i].begin(),ImageVector[i].end());
    }
}
void applyVerticalFlipEffect(vector<vector<Pixel>>&ImageVector){//does vertical flip by swapping rows
    int n=ImageVector.size();
    for(int i=0;i<n/2;i++){
        swap(ImageVector[i],ImageVector[n-i-1]);
    }
}
