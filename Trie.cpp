#include "Trie.h"
#include <iostream> 

Trie::Trie(){
    root = createNode(); 
}

void Trie::insert(std::string word){
    trieNode* currNode = root; 

    for(size_t i=0; i<word.length(); i++){
        int index = word[i] - 'a'; 
        if(!currNode->children[index])
            currNode->children[index] = createNode(); 
        
        //stores index's letter into child relative to letter number (for testing)
        // currNode->children.at(index)->letter = word[i]; 

        currNode = currNode->children[index]; 
    }
    currNode->isEndOfWord = true; 
}

std::string Trie::suggestionRecursive(trieNode* currNode, const std::string currPrefix) {

    if(currNode->isEndOfWord) {
        return currPrefix;
    }

    for(int i = 0; i < alphabetSize; i++) {
        if(currNode->children.at(i) != nullptr && currPrefix.at(0) ==  'a'+i) {
            char child = 'a' + i;
            std::cout << i << " " << currNode->isEndOfWord << std::endl;
            if(currNode->children.at(i)->isEndOfWord != 1)
                return suggestionRecursive(currNode->children.at(i), currPrefix + child);
        }
    }

    return "";
}


std::vector<std::string> Trie::getSuggestions(std::string partialWord) {

}


