#include "../include/Picture.h"
#include "../include/Settings.h"

/*

Constructor parameters:
THIS ASSUMES THAT SETTINGS IS BUILT FIRST
Settings: will be a setting object that has the settings
vector<unsigned>: our bitmap
unsigned&: width
unsigned&: height

*/

Picture::Picture(vector<unsigned char> bitmap, unsigned width, unsigned height){
    settings = Settings();
    this->bitmap = bitmap;
    this->bitmapWidth = width;
    this->bitmapHeight = height;

}


/*

calls change settings UI and changes settings

*/



void Picture::changeSettings(){
    settings.displaySettings();
}

//Conversion 

void Picture::convert(){

    //Create Output Stream
    ofstream outputFile(settings.getOutputPath());


    //Iterate through the image's pixels chunk size at a time
    for(float y = 0; y < bitmapHeight - settings.getChunkSize(); y += settings.getChunkSize()){
        for(float x = 0; x < bitmapWidth - settings.getChunkSize(); x += settings.getChunkSize()){

            //Calculates chunk brightness
            double chunkBrightness = calculateBrightness(x, y);

            //Picks character based on brightness
            unsigned charIndex = chunkBrightness*(settings.getCharMap().size()-1);

            //Checks if should print to console
            if(this->getPrintToConsole() == true) {
                cout << settings.getCharMap().at(charIndex);
            }

            //output to file
            outputFile << settings.getCharMap().at(charIndex);
        }

        //After every y value output new line
        if(this->getPrintToConsole() == true) {
            cout << "\n";
        }
        outputFile<< "\n";
    }
}       

double Picture::calculateBrightness(unsigned x, unsigned y){

    //Creates a fraction to create scalar for sampling
    float frac = settings.getChunkSize()/settings.getSampleSize();
    unsigned brightness = 0;
    unsigned numSampled = 0;
    for(unsigned i = 0; i < settings.getSampleSize(); i++){
        for(unsigned j = 0; j < settings.getSampleSize(); j++){

            //gets specific pixel for X and Y
            unsigned sampledX = x + frac * j;
            unsigned sampledY = y + frac * i;

            //Making sure it is in bitmap range
            if(sampledX > bitmapWidth || sampledY > bitmapHeight){
                continue;
            }

            //Calculates where the pixel in bitmap is
            unsigned index = (sampledY*bitmapWidth+ sampledX)*4;

            //Gets RGB values @ the pixel
            unsigned red = bitmap[index];
            unsigned green = bitmap[index +1];
            unsigned blue = bitmap[index+2];
            unsigned alpha = bitmap[index+3];

            //Alpha channels checks if it is blackc
            if(alpha == 0){
                brightness += 255;
            }else{

                //Calculate relative brightness of pixel(Not relative)
                brightness += (.2126*red) + (.7152*green) + (.0722*blue);
                
            }
            numSampled++;
        }
    }
    //returns the relative brightness of pixel
    return brightness / (numSampled * 255.0);
}
    
void Picture::changeInputPath(string inputPath) {
    this->settings.setInputPath(inputPath);
}

void Picture::changeOutputPath(string outputPath) {
    this->settings.setOutputPath(outputPath);
}

bool Picture::getPrintToConsole() {
    return this->settings.getPrintToConsole();
}
