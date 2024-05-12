

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI();
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    
    cout << "Code Guess #right #right in wrong spot Sum" << endl; 

    //Loop until solved and count to find solution
    

    for (int i = 0 ; i < 9999; i++)
    {
       guess=AI();
       eval(code,guess,rr,rw);
       cout << code << " " << guess << "      " << (int)rr << "          " << (int)rw << "             " << rr+rw << endl;

    }
    
    //Output the solution
    

    //Exit the program
    return 0;
}

string AI(){
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

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){
    string code="0120";
   /* for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    */
    return code; 
}