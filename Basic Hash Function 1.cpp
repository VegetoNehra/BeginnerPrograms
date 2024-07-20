#include <iostream>
using namespace std;

int main() {
    int n; // Number of elements in the array
    cin >> n;
    int array[n];
    
    // Reading the array elements
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Precompute elements frequency before call to record its frequency in array
    int hash[13] = {0}; // Assuming numbers in the array are in the range [0, 12]
    
    // Update hash array with frequency of elements
    for (int i = 0; i < n; i++) {
        if (array[i] < 0 || array[i] >= 13) {
            cerr << "Error: Number out of range for hash array!" << endl;
            return 1;
        }
        hash[array[i]] += 1;
    }

    // Process queries
    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        if (number < 0 || number >= 13) {
            cout << "0" << endl; // If number is out of range, frequency is 0
        } else {
            // Fetch the frequency of the queried number
            cout << hash[number] << "repetitions"<< endl;
        }
    }

    return 0;
}
