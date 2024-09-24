#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

// Function to determine if you can reach the last index
bool canJump(vector<int>& nums) {
    int maxIndex = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxIndex) {
            return false;
        }
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}

// Recursive function to calculate the minimum number of jumps to reach the end
int minJumps(vector<int>& nums, int start) {
    int n = nums.size();

    // If we have reached or passed the last index, no more jumps are needed
    if (start >= n - 1) {
        return 0;
    }

    // If the current element is 0, we can't jump from here
    if (nums[start] == 0) {
        return INT_MAX; 
    }

    int minJumpsRequired = INT_MAX;/*"I haven't found any valid jump path yet, so I'm setting this 
                         to an impossibly large value, and I'll update it when I find a valid path."*/

    // Explore all jumps possible from the current position
    for (int i = 1; i <= nums[start]; i++) {
        int jumps = minJumps(nums, start + i);
        
        // If the jump result is not INT_MAX, update the minimum jumps
        if (jumps != INT_MAX) {
            minJumpsRequired = min(minJumpsRequired, jumps + 1);
        }
    }

    return minJumpsRequired;
}

int main() {
    vector<int> nums = {2,1,3,0, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    bool ans = canJump(nums);

    if (ans) {
        cout << "It is possible to reach the last index." << endl;

        // Calculate the minimum number of jumps
        int minJumpsToReachEnd = minJumps(nums, 0);
        if (minJumpsToReachEnd != INT_MAX) {
            cout << "Minimum number of jumps to reach the last index: " << minJumpsToReachEnd << endl;
        }
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}
