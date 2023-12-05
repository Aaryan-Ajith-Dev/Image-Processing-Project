#include "Flip.h"
#include <bits/stdc++.h>
#include"../Pixel.h"
using namespace std;
void applyHorizontalFlipEffect(vector<vector<Pixel>>&ImageVector){
    int n=ImageVector.size();
    int m=ImageVector[0].size();
    for(int i=0;i<n;i++){
        reverse(ImageVector[i].begin(),ImageVector[i].end());
    }
}
void applyVerticalFlipEffect(vector<vector<Pixel>>&ImageVector){
    int n=ImageVector.size();
    for(int i=0;i<n/2;i++){
        swap(ImageVector[i],ImageVector[n-i-1]);
    }
}
