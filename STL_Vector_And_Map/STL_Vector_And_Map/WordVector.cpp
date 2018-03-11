#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
    /***** Complete this member function. *****/
}

WordVector::~WordVector()
{
    /***** Complete this member function. *****/
}

/**
 * Insert a new word into the sorted vector,
 * or increment the count of an existing word.
 * @param text the text of the word to insert or increment.
 * @return a pointer to the word entry.
 */
Word *WordVector::insert(const string text)
{
    /***** Complete this member function. *****/
    vector<Word> :: iterator itv = data.begin();
    int i = 0;
//    for(i = 0; i < data.size() && text >= data[i].get_text(); i++)
//    {
//        if (data[i].get_text() == text)
//        {
//            data[i].increase_count();
//            return &(data[i]);
//        }
//        itv++;
//    }
    int low = 0, high = static_cast<int>(data.size()) - 1 , mid;
    while (low <= high)
    {
        mid = (high + low)/2;
        if (data[mid].get_text() == text)
        {
            data[i].increase_count();
            return &(data[mid]);
        }
        else if (text < data[mid].get_text())
        {
            high = mid - 1;
        }
        else if (text > data[mid].get_text())
        {
            low = mid + 1;
        }
    }
    
    
    data.insert(itv, Word(text));
    return &(data[i]);    
}

Word *WordVector::search(const string text) // binary search
{
    /***** Complete this member function. *****/
    
    int low = 0, high = static_cast<int>(data.size()) - 1 , mid;
    while (low <= high)
    {
        mid = (high + low)/2;
        if (data[mid].get_text() == text)
        {
            return &(data[mid]);
        }
        else if (text < data[mid].get_text())
        {
            high = mid - 1;
        }
        else if (text > data[mid].get_text())
        {
            low = mid + 1;
        }
    }
    return nullptr;
}

vector<Word>* WordVector::get_data()
{
    return &data;
}

long WordVector::get_size()
{
    return data.size();
}

