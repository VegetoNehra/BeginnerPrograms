#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string data; // user entered string
    cout<<"Enter a String :"<<endl;
    cin >> data;
    

    //Precompute using map for arranged data
    //unordered map for data in user entered way  i.e. it is ot arranged
    unordered_map<char,int>mpp;
    for(int i=0 ;i<data.length();i++){
        mpp[data[i]]++;
    }

    //itirate the map
    for(auto num :mpp){
        cout<<num.first<<"->"<<num.second<<endl; //first is key and second is value
    }

    // Process queries
    int query;
    cout<<"Number of Queries: "<<endl;
    cin>>query;
    while(query--){
        char alphabet;
        cin>>alphabet;
        //fetch
        cout<<"Repetition are :"<<mpp[alphabet]<<endl;

    }

    return 0;
}
