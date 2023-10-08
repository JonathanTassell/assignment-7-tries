#include "Trie.h"
#include <iostream>

int main(){
    std::vector<std::string> suggestions; 

    Trie trie; 
    trie.insert("hell"); 
    trie.insert("help"); 
    trie.insert("heal"); 
    trie.insert("hellish"); 
    



    std::string word = trie.suggestionRecursive(trie.returnRoot(), "h"); 

    std::cout << word; 
}