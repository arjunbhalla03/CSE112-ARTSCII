#include "./lodepng/lodepng.h"
#include "include/Picture.h"
#include "include/Settings.h"
#include <iostream>

using namespace std;

void MainLoop(){
    bool loop = true;
    string ans;
    while(loop){
        string pngName;
        cout << "Input PNG file name: " << endl;
        cin >> pngName;
        vector<unsigned char> bitmap;
        unsigned bitmapWidth, bitmapHeight;
    
        while (lodepng::decode(bitmap, bitmapWidth, bitmapHeight, pngName) != 0){
            //ERROR("couldn't load file");
            cout << "bad input";
            cin >> pngName;
        }
        //should load a png into a bit map if picture is in correct format
        Picture pic(bitmap, bitmapWidth, bitmapHeight);
        pic.changeInputPath(pngName);
        pic.changeOutputPath(pngName.substr(0, pngName.size() - 4) + ".txt");
        pic.changeSettings();
        pic.convert();
        cout << "ASCII Image successfully generated at output path: " << pic.getOutputPath() << endl;
        cout << "Would you like to generate another PNG file in ASCII? Enter Y or N: " << endl;
        cin >> ans;
        while(ans != "Y" && ans != "N"){
            cout << "Please enter a valid answer of Y or N: " << endl;
            cin >> ans;
        }
        if(ans == "N"){
            loop = false;
        }
    }
}

int main(){
    MainLoop();
    return 0;
}
