//
//  Grudger.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Grudger.hpp"

Grudger::Grudger() : name("Grudger"), grudge(0) {}
Grudger::~Grudger() {}

string Grudger::GetName() const { return name; }
void Grudger::SetGrudge() { grudge = 0; }

int Grudger::Act(int history) {
    if (history == 0) grudge = 1;
    if (grudge == 1) return 0;
    return 1;
}
