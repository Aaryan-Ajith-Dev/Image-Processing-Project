package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class ContrastImplementation implements SingleValueParameterizableEffect
{
    private float amount;

    public void setParameterValue(float amount) throws IllegalParameterException
    {
        if (amount < 0 || amount > 200)
            throw new IllegalParameterException("Illegal parameter for Contrast effect");

        this.amount = amount;
    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService)
    {
        loggingService.addLog(fileName, "Contrast", Float.toString(amount));

        return ContrastInterface.applyContrast(image, amount);
    }
}