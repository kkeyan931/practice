#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main(){

    string str;

    cin >> str;

    int a,b;

    stack<int> stack;
    for(int i=0;i<str.size();++i){
        if(str[i]-'0'>=0 && str[i]-'0'<=9){
            stack.push(str[i]-'0');
        }
        else{
            switch (str[i]){
                case '+':
                    a=stack.top();
                    stack.pop();
                    b=stack.top();
                    stack.pop();
                    stack.push(a+b);
                    break;
                case '-':
                    a=stack.top();
                    stack.pop();
                    b=stack.top();
                    stack.pop();
                    stack.push(b-a);
                    break;
                case '*':
                    a=stack.top();
                    stack.pop();
                    b=stack.top();
                    stack.pop();
                    stack.push(a*b);
                    break;
                case '/':
                    a=stack.top();
                    stack.pop();
                    b=stack.top();
                    stack.pop();
                    stack.push(b/a);
                    break;
                case '%':
                    a=stack.top();
                    stack.pop();
                    b=stack.top();
                    stack.pop();
                    stack.push(b%a);
                    break;
            }
        }
    }
    cout << stack.top() << endl;
}