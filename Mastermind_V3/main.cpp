
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
string AI(int, int, string, int, int &);




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

    srand(time(NULL));              // Generates Random Number 

   
    code = generatedArr(len);             // Generates a random Array that will be compared to the input array to win  
    
    cout << "Hello User this program will guess the code in 9 guesses or less " << endl;
    do
    {
        guess = AI(coSpot, amCor, AIguess, counterGuess, counter);
        
        compareArr(code, guess, len, amCor, coSpot);
        cout << code << " " << guess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << endl;
        
        
    } while (compareArr(code, guess, len, amCor, coSpot));

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

string AI(int coSpot, int amCor, string AIguess, int counterGuess, int &counter) // The main purpose of this function is to create a guess created by the AI 
{
    string coDigit = "    "; // Settings coDigits to 4 length to test later to make sure that it holds the correct amount of numbers 
    int j = 0;
    if (counter < 4)
    {

        AIguess[0] = counterGuess + '0'; 
        AIguess[1] = counterGuess + '0'; 
        AIguess[2] = counterGuess + '0'; 
        AIguess[3] = counterGuess + '0'; 

        if (coSpot > 0)
        {
            while (counter <= coSpot) // NEED TO FIGURE OUT HOW TO GET THE ADD THE coDigits without changing the elements aready inside coDigit
            {
                coDigit[counter] += counterGuess;
            }   
            counter += coSpot; 
        }
        counterGuess++; 
        
    }
    if (counter == 4) // Now coDigit should be filled up with the all the digits in the code 
    {   
        
        // need to check for the first digit if it is in the correct spot 
        AIguess[0] = coDigit[j] + '0';
        j++; 
        if (j < 3)
        {
            AIguess[0] = coDigit[3];
        }
        
    }

    return AIguess; 
}
