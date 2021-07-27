#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getPriority(char c){
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}
int main(){

    string str;
    cin >> str;

    string result;
    stack<char> stack;

    int i=0;
    while(i<str.size()){
        if((str[i]>='0' && str[i]<='9') || (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
            result.push_back(str[i]);
            i++;
        }
        else if(str[i]=='('){
            stack.push(str[i]);
            i++;
        }
        else if(str[i]==')'){

            while(!stack.empty() && stack.top()!='('){
                char k = stack.top();
                result.push_back(k);
                stack.pop();
            }
            if(stack.empty()){
                cout << "Incorrect" << endl;
                exit(1);
            }
            stack.pop();
            i++;
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%' || str[i]=='^'){
            
            while(!stack.empty() && getPriority(str[i])<=getPriority(stack.top()) && str[i]!='('){
                char k = stack.top();
                result.push_back(k);
                stack.pop();  
            }
            stack.push(str[i]);
            i++;
        }
        else{
            cout << "Incorrect" << endl;
            exit(2);
        }
    }

    while(!stack.empty()){
        char k = stack.top();
        result.push_back(k);
        stack.pop();  
    }

    cout <<"PostFix : " <<  result << endl;
}