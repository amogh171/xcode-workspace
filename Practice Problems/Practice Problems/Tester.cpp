#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class BadLuckError : public runtime_error
{
public:
    BadLuckError();
};

BadLuckError::BadLuckError() : runtime_error("") {}

int mystery(int x)
{
    if (x == 0) throw invalid_argument("No zero please");
    if (x < 0) throw range_error("Let's not be negative");
    if (x > 100) throw out_of_range("");
    if (x == 13) throw BadLuckError();
    if (x == 1) return x;
    if (x % 2 == 0) return mystery(x / 2);
    return mystery(3 * x + 1);
}

void process(int arg, int& result, string& error);

void test(int a, int r, string e)
{
    try
    {
        int result = -1;
        string error;
        process(a, result, error);
        if (error != "") cout << error << endl;
        else cout << result << endl;
        if (e != "") cout << "Expected: " << e << endl;
        else cout << "Expected: " << r << endl;
    }
    catch (...)
    {
        cout << "process threw exception" << endl;
        if (e != "") cout << "Expected: " << e << endl;
        else cout << "Expected: " << r << endl;
    }
}

int main()
{
    test(-1, -1, "Let's not be negative");
    test(0, -1, "No zero please");
    test(30, -1, "logic_error");
    test(32, 1, "");
    test(33, -1, "runtime_error");
    test(34, -1, "runtime_error");
    test(35, -1, "logic_error");
    test(96, 1, "");
}
