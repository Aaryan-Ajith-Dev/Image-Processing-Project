package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.model.LogModel;

public class ContrastImplementation implements SingleValueParameterizableEffect
{
    private float amount;

    public void setParameterValue(float amount) throws IllegalParameterException
    {
        this.amount = amount;
    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService)
    {
        return ContrastInterface.applyContrast(image, amount);

        /* Code to write logs */
    }
}