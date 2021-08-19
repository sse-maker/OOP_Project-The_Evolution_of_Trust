//
//  Cheater.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Cheater_hpp
#define Cheater_hpp

#include "Agent.hpp"

class Cheater : public Agent {
public:
    Cheater();
    ~Cheater();
    
    string GetName() const;
    
    int Act(int history);
    
    void SetGrudge() {}
    void SetNumber() {}
    void SetCheck() {}
    
private:
    string name;
};

#endif /* Cheater_hpp */
