#include "HueSaturation.h"
#include <cmath>
#define scale M_PI

int clip(int value) {
    return min(max(value, 0), 255);
}


// finding hue by rgb rotate method
class RGBRotate{
    private:
        vector<vector<double>> matrix;
    public:
        // initialising the matrix with 0 values
        RGBRotate(){
            for(int i = 0; i < 3; i++){
                vector<double> temp;
                for (int j = 0; j < 3; j++){
                    temp.push_back(0);
                }
                matrix.push_back(temp);
            }
        }

        // matrix for rotating a vector about [1,1,1] vector
        // this is performed as a combination of 3 operations.. first rotating n = [1,1,1] to the z axis and then rotating that about the z axis by the given amount
        // then we perform the inverse of the first operation to bring back n vector to [1,1,1]
        // the following is a combination of the 3 operations represented as a matrix (we would have to find and multiply those 3 matrices)
        void setHueRotation(double degrees){
            double cosA = cos((degrees)*(M_PI)/(180));
            double sinA = sin((degrees)*(M_PI)/(180));
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

        // performs the linear transformation on the input (r,g,b) vector
        vector<double> apply(double r, double g, double b){
            vector<double> rgb;
            double rx = r * matrix[0][0] + g * matrix[0][1] + b * matrix[0][2];
            double gx = r * matrix[1][0] + g * matrix[1][1] + b * matrix[1][2];
            double bx = r * matrix[2][0] + g * matrix[2][1] + b * matrix[2][2];
            rgb.push_back(rx);
            rgb.push_back(gx);
            rgb.push_back(bx);
            return rgb;
        }
};

// converts hsv coords to rgb
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
        s = (diff / cmax)*100;

    double v = cmax*100;
    vector<double> arr = {h, s, v};
    return arr;
}

// converts hsv coords to rgb
vector<double> hsv_to_rgb(double h, double s, double v){
    double c = v * s / 100;
    double h1 = h / 60;
    double x = c * (1 - abs(fmod(h1,2) - 1));

    if (h1<1){
        vector<double> arr = {c, x, 0};
        double m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<2){
        vector<double> arr = {x, c, 0};
        double m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<3){
        vector<double> arr = {0, c, x};
        double m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<4){
        vector<double> arr = {0, x, c};
        double m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<5){
        vector<double> arr = {x, 0, c};
        double m = v - c;
        arr[0]+=m;
        arr[1]+=m;
        arr[2]+=m;
        return arr;
    }
    else if (h1<6){
        vector<double> arr = {c, 0, x};
        double m = v - c;
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

    // applies hue
    rgb.setHueRotation(hueValue * scale);
    for (int i = 0; i < n ;i++){
        for (int j = 0; j < m; j++){
            vector<double> RGBValues = rgb.apply(image[i][j].r,image[i][j].g,image[i][j].b);
            image[i][j].r = clip(RGBValues[0]);
            image[i][j].g = clip(RGBValues[1]);
            image[i][j].b = clip(RGBValues[2]);
        }
    }

    // applies saturation
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            vector<double> hsv = rgb_to_hsv(image[i][j].r, image[i][j].g, image[i][j].b);
            // hsv[0] += hueValue*scale;
            hsv[1] = saturationValue*2;
            vector<double> rgb = hsv_to_rgb(hsv[0], hsv[1], hsv[2]);
            int factor = hsv[2];
            image[i][j].r = clip(factor + rgb[0]);
            image[i][j].g = clip(factor + rgb[1]);
            image[i][j].b = clip(factor + rgb[2]);
        }
}

