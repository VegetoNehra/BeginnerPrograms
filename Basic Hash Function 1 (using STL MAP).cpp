#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; // Number of elements in the array
    cout<<"No of elements :"<<endl;
    cin >> n;
    int array[n];
    cout<<"Enter "<<n<<" elements :";
    // Reading the array elements
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    //Precompute using map
    map<int,int>mpp;
    for(int i=0 ;i<n;i++){
        mpp[array[i]]++;
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
        int num;
        cin>>num;
        //fetch
        cout<<"Repetition are :"<<mpp[num]<<endl;

    }

    return 0;
}
