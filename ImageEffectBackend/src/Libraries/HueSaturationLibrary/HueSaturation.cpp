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

vector<double> rgb_to_hsv(double r, double g, double b) 
{ 
  
    // R, G, B values are divided by 255 
    // to change the range from 0..255 to 0..1 
    r = r / 255.0; 
    g = g / 255.0; 
    b = b / 255.0; 
  
    // h, s, v = hue, saturation, value 
    double cmax = max(r, max(g, b)); // maximum of r, g, b 
    double cmin = min(r, min(g, b)); // minimum of r, g, b 
    double diff = cmax - cmin; // diff of cmax and cmin. 
    double h = -1, s = -1; 
  
    // if cmax and cmax are equal then h = 0 
    if (cmax == cmin) 
        h = 0; 
  
    // if cmax equal r then compute h 
    else if (cmax == r) 
        h = fmod(60 * ((g - b) / diff) + 360, 360); 
  
    // if cmax equal g then compute h 
    else if (cmax == g) 
        h = fmod(60 * ((b - r) / diff) + 120, 360); 
  
    // if cmax equal b then compute h 
    else if (cmax == b) 
        h = fmod(60 * ((r - g) / diff) + 240, 360); 

    // if cmax equal zero 
    if (cmax == 0) 
        s = 0; 
    else
        s = (diff / cmax) * 100;

    double v = cmax * 100;
    vector<double> arr = {h, s, v};
    return arr;
}

vector<double> hsv_to_rgb(double h, double s, double v){
    float c = v * s;
    float h1 = h / 60;
    float x = c * (1 - abs(fmod(h1,2) - 1));
    if (h1<1){
        vector<double> arr = {c, x, 0};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<2){
        vector<double> arr = {x, c, 0};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<3){
        vector<double> arr = {0, c, x};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<4){
        vector<double> arr = {0, x, c};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<5){
        vector<double> arr = {x, 0, c};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<6){
        vector<double> arr = {c, 0, x};
        int m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    vector<double> def = {0, 0, 0};
    return def;
}

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
    // int n = image.size();
    // int m = image[0].size();
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            vector<double> hsv = rgb_to_hsv(image[i][j].r, image[i][j].g, image[i][j].b);
            // hsv[0] = hueValue*scale;
            hsv[1] = saturationValue/50;
            vector<double> rgb = hsv_to_rgb(hsv[0], hsv[1], hsv[2]);
            int factor = hsv[2];
            image[i][j].r = clip(factor + rgb[0]);
            image[i][j].g = clip(factor + rgb[1]);
            image[i][j].b = clip(factor + rgb[2]);
        }
}

    // // hue
    // RGBRotate rgb;
    // int n = image.size();
    // int m = image[0].size();
    // rgb.setHueRotation(hueValue * scale);
    // for (int i = 0; i < n ;i++){
    //     for (int j = 0; j < m; j++){
    //         vector<float> RGBValues = rgb.apply(image[i][j].r,image[i][j].g,image[i][j].b);
    //         image[i][j].r = clip(RGBValues[0]);
    //         image[i][j].g = clip(RGBValues[1]);
    //         image[i][j].b = clip(RGBValues[2]);
    //     }
    // }

    // // saturation
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         int r = image[i][j].r;
    //         int g = image[i][j].g;
    //         int b = image[i][j].b;
    //         if (r>g && r>b){
    //             r += saturationValue;
    //             if(g<b)
    //                 g-=saturationValue;
    //             else
    //                 b-=saturationValue;
    //         }
    //         if (g>r && g>b){
    //             g += saturationValue;
    //             if(r<b)
    //                 r-=saturationValue;
    //             else
    //                 b-=saturationValue;
    //         }
    //         if (b>g && b>r){
    //             b += saturationValue;
    //             if(g<r)
    //                 g-=saturationValue;
    //             else
    //                 r-=saturationValue;
    //         }
    //         image[i][j].r = clip(r);
    //         image[i][j].g = clip(g);
    //         image[i][j].b = clip(b);
    //     }
    // }


