#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout<<"Enter any word in lowercase : ";
    cin>>word;
    int n=word.length();


    // Precompute elements frequency before call to record its frequency in array
    int hash[26] = {0}; // Assuming numbers in the array are 26 alphabets
    
    // Update hash array with frequency of elements
    for (int i = 0; i < n; i++) {
       
        hash[word[i]-'a'] += 1;
    }

    // Process queries 1
    bool processed[26] = {0}; // To keep track of processed characters

    for (int i = 0; i < n; i++) {
        if (!processed[word[i] - 'a']) {
            cout << "Repetitions of '" << word[i] << "' are " << hash[word[i] - 'a'] << endl;
            processed[word[i] - 'a'] = true; // Mark character as processed
        }
    }

    // Process queries 2
    char query;
    cout<<"Enter the character to search thru string :";
    cin>>query;
    cout<<"Repetitions of '"<< query <<"' in string is : "<<hash[query-'a'];


    return 0;
}
