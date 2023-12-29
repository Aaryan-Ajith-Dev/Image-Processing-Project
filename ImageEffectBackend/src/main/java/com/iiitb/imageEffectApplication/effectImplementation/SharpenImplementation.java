package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.SharpenInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class SharpenImplementation implements SingleValueParameterizableEffect {//setting the parameter and also handling illegal parameter exception
    private float amount;
    public void setParameterValue(float amount) throws IllegalParameterException{
        if(amount<0 || amount>200){
            throw new IllegalParameterException("Illegal parameter for Sharpen effect");
        }
        this.amount=amount;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){//applying the effect and also adding to log
        loggingService.addLog(fileName,"Sharpen",Float.toString(amount));
        return SharpenInterface.applySharpen(image, amount);
    }
    
}
