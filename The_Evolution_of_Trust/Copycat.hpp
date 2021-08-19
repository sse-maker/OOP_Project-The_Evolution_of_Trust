//
//  Copycat.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Copycat_hpp
#define Copycat_hpp

#include "Agent.hpp"

class Copycat : public Agent {
public:
    Copycat();
    ~Copycat();
    
    string GetName() const;
    
    int Act(int history);
    
    void SetGrudge() {}
    void SetNumber() {}
    void SetCheck() {}
    
private:
    string name;
};

#endif /* Copycat_hpp */
