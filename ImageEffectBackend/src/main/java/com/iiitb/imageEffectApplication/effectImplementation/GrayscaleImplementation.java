package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;// import the logging service
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterface;//import the grayscale interface

class DoGrayscale extends Thread{//this class handles converting to grayscale
    private Pixel[][] image;
    DoGrayscale(Pixel[][] image){
        this.image = image;
    }
    //getters and setters
    public Pixel[][] getImage() {
        return image;
    }
    public void setImage(Pixel[][] image) {
        this.image = image;
    }

    public void run(){//will be called when the thread starts to 'run'
        System.out.println("Doing the grayscale");
        this.setImage(GrayscaleInterface.applyGrayscale(image));//convert the image to grayscale
    }  
}

class DoLogging extends Thread{//this class handles logging
    private Pixel[][] image;
    private String fileName;
    private LoggingService loggingService;
    DoLogging(Pixel[][] image, String filename, LoggingService loggingService){
        this.image = image;
        this.fileName = filename;
        this.loggingService = loggingService;
    }
    //getters and setters
    public Pixel[][] getImage(){
        return image;
    }
    public void setImage(Pixel[][] image) {
        this.image = image;
    }
    public void run(){//will be called when the thread starts to 'run'
        System.out.println("Doing the log");
        loggingService.addLog(fileName, "GrayScale", "None");//do the logging
    }
}

//since grayscale needs no input parameters, no exceptions need to be handled
public class GrayscaleImplementation implements PhotoEffect{//extend only the PhotoEffect class
    public Pixel[][] apply(Pixel[][] image, String filename, LoggingService loggingService){
        DoGrayscale dg = new DoGrayscale(image);//create a dg object for conversion
        DoLogging dl = new DoLogging(image, filename, loggingService);// create a dl object for logging
        dg.start();//start both threads
        dl.start();
        boolean flag = true;
        while(dg.isAlive()){//if it is still working on grayscale
            // System.out.println("dg is still working");
            if(!dl.isAlive() && flag){//if it is done with logging
                System.out.println("the log finished first\n");
                //this print statement illustrates that logging finishes first, even thought it started later
                flag = false;
            }
        }
        image = dg.getImage();
        return image;//return the grayscaled image
    }
}


