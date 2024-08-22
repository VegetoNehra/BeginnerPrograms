#include <iostream>
#include <vector>

void findAllPairs(std::vector<int> arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << std::endl;
            }
        }
    }
}

int main() {
    std::vector<int> arr = {2, 7, 11, 15, 3, 6, 1, 5};
    int target = 9;
    findAllPairs(arr, target);
    return 0;
}
