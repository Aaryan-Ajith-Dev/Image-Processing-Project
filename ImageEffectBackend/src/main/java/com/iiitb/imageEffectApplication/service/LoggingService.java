package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

@Service
public class LoggingService {

    // Add new log
    public void addLog(String fileName, String effectName, String optionValues) {

        LocalDateTime localDateTime = LocalDateTime.now(); // Current date and time
        String currentTime = localDateTime.toString(); // Convert to string

        try
        {
            FileWriter fileWriter = new FileWriter("logfile.txt", true); // Open logfile.txt in append mode
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter); // Buffered writer object

            // Write effect details in the file
            bufferedWriter.write(fileName + "::" + effectName + "::" + optionValues + "::" + currentTime);
            bufferedWriter.newLine();

            bufferedWriter.close();
            fileWriter.close();
        }

        // Catch IO Exception
        catch (IOException e)
        {
            System.out.println("Exception occurred while writing to log file.");
            System.out.println(e);
        }

        return;
    }

    // Returns List containing log objects
    public List<LogModel> getAllLogs() {

        List<LogModel> allLogs = new ArrayList<LogModel>(); // Contains all the logs

        try
        {
            File logFile = new File("logfile.txt"); // Open logfile.txt to read

            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;

            // Read each line of file
            while ((line = bufferedReader.readLine()) != null)
            {
                String sp[] = line.split("::"); // To get details of effect
                String fileName = sp[0]; // File name
                String effectName = sp[1]; // Effect name
                String optionValues = sp[2]; // Option values (parameters for effect)
                String timestamp = sp[3]; // Time at which effect was applied
                
                // Create log object and add to List
                LogModel logModel = new LogModel(timestamp, fileName, effectName, optionValues);
                allLogs.add(logModel);
            }

            bufferedReader.close();
        }

        // Catch IO Exception
        catch (IOException e)
        {
            System.out.println("Error occurred while reading log file.");
            System.out.println(e);
        }

        return allLogs; // Return the List
    }

    // Returns only those logs in which the given effect was applied
    public List<LogModel> getLogsByEffect(String effectName) {

        List<LogModel> logsByEffect = new ArrayList<LogModel>(); // LogModel List
        
        try
        {
            File logFile = new File("logfile.txt"); // Open file for reading

            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;

            // Read each line of file
            while ((line = bufferedReader.readLine()) != null)
            {
                String sp[] = line.split("::"); // To get details
                String fileName = sp[0]; // Name of file
                String effect = sp[1]; // Effect name
                String optionValues = sp[2]; // Option values (parameters)
                String timestamp = sp[3]; // Time at which effect was applied

                // If the applied effect is equal to the required effect
                if (effect.equalsIgnoreCase(effectName))
                {
                    // Create LogModel object and add to list
                    LogModel logModel = new LogModel(timestamp, fileName, effect, optionValues);
                    logsByEffect.add(logModel);
                }
            }
            bufferedReader.close();
        }

        // Catch IO Exception
        catch (IOException e)
        {
            System.out.println("Error occurred while reading log file.");
            System.out.println(e);
        }

        return logsByEffect; // Return the required logs
    }

    // Clear all the logs
    public void clearLogs() {

        try
        {
            // Open fileWriter with append = false to clear the file
            new FileWriter("logfile.txt", false).close();
        }

        // Catch IO Exception
        catch (IOException e)
        {
            System.out.println("Error occurred while deleting logs.");
            System.out.println(e);
        }

        return;
    }

    // Get effects which were applied during the given time
    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {

        List<LogModel> logsBetweenTimestamps= new ArrayList<LogModel>(); // List of required logs
        
        try
        {
            File logFile = new File("logfile.txt"); // Open file for reading

            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;

            // Read each line
            while ((line = bufferedReader.readLine()) != null)
            {
                String sp[] = line.split("::"); // Get details
                String fileName = sp[0]; // File name
                String effectName = sp[1]; // Effect name
                String optionValues = sp[2]; // Option values (parameters)
                String timestamp = sp[3]; // Time at which effect was applied

                LocalDateTime effectTimeStamp = LocalDateTime.parse(timestamp); // Convert to LocalDateTime object

                // If effect was applied during the given time
                if (effectTimeStamp.isAfter(startTime) && effectTimeStamp.isBefore(endTime))
                {
                    // Create LogModel object and add it to list
                    LogModel logModel = new LogModel(timestamp, fileName, effectName, optionValues);
                    logsBetweenTimestamps.add(logModel);
                }
            }
            bufferedReader.close();
        }

        // Catch IO Exception
        catch (IOException e)
        {
            System.out.println("Error occurred while reading log file.");
            System.out.println(e);
        }

        return logsBetweenTimestamps; // Return the list
    }
}
