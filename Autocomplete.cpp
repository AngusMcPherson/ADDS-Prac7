// collaborated with Armaan Bahree a1843711 and Aiden Martin a1702878
#include <iostream>
#include <vector>
#include <string>
#include "Autocomplete.h"
using namespace std;

TrieNode::TrieNode()
{
    children = vector<TrieNode *>(MAX_NODE, nullptr);
    isEndOfWord = false;
}

void Autocomplete::insertHelper(TrieNode *node, string word)
{
    int temp = -1;
    for (int i = 0; i < word.length(); i++)
    {
        temp = word[i] - 'a';
        if (node->children[temp] == nullptr)
            node->children[temp] = new TrieNode();
        node = node->children[temp];
    }
    node->isEndOfWord = true;
}

void Autocomplete::getSuggestionsHelper(TrieNode *node, string partialWord, vector<string> &suggestions)
{
    if (node->isEndOfWord)
    {
        suggestions.push_back(partialWord);
    }
    for (int i = 0; i < MAX_NODE; i++)
    {
        if (node->children[i] != nullptr)
            getSuggestionsHelper(node->children[i], partialWord + char('a' + i), suggestions);
    }
}

Autocomplete::Autocomplete()
{
    root = new TrieNode();
}

void Autocomplete::insert(string word)
{
    insertHelper(root, word);
}

vector<string> Autocomplete::getSuggestions(string partialWord)
{
    vector<string> suggestions;
    TrieNode *node = root;
    int p = -1;
    for (int i = 0; i < partialWord.length(); i++)
    {
        p = partialWord[i] - 'a';
        if (node->children[p] == nullptr)
        {
            return suggestions;
        }
        node = node->children[p];
    }
    getSuggestionsHelper(node, partialWord, suggestions);
    return suggestions;
}