#include <iostream>
#include "./LinkedListClass.h"

void printTheList(LinkedListNode *head)
{
    LinkedListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void insertAtHead(LinkedListNode *&head, int data)
{
    LinkedListNode *insertingValue = new LinkedListNode(data);
    // if(head == NULL){
    //     head = insertingValue;
    //     return;
    // }
    insertingValue->next = head;
    head = insertingValue;
}

void insertAtTail(LinkedListNode *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    LinkedListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    LinkedListNode *insertingValue = new LinkedListNode(data);
    temp->next = insertingValue;
}

int TotalNumberOfNodes(LinkedListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtGivenPosition(LinkedListNode *head, int position, int data)
{
    LinkedListNode *prev = head, *newNode = new LinkedListNode(data), *curr = head;
    int totalNodes = TotalNumberOfNodes(head);
    if (position > totalNodes)
    {
        return;
    }

    int i = 1;
    while (prev != NULL || i < position)
    {
        prev = prev->next;
        i++;
    }

    curr = prev->next;
    prev->next = newNode;
    newNode->next = curr;
}

int main()
{
    LinkedListNode *head = new LinkedListNode(10);
    insertAtHead(head, 90);
    insertAtHead(head, 80);
    insertAtHead(head, 70);
    insertAtHead(head, 60);
    printTheList(head);
    cout<<endl;
    cout << TotalNumberOfNodes(head) << endl;
    insertAtGivenPosition(head, 3, 50);
    printTheList(head);
    return 0;
}