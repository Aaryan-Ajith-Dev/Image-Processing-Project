#include "Sepia.h"
#include<vector>
using namespace std;

void applySepia(vector<vector<Pixel>>& image){
    for(int i=0;i<image.size();i++)
        for(int j =0;j<image[i].size();j++){
            int tr = (int)(image[i][j].r*0.393+image[i][j].g*0.769+image[i][j].b*0.189);
            int tg = (int)(image[i][j].r*0.349+image[i][j].g*0.686+image[i][j].b*0.168);
            int tb = (int)(image[i][j].r*0.272+image[i][j].g*0.534+image[i][j].b*0.131);
            image[i][j].r = tr >255 ? 255 : tr;
            image[i][j].g = tg >255 ? 255 : tg;
            image[i][j].b = tb >255 ? 255 : tb;
        }
}