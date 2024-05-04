/*
 *Author: Julian Vara
 *Purpose: MasterMind Game 
 *Date: 4/30/24
 */
 
#include <iostream>
#include <string>
#include <iomanip> //Format Library 
#include <cstdlib>
#include <ctime> // This is for the random number generator 

using namespace std; 

void greetUser(int &, bool &);
void fillArr(char [], int);         // This function takes in the user input every time the user makes a guess 
void display(char [], int, int &, int, int);
void generatedArr(char [], int, bool);    // This functions creates the generated Arr that will have the code the user has to guess 
bool compareArr(char [], char [], int, int &, int &);
void win(); 

int main()
{
    int len = 0; 
    bool dup;
    int tries = 10;
    int amCor = 0;      // These two integer functions need to be reset everytime the function is called 
    int coSpot = 0; 

    srand(time(NULL));              // Generates Random Number 

    greetUser(len, dup);

    char arr[len];                              // This array is the user array 
    char genArr[len];                           // This array is the one that has the code 
    generatedArr(genArr, len, dup);             // Generates a random Array that will be compared to the input array to win   
    for(int i = 0; i < len; i++)
    {
        cout << genArr[i];
    }
    for(int i = 0; i < tries; i++)
    {
        fillArr(arr, len);                      // Fills up the array to have with the length that the user chose   
        if(compareArr(genArr, arr, len, amCor, coSpot))
        {
            win(); 
            break;
        }                             
        display(arr, len, tries, amCor, coSpot);                   // This will display an array of x's and the amount of tries that is left for the user to play
        
    }            
     
}

void greetUser(int &len, bool &dup)
{
    string input; 
    cout << "Welcome, This is Mastermind " << endl; 
    cout << "What code length do you want 4, 6, 8? " << endl; // Need to error check the user input to make sure input is correct 
    cin >> len; 
    cout << "Do you want duplicate values? " << endl;
    cout << "Y or N " << endl;  
    cin >> input;
    if(input == "y" || input == "Y")
    {
        dup = true; 
    }
    else {
        dup = false; 
    }
}

void fillArr(char arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << "Please enter value: ";
        cin >> arr[i];
    }
}

void display(char arr[], int len, int &tries, int amCor, int coSpot)
{
    cout << endl;
    cout << endl;
    for(int i = 0; i < tries; i++)
    {
        for(int j = 0; j < len; j++)
        {
            cout << "x" << " "; 
        }
       cout << endl; 
    }
    cout << "Wrong Spot: " << amCor << endl; 
    cout << "Correct Spot: " << coSpot << endl; 
    tries --; 
}

void generatedArr(char genArr[],int len, bool dup)
{
    bool hasDup; 
    
    if(dup == true)
    {
        for (int i = 0; i < len; i++)       // This for loop for randnums is good if user chooses dupplicates 
        {
            genArr[i] = (rand() % 10) + '0';
        }
    } else if( dup == false)
    {
        for (int i = 0; i < len; i++)       
        {
            genArr[i] = (rand() % 10) + '0';
        }
        do // This do while loop will generate an array that does not have duplicates 
        {
            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j < len; j++)
                {
                    if(genArr[i] == genArr[j])
                    {
                        hasDup = true;
                    } else 
                    {
                        hasDup = false; 
                    }
                }
            } 
            
        }
        while (hasDup == false);
    }
   
}


bool compareArr(char genArr[], char arr[], int len, int &amCor, int &coSpot)
{
     
    amCor = 0;      // These two integer functions need to be reset everytime the function is called 
    coSpot = 0; 
    int compare = 0; 
    bool isSame = true;

    for(int i = 0; i < len; i++)
    {
        if(arr[i] != genArr[i])
        {
            isSame = false; 
        }
        else if(arr[i] == genArr[i])
        { 
            coSpot ++; 
        }

    }
    for(int i = 0; i < len; i++)
    {
        compare = genArr[i];
        for(int j = 0; j < len; j++)
        {
            if(compare == arr[i])
            {
                amCor ++; 
            }
        }
    }

    return isSame; 
}

void win()
{
    cout << "You WIN!!" << endl; 
}