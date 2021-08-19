//
//  Game.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Game_hpp
#define Game_hpp

#include "Round.hpp"
#include "Tournament.hpp"

class Game {
public:
    Game();
    ~Game();
    
    int GetCommand();
    void Run();
    void SingleMatch();
    void SingleTournament();
    void RepeatedTournament();
    int SetCountJob();
    
private:
    int command;
    int roundNumber, selectOpponent;
    int countJob[SIZE];
    int tournamentNumber;
};

#endif /* Game_hpp */
