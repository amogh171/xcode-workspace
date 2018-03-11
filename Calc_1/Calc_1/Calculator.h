
#include<string.h>
#include <iostream>
using namespace std;


class Calc
{
public:
    Calc(); //ructor
    ~Calc(); //destructor
    double evaluate() throw(string);
    double expression() throw(string);
    double term() throw(string);
    double factor() throw(string);
    double number() throw(string);
   void get_c() throw(string);

private:
    string exp;

};
