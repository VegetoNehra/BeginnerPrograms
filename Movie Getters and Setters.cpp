#include <iostream>
using namespace std;

class Movie{
    private:
    string rating;
    public:
    string title;
    string director;
    Movie ( string atitle, string adirector ,string arating){
        title=atitle;
        director=adirector;
        setrating(arating);
    }
    void setrating(string arating){
      if (arating=="GF" || arating=="PG" || arating=="PG-13" || arating=="R" || arating=="NR"){
        rating=arating;
      }
      else{
        rating="NR";
      }
    }
    string getrating(){
      return rating;
      }
};
int main(){

  Movie avengers ("The Avengers","Josh Whedon" ,"PG-13");
  Movie LOTR ("Lord of the rings","RR TOLKEIN","IDK");
//rating other than setrating is overwritten as NR

  cout<< avengers.getrating()<<endl;
  cout<< LOTR.getrating()<<endl;
  // checks arating under the requirements and then outputs 
  
  
  return 0;
    
}
