package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.*;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class GaussianBlurImplementation implements SingleValueParameterizableEffect {
    private float radius;
    public void setParameterValue(float parameterValue) throws IllegalParameterException{//handling illegal parameter exception
        if(parameterValue<0 || parameterValue>200){
            throw new IllegalParameterException("Illegal parameter for GaussianBlur effect");
        }
        this.radius=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){//applying the effect
        loggingService.addLog(fileName, "GaussianBlur", Float.toString(radius));//adding to log
        return GaussianBlurInterface.applyGaussianBlur(image, radius);
    }
    
}
