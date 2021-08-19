//
//  Detective.hpp
//  The_Evolution_of_Trust
//
//  Created by 세광 on 2021/08/17.
//

#ifndef Detective_hpp
#define Detective_hpp

#include "Agent.hpp"

class Detective : public Agent {
public:
    Detective();
    ~Detective();
    
    string GetName() const;
    void SetNumber();
    void SetCheck();
    
    int Act(int history);
    
    void SetGrudge() {}
    
private:
    string name;
    int number, check;
};

#endif /* Detective_hpp */
