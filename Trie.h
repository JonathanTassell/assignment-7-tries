#ifndef TRIE_H
#define TRIE_H 

#include <vector> 
#include <string> 

const int alphabetSize = 26; 

class Trie{ 
    private:
        struct trieNode{
            //address of nodes child/children
            std::vector<trieNode*> children; 
            //if end of word then true 
            bool isEndOfWord; 
        }; 

        //root of Trie
        trieNode* root; 
       
    
    public: 

        //constructor setting root's children to nullptr
        Trie();      
    


        //insert function 
        void insert(std::string word); 

        //helper function for get suggestions
        std::string suggestionRecursive(trieNode* currNode, const std::string currPrefix);

        //get Suggestions main function 
        std::vector<std::string> getSuggestions(std::string partialWord); 





        /***** STRUCTS AND TESTING *****/


        //creates new node intialised with nullptrs
        struct trieNode* createNode(){
            struct trieNode* newNode = new trieNode; 

            for(int i=0; i<alphabetSize; i++){
                newNode->children.push_back(nullptr); 
            }
            newNode->isEndOfWord = false; 
            
            return newNode; 
        }
        
        //for testing
        trieNode* returnRoot(){
            return root; 
        }
}; 

#endif