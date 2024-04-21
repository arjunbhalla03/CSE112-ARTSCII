#include "../include/Settings.h"
#include <vector>
#include <fstream>
#include <limits>

/*

Settings constructor would have the default settings

*/
Settings::Settings(){

    this->inputPath = "";
    this->outputPath = "";
    this->chunkSize = 1;
    this->sampleSize = 1;
    this->printToConsole = false;

    charMap.push_back('@');
    charMap.push_back('%');
    charMap.push_back('#');
    charMap.push_back('+');
    charMap.push_back('?');
    charMap.push_back('*');
    charMap.push_back(';');
    charMap.push_back('=');
    charMap.push_back('-');
    charMap.push_back(':');
    charMap.push_back('.');
    charMap.push_back('`');
    charMap.push_back(' ');
}
/*

displaySettings would simply display settings that is it

*/
void Settings::displaySettings(){
    string choice = "";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "ARTSCII - Ascii Art Generator" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    cout << "CURRENT SETTINGS: " << endl << endl;
    cout << "1. Sample Size: " << sampleSize << endl;
    cout << "2. Input Path: " << inputPath << endl;
    cout << "3. Output Path: " << outputPath << endl;
    cout << "4. Chunk Size: " << chunkSize << endl;
    cout << "5. Print ASCII image to Console?: ";
    if(printToConsole == false) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    cout << "6. Char Map: ";
    for(unsigned i = 0; i < charMap.size(); i++) {
        cout << charMap.at(i);
    }
    cout << endl << endl;
    cout << "Would you like to make any changes to the current settings, or finalize your settings and generate your image? (Y/N/F)" << endl;
    cin >> choice;
    cout << endl;
    while(choice != "Y" && choice != "N" && choice != "F") {
        cout << "Invalid input. Enter Y for Yes, N for No." << endl;
        cin >> choice;
        cout << endl;
    }
    if(choice == "Y") {
        this->changeSettingsUI();
    }
    else if(choice == "N") {
        this->displaySettings();
    }
    else {
    }
}
/*

changeSettingsUI would change present the user a simple UI that changes settings
this would act as kind of like a menu that you cna navigate to change the settings

*/
void Settings::changeSettingsUI(){
    string choice = "";
    cout << "CURRENT SETTINGS: " << endl << endl;
    cout << "1. Sample Size: " << sampleSize << endl;
    cout << "2. Input Path: " << inputPath << endl;
    cout << "3. Output Path: " << outputPath << endl;
    cout << "4. Chunk Size: " << chunkSize << endl;
    cout << "5. Print ASCII image to Console?: ";
    if(printToConsole == false) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    cout << "6. Char Map: ";
    for(unsigned i = 0; i < charMap.size(); i++) {
        cout << charMap.at(i);
    }
    cout << endl << endl;
    cout << "Enter the number corresponding to the setting you would like to change:" << endl;
    cin >> choice;
    cout << endl;
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
        cout << "Invalid input. Enter a number 1-6 corresponding to the setting you would like to change." << endl;
        cin >> choice;
        cout << endl;
    }
    if(choice == "1") {
        this->changeSampleSize();
    }
    else if(choice == "2") {
        this->changeInputPath();
    }
    else if(choice == "3") {
        this->changeOutputPath();
    }
    else if(choice == "4") {
        this->changeChunkSize();
    }
    else if(choice == "5") {
        this->changePrintToConsole();
    }
    else if(choice == "6") {
        this->changeCharMap();
    }
    cout << endl;
    this->displaySettings();
}


/*

for all change functions:
1. Prompts the user to the value you want
2. After input validates
if good, return true
3. Should loop until it returns true !!

*/
bool Settings::changeSampleSize(){
    float newSampleSize;
    bool flag = 0;
    cout << "Enter a new Sample Size: " << endl;
    cin >> newSampleSize;
    while (1) {
         if(cin.fail() || newSampleSize <= 0) {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             cout << "Invalid input - try again. " << endl;
             cout << "Enter a new Sample Size: ";
             cin >> newSampleSize;
         }
         else {
            break;
         }
    }
    this->sampleSize = newSampleSize;
    flag = 1;
    cout << "New Sample Size = " << newSampleSize << endl;
    return flag;
}
bool Settings::changeInputPath(){
    string newInputPath;
    bool flag = 0;
    cout << "Enter a new Input Path: " << endl;
    cin >> newInputPath;
    while (1) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input - try again. " << endl;
            cout << "Enter a new Input Path: ";
            cin >> newInputPath;
        }
        else {
            break;
        }
    }
    this->inputPath = newInputPath;

    flag = 1;
    cout << "New Input Path = " << newInputPath << endl;
    return flag;
}
bool Settings::changeOutputPath(){
    string newOutputPath;
    bool flag = 0;
    cout << "Enter a new Output Path: " << endl;
    cin >> newOutputPath;
    while (1) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input - try again. " <<  endl;
            cout << "Enter a new Output Path: ";
            cin >> newOutputPath;
        }
        else {
            break;
        }
    }
    this->outputPath = newOutputPath;
    flag = 1;
    cout << "New Output Path = " << newOutputPath << endl;
    return flag;
}
bool Settings::changeChunkSize(){
    unsigned newChunkSize;
    bool flag = 0;
    cout << "Enter a new Chunk Size: " << endl;
    cin >> newChunkSize;
    while (1) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input - try again. " << endl;
            cout << "Enter a new Chunk Size: ";
            cin >> newChunkSize;
        }
        else {
            break;
        }
    }
    this->chunkSize = newChunkSize;
    flag = 1;
    cout << "New Chunk Size = " << newChunkSize << endl;
    return flag;
}
bool Settings::changeCharMap(){
    string newCharMap;
    bool flag = 0;
    cout << "Enter a new Char Map: " << endl;
    cin >> newCharMap;
    while (1) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input - try again. " << endl;
            cout << "Enter a new Char Map: ";
            cin >> newCharMap;
        }
        else {
            break;
        }
    }
    vector<char> charList;
    for(unsigned i = 0; i < newCharMap.size(); i++) {
        charList.push_back(newCharMap.at(i));
    }
    this->charMap = charList;
    flag = 1;
    cout << "New Char Map consists of these characters: " << newCharMap << endl;
    return flag;
}

bool Settings::changePrintToConsole(){
    string newPrintToConsole;
    bool flag = 0;
    cout << "Would you like your ASCII image to be printed to the console (Y/N)?: " << endl;
    cin >> newPrintToConsole;
    while(newPrintToConsole != "Y" && newPrintToConsole != "N") {
        cout << "Invalid answer." << endl;
        cout << "Would you like your ASCII image to be printed to the console (Y/N)?: " << endl;
    }
    if(newPrintToConsole == "Y") {
        printToConsole = true;
    }
    else {
        printToConsole = false;
    }
    flag = 1;
    cout << endl << "Print Image to Console set to ";
    if(newPrintToConsole == "Y") {
        cout << "true." << endl;
    }
    else {
        cout << "false." << endl; 
    }
    return flag;
}

void Settings::setInputPath(string inputPath) {
    this->inputPath = inputPath;
}
void Settings::setOutputPath(string outputPath) {
    this->outputPath = outputPath;
}
bool Settings::getPrintToConsole() {
    return this->printToConsole;
}

