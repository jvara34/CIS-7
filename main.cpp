/*
 *Author: Julian Vara
 *Purpose: MasterMind Game 
 *Date: 4/30/24
 */

#include <iostream>
#include <string>
#include <iomanip> //Format Library 

using namespace std; 

void greetUser(int &, bool &);
void fillArr(char [], int);
void display(char [], int, int &);

int main()
{
    int len = 0; 
    bool dup;
    int tries = 10; 

    greetUser(len, dup);

    char arr[len]; // Need to take the length of the array and fill the array with x's for visuall effects 
    fillArr(arr, len);
    display(arr, len, tries); 
}

void greetUser(int &len, bool &dup)
{
    string input; 
    cout << "Welcome, This is Mastermind " << endl; 
    cout << "What code length do you want 4, 6, 8? " << endl; 
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
        arr[i] = 'x';
    }
}

void display(char arr[], int len, int &tries)
{
    cout << endl;
    cout << endl;
    for(int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
    cout << "    ";
    cout << "You have " << tries << " left" << endl;
    cout << endl;
}