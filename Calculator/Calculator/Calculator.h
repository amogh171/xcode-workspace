//
//  calculator.h
//  Calculator
//
//  Created by Amogh Ramaswamy on 10/28/17.
//  Copyright © 2017 Amogh Ramaswamy. All rights reserved.
//

#ifndef calculator_h
#define calculator_h
#include <string>
#include <iostream>

using namespace std;



class Calculator
{
public:
    /*
     *Default constructor
     */
    Calculator();
    
    /*
     * removes all spaces from the input expression
     */
    void remove_space();
    
    /*
     * evaluates the expression() by calling the function term,
     * which are sepated by + and - operators
     * @return the result of the expression as double
     */
    double expression();
    
    /*
     * evaluates the term() by calling the factors separted by
     * operators + and -
     * @return the result of the term in double
     */
    double term();
    
    /*
     * evaluates the factor() by calling number() if character is
     * a number. Else checks for '(' and calls expression()
     * return the value of calculated term
     */
    double factor();
    
    /*
     * Evaluates number by checking if parsed character is a number
     * and adding it to the result for each subsequent number
     * @return the final calculated number
     * 
     */
    double number();
    
    /*
     * getter
     * returns the first character of the current expression
     */
    char peek();
    
    /*
     * getter
     * return the first character of the current expression
     * and removes that character from the expression
     */
    char get();
    
    /*
     * setter
     * sets the expression value based on the input string after
     * removing all spaces. Also checks for brackets are matched
     * and throws error otherwise
     */
    void set_exp(string s);
    
    /*
     * checks if brackets of expression are balanced, else throws
     * error
     */
    void check_brackets();
    
private:
    string exp;    
};

#endif /* calculator_h */
