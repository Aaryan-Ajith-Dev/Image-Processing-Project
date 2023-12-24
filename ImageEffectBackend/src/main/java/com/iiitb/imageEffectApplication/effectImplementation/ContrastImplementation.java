package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class ContrastImplementation implements SingleValueParameterizableEffect
{
    private float amount; // Parameter value to apply effect

    // Set the parameter value
    public void setParameterValue(float amount) throws IllegalParameterException
    {
        // In case of illegal amount value, throw IllegalParameterException
        if (amount < 0 || amount > 200)
            throw new IllegalParameterException("Illegal parameter for Contrast effect");

        this.amount = amount; // Set amount
    }

    // Apply the effect
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService)
    {
        // Add log for the given effect
        loggingService.addLog(fileName, "Contrast", Float.toString(amount));

        // Return the modified image
        return ContrastInterface.applyContrast(image, amount);
    }
}