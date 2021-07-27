#include <bits/stdc++.h>

using namespace std;

struct trieNode
{
    char data;
    struct trieNode *child[26];
    int wordEnd;

    trieNode() {}
    trieNode(char data)
    {
        this->data = data;
        this->wordEnd = 0;
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
        ptr = ptr->child[index];
    }
    ptr->wordEnd += 1;
}

bool searchWord(string str)
{
    trieNode *ptr = root;

    for (int i = 0; str[i]; ++i)
    {
        int index = str[i] - 'a';

        if (ptr->child[index] == nullptr)
        {
            return false;
        }
        ptr = ptr->child[index];
    }
    if (ptr->wordEnd > 0)
    {
        return true;
    }
    return false;
}

bool deleteWord(string str)
{

    if (searchWord(str))
    {
        trieNode *ptr = root;
        for (int i = 0; str[i]; ++i)
        {
            int index = str[i] - 'a';

            ptr = ptr->child[index];
        }
        ptr->wordEnd -= 1;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    init();

    vector<string> words{"hello",
                         "karthik",
                         "hakuna",
                         "matata",
                         "ami"};

    for (auto &word : words)
    {
        insertWord(word);
    }

    for (auto &word : words)
    {
        cout << searchWord(word) << " ";
    }

    cout << endl;
    deleteWord("hello");

    cout << searchWord("karthik") << endl;
    cout << searchWord("hello") << endl;
}