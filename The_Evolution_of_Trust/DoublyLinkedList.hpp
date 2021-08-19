//
//  DoublyLinkedList.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include "ItemType.hpp"

struct NodeType {
    ItemType job;
    NodeType *prev;
    NodeType *next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    NodeType* GetpFirst() const;
    NodeType* GetpLast() const;
    int Getlength() const;
    void SetpFirst(NodeType *pFirst);
    void SetpLast(NodeType *pLast);
    void Setlength(int length);
    
    bool IsEmpty();
    void MakeEmpty();
    void Add(ItemType item);
    void Delete();
    
private:
    NodeType *pFirst;
    NodeType *pLast;
    int length;
};

#endif /* DoublyLinkedList_hpp */
