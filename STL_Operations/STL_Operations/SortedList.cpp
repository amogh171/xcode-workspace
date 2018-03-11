#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return static_cast<int>(data.size()); }

bool SortedList::check()
{
    if (data.size() == 0) return true;
    
    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;
    
    it++;
    
    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }
    
    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.push_front(node);
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
    Node node(value);
    data.push_back(node);
}

void SortedList::remove(const int index)
{
    /***** Complete this function. *****/
    list<Node>::iterator it;
    int find = 0;
    for(it = data.begin(); it!= data.end(); it++)
    {
        if(find == index)
        {
            data.erase(it);
            return;
        }
        find++;
    }
}

void SortedList::insert(const long value)
{
    /***** Complete this function. *****/
    list<Node>::iterator it;
    Node node(value);
    if (data.size() == 0)
    {
        data.push_back(node);
        return;
    }
    else
    {
        for(it = data.begin(); it != data.end() && value >= it->get_value(); it++)
        {
            if(value == it->get_value())
            {
                return;
            }
        }
    }
    data.insert(it, node);
    
}

Node SortedList::at(const int index)
{
    /***** Complete this function. *****/
    
    
    list<Node>::iterator it = data.begin();
    for(int i = 0; i< index && it != data.end(); i++)
    {
        it++;
    }
    return *it;
}

