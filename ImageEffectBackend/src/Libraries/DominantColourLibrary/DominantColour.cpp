#include "Grayscale.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<Pixel>> do_domination(vector<vector<Pixel>> &v){//find the dominant colour and replace all other pixels with that colour
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            Pixel p = v[i][j];
            double average = (p.b + p.g + p.r)/3.0;
            
            
        }
    }
    return v;
}