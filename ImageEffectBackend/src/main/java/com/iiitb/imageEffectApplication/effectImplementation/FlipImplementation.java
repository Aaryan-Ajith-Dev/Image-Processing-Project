package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.*;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class FlipImplementation implements DiscreteEffect {
    private int horizontalFlipValue;
    private int verticalFlipValue;
    public void selectOptionValue(String optionName,int value) throws IllegalParameterException{
        if((!optionName.equals("horizontalFlipValue") && !optionName.equals("verticalFlipValue"))||(value!=1 && value!=0)){
            throw new IllegalParameterException("Illegal option for Flip effect");
        }
        if(optionName.equals("horizontalFlipValue")){
            this.horizontalFlipValue=value;
        }
        if(optionName.equals("verticalFlipValue")){
            this.verticalFlipValue=value;
        }
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "FlipEffect","None");
        
        return FlipInterface.applyFlip(image, horizontalFlipValue, verticalFlipValue);
    }   
}
