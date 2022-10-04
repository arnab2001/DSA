#include<iostream>
using namespace std;
class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { 
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; 
        }
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
         if(isEmpty()){
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { 
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main(){

    Deque dq(5);
   
    cout << "Insert element at rear end  : 5 \n";
    dq.pushRear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.pushRear(10);
 
    cout << "get rear element "
         << " " << dq.getRear() << endl;
 
    dq.popRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "inserting element at front end \n";
    dq.pushFront(15);
 
    cout << "get front element "
         << " " << dq.getFront() << endl;
 
    dq.popRear();
 
    cout << "After delete front element new "
         << "front become " << dq.getFront() << endl;
    return 0;
}