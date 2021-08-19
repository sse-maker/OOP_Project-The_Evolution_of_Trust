//
//  Detective.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Detective.hpp"

Detective::Detective() : name("Detective"), number(0), check(0) {}
Detective::~Detective() {}

string Detective::GetName() const { return name; }
void Detective::SetNumber() { number = 0; }
void Detective::SetCheck() { check = 0; }

int Detective::Act(int history) {
    if (number < 4) {
        if (history == 0) check = 1;
        if (number != 1) {
            number++;
            return 1;
        } else {
            number++;
            return 0;
        }
    } else {
        if (check == 1) {
            if (history == 1) return 1;
            else return 0;
        } else {
            return 0;
        }
    }
}
