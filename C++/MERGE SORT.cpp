#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array,int low,int mid , int high){
    vector <int> temp;

    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if (array[left]<=array[right]){
            temp.push_back(array[left]);
            left++;
        }
        else{
            temp.push_back(array[right]);
            right++;
        }}
    while(left<=mid){
        temp.push_back(array[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(array[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        array[i]=temp[i-low];
    }
    
}

void MS(vector<int> &array,int low , int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    MS(array,low,mid);
    MS(array,mid+1,high);
    merge(array,low,mid,high);
}   

void MergeSort(vector<int> &array , int n){
    MS(array,0,n-1);
}

int main(){
    vector<int> array={8,9,5,9,2,5};
    int size=array.size();
    cout<<"Original Array is : ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    MergeSort(array,size);
    cout<<"Sorted Array is : ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}