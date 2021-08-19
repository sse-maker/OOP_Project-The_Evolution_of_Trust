//
//  ItemType.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "ItemType.hpp"

ItemType::ItemType() : agent(NULL), reward(0) {}
ItemType::~ItemType() {}

Agent* ItemType::GetAgent() const { return agent; }
int ItemType::GetReward() const { return reward; }
void ItemType::SetReward(int reward) { this->reward = reward; }
void ItemType::SetAgent(int set) {
    switch (set) {
        case player:
            agent = new Player;
            break;
            
        case copycat:
            agent = new Copycat;
            break;
            
        case cheater:
            agent = new Cheater;
            break;
            
        case cooperator:
            agent = new Cooperator;
            break;
            
        case grudger:
            agent = new Grudger;
            break;
            
        case detective:
            agent = new Detective;
            break;
    }
}
