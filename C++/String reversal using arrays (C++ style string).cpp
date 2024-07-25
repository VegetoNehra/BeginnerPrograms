#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reversestring(string &C) { // here we used string &C to reference the string and modify it directly.
    stack<char> S;
    int n = C.size();
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }
    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}

int main() {
    string C;
    cout << "Enter a String: " << endl;
    cin >> C;
    reversestring(C);
    cout << "Reversed String is: " << C << endl;
    return 0;
}
