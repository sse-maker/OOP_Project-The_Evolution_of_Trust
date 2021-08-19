//
//  Grudger.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Grudger_hpp
#define Grudger_hpp

#include "Agent.hpp"

class Grudger : public Agent {
public:
    Grudger();
    ~Grudger();
    
    string GetName() const;
    void SetGrudge();
    
    int Act(int history);
    
    void SetNumber() {}
    void SetCheck() {}
    
private:
    string name;
    int grudge;
};

#endif /* Grudger_hpp */
