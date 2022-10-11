#include<iostream>
#include<conio.h>

using namespace std;
class Stack{
private:
	int top;
	int arr[5];
public:
	Stack(){
		top = -1;
		for (int i = 0; i < 5; i++){
			arr[i] = 0;
		}
	}

	bool isEmpty(){
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull(){
		if (top == 4)
			return true;
		else
			return false;
	}

	void push(int val){
		if (isFull()){
			cout << "Stack Overflow" << endl;
		}
		else
		{
			top++;  // top will become 0
			arr[top] = val;

		}
	}

	int pop(){
		if (isEmpty()){
			cout << "Stack Underflow" << endl;
			return 0;
		}
		else{
			int popvalue = arr[top];
			arr[top] = 0; // we are removing a value
			top--;
			return popvalue;
		}
	}

	int count(){
		return(top)+1;
	}

	int peek(int pos){
		if (isEmpty()){
			cout << "Stack is Underflow" << endl;
		}
		else{
			return arr[pos];
		}
	}

	void change(int positon, int val){
		arr[positon] = val;
		cout << "Value Changed at location " << positon << endl;
	}

	void display(){
		cout << "All values in the stack are :" << endl;
		for (int i = 4; i >= 0; i--){
			cout << arr[i] << endl;
		}
	}
};

int main(){

	Stack s1;
	int option, position, value;

	do
	{
		cout << "What operation do you want to perform" << endl;
		cout << "Select one option but Enter [0] to exit the program" << endl;
		cout << "1. Push()" << endl;
		cout << "2. Pop()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. Peek()" << endl;
		cout << "6. Count()" << endl;
		cout << "7. Change()" << endl;
		cout << "8. Display()" << endl;
		cout << "9. Clear Screen" << endl;

		cin >> option;

	switch (option){
	case 1:
		cout << "Enter an Item to push in the stack" << endl;
		cin >> value;
		s1.push(value);
		break;
	case 2:
		cout << "Pop function called - pop value :" << s1.pop() << endl;
		break;
	case 3:
		if (s1.isEmpty()){
			cout << "Stack is Empty" << endl;
		}
		else
			cout << "Stack is not Empty" << endl;
		break;
		
	case 4:
		if (s1.isFull()){
			cout << "Stack is full" << endl;
		}
		else
			cout << "Stack is not full" << endl;
		break;
	case 5:
		cout << "Enter position of item you want to peek:" << endl;
		cin >> position;
		cout << "Peek function called - value at position "<<position<< "is" << endl << s1.peek(position) << endl;
		break;
	case 6:
		cout << "Count Function called number of item in the stack are : " << s1.count() << endl;
		break;
	case 7:
		cout << "Change Function called " << endl;
		cout << "Enter position of item you want to change:";
		cin >> position;
		cout << endl;
		cout << "Enter Value of item you want to change:";
		cin >> value;
		s1.change(position, value);
		break;
	case 8:
		cout << "Dsiplay Function called" << endl;
		s1.display();
	case 9:
		cout << "Bye Bye!" << endl;
		system("cls");
		break;
	default:
		cout << "Enter Proper order that are Offered" << endl;
	}
	} while (option != 0);
	
	_getch();
	return 0;
}