package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.*;
import com.iiitb.imageEffectApplication.service.LoggingService;


public class RotationImplementation implements SingleValueDiscreteEffect {
    private int value;
    public void setParameterValue(int parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>3){
            throw new IllegalParameterException("Illegal parameter for Rotation effect");
        }
        this.value=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Rotation", Integer.toString(value*90));
        return RotationInterface.applyRotation(image, value);
    }
}
