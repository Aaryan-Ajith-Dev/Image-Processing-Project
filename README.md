The project is about implementing parts of an image processing web-app.
The features implemented in this project are as follows:
1. Brightness - Ananthakrishna K(IMT2022086)
2. Contrast - Kandarp Dave (IMT2022115)
3. DominantColour - Kandarp Dave (IMT2022115)
4. Flip - Shreyas S (IMT2022078)
5. Gaussian Blur
6. Grayscale - Prateek Rath (IMT2022017)
7. HueSaturation
8. Invert - Shreyas S (IMT2022078)
9. Rotation - Ananthakrishna K(IMT2022086)
10. Sepia - Ananthakrishna K(IMT2022086)
11. Sharpen
-- Threading - Prateek Rath (IMT2022017)
-- LoggingService - Kandarp Dave (IMT2022115)

Note: The exact algorithms or descriptions of the cpp files are written as comments within them. This README just provides an overview of various parts of the project.

Most of the work is done in the ImageEffectBackend/src Directory. 
There are 3 directories under the src directory

1. The libraries directory:
This directory has subdirectories corresponding to each of the features.Each subdirectory has 2 .cpp files and one .h file.
The .h file contains the declaration of methods defined in the <feature_name>.cpp files. The <name>Interface.cpp file is mostly prewritten.
This file is responsible for returning the modified array of pixels after calling the function defined in the <feature_name>.cpp file.


3. The main directory:
More specifically we describe the main/java/com/iiitb/imageEffectApplication directory. 
Few subdirectories are of importance here:
	a. baseEffects
	b. libraryInterfaces
	c. EffectImplementation
	d. service

a. baseEffects:
This directory has interfaces that are to be implemented by classes in the EffectImplementation directory.

b. libraryInterfaces:
This directory has interfaces that contain apply functions declared as static and native. These functions are actually defined in the libraries deirectory in c++.

c. effectImplementation:
This directory has files of the form <feature_name>Implementation.java. Each file has a class that defines the apply method and implements a class from the baseEffects directory.
Let us take a specific example to understand this better. The ContrastImplementation.java file has the ContrastImplementation class which implements the SingleValueParameterizableEffect. 
The class defines the apply method which makes use of the static applyContrast method defined in the ContrastInterface.java file in the libraryInterfaces directory.

d. service:
This directory has two files.
The LoggingService.java file has various methods to aid logging the use of a service.
The PhotoEffectService.java file has a PhotoEffectService class. It has methods of the form public ResponseEntity<byte[]> apply<feature_name>Effect. 
In each of these methods we have added lines of code in the "todo" section that assign the modified pixels to the modifiedImage matrix using the 
corresponding apply methods defined in the EffectImplementation directory.

