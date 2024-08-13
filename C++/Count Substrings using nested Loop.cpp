#include <iostream>
#include <string>
#include <set>
using namespace std;

int countDistinctSubstrings(string s) {
    set<string> substrings;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j <= s.length(); j++) {
            substrings.insert(s.substr(i, j - i));
        }
    }

    return substrings.size()+1;
}

int main() {
    string s = "abab";
    int distinctCount = countDistinctSubstrings(s);

    cout << "Number of distinct substrings: " << distinctCount << endl;

    return 0;
}
