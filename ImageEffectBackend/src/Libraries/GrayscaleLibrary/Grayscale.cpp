#include "Grayscale.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<Pixel>> grayscaleconvert(vector<vector<Pixel>> &v){//just for safety if reference doesn't work, we will return the pixels
    //we have a reference to that vector, so whatever we do will effect that vector only
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            Pixel p = v[i][j];
            double average = (p.b + p.g + p.r)/3.0;
            // p.b = p.g = p.r = (int)average;
            // p.b = p.g = p.r = 255;
            v[i][j].r = v[i][j].b = v[i][j].g= (int)average;
        }
    }
    return v;
}