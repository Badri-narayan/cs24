//
//  word.cpp
//  
//
//  Created by Badri Tulsiram on 10/27/18.
//

#include "word.hpp"

Word::Word(){
    this -> word = word; 
}

void Word::set_word(string word1){
    word=word1;
}

void Word::set_bag(bag& word1bag){
    this_bag = new bag(word1bag);
    
}

string Word::get_word(){
    return word;
}

bag* Word::get_bag() {
    return this_bag;
}
