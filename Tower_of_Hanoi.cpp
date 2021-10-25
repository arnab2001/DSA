#include<iostream>
using namespace std;
void towerofhanoi(int n,char src,char dest,char helper){
    if(n==0){
        return;
    }
    towerofhanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofhanoi(n-1,helper,dest,src);
}
int main(){
    int n;
    char src,dest,helper;
    cout<<"Enter the number of stands - ";
    cin>>n;
    cout<<"Enter the source stand - ";
    cin>>src;
    cout<<"Enter the destination stand - ";
    cin>>dest;
    cout<<"Enter the helper stand - ";
    cin>>helper;
    towerofhanoi(n,src,dest,helper);
    return 0;
}
