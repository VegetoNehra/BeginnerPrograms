#include <iostream>
using namespace std;

void insertionsort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        
        array[j + 1] = key;
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
