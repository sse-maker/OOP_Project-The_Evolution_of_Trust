//
//  Population.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Population_hpp
#define Population_hpp

#include "DoublyLinkedList.hpp"

class Population : public ItemType {
public:
    Population();
    ~Population();
    
    DoublyLinkedList* GetList() const;
    
    void Add(int set);
    void Eliminate();
    void Reproduce();
    void Sort();
    void ShowTotalReward();
    void SetAgentValue();
    
private:
    DoublyLinkedList *dList;
    ItemType *pCurPointer;
};

#endif /* Population_hpp */
