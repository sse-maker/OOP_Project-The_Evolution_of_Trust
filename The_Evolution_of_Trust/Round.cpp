//
//  Round.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Round.hpp"

Round::Round(int roundNumber, int selectOpponent) : roundNumber(roundNumber), selectOpponent(selectOpponent) {}
Round::~Round() {}

void Round::Repeat() {
    Match match;
    Population population;
    population.Add(player);
    population.Add(selectOpponent);
    for (int i = 1; i <= roundNumber; i++) {
        cout << "===========Round  " << i << "===========" << endl;
        while (true) {
            cout << "Cooperating(1) or Cheating(0)?" << endl;
            cin >> select;
            if (!(select == 0 || select == 1)) cout << "Invalid Input!" << endl << endl;
            else break;
        }
        match.DetectSingleMatch(select, population.GetList()->GetpFirst()->job, population.GetList()->GetpLast()->job, population);
    }
    match.ShowWinner(population.GetList()->GetpFirst()->job, population.GetList()->GetpLast()->job);
}
