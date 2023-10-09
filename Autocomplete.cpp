#include "Autocomplete.h"
#include <iostream> 

Autocomplete::Autocomplete(){
    root = createNode(); 
}

void Autocomplete::insert(std::string word){
    Node* currNode = root; 

    for(size_t i=0; i<word.length(); i++){
        int index = word[i] - 'a'; 
        if(!currNode->children[index])
            currNode->children[index] = createNode(); 

        currNode = currNode->children[index]; 
    }
    currNode->isEndOfWord = true; 
}

std::vector<std::string> Autocomplete::suggestionRecursive(Node* currNode, const std::string prefix){
    std::vector<std::string> suggestions;

    if(currNode->isEndOfWord){
        suggestions.push_back(prefix);
    }


    for(int i = 0; i < 26; i++){
        if(currNode->children.at(i)){
            
            char nextChar = static_cast<char>('a' + i);
            std::string nextPrefix = prefix + nextChar;

            //Using 
            std::vector<std::string> childSuggestions = suggestionRecursive(currNode->children.at(i), nextPrefix);
            suggestions.insert(suggestions.end(), childSuggestions.begin(), childSuggestions.end());
        }
    }

    return suggestions;
}


std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    std::vector<std::string> suggestions;
    Node* currNode = root;

    for(size_t i = 0; i < partialWord.length(); i++){
        int index = partialWord.at(i) - 'a';
        if (!currNode->children.at(index)){
            return suggestions;
        }
        currNode = currNode->children.at(index);
    }

    suggestions = suggestionRecursive(currNode, partialWord);

    return suggestions;
}


