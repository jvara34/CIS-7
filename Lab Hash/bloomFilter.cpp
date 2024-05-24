#include <iostream> 
#include <fstream>
#include <string>
#include "GeneralHashFunctions.h"
#include "GeneralHashFunctions.cpp"

using namespace std; 

string hashPicker(int &, string);

int main()
{
    string input;
    string hashOutput;
    string oneline;
    int counter = 0;

    cout << "Enter a string: ";
    cin >> input; 
    cout << "RSHash: " << RSHash(input) << endl;
    cout << "JSHash: " << JSHash(input) << endl;
    cout << "*********************************\n";

    string fileName = "random.txt";
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 1;
    }

    while(getline(inFile, oneline))
    {
        cout << "Random String:" << oneline << endl;
        hashOutput = hashPicker(counter, oneline);
        cout << hashOutput << endl;
    }
    inFile.close();

    string Name = "random.txt";
    ifstream File(Name);

    if (!File.is_open()) {
        std::cerr << "Error opening file: " << Name << std::endl;
        return 1;
    }

    int currentLine = 0;
    int lineNumber = 2;
    cout << "**********************************\n";
    cout << "Confirmed Positions 2\n";
    while(getline(File, oneline))
    {
        if (currentLine == lineNumber)
        {
            hashOutput = ELFHash(oneline);
            cout << "Position 2: " << hashOutput << endl;
        }
        currentLine += 1;
    }
    
    File.close();
    
}


string hashPicker(int &counter, string oneline)
{
    string input; 
    if (counter == 0)
    {
        input = PJWHash(oneline);
        return input;
    } else if (counter == 1)
    {
        input = ELFHash(oneline);
        return input;
    } else if (counter == 2)
    {
        input = BKDRHash(oneline);
        return input;
    } else if (counter == 3)
    {
        input = SDBMHash(oneline);
        return input;
    } else if (counter == 4)
    {
        input = DJBHash(oneline);
        return input;
    }
     else if (counter == 5)
    {
        input = DEKHash(oneline);
        return input;
    } else if (counter == 6)
    {
        input = BPHash(oneline);
        return input;
    } else if (counter == 7)
    {
        input = FNVHash(oneline);
        return input;
    } else if (counter == 8)
    {
        input = APHash(oneline);
        return input;
    } 
    return input; 
    counter ++;
    
}