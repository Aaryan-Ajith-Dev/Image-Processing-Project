package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterface;

public class Grayscale implements PhotoEffect{
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        //so there is a c++ method that does this stuff
        //but who gives it to c++?
        //the library interfaces!!!!
        //we add the required imports and then just call the function
        System.out.printf("%d %d", image[0][0].getR(), image[0][0].getG(), image[0][0].getB());
        Pixel[][] p = GrayscaleInterface.applyGrayscale(image);
        image = GrayscaleInterface.applyGrayscale(image);
        return image;
    }
}
