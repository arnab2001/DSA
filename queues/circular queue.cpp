#include<iostream>
using namespace std;

struct Queue
{
	int cap,size;
	int front; 
	int *arr;
	Queue(int cap)
	{
		front=0;
		this->cap=cap;
		size=0;
		arr=new int[cap];
	}
	
	int getFront() 
	{
		if(isEmpty()) return -1;
		return front;
	}
	
	int getRear() //return index of rear
	{
		if(isEmpty()) return -1;
		return (front+size-1)%cap;
	}
		
	
	bool isEmpty() 
	{
		return(size==0);
	}
	
	bool isFull() 
	{
		return(size==cap);
	}
	
	void enque(int x) 
	{
		if(size==cap) return;
		
		arr[(getRear()+1)%cap]=x;
		
		++size;
	}
	
	void deque() 
	{
		if(isEmpty()) return;
	
		front=(front+1)%cap;
		--size;
	}
	
	void display()
	{
		if(isEmpty()) 
		{ cout<<"\nQueue is empty!\n";
		return;}
		
		cout<<"\nPrinting circular queue:- \n";
		for(int i=0;i<size;++i)
		cout<<arr[(front+i)%cap]<<" ";
	}
};

int main()
{
	Queue q(57);
	q.enque(61);
	q.enque(3);
	q.enque(4);
	q.display();
	q.deque();
	q.enque(10);
	q.display();
	q.deque();
	q.deque();
	q.display();
}