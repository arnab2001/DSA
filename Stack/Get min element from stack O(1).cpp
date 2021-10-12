#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}




/*returns min element from stack*/
// This solution is O(n) space & O(1) time 
// int _stack :: getMin()
// {
//     if (s.empty())
//         return -1;
//     return s.top();
// }

// /*returns poped element from stack*/
// int _stack ::pop()
// {
//     if (s.empty())
//         return -1;
//     s.pop();
//     int popped = s.top();
//     s.pop();
//     if (!s.empty())
//       minEle = s.top();
//     return popped;
// }

// /*push element x into the stack*/
// void _stack::push(int x)
// {
//     if (s.empty())
//       minEle = INT_MAX;
//     if (minEle>x)
//       minEle = x;
//     s.push(x);
//     s.push(minEle);
// }


// Best possible solution : O(1) space & O(1) time
int _stack :: getMin()
{
    if (s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if (s.empty())
        return -1;
    int popped = s.top(); 
    s.pop();
    if (!s.empty())
      minEle = s.top()/1000;  // Division gives us the minELement
    return popped%1000;  // Modulo gives us the 'x' (pushed) value
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if (s.empty())
      minEle = INT_MAX;
    if (minEle>x)
      minEle = x;
    s.push(minEle*1000 + x);
}

