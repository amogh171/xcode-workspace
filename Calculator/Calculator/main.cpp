#include <iostream>
#include <string>
#include "Calculator.h"
#include "Tester.h"

using namespace std;

void parse_string(string &s);

int main()
{
    
    Calculator calc;
    Tester sample_test;
    sample_test.SetExpression();
    string input_expression;
    int i = 0;
    do
    {
        try
        {
            cout <<endl <<"Expression? ";
            //getline(cin, input_expression);
            input_expression = sample_test.getExpression(i++);
            cout <<input_expression <<endl;
            if(input_expression != ".")
            {
                parse_string(input_expression);
                calc.set_exp(input_expression);
                double result = calc.expression();
                cout <<result <<endl;
            }
        }
        catch (string ex) // Catching exceptions like "Missing (" and unexpected %
        {
            cout <<endl <<"***** " <<ex <<endl;
        }
    } while(input_expression != ".");
    cout <<"Done!" <<endl;
    return 0;
}

void parse_string(string &s)
{
    int i;
    for(i = 0; i < s.size() ; i++)
    {
        if (s[i] == '=')
        {
            s = s.substr(0, i);
            break;
        }
    }
}
