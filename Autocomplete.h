// collaborated with Armaan Bahree a1843711 and Aiden Martin a1702878
#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <string>
#include <vector>

const int MAX_NODE = 26;
class TrieNode {
public:
    std::vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
};

class Autocomplete {
private:
    TrieNode* root;
    void insertHelper(TrieNode* node, std::string word);
    void getSuggestionsHelper(TrieNode* node, std::string partialWord, std::vector<std::string>& suggestions);
public:
    Autocomplete();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
};
#endif
      
    
    

