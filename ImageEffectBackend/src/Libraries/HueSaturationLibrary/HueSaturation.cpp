#include "HueSaturation.h"
#include <cmath>
#define scale M_PI

int clip(int value) {
    return min(max(value, 0), 255);
}

class RGBRotate{
    private:
        vector<vector<float>> matrix;
    public:
        RGBRotate(){
            for(int i = 0; i < 3; i++){
                vector<float> temp;
                for (int j = 0; j < 3; j++){
                    temp.push_back(0);
                }
                matrix.push_back(temp);
            }
        }

        void setHueRotation(float degrees){
            float cosA = cos((degrees)*(M_PI)/(180));
            float sinA = sin((degrees)*(M_PI)/(180));
            matrix[0][0] = cosA + (1.0 - cosA) / 3.0;
            matrix[0][1] = 1./3. * (1.0 - cosA) - sqrt(1./3.) * sinA;
            matrix[0][2] = 1./3. * (1.0 - cosA) + sqrt(1./3.) * sinA;
            matrix[1][0] = 1./3. * (1.0 - cosA) + sqrt(1./3.) * sinA;
            matrix[1][1] = cosA + 1./3. *(1.0 - cosA);
            matrix[1][2] = 1./3. * (1.0 - cosA) - sqrt(1./3.) * sinA;
            matrix[2][0] = 1./3. * (1.0 - cosA) - sqrt(1./3.) * sinA;
            matrix[2][1] = 1./3. * (1.0 - cosA) + sqrt(1./3.) * sinA;
            matrix[2][2] = cosA + 1./3. * (1.0 - cosA);
        }

        vector<float> apply(float r, float g, float b){
            vector<float> rgb;
            float rx = r * matrix[0][0] + g * matrix[0][1] + b * matrix[0][2];
            float gx = r * matrix[1][0] + g * matrix[1][1] + b * matrix[1][2];
            float bx = r * matrix[2][0] + g * matrix[2][1] + b * matrix[2][2];
            rgb.push_back(rx);
            rgb.push_back(gx);
            rgb.push_back(bx);
            return rgb;
        }
};

void applyHueSaturation(vector< vector<Pixel> > &image, float saturationValue, float hueValue) {
    // hue
    RGBRotate rgb;
    int n = image.size();
    int m = image[0].size();
    rgb.setHueRotation(hueValue * scale);
    for (int i = 0; i < n ;i++){
        for (int j = 0; j < m; j++){
            vector<float> RGBValues = rgb.apply(image[i][j].r,image[i][j].g,image[i][j].b);
            image[i][j].r = clip(RGBValues[0]);
            image[i][j].g = clip(RGBValues[1]);
            image[i][j].b = clip(RGBValues[2]);
        }
    }

    // saturation
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int r = image[i][j].r;
            int g = image[i][j].g;
            int b = image[i][j].b;
            if (r>g && r>b){
                r += saturationValue;
                if(g<b)
                    g-=saturationValue;
                else
                    b-=saturationValue;
            }
            if (g>r && g>b){
                g += saturationValue;
                if(r<b)
                    r-=saturationValue;
                else
                    b-=saturationValue;
            }
            if (b>g && b>r){
                b += saturationValue;
                if(g<r)
                    g-=saturationValue;
                else
                    r-=saturationValue;
            }
            image[i][j].r = clip(r);
            image[i][j].g = clip(g);
            image[i][j].b = clip(b);
        }
    }
}


