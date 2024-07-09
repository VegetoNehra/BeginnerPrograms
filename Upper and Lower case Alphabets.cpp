#include <iostream>
#include <cctype> // for toupper and tolower functions
using namespace std;

int main() {
    char uppercase = 'A';
    char lowercase = 'a';

    // Convert lowercase to uppercase
    char convertedToUpper = toupper(lowercase);

    // Convert uppercase to lowercase
    char convertedToLower = tolower(uppercase);

    // Now both convertedToUpper and uppercase should have the same value
    cout << "Original lowercase: " << lowercase << endl;
    cout << "Converted to uppercase: " << convertedToUpper << endl;

    // Now both convertedToLower and lowercase should have the same value
    cout << "Original uppercase: " << uppercase << endl;
    cout << "Converted to lowercase: " << convertedToLower << endl;

    return 0;
}
