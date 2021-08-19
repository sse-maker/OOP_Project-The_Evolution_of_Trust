//
//  Tournament.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Tournament.hpp"

Tournament::Tournament(int countJob[]) { for (int i = 0; i < SIZE; i++) this->countJob[i] = countJob[i]; }
Tournament::~Tournament() {}

void Tournament::Single() {
    int current = 1;
    Match match;
    Population population;
    SetJob(population);
    cout << "------------------------------" << endl;
    population.ShowTotalReward();
    for (NodeType* currNode = population.GetList()->GetpFirst(); currNode != NULL; currNode = currNode->next) {
        int next = current + 1;
        for (NodeType* nextNode = currNode->next; nextNode != NULL; nextNode = nextNode->next) {
            while (true) {
                cout << "------------------------------" << endl;
                cout << "Continue(1) or Stop(0)?" << endl;
                cin >> select;
                if (!(select == 0 || select == 1)) cout << "Invalid Input!" << endl;
                else break;
            }
            if (select == 1) {
                cout << "===========" << current << " vs " << next << "============" << endl;
                for (int i = 0; i < 10; i++) match.Detect(currNode->job, nextNode->job);
                match.SetJobChoose();
                population.SetAgentValue();
                population.ShowTotalReward();
                next++;
            } else return;
        }
        current++;
    }
    population.Sort();
    cout << "==============================" << endl;
    population.ShowTotalReward();
}

void Tournament::Repeated(int tournamentNumber) {
    Match match;
    Population population;
    SetJob(population);
    cout << "------------------------------" << endl;
    population.ShowTotalReward();
    for (int i = 1; i <= tournamentNumber; i++) {
        while (true) {
            cout << "------------------------------" << endl;
            cout << "Continue(1) or Stop(0)?" << endl;
            cin >> select;
            if (!(select == 0 || select == 1)) cout << "Invalid Input!" << endl;
            else break;
        }
        if (select == 1) {
            for (NodeType* currNode = population.GetList()->GetpFirst(); currNode != NULL; currNode = currNode->next) {
                for (NodeType* nextNode = currNode->next; nextNode != NULL; nextNode = nextNode->next) {
                    for (int j = 0; j < 10; j++) match.Detect(currNode->job, nextNode->job);
                    match.SetJobChoose();
                    population.SetAgentValue();
                }
            }
        } else return;
        population.Sort();
        cout << "=========Tournament " << i << "=========" << endl;
        population.ShowTotalReward();
        while (true) {
            cout << "------------------------------" << endl;
            cout << "Eliminate(1) or Stop(0)?" << endl;
            cin >> select;
            if (!(select == 0 || select == 1)) cout << "Invalid Input!" << endl;
            else break;
        }
        if (select == 1) population.Eliminate();
        else return;
        while (true) {
            cout << "------------------------------" << endl;
            cout << "Reproduce(1) or Stop(0)?" << endl;
            cin >> select;
            if (!(select == 0 || select == 1)) cout << "Invalid Input!" << endl;
            else break;
        }
        if (select == 1) {
            population.Reproduce();
            cout << "------------------------------" << endl;
            population.ShowTotalReward();
        } else return;
    }
}

void Tournament::SetJob(Population& population) {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 0; j < countJob[i - 1]; j++) population.Add(i);
    }
}
