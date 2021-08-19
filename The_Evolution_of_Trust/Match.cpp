//
//  Match.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Match.hpp"

Match::Match() : job1Choose(1), job2Choose(1) {}
Match::~Match() {}

void Match::SetJobChoose() {
    job1Choose = 1;
    job2Choose = 1;
}

void Match::Detect(ItemType& job1, ItemType& job2, int beforeJob1Choose) {
    int beforeJob2Choose = job2Choose;
    if (beforeJob1Choose == -1) {
        beforeJob1Choose = job1Choose;
        job1Choose = job1.GetAgent()->Act(beforeJob2Choose);
        job2Choose = job2.GetAgent()->Act(beforeJob1Choose);
    } else {
        job2Choose = job2.GetAgent()->Act(job1Choose);
        job1Choose = job1.GetAgent()->Act(beforeJob1Choose);
    }
    if (job1Choose == job2Choose) {
        if (job1Choose == 1) {
            job1.SetReward(job1.GetReward() + 2);
            job2.SetReward(job2.GetReward() + 2);
        }
    } else {
        if (job1Choose == 1) {
            job1.SetReward(job1.GetReward() - 1);
            job2.SetReward(job2.GetReward() + 3);
        } else {
            job1.SetReward(job1.GetReward() + 3);
            job2.SetReward(job2.GetReward() - 1);
        }
    }
}

void Match::DetectSingleMatch(int select, ItemType& player, ItemType& opponent, Population& population) {
    Detect(player, opponent, select);
    if (job1Choose == job2Choose) {
        if (job1Choose == 1) {
            cout << "Player: Cooperating!" << endl;
            cout << opponent.GetAgent()->GetName() << ": Cooperating!" << endl;
        } else {
            cout << "Player: Cheating!" << endl;
            cout << opponent.GetAgent()->GetName() << ": Cheating!" << endl;
        }
    } else {
        if (job1Choose == 1) {
            cout << "Player: Cooperating!" << endl;
            cout << opponent.GetAgent()->GetName() << ": Cheating!" << endl;
        } else {
            cout << "Player: Cheating!" << endl;
            cout << opponent.GetAgent()->GetName() << ": Cooperating!" << endl;
        }
    }
    cout << "------------------------------" << endl;
    cout << "Total Reward" << endl;
    population.ShowTotalReward();
}

void Match::ShowWinner(ItemType& player, ItemType& opponent) {
    cout << "==============================" << endl;
    if (player.GetReward() > opponent.GetReward()) {
        cout << "The winner is Player" << endl;
    } else if (player.GetReward() < opponent.GetReward()) {
        cout << "The winner is " << opponent.GetAgent()->GetName() << endl;
    } else {
        cout << "Duce" << endl;
    }
}
