#include <iostream> 
#include <string> 

using namespace std; 

unsigned int RSHash(const std::string& str);
string add(string, string);


int main()
{
    string L1, L2, L3, L4;
    string hL1, hL2, hL3, hL4;
    string HASH10, HASH00;
    string HASH1, HASH0;
    string finalHash;
    L1 = "Then out spake brave Horatius, The Captain of the Gate:";
    L2 = "\"To every man upon this earth Death cometh soon or late.";
    L3 = "And how can man die better Than facing fearful odds, and";
    L4 = " For the ashes of his fathers, And the temples of his Gods.\"";
    hL1 = RSHash(L1);
    hL2 = RSHash(L2);
    hL3 = RSHash(L3);
    hL4 = RSHash(L4); //Level 1 is hashed 

    cout << "L1 0-0: " << hL1 << endl; // Printed Level 1 
    cout << "L2 0-1: " << hL2 << endl;
    cout << "L3 1-0: " << hL3 << endl; 
    cout << "L4 1-1: " << hL4 << endl;  

    HASH00 = add(hL1, hL2); // Combining level 1 left 
    HASH10 = add(hL3, hL4); // Combing level 1 right

    HASH0 = RSHash(HASH00); // Hashing combined level 1 left 
    HASH1 = RSHash(HASH10); // Hashing combined level 1 right

    cout << "Hash 0: " << HASH0 << endl;  // Printing level 2 left 
    cout << "Hash 1: " << HASH1 << endl;  // Printing level 2 right


    finalHash = add(HASH0, HASH1); // Combining level 2 

    cout << "Top Hash: " << RSHash(finalHash) << endl; // Printing and hashing level 2 which is now the top 
}

unsigned int RSHash(const std::string& str)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}

string add(string hL1, string hL2)
{
    string hash = hL1 + hL2;
    return hash; 
}