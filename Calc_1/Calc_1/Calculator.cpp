#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Calculator.h"

//Default ructor
Calc::Calc()
{

}
//Destructor
Calc:: ~Calc()
{

}

//Evaluating an expression
double Calc::evaluate()  throw(string)
{
    return expression();
}

double Calc::expression()  throw(string)
{
    double result=term();
    while(exp[0] == '+' || exp[0]== '-')
        if(exp[0] == '+')
        {
            exp=exp.substr(1);
            result+=term();
        }
    else
        {
            exp=exp.substr(1);
            result-=term();
        }
    return result;
}

double Calc::term()  throw(string)
{

    double result=factor();
    while(exp[0] == '/' || exp[0]== '*')
        if(exp[0] == '/')
        {
            exp=exp.substr(1);
            result/=factor();
        }
        else
        {
            exp=exp.substr(1);
            result*=factor();
        }
    return result;
}

double Calc::factor()  throw(string) {
    if (cin.peek() >= '0' && cin.peek() <= '9')
    {
        return number();
    }
    else if (cin.peek() == '(')
    {
        get_c();
    double result = expression();
    if (cin.peek() == ')')
        get_c();
    else
        throw string("Missing )");
    return result;
}
else if (cin.peek() == '-')
    {
        get_c();
        return -factor();
    }
    else if (cin.peek() == '+')
    {
        get_c();
        return factor();
    }
else
        return 0;
}

void Calc ::get_c() throw(string)
{
	cin >> ws;             // skip blanks
	cin.peek();
}


double Calc::number()  throw(string)
{
	//cin >> ws;             // skip blanks
	    char ch = cin.peek();  // what's the next input character?

	    // Evaluate a number.
	    if (isdigit(ch))
	    {
	        return (ch - '0');  // evaluate and return a number's value
	    }

	    // Recursively evaluate a parenthesized subexpression.
	    else if (ch == '(')
	    {
	        //cin >> ch;                    // read the (
	        double value = expression();  // evaluate the subexpression

	        // The next character should be the matching )
	        ch = cin.peek();
	        if (ch == ')') cin >> ch;     // read the )
	        else
	        {
	            throw string("Missing )");
	        }

	        return value;  // return the parenthesized subexpression's value
	    }

	    // Handle an invalid factor.
	    else
	    {
	        throw string("Invalid factor");
	        return 0;
	    }
}
