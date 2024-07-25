#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void reversestring(char* C , int n){ //chare* C is used as a pointer to Array C as it is  a C-style string;
    stack<char>S;                    //we will have to use string&C if we used C++ style string which directly references the string.
    for(int i=0 ; i<n ;i++){
        S.push(C[i]);
    }
    for(int i =0 ; i<n ; i++){
        C[i]=S.top();
        S.pop();
    }
};

int main(){
    char C[100];
    cout<<"Enter a String : "<<endl;
    cin>>C;
    reversestring(C,strlen(C));
    cout<<"Reversed String is : "<<C<<endl;
    return 0;
}