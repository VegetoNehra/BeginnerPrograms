#include <iostream>
#include <vector>
using namespace std;

bool greedyLemon(vector<int> array) {
    int five = 0;
    int ten = 0;
    int n = array.size();
    for (int i = 0; i < n; i++) {
        if (array[i] == 5) {
            five++;
        } 
        else if (array[i] == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } 
        else if (array[i] == 20) { // Correct condition for handling 20 bill
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> array = {5, 10, 5, 5, 5 , 5}; // Example with two 20s
    cout << (greedyLemon(array) ? "Successful transactions" : "Failed transactions");
    return 0;
}
 