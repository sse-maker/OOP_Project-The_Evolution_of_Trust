//
//  Tournament.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Tournament_hpp
#define Tournament_hpp

#include "Match.hpp"

#define SIZE 5

class Tournament {
public:
    Tournament(int countJob[]);
    ~Tournament();
    
    void Single();
    void Repeated(int tournamentNumber);
    void SetJob(Population& population);
    
private:
    int countJob[SIZE];
    int select;
};

#endif /* Tournament_hpp */
