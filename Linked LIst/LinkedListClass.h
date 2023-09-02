#include<iostream>
using namespace std;

class LinkedListNode {
    public:
    int data;
    LinkedListNode* next;

    LinkedListNode(){
        this->data = 0;
        this->next = NULL;
    }

    LinkedListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

