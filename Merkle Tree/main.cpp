#include <iostream> 

using namespace std; 

unsigned int RSHash(const std::string& str);
string hash0(string, string);
string hash1(string, string); 
string topHash(string, string);

int main()
{
    string L1, L2, L3, L4;
    string hL1, hL2, hL3, hL4;
    string HASH1, HASH0;
    string topHASH1, topHASH0;
    string finalHash;
    L1 = "Then out spake brave Horatius, The Captain of the Gate:";
    L2 = "\"To every man upon this earth Death cometh soon or late.";
    L3 = "And how can man die better Than facing fearful odds, and";
    L4 = " For the ashes of his fathers, And the temples of his Gods.\"";
    hL1 = RSHash(L1);
    hL2 = RSHash(L2);
    hL3 = RSHash(L3);
    hL4 = RSHash(L4);

    cout << "L1 0-0: " << hL1 << endl; 
    cout << "L2 0-1: " << hL2 << endl;
    cout << "L3 1-0: " << hL3 << endl; 
    cout << "L4 1-1: " << hL4 << endl;  

    HASH0 = hash0(hL1, hL2);
    HASH1 = hash1(hL3, hL4);

    cout << "Hash 0: " << HASH0 << endl; 
    cout << "Hash 1: " << HASH1 << endl;  

    topHASH0 = RSHash(HASH0);
    topHASH1 = RSHash(HASH1);

    finalHash = topHash(topHASH0, topHASH1);

    cout << "Top Hash: " << finalHash << endl;



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

string hash0(string hL1, string hL2)
{
    string Hash0 = hL1 + hL2;
    return Hash0; 
}


string hash1(string hL3, string hL4)
{
    string Hash1 = hL3 + hL4;
    return Hash1; 
}

string topHash(string topHASH0, string topHASH1)
{   
    string hash = topHASH0 + topHASH1;
    return hash; 
}