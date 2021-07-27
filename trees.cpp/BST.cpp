#include <iostream>
#include <utility>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    BinarySearchTree(const BinarySearchTree &rhs)
    {
        root = new BinaryNode{rhs, nullptr, nullptr};
    }
    BinarySearchTree(BinarySearchTree &&rhs)
    {
        root = new BinaryNode{std::move(rhs), nullptr, nullptr};
    }
    ~BinarySearchTree()
    {
        makeEmpty();
    }
    const Comparable &findMin() const
    {
        return findMin(root)->element;
    }
    const Comparable &findMax() const
    {
        return findMax(root)->element;
    }
    bool contains(const Comparable &x) const
    {
        return contains(x, root);
    }
    bool isEmpty() const
    {
        return root == nullptr ? true : false;
    }
    void printTree(ostream &out = cout) const
    {
        printTree(root, out);
    }

    void BFS(int level,ostream &out = cout) const{
        BFS(root,level,out);
    }

    int height() const{
        return height(root);
    }
    void
    makeEmpty()
    {
        makeEmpty(root);
    }
    void
    insert(const Comparable &x)
    {
        insert(x, root);
    }
    void
    insert(Comparable &&x)
    {
        insert(move(x), root);
    }
    void
    remove(const Comparable &x)
    {
        remove(x, root);
    }
    int sum() const{
        return sum(root);
    }
private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}
        BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };
    BinaryNode *root;
    void insert(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if (x > t->element)
        {
            insert(x, t->right);
        }
        else
            ;
    }
    void insert(Comparable &&x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        }
        else if (x < t->element)
        {
            insert(std::move(x), t->left);
        }
        else if (x > t->element)
        {
            insert(std::move(x), t->right);
        }
        else
            ;
    }
    void remove(const Comparable &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            return;
        }
        else if (x < t->element)
        {
            remove(x, t->left);
        }
        else if (x > t->element)
        {
            remove(x, t->right);
        }
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *temp = t;

            t = (t->left != nullptr) ? t->left : t->right;

            delete temp;
        }
    }
    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        if (t->left == nullptr)
        {
            return t;
        }
        return findMin(t->left);
    }
    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        if (t->right == nullptr)
        {
            return t;
        }
        return findMax(t->right);
    }
    bool contains(const Comparable &x, BinaryNode *t) const
    {
        if (t == nullptr)
        {
            return false;
        }
        else if (x < t->element)
        {
            contains(x, t->left);
        }
        else if (x > t->element)
        {
            contains(x, x->right);
        }
        else
        {
            return true;
        }
    }
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    void printTree(BinaryNode *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element << " ";
            printTree(t->right, out);
        }
    }

    void BFS(BinaryNode *t,int level,ostream &out) const{
        if(t==nullptr)
            return;
        if(level==1){
            cout << t->element << " ";
        }
        else{
            BFS(t->left,level-1,out);
            BFS(t->right,level-1,out);
        }
    }

    int height(BinaryNode *t) const{

        if(t==nullptr){
            return -1;
        }
        else{
            return 1+max(height(t->left),height(t->right));
        }
    }

    int sum(BinaryNode *t) const{


        if(t==nullptr){
            return 0;
        }
        return t->element + sum(t->left) + sum(t->right);
    }
};
