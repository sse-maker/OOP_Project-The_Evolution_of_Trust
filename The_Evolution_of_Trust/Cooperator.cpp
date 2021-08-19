//
//  Cooperator.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Cooperator.hpp"

Cooperator::Cooperator() : name("Cooperator") {}
Cooperator::~Cooperator() {}

string Cooperator::GetName() const { return name; }

int Cooperator::Act(int history) { return 1; }
