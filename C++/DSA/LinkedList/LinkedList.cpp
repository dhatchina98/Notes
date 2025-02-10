#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void AddAtFirst(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void AddAtLast(Node *head, int val)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
}

void AddAfterNode(Node *head, int key, int val)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        cout << "Key Not Found" << endl;
    }
}

void DeleteAtFirst(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete (temp);
}

void DeleteAtLast(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *t = temp->next;
    temp->next = NULL;
    delete (temp->next);
}

void DeleteAfterNode(Node *head, int key)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        Node *t = temp->next;
        temp->next = temp->next->next;
        delete (t);
    }
    else
    {
        cout << "Key Not Found" << endl;
    }
}

void search(Node *head, int key)
{
    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element Found At " << i << " position" << endl;
            break;
        }
        i++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Element Not Found " << endl;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    AddAtFirst(head, 3);
    print(head);
    AddAtFirst(head, 2);
    print(head);
    AddAtFirst(head, 1);
    print(head);
    AddAtLast(head, 5);
    print(head);
    AddAtLast(head, 6);
    print(head);
    AddAfterNode(head, 3, 4);
    print(head);
    DeleteAtFirst(head);
    print(head);
    DeleteAtLast(head);
    print(head);
    DeleteAfterNode(head, 3);
    print(head);
    search(head,3);
    search(head,9);
    return 0;
}