#include <bits/stdc++.h>

using namespace std;

struct trieNode
{
    char data;
    struct trieNode *child[26];
    int pc;

    trieNode() {}
    trieNode(char data)
    {
        this->data = data;
        this->pc = 0;
        for (int i = 0; i < 25; ++i)
        {
            child[i] = nullptr;
        }
    }
};

vector<trieNode> triePool(10000);
int nodeCount = 0;

trieNode *root;

void init()
{
    root = &triePool[nodeCount++];
    root->data = '/';
}

trieNode *setNode(char c)
{
    trieNode *node = &triePool[nodeCount++];
    node->data = c;
    return node;
}

void insertWord(string str)
{

    trieNode *ptr = root;
    for (int i = 0; str[i]; ++i)
    {
        int index = str[i] - 'a';
        if (ptr->child[index] == nullptr)
        {
            ptr->child[index] = setNode(str[i]);
        }
        ptr->pc += 1;
        ptr = ptr->child[index];
    }
}

int prefixCount(string str)
{

    trieNode *ptr = root;

    for (int i = 0; str[i]; ++i)
    {
        int index = str[i] - 'a';

        if (ptr->child[index] == nullptr || ptr->pc == 0)
        {
            return 0;
        }
        ptr = ptr->child[index];
    }
    return ptr->pc;
}

int main()
{

    init();

    vector<string> words{"hello",
                         "karthik",
                         "hakuna",
                         "matata",
                         "ami",
                         "arab",
                         "araaaa",
                         "araac",
                         "arrrr",
                         "ararr"};

    for (auto &word : words)
    {
        insertWord(word);
    }

    cout << prefixCount("ka") << endl;
}
