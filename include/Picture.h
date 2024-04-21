#ifndef PICTURE_H
#define PICTURE_H

#include "Settings.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Picture{

    public:
        /*
        
        Constructor parameters:
            THIS ASSUMES THAT SETTINGS IS BUILT FIRST
            Settings: will be a setting object that has the settings
            vector<unsigned>: our bitmap
            unsigned&: width
            unsigned&: height

        */
        Picture(vector<unsigned char>, unsigned, unsigned);

        /*
        
        calls change settings UI and changes settings

        */

    

        void changeSettings(); //Calls changeSettingsUI

        void convert();         //converts the bitmap to the ascii characters

        void changeOutputPath(string);  //Changes output Path
        
        void changeInputPath(string);   //Changes input path

        bool getPrintToConsole();

        string getOutputPath() {
            return this->settings.getOutputPath();
        }

    private:
        vector<unsigned char> bitmap; //out bitmap file in vector
        unsigned bitmapHeight;  //height of bitmap
        unsigned bitmapWidth;   //width of bitmap
        Settings settings;
        double calculateBrightness(unsigned x, unsigned y);
};



#endif
