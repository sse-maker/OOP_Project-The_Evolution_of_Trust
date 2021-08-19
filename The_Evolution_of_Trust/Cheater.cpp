//
//  Cheater.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Cheater.hpp"

Cheater::Cheater() : name("Cheater") {}
Cheater::~Cheater() {}

string Cheater::GetName() const { return name; }

int Cheater::Act(int history) { return 0; }
