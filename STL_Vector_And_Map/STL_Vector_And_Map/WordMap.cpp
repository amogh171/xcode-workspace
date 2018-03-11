#include <iostream>
#include <map>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{
    /***** Complete this member function. *****/
}

WordMap::~WordMap()
{
    /***** Complete this member function. *****/
}

/**
 * Insert a new word into the map,
 * or increment the count of an existing word.
 * @param text the text of the word to insert or increment.
 * @return a pointer to the word entry.
 */
Word *WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
    //Word *word = new Word(text);
    
//    if (data.find(text) == data.end())
//    {
//        //data.insert ( std::pair<string, Word> (text, *word)); //check this
//        data[text] = Word(text);
//    }
//    else if (data.find(text) != data.end())
//    {
//        data[text].increase_count();
//    }
//    return &data[text];
    
    std::pair<map<string, Word>::iterator,bool> ret;
    ret = data.insert(std::pair<string, Word>(text, Word(text)));
    
    if(ret.second == false) //text already exists
    {
        ret.first->second.increase_count();
    }    
    return &(ret.first->second);
   
}

/**
 * Search the map for a word entry with the given text.
 * @param text the text of the word to find.
 * @return a pointer to the word entry if found, nullptr if not.
 */
Word *WordMap::search(const string text)
{
    /***** Complete this member function. *****/
    auto temp = data.find(text);
    return temp != data.end() ? &(temp->second) : nullptr;
}

long WordMap::get_size()
{
    return data.size();
}

map<string, Word>& WordMap::get_data()
{
    return data;
}

