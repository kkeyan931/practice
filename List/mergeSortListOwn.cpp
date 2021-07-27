#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void partition(Node *head, Node **firstList, Node **secondList)
{

    Node *slow;
    Node *fast;
    if (head == nullptr || head->next == nullptr)
    {
        *firstList = head;
        *secondList = nullptr;
    }
    else
    {
        slow = head;
        fast = head->next;

        while (fast != nullptr)
        {
            fast = fast->next;

            if (fast!= nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *firstList = head;
        *secondList = slow->next;
        slow->next = nullptr;
    }
}

Node *merge(Node *list1, Node *list2)
{

    Node *result = nullptr;

    if (list1 == nullptr)
    {
        return list2;
    }
    if (list2 == nullptr)
    {
        return list1;
    }

    if (list1->data <= list2->data)
    {
        result = list1;
        result->next = merge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = merge(list1, list2->next);
    }

    return result;
}

void mergeSort(Node **source){

    Node *head = *source;
    Node *firstList=nullptr;
    Node *secondList=nullptr;
    if(head==nullptr || head->next==nullptr){
        return;
    }

    partition(head,&firstList,&secondList);

    mergeSort(&firstList);
    mergeSort(&secondList);

    *source = merge(firstList,secondList);
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{

    Node *res = NULL;
    Node *a = NULL;

 
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    mergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);


}