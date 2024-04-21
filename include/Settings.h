#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

class Settings{
    public:
        /*
        
        Settings constructor would have the default settings

        */
        Settings();
        /*
        
        displaySettings would simply display settings that is it

        */
        void displaySettings();
        /*

        changeSettingsUI would change present the user a simple UI that changes settings
        this would act as kind of like a menu that you cna navigate to change the settings
        
        */
        void changeSettingsUI();

        string getInputPath(){
            return inputPath;
        }
        string getOutputPath(){
            return outputPath;
        }
        unsigned getChunkSize(){
            return chunkSize;
        }

        float getSampleSize(){
            return sampleSize;
        }

        vector<char> getCharMap(){
            return charMap;
        }

        void setInputPath(string);
        void setOutputPath(string);
        bool getPrintToConsole();

    private:
        string inputPath;   //The input path of the original PNG
        string outputPath;  //The output path for the new PNG
        unsigned chunkSize; //the amount of pixels in the PNG that would be replaced by an ASCII char
        vector<char> charMap;   //Char map that would be used to build image
        float sampleSize;   //Sample size, would be used for sampling the average light around pixel
        bool printToConsole; //Decides whether to print to console or not
        /*

        for all change functions:
            1. Prompts the user to the value you want
            2. After input validates
                if good, return true
            3. Should loop until it returns true !!
        
        */
        bool changeSampleSize();
        bool changeInputPath();
        bool changeOutputPath();
        bool changeChunkSize();
        bool changeCharMap();
        bool changePrintToConsole();
        

        //initilization of full char map below
};

#endif
