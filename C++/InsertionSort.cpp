#include <iostream>
using namespace std;

void insertionsort(int array[], int n) {
    for (int i = 1; i < n; i++) {   
// Start from the second element
        int key = array[i];  
 /* The element to be inserted into the sorted portion*/
        int j = i - 1;  /* Compare it with the sorted portion, starting from the rightmost element */
        
        /* Shift elements of the sorted portion that are greater than 'key' to the right*/
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];  // Shift element to the right
            j--;  // Move to the next element
        }
        
        array[j + 1] = key; 
 // Insert 'key' into its correct position
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
