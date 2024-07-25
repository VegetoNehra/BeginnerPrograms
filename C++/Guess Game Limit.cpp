#include <iostream>
using namespace std;
int main(){
    int secretnum = 69 ;
    int guess;
    int guesscount=0;
    int guesslimit=3;
    bool outofguesses= false;
    while (secretnum!=guess && !outofguesses){
        if(guesscount<=guesslimit){
            cout<<"Enter your guess";
            cin>>guess;
            guesscount++;
        }
        else{
            outofguesses=true;
        }    
        }
    if(outofguesses){
        cout<<"you lose";
    }
    else{
        cout<<"winner";
    }
    return 0;

    }
    
    