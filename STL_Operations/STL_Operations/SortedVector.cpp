#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return static_cast<int>(data.size()); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;
    
    vector<Node*>::const_iterator it = data.begin();
    vector<Node*>::const_iterator prev = it;
    
    it++;
    
    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }
    
    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
    Node *node = new Node(value);
    vector<Node*>::iterator it = data.begin();
    data.insert(it, node);
    
}

void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
    Node *node = new Node(value);
    data.push_back(node);
}

void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
    vector<Node*>::iterator it ;
    int find = 0;
    for(it = data.begin(); it != data.end(); it++)
    {
        if(find == index)
        {
            data.erase(it);
            return;
        }
        find++;
    }
}

void SortedVector::insert(const long value)
{
    /***** Complete this function. *****/
    
    vector<Node*>::iterator it;
    Node *node = new Node(value);
    if (data.size() == 0)
    {
        data.push_back(node);
        return;
    }
    else
    {
        for(it = data.begin(); it != data.end() && value >= (*it)->get_value(); it++)
        {
            if(value == (*it)->get_value())
            {
                return;
            }
        }
    }
    data.insert(it, node);
}

Node* SortedVector::at(const int index) const
{
    /***** Complete this function. *****/
    
    return data[index];
}

