#include <iostream>
#include <utility>
using namespace std;

template <typename Comparable>
class AVL
{
public:
    AVL()
    {
        root = nullptr;
    }
    AVL(const AVL &rhs)
    {
        root = new AVLNode{rhs, nullptr, nullptr};
    }
    AVL(AVL &&rhs)
    {
        root = new AVLNode{std::move(rhs), nullptr, nullptr};
    }
    ~AVL()
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
    remove(const Comparable &x)
    {
        remove(x, root);
    }
    int sum() const
    {
        return sum(root);
    }
    

private:
    struct AVLNode
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;
        AVLNode(const Comparable &ele, AVLNode *lt, AVLNode *rt, int h = 0)
            : element{ele}, left{lt}, right{rt}, height{h} {}
        AVLNode(Comparable &&ele, AVLNode *lt, AVLNode *rt, int h = 0)
            : element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
    };
    AVLNode *root;

    int height(AVLNode *t)
    {
        return t == nullptr ? -1 : t->height;
    }

    void insert(const Comparable &x, AVLNode *&t)
    {
        if (t == nullptr)
            t = new AVLNode{x, nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);

        balance(t);
    }
    static const int ALLOWED_IMBALANCE = 1;

    void balance(AVLNode *&t)
    {
        if (t == nullptr)
            return;
        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    void rotateWithLeftChild(AVLNode *&k2)
    {
        AVLNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }
    void rotateWithRightChild(AVLNode *&k2)
    {
        AVLNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->right), height(k2->left)) + 1;
        k1->height = max(height(k1->right), k2->height) + 1;
        k2 = k1;
    }

    void doubleWithLeftChild(AVLNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AVLNode *&k3)
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    void remove(const Comparable &x, AVLNode *&t)
    {
        if (t == nullptr)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            AVLNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }

        balance(t);
    }

    AVLNode *
    findMin(AVLNode *t) const
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
    AVLNode *findMax(AVLNode *t) const
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
    bool contains(const Comparable &x, AVLNode *t) const
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
    void makeEmpty(AVLNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    void printTree(AVLNode *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element << " ";
            printTree(t->right, out);
        }
    }

    int sum(AVLNode *t) const
    {

        if (t == nullptr)
        {
            return 0;
        }
        return t->element + sum(t->left) + sum(t->right);
    }
};
