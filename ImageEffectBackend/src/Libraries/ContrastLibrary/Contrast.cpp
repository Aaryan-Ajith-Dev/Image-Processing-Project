#include "Contrast.h"
#define scale 25

void contrastEffect(vector<vector<Pixel>>& imageVector, float amount)
{
    amount = amount / scale;
    for (int i = 0; i < imageVector.size(); ++i)
    {
        for (int j = 0; j < imageVector[0].size(); ++j)
        {
            imageVector[i][j].r = min(255, (int)(imageVector[i][j].r * amount));
            imageVector[i][j].g = min(255, (int)(imageVector[i][j].g * amount));
            imageVector[i][j].b = min(255, (int)(imageVector[i][j].b * amount));
        }
    }
}