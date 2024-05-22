/*
 *Author: Julian Vara
 *Purpose: This program is show that the #right and #right in wrong spot work 
            also how a simple AI that guess just be incrementing by +1 until it 
            guesses the correct value and it will stop 
 *Date: 4/30/24
 */
 
#include <iostream>
#include <string>
#include <iomanip> //Format Library 
#include <cstdlib>
#include <ctime> // This is for the random number generator 

using namespace std; 

string generatedArr(int);                            // This functions creates the generated Arr that will have the code the user has to guess 
bool compareArr(string, string, int, int &, int &);
string AI(int, int);
void display(int, int, int [], int []);
void counter(int, int, int [], int []);
bool breakCode(string, string);


int main()
{
    const int len = 4; 
    bool dup;
    int tries = 10;
    int amCor = 0;      // amCor = right # wrong place
    int coSpot = 0;     // coSpot = correct spot  
    string guess, code, userCode; 
    int choice = 0; 
    int counterGuess = 0; 
    int rightArr[5] = {0, 0, 0, 0, 0};
    int wrongArr[5] = {0, 0, 0, 0, 0};
    bool codeBroken;

    srand(time(NULL));              // Generates Random Number 

   
    code = generatedArr(len);             // Generates a random Array that will be compared to the input array to win  
    
    cout << "Hello User this program will guess the code in 9 guesses or less " << endl;
    do
    {
        guess = AI(len, counterGuess);
        
        compareArr(code, guess, len, amCor, coSpot);
        bool codeBroken = breakCode(guess, code);

    } while (codeBroken == false);
    

}


string generatedArr(int len)
{   
    string code = "0000";
    for (int i = 0; i < len; i++)       // for loop generates a random number 
    {
        code[i] = rand() % len + '0';
    }
    return code; 
}

bool compareArr(string code, string guess, int len, int &amCor, int &coSpot)
{
     
    amCor = 0;      // These two integer functions need to be reset everytime the function is called 
    coSpot = 0; 
    int compare = 0; 
    string check = "    ";

    for(int i = 0; i < len; i++)
    {
        if(guess[i] == code[i])
        { 
            check[i] = 'x';
            guess[i] = 'x';
            coSpot++; 
        }
    }
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if((i != j) && (code[j] == guess[i]) && (check[j] == ' '))
            {
                check[j] = 'x';
                amCor ++; 
                break;
            }
        }
    }

    if (coSpot == 4)
    {
        return false; 
    }
    return true; 

   
}

string AI(int len, int counterGuess) // The main purpose of this function is to create a guess created by the AI 
{

    string guess = "0000";
    guess[0] = counterGuess; 
    guess[1] = counterGuess; 
    guess[2] = counterGuess; 
    guess[3] = counterGuess; 

    counterGuess++; 

    return guess; 
}

void counter(int coSpot, int amCor, int rightArr[], int wrongArr[])
{
    if (coSpot == 0)
    {
        rightArr[0]++;
    } else if (coSpot == 1)
    {
        rightArr[1]++;
    } else if (coSpot == 2)
    {
        rightArr[2]++;
    } else if (coSpot == 3)
    {
        rightArr[3]++; 
    } else if (coSpot == 4)
    {
        rightArr[4]++;
    }

    if (amCor == 0)
    {
        wrongArr[0]++;
    } else if (amCor == 1)
    {
        wrongArr[1]++;
    } else if (amCor == 2)
    {
        wrongArr[2]++;
    } else if (amCor == 3)
    {
        wrongArr[3]++; 
    } else if (amCor == 4)
    {
        wrongArr[4]++;
    }
        
}

void display(int coSpot, int amCor, int rightArr[], int wrongArr[])
{

    for (int i = 0; i < 5; i++)
    {
        cout << "The amount RIGHT in position " << i << ": " << rightArr[i] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "The amount RIGHT in WRONG in position " << i << ": " << wrongArr[i] << endl;
    }
}


bool breakCode(string AIguess, string code) //AIguess is from the AI function and code is from the generated code 
{
    /*  this function will get the AI guess and compare the values with the code 
        whenever the function detects the that the AIguess is in the right spot then it will add that element to another array called guessCode which will slowly have the correct code through each iteration 
    */ 
   string codeBreak;

   for (int i = 0; i < 4; i++)
   {
        if (AIguess[i] == code[i])
        {
            codeBreak += AIguess[i];
        } else if (codeBreak[i] == code[i])
        {
            return true;                //CodeBreak and code need to be exact in order to be true then be able to return true
        } else if (codeBreak[i] != code[i])
        {
            return false; 
        }
   }

    return false; 

}