//
//  Round.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Round_hpp
#define Round_hpp

#include "Match.hpp"

class Round {
public:
    Round(int roundNumber, int selectOpponent);
    ~Round();
    
    void Repeat();
    
private:
    int roundNumber, selectOpponent;
    int select;
};

#endif /* Round_hpp */
