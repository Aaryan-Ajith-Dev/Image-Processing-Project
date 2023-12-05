#include "Contrast.h"

void contrastEffect(vector<vector<Pixel>>& imageVector, float amount)
{
    for (int i = 0; i < imageVector.size(); ++i)
    {
        for (int j = 0; j < imageVector[0].size(); ++j)
        {
            imageVector[i][j].r = min(255, imageVector[i][j].r * (int)amount);
            imageVector[i][j].g = min(255, imageVector[i][j].g * (int)amount);
            imageVector[i][j].b = min(255, imageVector[i][j].b * (int)amount);
        }
    }
}