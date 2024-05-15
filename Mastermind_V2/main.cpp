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

void generatedArr(char [], int);                            // This functions creates the generated Arr that will have the code the user has to guess 
bool compareArr(char [], char [], int, int &, int &);
void AI(char []);



int main()
{
    const int len = 4; 
    bool dup;
    int tries = 10;
    int amCor = 0;      // amCor = right # wrong place
    int coSpot = 0;     // coSpot = correct spot  
    char sGuess [len]; 
    char code [len]; 
   string guess, CODE; 

    srand(time(NULL));              // Generates Random Number 

    generatedArr(code, len);
          // Generates a random Array that will be compared to the input array to win  
  
        cout << "Code Guess #right #right in wrong spot Sum" << endl; 
        for (int i = 0; i < 10000; i++)
        {
            AI(sGuess); 
            
            compareArr(code, sGuess, len, amCor, coSpot);
            cout << code << " " << sGuess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << endl;
        
        }

     
}




void generatedArr(char code[], int len)
{   
   

    for (int i = 0; i < len; i++)       // for loop generates a random number 
    {
        code[i] = rand() % len + '0';
    }
     
}


bool compareArr(char code[], char sGuess[], int len, int &amCor, int &coSpot)
{
     
    amCor = 0;      // These two integer functions need to be reset everytime the function is called 
    coSpot = 0; 
    int compare = 0; 
    string check = "    ";

    for(int i = 0; i < len; i++)
    {
        if(sGuess[i] == code[i])
        { 
            check[i] = 'x';
            sGuess[i] = 'x';
            coSpot++; 
        }
    }
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if((i != j) && (code[j] == sGuess[i]) && (check[j] == ' '))
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


void AI(char sGuess[])
{
    static int guess=-1;
    guess++; 
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess%1000-guess%100)/100;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    //cout<<n1000<<n100<<n10<<n1<<endl;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
}

