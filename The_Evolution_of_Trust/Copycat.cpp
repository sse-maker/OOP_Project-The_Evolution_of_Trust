//
//  Copycat.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Copycat.hpp"

Copycat::Copycat() : name("Copycat") {}
Copycat::~Copycat() {}

string Copycat::GetName() const { return name; }

int Copycat::Act(int history) {
    if (history == 1) return 1;
    else return 0;
}
