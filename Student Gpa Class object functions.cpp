#include <iostream>
using namespace std;

class STUDENT {
    public:
      string name;
      string major;
      double gpa;
      STUDENT(string aname ,string amajor ,double agpa){
        major=amajor;
        name=aname;
        gpa=agpa;
      }
      bool honors(){
        if (gpa>=3.5){
          return true;
        }
        return false; 
      }    
};
int main(){
    STUDENT student1("JIM","PCM",4.1);
    STUDENT student2("SAM","ECO",3.0);
    cout << student1.honors()<<"\n";
    cout << student2.honors();


    return 0;
    
}
