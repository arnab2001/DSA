#include <stdio.h>
#include <stdlib.h>
struct node *push(struct node*);
struct node *pop(struct node *);
void peek(struct node *);
void display(struct node *);
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node* top=0;
    int choice;
    printf("Press 1 for Push\nPress 2 for Pop\nPress 3 for Display\nPress 4 for Peek\nPress 5 for Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: top=push(top);
            break;

            case 2: if(top==0){
                printf("Stack is Empty");
                break;
            }
            else{
                top=pop(top);
                break;
            }

            case 3: if(top==0){
                printf("Stack is Empty");
                break;
            }
            else{
                display(top);
                break;
            }

            case 4: if(top==0){
                printf("Stack is Empty");
                break;
            }
            else{
                peek(top);
                break;
            }

            case 5: break;
            default: printf("You have entered wrong choice");
        }
    }while(choice!=5);
}
struct node *push(struct node* top){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
    return top;
}
struct node *pop(struct node *top){
    struct node *temp=top;
    printf("The popped element is %d",top->data);
    top=top->next;
    free(temp);
    return top;
}
void display(struct node *top){
    struct node *temp=top;
    printf("The elements in the stack are: ");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void peek(struct node *top){
    printf("The element at the top is %d",top->data);
}
