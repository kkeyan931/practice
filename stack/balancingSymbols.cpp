#include <iostream>
#include <stack>

using namespace std;

int main()
{

    string str;

    cin >> str;
    stack<char> st;

    int i;
    for (i = 0; i < str.size(); ++i)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            st.push(str[i]);
        else if(str[i]==')' && !st.empty() && st.top()=='(')
            st.pop();
        else if(str[i]=='}' && !st.empty() && st.top()=='{')
            st.pop();
        else if(str[i]==']' && !st.empty() && st.top()=='[')
            st.pop();
        else{
            cout << "Incorrect";
            break;
        }
    }
    if(!st.empty()){
        cout << "Incorrect";
    }
    else{
        cout << "Correct";
    }
}