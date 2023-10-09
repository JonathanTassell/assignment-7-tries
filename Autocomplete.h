#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <iostream>
#include <string>

const int alphabetSize = 26; 

class Autocomplete{
    private:
        struct Node{
            std::vector<Node*> children; 
            bool endOfWord; 
        }; 

        Node* root; 
    
    public:
        Autocomplete(); 

        void insert(std::string word); 

        void printNode(int num); 

        std::vector<std::string> suggestionRecursive(Node* currNode, const std::string currPrefix);

        std::vector<std::string> getSuggestions(std::string partialWord); 

        //initialises
        struct Node* createNode(){
            struct Node* newNode = new Node; 

            for(int i=0; i<alphabetSize; i++){
                newNode->children.push_back(nullptr); 
            }
            newNode->endOfWord = false; 
            
            return newNode; 
        }


}; 

#endif
