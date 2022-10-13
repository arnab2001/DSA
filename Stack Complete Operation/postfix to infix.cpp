Rules for Postfix to Infix using stack DS –
Scan POSTFIX expression from LEFT to RIGHT
IF the incoming symbol is a OPERAND, PUSH it onto the Stack
IF the incoming symbol is a OPERATOR, POP 2 OPERANDs from the Stack, ADD this incoming OPERATOR in between the 2 OPERANDs, ADD ‘(‘ & ‘)’ to the whole expression & PUSH this whole new expression string back into the Stack.
At the end POP and PRINT the full INFIX expression from the Stack.


#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperand(postfix[i])) {
            string op(1, postfix[i]);

            //string op=postfix[i];

            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return s.top();
}

int main()
{

    string infix, postfix;
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    infix = PostfixToInfix(postfix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;

    return 0;
}