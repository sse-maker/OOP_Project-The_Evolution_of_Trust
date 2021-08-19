//
//  ItemType.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef ItemType_hpp
#define ItemType_hpp

#include "Agent.hpp"
#include "Player.hpp"
#include "Copycat.hpp"
#include "Cheater.hpp"
#include "Cooperator.hpp"
#include "Grudger.hpp"
#include "Detective.hpp"

enum Job { player, copycat, cheater, cooperator, grudger, detective };

class ItemType {
public:
    ItemType();
    virtual ~ItemType();
    
    Agent* GetAgent() const;
    int GetReward() const;
    void SetReward(int reward);
    void SetAgent(int set);
    
private:
    Agent *agent;
    int reward;
};

#endif /* ItemType_hpp */
