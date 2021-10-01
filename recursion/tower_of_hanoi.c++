
// tower of hanoi
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}



  void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    
    
    if(n==0){
     cout<<source<<" "<<destination<<endl;    
      return;
    }
    
    
   
   
    towerOfHanoi( n-1,source,destination,auxiliary);
    cout<<source<<" "<<destination<<endl;
    towerOfHanoi( n-1,auxiliary,source,destination);

    
 

}
