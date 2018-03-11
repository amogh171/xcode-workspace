#include "TimedContainer.h"
#include "Word.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

/***** Modify this file as needed. *****/

TimedContainer::TimedContainer(): elapsed_time(0) {}

long TimedContainer::get_elapsed_time() const
{
    return elapsed_time;
}

void TimedContainer::reset_elapsed_time()
{
    elapsed_time = 0;
}

void TimedContainer::increment_elapsed_time(long x)
{
    elapsed_time += x;
}

Word *TimedContainer::timed_insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();
    
    // Do the insertion.
    Word *word = insert(text);
    
    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
    
    return word;
}

Word *TimedContainer::timed_search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();
    
    // Do the search.
    Word *word = search(text);
    
    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);
    
    return word;
}

TimedContainer::~TimedContainer()
{
    
}

