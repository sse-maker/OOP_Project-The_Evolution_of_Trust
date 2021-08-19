//
//  Agent.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <iostream>
#include <string>

using namespace std;

class Agent {
public:
    Agent();
    virtual ~Agent();
    
    virtual string GetName() const = 0;
    virtual int Act(int history) = 0;
    
    virtual void SetGrudge() = 0;
    virtual void SetNumber() = 0;
    virtual void SetCheck() = 0;
};

#endif /* Agent_hpp */
