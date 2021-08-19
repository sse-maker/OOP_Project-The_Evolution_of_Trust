//
//  DoublyLinkedList.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() : pFirst(NULL), pLast(NULL), length(0) {}
DoublyLinkedList::~DoublyLinkedList() { MakeEmpty(); }

NodeType* DoublyLinkedList::GetpFirst() const { return pFirst; }
NodeType* DoublyLinkedList::GetpLast() const { return pLast; }
int DoublyLinkedList::Getlength() const { return length; }
void DoublyLinkedList::SetpFirst(NodeType *pFirst) { this->pFirst = pFirst; }
void DoublyLinkedList::SetpLast(NodeType *pLast) { this->pLast = pLast; }
void DoublyLinkedList::Setlength(int length) { this->length = length; }

bool DoublyLinkedList::IsEmpty() {
    return length == 0;
}

void DoublyLinkedList::MakeEmpty() {
    NodeType *currNode = pFirst;
    NodeType *tempNode;
    while (currNode->next != NULL) {
        tempNode = currNode;
        currNode = currNode->next;
        delete tempNode;
    }
    delete currNode;
    pFirst = NULL;
    pLast = NULL;
    length = 0;
}

void DoublyLinkedList::Add(ItemType item) {
    NodeType *newNode = new NodeType;
    newNode->job = item;
    if (length == 0) {
        newNode->prev = NULL;
        newNode->next = NULL;
        pFirst = newNode;
        pLast = newNode;
    } else {
        newNode->prev = pLast;
        newNode->next = NULL;
        pLast->next = newNode;
        pLast = newNode;
    }
    Setlength(length + 1);
}

void DoublyLinkedList::Delete() {
    if (pLast == NULL) {
        cout << "There is no player" << endl;
        return;
    }
    NodeType *currNode = pLast;
    NodeType *tempNode = pLast->prev;
    tempNode->next = NULL;
    pLast = tempNode;
    delete currNode;
    Setlength(length - 1);
}
