#include "Autocomplete.h"

Autocomplete::Autocomplete(){
    root = createNode();  
}

void Autocomplete::insert(std::string word){
        Node* currNode = root; 
        
    
    for (size_t i = 0; i < word.length(); i++) {
        int index = word.at(i) - 'a'; 
        
        if (!currNode->children.at(index)) {
            std::cout << "hi"; 
            currNode->children.at(index) = new Node; 
            currNode = currNode->children.at(index); 
        }
        else {
            currNode = currNode->children.at(index); 
        }
    }
    currNode->endOfWord = true;
}



void Autocomplete::printNode(int num){
    if(root->children.at(num) == nullptr)
        return; 

    Node* currNode = root->children.at(num); 
    
    for(int i=0; i<26; i++){
        if(currNode->children.at(i)){
            if(currNode->endOfWord)
                return;
            currNode = currNode->children.at(i); 
            std::cout << std::to_string(i + 'a') << " "; 
        }
    }

}