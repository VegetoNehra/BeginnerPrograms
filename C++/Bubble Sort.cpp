#include<iostream>
using namespace std;

void bubblesort(int array[],int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}
int main(){
    int List[6]={8,9,5,9,2,5};
    int size=6;
    cout<<"Original Array is : ";
    for(int i=0;i<size;i++){
        cout<<List[i]<<" ";
    }
    cout<<endl;
    bubblesort(List,size);
    cout<<"Sorted Array is : ";
    for(int i=0;i<size;i++){
        cout<<List[i]<<" ";
    }
    cout<<endl;
    return 0;

}
