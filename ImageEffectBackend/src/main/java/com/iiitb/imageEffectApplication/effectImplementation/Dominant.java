package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.DominantColourInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class Dominant {
 public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        //so there is a c++ method that does this stuff
        //but who gives it to c++?
        //the library interfaces!!!!
        //we add the required imports and then just call the function
        
        image = DominantColourInterface.applyDominantColour(image);
        loggingService.addLog(fileName, "Grayscale", "None");
        return image;
    }   
}
