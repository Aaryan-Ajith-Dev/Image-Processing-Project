package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterfaces;

class DoGrayscale extends Thread{
    private Pixel[][] image;
    DoGrayscale(Pixel[][] image){
        this.image = image;
    }
    public Pixel[][] getImage() {
        return image;
    }
    public void setImage(Pixel[][] image) {
        this.image = image;
    }

    public void run(){
        System.out.println("Doing the grayscale");
        this.setImage(GrayscaleInterface.applyGrayscale(image));
    }  
}

class DoLogging extends Thread{
    private Pixel[][] image;
    private String fileName;
    private LoggingService loggingService;
    DoLogging(Pixel[][] image, String filename, LoggingService loggingService){
        this.image = image;
        this.fileName = filename;
        this.loggingService = loggingService;
    }
    public Pixel[][] getImage(){
        return image;
    }
    public void setImage(Pixel[][] image) {
        this.image = image;
    }
    public void run(){
        System.out.println("Doing the log");
        loggingService.addLog(fileName, "GrayScale", "None");
    }
}


public class Grayscale implements PhotoEffect{
    public Pixel[][] apply(Pixel[][] image, String filename, LoggingService loggingService){
        DoGrayscale dg = new DoGrayscale(image);
        DoLogging dl = new DoLogging(image, filename, loggingService);
        dg.start();
        dl.start();
        boolean flag = true;
        while(dg.isAlive()){
            // System.out.println("dg is still working");
            if(!dl.isAlive() && flag){
                System.out.println("the log finished first\n");
                flag = false;
            }
        }
        image = dg.getImage();
        return image;
    }
}


