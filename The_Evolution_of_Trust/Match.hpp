//
//  Match.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Match_hpp
#define Match_hpp

#include "Population.hpp"

class Match {
public:
    Match();
    ~Match();
    
    void SetJobChoose();
    
    void Detect(ItemType& job1, ItemType& Job2, int beforeJob1Choose = -1);
    void DetectSingleMatch(int select, ItemType& player, ItemType& opponent, Population& population);
    void ShowWinner(ItemType& player, ItemType& opponent);
    
private:
    int job1Choose, job2Choose;
};

#endif /* Match_hpp */
