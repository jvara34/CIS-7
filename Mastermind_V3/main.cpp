
/*
 *Author: Julian Vara
 *Purpose: Creating an AI for the Mastermind game to guess the code under 16 guesses 
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
string AI(int, int, string, string &, string &, int &, int &, int &);




int main()
{
    const int len = 4; 
    bool dup;
    int counter = 0;
    int tries = 10;
    int amCor = 0;      // amCor = right # wrong place
    int coSpot = 0;     // coSpot = correct spot  
    string guess, code, userCode; 
    int choice = 0; 
    int counterGuess = 0; 
    string AIguess = "    ";
    string coDigit; 
    int counter1 = 0;
    string coPosition = "xxxx";


    srand(static_cast<unsigned int>(time(0)));              // Generates Random Number 

   
    code = generatedArr(len);             // Generates a random Array that will be compared to the input array to win  
    
    cout << "Hello User this program will guess the code in 9 guesses or less " << endl;
    do
    {
        guess = AI(coSpot, amCor, AIguess, coDigit, coPosition, counterGuess, counter, counter1);
        
        compareArr(code, guess, len, amCor, coSpot);
        cout << code << " " << guess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << "                coDigit: " << coDigit << endl;
        
        
    } while (compareArr(code, guess, len, amCor, coSpot));

}


string generatedArr(int len)
{   
    string code = "0000";   
    for(int i = 0; i < code.length(); i++)
    {
        code[i] = rand() % 10 + '0';
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

string AI(int coSpot, int amCor, string AIguess, string &coDigit, string &coPosition, int &counterGuess, int &counter, int &counter1) // The main purpose of this function is to create a guess created by the AI 
{
    int j = 0;
    
    if (counter < 4) // Version 1 
    {
        AIguess[0] = counterGuess + '0'; 
        AIguess[1] = counterGuess + '0'; 
        AIguess[2] = counterGuess + '0'; 
        AIguess[3] = counterGuess + '0'; 

        if (coSpot > 0)
        {
            counterGuess --; // Previous Guess 
            
            for (int i = 0; i < coSpot; i++)
            {
                coDigit += counterGuess + '0';
            } 
            counterGuess ++; // Current Guess 
            counter += coSpot; // Once counter equals 4 then this variable will stay at 4 to skip all of this code 
        }
        counterGuess++; // Next Guess 

        return AIguess; 
        
    }


    /*
    the correct amount of digits is correct Now I need to place the correct digits in the right position 
    
        - In order to place digits into right position I need a new string that will have all x's and then I position the first element from coDigit until I get a correct
        spot 
        */

   

    if (counter == 4)    
    {
        
        coPosition[0] = coDigit[counter1];
        counter1++;
        if (coSpot == 1)
        {
            counter1 -= 2; // Previous 2 guesses
            coPosition[0] = coDigit[counter1];
            counter1 = 0;
            counter++; // this makes this if statement unusable for the next function call to focus on the next element of guesses 
        }
        //NEED TO UPDATE THE AIguess
        for (int i = 0; i < 4; i++)
        {
            AIguess[i] = coPosition[i];
        } 
        
    }  
    else if (counter == 5)
    {
        coPosition[1] = coDigit[counter1];
        counter1++; 
        if (coSpot == 2)
        {
            counter1 -= 2;
            coPosition[1] = coDigit[counter1];
            counter1 = 0;
            counter++; // this makes this if statement unusable for the next function call to focus on the next element of guesses 
           
        }
        for (int i = 0; i < 4; i++)
        {
            AIguess[i] = coPosition[i];
        }
    }
    else if (counter == 6)
    {
        coPosition[2] = coDigit[counter1];
        counter1++; 
        if (coSpot == 3)
        {
            counter1 -= 2;
            coPosition[2] = coDigit[counter1];
            counter1 = 0;
            counter++; // this makes this if statement unusable for the next function call to focus on the next element of guesses 
           
        }
        for (int i = 0; i < 4; i++)
        {
            AIguess[i] = coPosition[i];
        }
    }
    else if (counter == 7)
    {
        coPosition[3] = coDigit[counter1];
        counter1++; 
        if (coSpot == 4)
        {
            counter1 -= 2;
            coPosition[3] = coDigit[counter1];
            counter1 = 0;
            counter++; // this makes this if statement unusable for the next function call to focus on the next element of guesses 
            
        }
        for (int i = 0; i < 4; i++)
        {
            AIguess[i] = coPosition[i];
        }
    }
    
     

    return AIguess;  
}
