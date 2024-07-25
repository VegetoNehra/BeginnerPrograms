#include <iostream>
using namespace std;

class Book {
    public:
       string title;
       string author;
       int pages;
       Book( string atitle , string aauthor ,int apages){
        title=atitle;
        author=aauthor;
        pages=apages;
       }
};
int main(){
    Book Book1("HARRY POTTER", "JK ROWLING", 560);
    Book Book2("LOTR","TOLKEIN",780);
    

    cout<<Book1.title<< endl;
    cout<<Book2.title<<endl;
    return 0;
}