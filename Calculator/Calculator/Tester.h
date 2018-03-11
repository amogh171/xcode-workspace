//
//  Tester.h
//  Calculator
//
//  Created by Amogh Ramaswamy on 10/30/17.
//  Copyright © 2017 Amogh Ramaswamy. All rights reserved.
//

#ifndef Tester_h
#define Tester_h

#include <vector>
#include <string>

using namespace std;

class Tester
{
public:
    
    /*
     * Default Constructor
     */
    Tester();
    
    /*
     * Sets a sample string of expressions to
     * test the calculator program
     */
    void SetExpression();
    
    /*
     * gets expression at index
     * @param index the index of the expression vector
     */
    string getExpression(int index);
    
private:
    vector<string> expressions;
    
};


#endif /* Tester_h */
