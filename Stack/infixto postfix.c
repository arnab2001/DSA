#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 50
char s[MAX];
char s2[MAX];
int top=-1;
int top2=-1;
void push(char x)
{
 s[++top]=x;
}
void push2(int x)
{
 s2[++top2]=x;
}
char pop()
{
 return s[top--];
}
int pop2()
{
 return s2[top2--];
}
int priority(char ch)
{
 if(ch=='^')
return 3;
if(ch=='*' || ch=='/')
return 2;
else if(ch=='+' || ch=='-')
return 1;
else
return 0;
}
void transfer()
{
char in[MAX];
printf("\nenter infix expresssion :- ");
scanf("%s",in);
char post[MAX];
int pos=0,temp;
    for(int i=0;i<=strlen(in);i++)
    {
            char d=in[i];
         if(d>='a'&&d<='z')
         {
            post[pos]=d;
            pos++;
         }
         else if(d>='A'&&d<='Z')
         {
         post[pos]=d;
         pos++;
         }
         else if(d>='0'&&d<='9')
              {
              post[pos]=d;
              pos++;
              }
         else if(d=='(')
              push(d);
         else if (d==')')
         {
         temp=pop();
         while(temp!='(')
            {
              post[pos]=temp;
              pos++;
              temp=pop();
            }
         }
         else if(d=='+'||d=='-'||d=='*'||d=='/' || d=='^')
         {
          while(priority(d)<=priority(s[top]))
          {
          temp=pop();
          post[pos]=temp;
          pos++;
          }
          push(d);
         }
    }
char t;
     while(top!=-1)
     {
      t=pop();
      post[pos]=t;
      pos++;
     }
post[pos]='\0';
printf("the postfix expression is :- ");
puts(post);
}
void execute(char c)
{
int a,b,ans;
a=pop2();
top--;
b=pop2();
switch(c)
{
 case '^':
      ans=pow(b,a);
      break;
 case '+':
      ans=b+a;
      break;
 case '-':
      ans=b-a;
      break;
 case '*':
      ans=b*a;
      break;
 case '/':
      ans=b/a;
      break;
}
top2++;          
    s2[top2]=ans;
}
void solution ()
{
char p[MAX];
printf("\nenter postfix expresssion :- ");
scanf("%s",p);
for(int i=0;i<strlen(p);i++)
{                
if(p[i]>='0' && p[i]<='9')
push2(p[i]-'0');
else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i]=='^')
{
execute(p[i]);
}
}
printf("\nresult = %d",s2[top2]);
}
int main ()
{
int t;
       while(1)
    {
      printf("\n1.infix to postfix\n2.solution using postfix\n3.exit\nenter your choice :- ");
      scanf("%d",&t);
      switch(t)
{
 case 1:
      transfer();
      break;
 case 2:
      solution();
      break;
 case 3:
      exit(0);
default:
printf("wrong input");
}
}
}
