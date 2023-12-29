package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.DominantColourInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class DominantColourImplementation implements PhotoEffect{
    
    // Apply the effect
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService)
    {
        image = DominantColourInterface.applyDominantColour(image); // Modified image

        // Add log for the effect
        loggingService.addLog(fileName, "DominantColour", "None");
        
        return image; // Return the modified image
    }   
}