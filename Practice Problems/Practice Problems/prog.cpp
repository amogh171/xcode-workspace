#include <string>
#include <exception>
#include <stdexcept>

using namespace std;
/*
 Complete this function that passes the argument to the
 mystery function. If the mystery function returns without throwing
 an exception, set result to its result. Otherwise, if the function
 throws a std::invalid_argument exception or std::range_error,
 set error to the what string of the exception object.
 If the function throws a different kind of std::logic_error or
 std::runtime_error, set error to "logic_error" or "runtime_error".
 Otherwise, set error to the string "unknown exception".
 */

int mystery(int x);

void process(int arg, int& result, string& error)
{
    mystery(arg);
}
