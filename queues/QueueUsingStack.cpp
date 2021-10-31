#include<iostream>
#define MAX 5

using namespace std;

class Stack{
 		
 	public:
	 	int a[MAX];
 		int top;	
 		Stack(){
			top=-1;
			}
		int isempty(){
  			if(top == -1)
   				return 1;
  			else
   				return 0;
		}

		int isfull(){
  			if(top==MAX-1)
   				return 1;
  			else
   				return 0;
		}

		void push(int n)
		{
  			if(isfull()==1)
   				cout<<"STACK IS FULL!! CAN'T ENTER MORE DATA "<<endl;
  			else{
  				top++;
   				a[top]=n; 
   			}
		}

		int pop(){
  			if(!isempty())
  			{
  				int x = a[top--];
  				return x;
			}
			else{
				cout<<"Nothing to pop"<<endl;
			}
		}
		
		int Top(){
			if(top==-1){
				cout<<"Undererflow"<<endl;
				return 0;
			}	
			return a[top];
		}
		
		void show(){
  			for(int j=top;j>=0;j--)
   			cout<<a[j]<<" ";
  			cout<<endl;
		}
};

class Queue
{
    Stack s1, s2;
 	int count=0;
public:
    
    void enqueue(int data)
    {
        while (!s1.isempty())
        {
            s2.push(s1.Top());
            s1.pop();
        }
 
        s1.push(data);
 
        
        while (!s2.isempty())
        {
            s1.push(s2.Top());
            s2.pop();
        }
    }
 
    
    int dequeue()
    {
        int top = s1.Top();
        s1.pop();
        return top;
    }
	
	void print(){
		s1.show();
	}
};


int main(void){
 	Queue a;
 	int m=1;
 	while(m!=0){
  			cout<<endl<<"ENTER CHOICE "<<endl<<"1 Enqueue Element"<<endl<<"2 Dequeue Element"<<endl<<"3 Display"<<endl<<"0 TO CLOSE THE PROGRAM"<<endl;
  			cin>>m;
  			cout<<endl<<endl;
  		switch(m){
   		case 1:
   			system("CLS");
   			cout<<"Enter the element which you want to push: "<<endl;
   			int data;
   			cin>>data;
    		a.enqueue(data);
    		break;
   		case 2:
   			system("CLS");
    		cout<<endl<<"The element is deleted: "<<endl;
    		a.dequeue();
    		break;
    	case 3:
    		system("CLS");
    		cout<<"The elements are: ";
    		a.print();
    		break;
   		case 0:
    		cout<<"CLOSING THE PROGRAM....";
    		break;        
		}
	}
}