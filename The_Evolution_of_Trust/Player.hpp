//
//  Player.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Player_hpp
#define Player_hpp

#include "Agent.hpp"

class Player : public Agent {
public:
    Player();
    ~Player();
    
    string GetName() const;
    
    int Act(int history);
    
    void SetGrudge() {}
    void SetNumber() {}
    void SetCheck() {}
    
private:
    string name;
};

#endif /* Player_hpp */
