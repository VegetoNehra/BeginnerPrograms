#include <iostream>
using namespace std;

void selectionsort(int array[],int size){
    for(int i=0 ;i<size-1;i++){
        int min_index=i;
        for (int j=i+1;j<size;j++){
            if (array[j]<array[min_index]){
                min_index=j;
            }
        }
        //int temp=array[min_index];
        //array[min_index]=array[i];
        //array[i]=temp;
        swap(array[min_index],array[i]);
    }
}

int main(){
    int List[6]={8,5,6,4,2,9};
    int size=6;
    cout<<"Original Array is : ";
    for (int i=0 ;i<size;i++){
        cout<<List[i]<<" ";
    }
    cout<<endl;
    selectionsort(List,size);

    cout<<"Sorted Array is : ";
    for (int i=0 ;i<size;i++){
        cout<<List[i]<<" ";
    } 
}