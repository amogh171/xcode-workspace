#include <iostream>
#include <stdlib.h>
#include "Calculator.h"

using namespace std;
void evaluate_expression(Calc& calculator);
int main()
{
    Calc calculator;
    char ch;
    do
    {
        cout << "Expression? ";
        cin >> ws;
        ch = cin.peek();
        if (ch != '.') evaluate_expression(calculator);
    }  while (ch != '.');

    cout << "Complete..." << endl;
    return 0;
}

void evaluate_expression(Calc& calculator)
{
    try
    {
        // Evaluate the expression and print its value.
        cout << calculator.evaluate() << endl;

        // An = sign must follow the expression.
        char ch;
        cin >> ch;
        if (ch != '=') throw string("Unexpected ") + ch;
    }
    catch(string& msg)
    {
        cout << "***** " << msg << endl;
    }

    // Skip the rest of the input line.
    string rest_of_line;
    getline(cin, rest_of_line);
}
