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
string AI();
void code_break(string string, int, int);


int main()
{
    const int len = 4; 
    bool dup;
    int tries = 10;
    int amCor = 0;      // amCor = right # wrong place
    int coSpot = 0;     // coSpot = correct spot  
    string guess, code; 
    int choice = 0; 

    srand(time(NULL));              // Generates Random Number 

   
    code = generatedArr(len);             // Generates a random Array that will be compared to the input array to win  
    
    cout << "Hello User this program will guess a code by going from 0000-9999 " << endl; 
    cout << "1) Break the code " << endl; 
    cout << "2) Loop to 9999 " << endl;
    cin >> choice; 
    if (choice == 1)
    {
        cout << "Code Guess #right #right in wrong spot Sum" << endl; 
        do{
            guess=AI();
            compareArr(code, guess, len, amCor, coSpot);
            cout << code << " " << guess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << endl;
        }while(compareArr(code, guess, len, amCor, coSpot));
        cout << "The code was " << code; 
    }
    else if (choice == 2)
    {
        cout << "Code Guess #right #right in wrong spot Sum" << endl; 
        for (int i = 0; i < 10000; i++)
        {
            guess = AI(); 
            compareArr(code, guess, len, amCor, coSpot);
            cout << code << " " << guess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << endl;
        
        }
    }

     
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


string AI()
{
    static int guess=-1;
    guess++; 
    string sGuess = "0000";
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess%1000-guess%100)/100;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    //cout<<n1000<<n100<<n10<<n1<<endl;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
    return sGuess;
}

