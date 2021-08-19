//
//  Cooperator.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Cooperator_hpp
#define Cooperator_hpp

#include "Agent.hpp"

class Cooperator : public Agent {
public:
    Cooperator();
    ~Cooperator();
    
    string GetName() const;
    
    int Act(int history);
    
    void SetGrudge() {}
    void SetNumber() {}
    void SetCheck() {}
    
private:
    string name;
};

#endif /* Cooperator_hpp */
