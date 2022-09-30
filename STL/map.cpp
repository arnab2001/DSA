#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
  	map<char, int> M; //based on balanced binary tree takes O(logn) access time
	unordered_map<char, int> U; //uses hashing and accessing elements takes O(1)
	//U.add(key,value);
  	//U.erase(key,value);
  	
  	//map each letter to their occurance
  	string s = "Sumant Tirkey";
  	for (char c : s) {
  		M[c]++;
	  }
	for (char c : s){
		U[c]++;
	}

    for(auto it:U){
        cout<<it.first<<" "<<it.second<<endl;
    }
  
  return 0;
}
