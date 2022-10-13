bool isValid(string value)
{
    string<stack> s;
    for(int i=0; i<value.length(); i++)
    {
        char ch=value[i];
        
        // if we face with opening bracket push it to the stack
        // if we get closing bracket compare it with the top and pop it if it get matched
        
        if(ch=='(' || ch=='{' || ch=='[')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char top=s.top();
                
                if((ch==')' && top == '(') || (ch=='}' && top=='{') || (ch==']' && top=='['))
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    else{
        return false;
    }
}