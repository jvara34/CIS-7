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



int main()
{   
    
    const int len = 4; 
    int counterRight[len];
    int counterWrong[len];
    int right, rightWrong; 
    bool dup;
    string code, guess; 
    int tries = 10;
    int amCor = 0;      // amCor = right # wrong place
    int coSpot = 0;     // coSpot = correct spot   

    srand(time(NULL));              // Generates Random Number 

    code = generatedArr(len);
          // Generates a random Array that will be compared to the input array to win  
  
        cout << "Code Guess #right #right in wrong spot Sum" << endl; 
        for (int i = 0; i < 10000; i++)
        {
            guess = AI(); 
            
            compareArr(code, guess, len, amCor, coSpot);
            cout << code << " " << guess << "      " << coSpot << "          " << amCor << "             " << amCor + coSpot << endl;
                if (coSpot == 1)
                {
                    counterRight[0]++; 
                } else if (coSpot == 2)
                {
                    counterRight[1]++;
                } else if (coSpot == 3)
                {
                    counterRight[2]++;
                } else if (coSpot == 4)
                {
                    counterRight[3]++;
                }

                if (amCor == 1)
                {
                    counterWrong[0]++;
                } else if (amCor == 2)
                {
                    counterWrong[1]++;
                } else if (amCor == 3)
                {
                    counterWrong[2]++;
                } else if (amCor == 4)
                {
                    counterWrong[3]++;
                }
                
                
        }

        for (int i = 0; i < len; i++)
        {
            cout << "Number Right in Position: " << counterRight[i] << endl;
        }

        for (int i = 0; i < len; i++)
        {
            cout << "Number Right Wrong in Position: " << counterWrong[i] << endl;
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


bool compareArr(string code, string sGuess, int len, int &amCor, int &coSpot)
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


string AI()
{
    static int guess=-1;
    guess++;
    string sGuess="0000";
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

