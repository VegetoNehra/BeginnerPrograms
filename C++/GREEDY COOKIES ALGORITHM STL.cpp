#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greedycookie(vector<int>greed ,vector<int> cookie){
    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());

    int l=0;
    int r=0;

    int n=greed.size();
    int m=cookie.size();

    while(l<m && r<n ){
        if (greed[r]<=cookie[l]){
            r++;
        }
        l++;
    }
    return r;
   
    
}

int main(){
    vector <int>greed={1,5,3,3,4};
    vector <int>cookie={4,2,1,2,1,3};
    int x=greedycookie(greed,cookie);
    cout<<"MAXIMUM CHILDREN WHO CAN GET DESIRED COOKIE ARE : "<< x<<endl;\
    return 0;

}