#include <iostream>
using namespace std;

int frogjump(int width) {
    if (width <= 0) {
        return 0;
    }
    if (width == 1) {
        return 1;
    }
    if (width == 2) {
        return 2;
    }
    return frogjump(width - 1) + frogjump(width - 2);
}

int main() {
    int width;
    cout<<"Enter width of river:"<<endl;
    cin>>width;
    cout << "The number of ways the frog can get to the end is: " << frogjump(width) << endl;
    return 0;
}
/*There's a frog looking over a river that's x feet wide, and there are x-1 stones placed in the river one foot apart.
 (From the beginning to the first stone is one foot, from the last stone to the end is one foot, etc.) 
 This frog is able to jump either 1 foot or 2 feet.
(After the first jump the frog could either be on the first or the second stone and again jump 1 or 2 feet from where he was initially.)
 The question is, how many ways are there for the frog to get to the end?
using  recursion in c++*/