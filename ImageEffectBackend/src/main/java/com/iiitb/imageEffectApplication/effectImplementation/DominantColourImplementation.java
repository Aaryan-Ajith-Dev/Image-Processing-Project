package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.DominantColourInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class DominantColourImplementation implements PhotoEffect{
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        image = DominantColourInterface.applyDominantColour(image);
        loggingService.addLog(fileName, "DominantColour", "None");
        return image;
    }   
}