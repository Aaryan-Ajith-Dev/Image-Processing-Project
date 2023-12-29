#include "Contrast.h"
#define scale 50 // Scaling factor

void contrastEffect(vector<vector<Pixel>>& imageVector, float amount)
{
    amount = amount / scale; // Scale down the given amount

    /* Iterate through each pixel and multiply the RGB values with the given amount.
       Also, see to it that the value does not exceed 255. */

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