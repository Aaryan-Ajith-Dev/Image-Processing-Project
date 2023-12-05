#include "Invert.h"
#include<vector>
using namespace std;

void applyInvertEffect(vector<vector<Pixel>>&ImageVector){
    int n=ImageVector.size();
    int m=ImageVector[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ImageVector[i][j].b=255-ImageVector[i][j].b;
            ImageVector[i][j].r=255-ImageVector[i][j].r;
            ImageVector[i][j].g=255-ImageVector[i][j].g;
        }
    }
}