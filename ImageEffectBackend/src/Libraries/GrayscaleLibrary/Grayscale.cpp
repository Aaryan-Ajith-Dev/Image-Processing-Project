#include "Grayscale.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<Pixel>> grayscaleconvert(vector<vector<Pixel>> &v){//function returns a vector of vectors
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            Pixel p = v[i][j];
            double average = (p.b + p.g + p.r)/3.0; // grayscale is the average of r, g, b components for each pixel
            v[i][j].r = v[i][j].b = v[i][j].g= (int)average;// type cast and assign
        }
    }
    return v;
}
