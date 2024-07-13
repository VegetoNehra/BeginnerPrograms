#include <iostream>
#include <stack>
#include <string>
using namespace std;

void checkparantheses(string exp){

    stack<char> S;
    for (int i=0 ; i<exp.size() ; i++){
        if(exp[i]=='['|| exp[i]=='{' || exp[i]=='('){
            S.push(exp[i]);
        }
        else if(exp[i]==']' ||exp[i]== '}' ||exp[i]== ')'){
            if (S.empty()){
                cout<<"Expression Unbalanced"<<endl;
                return;
                }
            char top=S.top();
            if((exp[i]==']' && top=='[') || (exp[i]==')' && top=='(') ||(exp[i]=='}' && top=='{')){
                S.pop();
            }
        }
    }
    if( S.empty()){
        cout<<"Your Expression is balanced"<<endl;
    }
    else{
        cout<<"Your expression is unbalanced"<<endl;
    }

};

int main(){
    string exp;
    cout << "Enter an expression" <<endl;
    getline(cin,exp);// getline is used to get the whole sentence entered , cin will just get the first word 
    checkparantheses(exp);
    return 0;
}