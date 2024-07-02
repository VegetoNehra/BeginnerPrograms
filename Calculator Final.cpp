#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num1,num2;
    cout << "Emter a number-";
    cin>>num1;
    cout << "Enter another numberc-";
    cin>>num2;
    int Opt ;
    cout << "ENTER 1 TO ADD" <<endl;
    cout <<"ENTER 2 TO DIVIDE" <<endl ;
    cout << "ENTER 3 TO SUBTRACT" <<endl;
    cout<< "ENTER 4 TO MULTIPLY"<<endl ;
    cin >> Opt;
    if (Opt==1){
        cout<<num1+num2<<endl;
    }
    else if (Opt==2){
        cout<<num1/num2<<endl;
    }
    else if (Opt==3){
        cout<<num1-num1<<endl;
    }
    else {
        cout<<num1*num2<<endl;
    }      


}