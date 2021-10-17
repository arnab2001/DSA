#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x;
    node *next;
}node;
node **enqueue(node *front, node *temp, node *rear, node *newnode, node *arr[2])
{
    rear = arr[0];
    front = arr[1];
    newnode = (node *) malloc (sizeof (node));
    cout << "Enter the value to insert : " << endl;
    cin >> newnode -> x;
    newnode -> next = NULL;
    if (front == NULL)
    {
        rear = newnode;
        front = newnode;
        temp =  newnode;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
    }
    arr[0] = rear;
    arr[1] = front;
    return arr;
}
node **dequeue (node *front, node *temp, node *rear, node *newnode, node *arr[2])
{
    rear = arr[0];
    front = arr[1];
    if (front == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        temp = front;
        front = front -> next;
        free (temp);
        cout << "**************The element at front is deleted***************" << endl;
    }
    arr[0] = rear;
    arr[1] = front;
    return arr;
}
node **display(node *front, node *temp, node *rear, node *newnode, node *arr[2])
{
    rear = arr[0];
    front = arr[1];
    temp = front;
    if (rear == NULL || front == NULL)
    {
        cout << "The queue is empty !!" << endl;
    }
    else
    {
        cout << "***************The queue is displaying***********************" << endl;
        while (temp != NULL)
       {
        cout << temp -> x << "->" << " ";
        temp = temp -> next;
       }
    cout << "\n";
    }
    return arr;
}
int main()
{
    int choice = 1;
    node *front = NULL;
    node *temp = NULL;
    node *rear = NULL;
    node *newnode = NULL;
    node* arr[2];
    node **p;
    arr[0] = rear;
    //cout << arr[0];
    arr[1] = front;
    while (choice)
    {
        cout << "Press 1 for enqueue operation" << endl;
        cout << "Press 2 for  dequeue operation" << endl;
        cout << "Press 3 for display operation" << endl;
        cout << "Press 0 for the end of the program" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        if (choice == 1)
        {
            p = enqueue(front, temp, rear, newnode, arr);
        }
        else if (choice == 2)
        {
            p = dequeue(front, temp, rear, newnode, arr);
        }
        else if (choice == 3)
        {
            p = display(front, temp, rear, newnode, arr);
        }
        else if (choice == 0)
        {
            cout << "The program is ended" << endl;
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}