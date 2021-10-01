#include<iostream>
#define size 5
using namespace std;

class queue{
	int q[5];
	int front,rear;
	public:
		queue(){front=rear=-1;}
		void Enqueue(int x)
		{
			if(rear==size-1&&front==0 || (front==rear+1))
			{
				cout<<"Queue OverFlow"<<endl;
			}
			else if(front=-1)
			{
				rear++;
				front++;
			}
			else if(rear==size-1 && front!=0)
			{
				rear=0;
			}
			else
			{
					rear++;
			}
			q[rear]=x;
			cout<<"Element Inserted"<<endl;
		}
		void Dequeue()
		{
			if(front==-1)
			{
				cout<<"Queue Underflow"<<endl;
			}
			else if(front==rear)
			{
				cout<<"DELETED="<<q[front]<<endl;
				front=-1;
				rear=-1;
			}
			else if(front=size-1)
			{
				cout<<"DELETED="<<q[front]<<endl;
			}
			else
			{
				cout<<"DELETED="<<q[front]<<endl;
				front++;
			}
		}
		void display()
		{
				for(int i=front;i<=rear;i++)
				{
					cout<<" "<<q[i]<<endl;
				}
		}
};
int main()
{
	queue q;
	int p=1,x;
	while(p!=0)
	{
			cout<<"To Store Enter 1"<<endl;
   	        cout<<"To Display queue Enter 2"<<endl;
   	        cout<<"To Exit Enter 0"<<endl;
			cin>>p;
	switch(p)
		{
		case 1:
			cout<<"Enter the element"<<endl;
			cin>>x;
			q.Enqueue(x);
			break;
		case 2:
			q.display();
			break;
		case 3:
			q.Dequeue();
			break;
		default:
			cout<<"invalid"<<endl;
			break;
	}
}
}