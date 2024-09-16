#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &array, int low, int high) {
    int pivot = array[low];  // Pivot is the first element
    int i = low;
    int j = high;

    while (i < j) {
        // Move i to the right as long as elements are less than or equal to the pivot
        while (i <= high && array[i] <= pivot) {
            i++;
        }
        // Move j to the left as long as elements are greater than the pivot
        while (array[j] > pivot) {
            j--;
        }
        // Swap elements if i is less than j
        if (i < j) {
            swap(array[i], array[j]);
        }
    }
    // Swap pivot element with element at position j
    swap(array[low], array[j]);
    return j;
}

void QS(vector<int> &array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        QS(array, low, pivotIndex - 1);
        QS(array, pivotIndex + 1, high);
    }
}

void QuickSort(vector<int> &array) {
    QS(array, 0, array.size() - 1);
}

int greedycookie(vector<int>greed ,vector<int> cookie){
    QuickSort(greed);
    QuickSort(cookie);

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