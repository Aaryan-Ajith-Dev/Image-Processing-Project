package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.*;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class HueSaturationImplementation implements ParameterizableEffect {
    private float hueAmount;
    private float saturationAmount;
    public void setParameter(String paramName,float value) throws IllegalParameterException{
        if((!paramName.equals("Hue") && !paramName.equals("Saturation"))|| value<0 || value>200){
            throw new IllegalParameterException("Illegal paramter for HueSaturation effect");
        }
        if(paramName.equals("Hue")){
            this.hueAmount=value;
        }
        if(paramName.equals("Saturation")){
            this.saturationAmount=value;
        }
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "HueSaturation", Float.toString(hueAmount)+" "+Float.toString(saturationAmount));
        return HueSaturationInterface.applyHueSaturation(image, saturationAmount, hueAmount);
    }
    
}
