#include "PrefixMatcher.h"

struct PrefixMatcher::TrieNode{
    TrieNode* children[2];
    int routerNumber;
    //std::cout

    TrieNode(){
        children[0] = nullptr;
        children[1] = nullptr;
        routerNumber = -1;
    }
};

PrefixMatcher::PrefixMatcher(){
    root = new TrieNode();
}

void PrefixMatcher::insert(std::string address, int routerNumber){
    TrieNode* currentNode = root;

    for (char bit : address){
        int index = bit - '0';
        if (!currentNode->children[index]){
            currentNode->children[index] = new TrieNode();
        }
        currentNode = currentNode->children[index];
    }

    currentNode->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress){
    TrieNode* currentNode = root;
    int selectedRouter = -1;

    for (char bit : networkAddress){
        int index = bit - '0';
        if (!currentNode->children[index]){
            break;
        }
        currentNode = currentNode->children[index];


        if (currentNode->routerNumber != -1){
            selectedRouter = currentNode->routerNumber;
        }
    }
    return selectedRouter;
}