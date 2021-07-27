#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

    auto i = l1;
    auto j = l2;

    if (i == nullptr)
    {
        return j;
    }
    if (j == nullptr)
    {
        return i;
    }
    ListNode *head0 = new ListNode(-1);
    ListNode *head = head0;
    while (i != nullptr && j != nullptr)
    {
        if ((i->val) < (j->val))
        {
            head->next = i;
            head = head->next;
            i = i->next;
        }
        else if ((i->val) > (j->val))
        {
            head->next = j;
            head = head->next;
            j = j->next;
        }
        else
        {
            head->next = i;
            head = head->next;
            head->next = j;
            head = head->next;
            i = i->next;
            j = j->next;
        }
    }
    while (i != nullptr)
    {
        head->next = i;
        head = head->next;
        i = i->next;
    }

    while (j != nullptr)
    {
        head->next = j;
        head = head->next;
        j = j->next;
    }
    head->next = nullptr;

    return head0->next;
}

