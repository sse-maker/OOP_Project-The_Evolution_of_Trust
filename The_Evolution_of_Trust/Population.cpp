//
//  Population.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Population.hpp"

Population::Population() : dList(NULL), pCurPointer(NULL) {}
Population::~Population() {}

DoublyLinkedList* Population::GetList() const { return dList; }

void Population::Add(int set) {
    if (dList == NULL) dList = new DoublyLinkedList;
    pCurPointer = new ItemType;
    pCurPointer->SetAgent(set);
    dList->Add(*pCurPointer);
}

void Population::Eliminate() {
    for (int i = 0; i < 5; i++) {
        dList->Delete();
    }
}

void Population::Reproduce() {
    ItemType item = dList->GetpFirst()->job;
    NodeType *currNode = dList->GetpFirst();
    for (int i = 0; i < 5; i++) {
        NodeType *copyNode = new NodeType;
        copyNode->job = item;
        copyNode->prev = currNode;
        copyNode->next = currNode->next;
        if (currNode->next == NULL) dList->SetpLast(currNode);
        if (currNode->next != NULL) currNode->next->prev = copyNode;
        currNode->next = copyNode;
        currNode = copyNode;
    }
    if (currNode->next == NULL) dList->SetpLast(currNode);
    currNode = dList->GetpFirst();
    while (currNode != NULL) {
        currNode->job.SetReward(0);
        currNode = currNode->next;
    }
}

void Population::Sort() {
    for (NodeType *currNode = dList->GetpFirst(); currNode != NULL; currNode = currNode->next) {
        NodeType *maxNode = currNode;
        for (NodeType *tempNode = currNode->next; tempNode != NULL; tempNode = tempNode->next) {
            if (maxNode->job.GetReward() < tempNode->job.GetReward()) maxNode = tempNode;
        }
        ItemType temp = currNode->job;
        currNode->job = maxNode->job;
        maxNode->job = temp;
    }
}

void Population::ShowTotalReward() {
    NodeType *currNode = dList->GetpFirst();
    int num = 1;
    while (currNode != NULL) {
        cout << num << ". " << currNode->job.GetAgent()->GetName() << ": " << currNode->job.GetReward() << endl;
        currNode = currNode->next;
        num++;
    }
}

void Population::SetAgentValue() {
    NodeType *currNode = dList->GetpFirst();
    if (currNode->next == NULL) dList->SetpLast(currNode);
    while (currNode != NULL) {
        if (currNode->job.GetAgent()->GetName() == "Detective") {
            currNode->job.GetAgent()->SetNumber();
            currNode->job.GetAgent()->SetCheck();
        } else if (currNode->job.GetAgent()->GetName() == "Grudger") {
            currNode->job.GetAgent()->SetGrudge();
        }
        currNode = currNode->next;
    }
}
