#include <iostream> 

using namespace std; 

int main()
{
    int counterGuess = 0;

    while(counterGuess < 10)
    {
        string guess = "0000";
        guess[0] = counterGuess + '0'; 
        guess[1] = counterGuess + '0';  
        guess[2] = counterGuess + '0';  
        guess[3] = counterGuess + '0'; 

        counterGuess++;

        cout << guess << endl; 
    } 
     

 
}