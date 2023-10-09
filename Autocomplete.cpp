#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H 

#include <vector> 
#include <string> 

const int alphabetSize = 26; 

class Autocomplete{ 
    private:
        struct Node{
            //address of nodes children
            std::vector<Node*> children; 
            //if end of word then true 
            bool isEndOfWord; 
        }; 

        //root of Autocomplete
        
       
    
    public: 
        Node* root; 
        //constructor setting root's children to nullptr
        Autocomplete();      
    


        //insert function 
        void insert(std::string word); 

        //helper function for get suggestions
        std::vector<std::string> suggestionRecursive(Node* currNode, const std::string currPrefix);

        //get Suggestions main function 
        std::vector<std::string> getSuggestions(std::string partialWord); 





        /***** STRUCTS AND TESTING *****/


        //creates new node intialised with nullptrs
        struct Node* createNode(){
            struct Node* newNode = new Node; 

            for(int i=0; i<alphabetSize; i++){
                newNode->children.push_back(nullptr); 
            }
            newNode->isEndOfWord = false; 
            
            return newNode; 
        }
        
        //for testing
        Node* returnRoot(){
            return root; 
        }
}; 

#endif
