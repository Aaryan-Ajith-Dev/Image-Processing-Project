#include "Rotation.h"
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyRotation(vector<vector<Pixel>>& image,int value){
    // function which rotates the array required number of times by 90 deg

    while(value--){  // rotate the array by 90 deg value times

        vector<vector<Pixel>> temp; //temp stores the rotated array temporarily

        for(int i=image[0].size()-1; i>=0; i--){
            // rotate the array
            vector<Pixel> row;
            for(int j=0; j<image.size(); j++) row.push_back(image[j][i]);
            temp.push_back(row);
        }

        image = temp;
    }
}