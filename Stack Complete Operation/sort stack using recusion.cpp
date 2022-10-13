void insertSort(stack<int> &stack, int num)
{
    //base case
    if(stack.empty() || stack.empty() && stack.top<num)
    {
        stack.push(num);
    }
    
    int n= stack.top();
    stack.pop();
    
    
    recursive(stack, num);
    
    stack.push(n);
}


void sortStack(stack<int>&stack)
{
    //base case
    
    if(stack.empty())
    {
        return;
    }
    int num= stack.top();
    stack.pop();
    
    // recursive call
    
    sortStack(stack)
    
    insertSort(stack, num);
}