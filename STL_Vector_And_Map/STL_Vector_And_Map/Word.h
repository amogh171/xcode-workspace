#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/***** Modify this file as needed. *****/

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word(); // Done
    
    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text); //Done
    
    /*
     * getter
     * returns the count of the word
     */
    int get_count(); //Done
    
    /*
     * getter
     * returns the text (string) of the word
     */
    string get_text(); //Done
    
    /*
     * overloaded != operator
     */
    bool operator != (Word word); //Done
    
    /*
     * overlaoded == operator
     */
    bool operator == (Word word);
    
    /*
     * Setter
     * increment count value by 1
     */
    void increase_count();    
    
    /**
     * Destructor.
     */
    virtual ~Word(); //Empty Done
    
private:
    string text;
    int count;
};

#endif /* WORD_H_ */

