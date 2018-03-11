//
//  calculator.cpp
//  Calculator
//
//  Created by Amogh Ramaswamy on 10/28/17.
//  Copyright © 2017 Amogh Ramaswamy. All rights reserved.
//

#include "Calculator.h"
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

char Calculator::peek()
{
    return exp[0];
}

char Calculator::get()
{
    char s = exp[0];
    exp = exp.substr(1);
    return s;
}
Calculator::Calculator()
{
    exp = "";
    //result = 0;
}

double Calculator::expression()
{
    double result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

double Calculator::term()
{
    double result = factor();
    while (peek() == '*' || peek() == '/' )
        if (get() == '*')
            result *= factor();
        else
        {
            double div = factor();
            if (div == 0)
            {
                string exp = "Division by zero";
                throw exp;
            }
            result /= div;
        }
    
    if (peek() == 'e' || peek() == 'E')
    {
        get();
        if (peek() == '+')
        {
            get();
            result *= pow (10, peek() - '0' );
        }
        else if (peek() == '-')
        {
            get();
            result *= pow (10, -( peek() - '0' ));
        }
    }
    
    if (peek() == '%')
    {
        string exp = "Unnexpected .";
        exp[12] = peek();
        throw exp;
    }
    return result;
}

double Calculator::factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        double result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0;
}

double Calculator::number()
{
    double result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10 * result + get() - '0';
    }
    if (peek() == '.')
    {
        get();
        int i = 1;
        while (peek() >= '0' && peek() <= '9')
        {
            result =  result + (get() - '0') * pow((0.1),i) ;
            i++;
        }
    }
    return result;
}

void Calculator::remove_space()
{
    string exp_store;
    for(int i = 0; i< exp.size() ; i++)
    {
        if(exp[i] != ' ')
        {
            exp_store += exp[i];
        }
    }
    exp = exp_store;
}

void Calculator::set_exp(string s)
{
    exp = s;
    remove_space();
    check_brackets();
}

void Calculator::check_brackets()
{
    int count_open = 0, count_close = 0;
    for (int i = 0; i < exp.size() ; i++)
    {
        if (exp[i] == '(') count_open ++;
        else if (exp[i] == ')') count_close ++;
    }
    if (count_close > count_open)
    {
        string ex = "Unexpected )";
        throw ex;
    }
    else if (count_close < count_open)
    {
        string ex = "Missing )";
        throw ex;
    }
}
