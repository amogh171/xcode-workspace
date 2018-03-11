//
//  Tester.cpp
//  Calculator
//
//  Created by Amogh Ramaswamy on 10/30/17.
//  Copyright © 2017 Amogh Ramaswamy. All rights reserved.
//

#include "Tester.h"
#include <vector>
#include <string>

using namespace std;

Tester::Tester()
{    
}

void Tester::SetExpression()
{
    expressions.push_back("42 =");
    expressions.push_back("2*(42 - 42e-1) =");
    expressions.push_back("12/(5.5*(17 + 0.00314E+3)) =");
    expressions.push_back(" 65%2 =");
    expressions.push_back("12/(5.5*(17 + 0.00314E+3) =");
    expressions.push_back("(((((5))))) =");
    expressions.push_back("(5)) + 2 =");
    expressions.push_back("5/(6 - 2*3) =");
    expressions.push_back("(8 /( 5 * 3 ) * (6/3) )= ");
    expressions.push_back(".");
}

string Tester::getExpression(int index)
{
    return expressions.at(index);
}
