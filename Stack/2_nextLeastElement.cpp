// Nearest Smallest Element to left
// Return the Vector with the list of Elements 
// that are the next smallest/least element to the left
// For Example : 
//     Arr[]:  4 5 2 10 8
//  result[]: -1 4 -1 2 2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackSolution{
    public:
    vector<int> NextSmallestLeft(vector<int> arr){
        int n= arr.size(); //size of vector
        // We will use a stack to store the values of 
        // current minimum on top 
        stack <int> stack;
        // Right means we will traverse the array from right
        // To store the result we will use vector v
        vector<int> v;
        for(int i=0;i<n;i++){
            // If the stack is empty means there is no smaller element
            if(stack.empty()){
                v.push_back(-1);
            }
            // The top element will always be the current minimum Element
            else if(stack.top()<=arr[i]){
                v.push_back(stack.top());
            }
            // Most IMP Case
            // If top Element is not smaller than the current element arr[i]
            // then we will pop that element as it could never be the next smallest
            // element after this point as the current element arr[i] would be
            // their which is smaller than this element
            else{
                while(!stack.empty() || stack.top()>arr[i]){
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

// This would be exactly same for if we are searching in right also
// The only changes ==>
// We traverse the array from ending/ backwards
// We have to reverse the result vector
