
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  pair<int,char>p{2,'a'};
   cout<<p.first<<" "<<p.second<<endl;

//   vector<vector<int>>v(2);   
//     for(int i=0;i<2;i++){
//         int j;
//         cin>>j;
//         v[i].resize(j);
//         for(int k=0;k<j;k++){
//             cin>>v[i][k];
//         }
//     }

// cout<<endl;

//     for(vector<int> i:v){
//         for(int j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }


  vector<pair<int,string>>v(3,{1,"abc"});
   for(pair<int,string> i:v){
       cout<<i.first<<" "<<i.second<<endl;
   }
}
