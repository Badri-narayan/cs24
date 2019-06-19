//
//  word.hpp
//  
//
//  Created by Badri Tulsiram on 10/27/18.
//

#ifndef word_hpp
#define word_hpp

#include "bag.h"

class Word {

public:
    //constructor
    Word();
    //modifiers
    void set_word(string word1);
    void set_bag(bag& word1bag);
    
    //observers
    string get_word();
    bag* get_bag();
    
private:
    string word;
    bag* this_bag;
    
};
#endif /* word_hpp */
