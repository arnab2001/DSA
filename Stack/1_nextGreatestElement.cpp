// Nearest Greatest Element to right
// Return the Vector with the list of Elements 
// that are the next greatest/largest element to the right
// For Example : 
//     Arr[]: 1 3 2 4
//  result[]: 3 4 4 -1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackSolution{
    public:
    vector<int> NextGreatestRight(vector<int> arr){
        int n= arr.size(); //size of vector
        // We will use a stack to store the values of 
        // current maximum on top 
        stack <int> stack;
        // Right means we will traverse the array from right
        // To store the result we will use vector v
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            // If the stack is empty means there is no greater element
            if(stack.empty()){
                v.push_back(-1);
            }
            // The top element will always be the current maximum Element
            else if(stack.top()>=arr[i]){
                v.push_back(stack.top());
            }
            // Most IMP Case
            // If top Element is not greater than the current element arr[i]
            // then we will pop that element as it could never be the next greatest
            // element after this point as the current element arr[i] would be
            // their which is greater than this element
            else{
                while(!stack.empty() || stack.top()<arr[i]){
                    // Hence we will pop it until
                    // either we empty the stack
                    // or ideal top element is achieved
                    stack.pop();
                    if(stack.empty()){
                        v.push_back(-1);
                    }
                }
                if(!stack.empty()){
                    v.push_back(stack.top());
                }
            }
            stack.push(arr[i]);
        }
        // As we traversed the array backwards we need to reverse the result vector also.
        reverse(v.begin(),v.end());
        return v;
    }
};

// This would be exactly same for if we are searching in left also
// The only changes ==>
// We traverse the array from starting
// We don't have to reverse the result vector
