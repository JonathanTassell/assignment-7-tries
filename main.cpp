#include "Autocomplete.h"
#include <iostream>

int main(){
    std::vector<std::string> suggestions; 

    Autocomplete trie; 
    trie.insert("hell"); 
    trie.insert("help"); 
    trie.insert("heal"); 
    trie.insert("hellish"); 

    std::cout << trie.getSuggestions("h").at(3); 
    

}
