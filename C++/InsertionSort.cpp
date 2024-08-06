#include <iostream>
using namespace std;

void insertionsort(int array[],int n){
    for (int i=0;i<n;i++){
        for(int j=0 ; j<=i;j++){
            if (array[i]<array[j]){
                swap(array[i],array[j]);
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
    insertionsort(List,size);
    cout<<"Sorted Array is : ";
    for(int i=0;i<size;i++){
        cout<<List[i]<<" ";
    }
    cout<<endl;
    return 0;

}
