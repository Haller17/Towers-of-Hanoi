#include <iostream>
#include<vector>
using namespace std;
int main() {
  vector <int>t[3];
  int rings;
  int from = 0, to, candidate = 1, move = 0;
  cout<<"Please enter the number of rings to move: ";
  cin>>rings;
  cout<<endl;
  //initialize the towers
  for(int i = rings + 1; i >= 1; i--){ 
    t[0].push_back(i);
  }  
  t[1].push_back(rings+1);
  t[2].push_back(rings+1);
 
 if ((rings%2)==1) { // if the number of rings is odd.
   to = 1;
 }
  else {
    to = 2;
  }
   
while (t[1].size() < rings + 1){ //while t[1] does not contain all the rings
  cout<<"move #"<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<" tower"<<endl;

  t[to].push_back(t[from].back()); // move ring from the "from" tower to the "to" tower
    
  t[from].pop_back(); //delete's the ring from the "from" tower
  
  if (rings%2==1){ //If theres an odd # of rings.
    
  if (t[(to+1)%3].back() < t[(to+2)%3].back()){
    from = (to+1) % 3; // Determine the "from" tower (the smallest available ring that has NOT just been moved).
  }
  else {
      from = ((to+2) % 3);
  }
    //get next "to" tower
    if (t[from].back() < t[(from+1)%3].back()) {
      to = (from+1) % 3;
    }

  else {
    to = (from+2) % 3;
  }
  //find next candidate
  candidate = t[from].back(); // if its on top of the current "from tower"
  
}
  if (rings%2 == 0) { //if theres even # of rings
    if (t[(to+1)%3].back() < t[(to+2)%3].back()) {
      from = (to+1) % 3;
    }

    else {
      from = (to+2) % 3;
    }
    //find next "to" tower
    if (t[from].back() < t[(from+2)%3].back()) {
      to = (from+2) % 3;
    }
    else {
      to = (from+1) % 3;
    }
    //find next canadidate 
    candidate = (t[from].back()); // if its ontop of the current "from tower"
      }
    }
  return 0;
 }
     

