#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <map>

using namespace std;

struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printTree(TreeNode *root)
{
    if (root != nullptr)
    {
        
        printTree(root->left);
        printTree(root->right);
        cout << root->data << " ";
    }
}

int main()
{

    string exp;
    cin >> exp;

    stack<TreeNode *> stack;

    for (int i = 0; i < exp.size(); ++i)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {

            TreeNode *node1 = stack.top();
            stack.pop();
            TreeNode *node2 = stack.top();
            stack.pop();

            TreeNode *op = new TreeNode;
            op->data = exp[i];
            op->left = node2;
            op->right = node1;

            stack.push(op);
        }
        else
        {
            TreeNode *node = new TreeNode;
            node->data = exp[i];
            node->left = nullptr;
            node->right = nullptr;

            stack.push(node);
        }
    }

    printTree(stack.top());

    //cout << stack.top()->data << endl;
}