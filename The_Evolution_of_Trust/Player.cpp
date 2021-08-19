//
//  Player.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Player.hpp"

Player::Player() : name("Player") {}
Player::~Player() {}

string Player::GetName() const { return name; }

int Player::Act(int history) { return history; }
