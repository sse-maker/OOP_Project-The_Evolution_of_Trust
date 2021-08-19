//
//  Game.cpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#include "Game.hpp"

Game::Game() : command(0), roundNumber(0), selectOpponent(0), tournamentNumber(0) { memset(countJob, 0, sizeof(countJob)); }
Game::~Game() {}

int Game::GetCommand() {
    cout << "==============================" << endl;
    cout << "Select Menu" << endl;
    cout << "==============================" << endl;
    cout << "1. Single Match" << endl;
    cout << "2. Single Tournament" << endl;
    cout << "3. Repeated Tournament" << endl;
    cout << "4. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Command: "; cin >> command;
    return command;
}

void Game::Run() {
    while (true) {
        switch (GetCommand()) {
            case 1:
                SingleMatch();
                break;
            
            case 2:
                SingleTournament();
                break;
                
            case 3:
                RepeatedTournament();
                break;
                
            case 4:
                return;
                
            default:
                cout << "Invalid Input!" << endl << endl;
                break;
        }
    }
}

void Game::SingleMatch() {
    while (true) {
        cout << "Total Round Number: ";
        cin >> roundNumber;
        if (!(1 <= roundNumber && roundNumber <= 50)) cout << "Invalid Input!" << endl << endl;
        else break;
    }
    while (true) {
        cout << "Select an Opponent! Copycat(1), Cheater(2), Cooperator(3), Grudger(4), Detective(5)" << endl;
        cin >> selectOpponent;
        if (!(1 <= selectOpponent && selectOpponent <= 5)) cout << "Invalid Input!" << endl << endl;
        else break;
    }
    Round round(roundNumber, selectOpponent);
    round.Repeat();
}

void Game::SingleTournament() {
    while (true) {
        int total = SetCountJob();
        if (!(2 <= total && total <= 50)) cout << "Invalid Input!" << endl << endl;
        else break;
    }
    Tournament singleTournament(countJob);
    singleTournament.Single();
}

void Game::RepeatedTournament() {
    while (true) {
        cout << "Total Tournament Number: ";
        cin >> tournamentNumber;
        if (!(1 <= tournamentNumber && tournamentNumber <= 50)) cout << "Invalid Input!" << endl << endl;
        else break;
    }
    while (true) {
        int total = SetCountJob();
        if (!(6 <= total && total <= 50)) cout << "Invalid Input!" << endl << endl;
        else break;
    }
    Tournament repeatedTournament(countJob);
    repeatedTournament.Repeated(tournamentNumber);
}

int Game::SetCountJob() {
    int total = 0;
    cout << "Decide Population" << endl;
    for (int i = 0; i < SIZE; i++) {
        switch (i + 1) {
            case 1:
                cout << "Copycat: ";
                break;

            case 2:
                cout << "Cheater: ";
                break;

            case 3:
                cout << "Cooperator: ";
                break;

            case 4:
                cout << "Grudger: ";
                break;

            case 5:
                cout << "Detective: ";
                break;
        }
        while (true) {
            cin >> countJob[i];
            if (!(0 <= countJob[i] && countJob[i] <= 50)) cout << "Invalid Input! Enter again: ";
            else break;
        }
        total += countJob[i];
    }
    return total;
}
