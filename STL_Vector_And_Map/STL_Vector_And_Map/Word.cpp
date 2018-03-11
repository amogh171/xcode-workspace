#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}

Word::Word(string text) : text(text), count(1) {}

int Word::get_count()
{
    return count;
}

string Word::get_text()
{
    return text;
}

void Word::increase_count()
{
    count++;
}

bool Word::operator != (Word word)
{
    return (text != word.text || count != word.count);
}

bool Word::operator == (Word word)
{
    return (text == word.text && count == word.count);
}

Word::~Word() {}

