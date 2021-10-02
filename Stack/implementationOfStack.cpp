#include<iostream>
#define n 101
using namespace std;

template<class T>
class stack
{
public:

  T * arr;
  stack(){
    arr=new T[n];
    top=-1;
    }

void Push(int x)
{
    if(top>=n-1){        
        cout<<"Error StackOverflow";
    return;
    }
    A[++top]=x;
}

void Pop(){
    if(top==-1){
        cout<<"No element to pop";
        return;
    }
    top--;
}
void print_Stack_DS(){
    int i;
    printf("stack : ");
    for(int i=0;i<=top;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}


bool isEmpty(){
    if(top==-1){
        return false;
    }
    else
    return true; 
}




};
/////////////////////////////////////////////////////////////////////////////
////////////----------------------------------//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


int main(){
    stack<int>st;
   cout<<st.isEmpty();
 st.Push(2);
 st.Push(3);
 st.Push(2);
 st.Push(2);
 st.Push(2);
 st.print_Stack_DS();

}
