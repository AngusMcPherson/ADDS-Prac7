// collaborated with Armaan Bahree a1843711 and Aiden Martin a1702878
#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>
#include <iostream>

const int MAX_NODE = 2;

class TrieNodes {
public:
    TrieNodes* children[MAX_NODE];
    int routerNumber;
    TrieNodes();
};

class PrefixMatcher {
private:
    TrieNodes* root;
    void insertHelper(TrieNodes* node, std::string address, int routerNumber);
    int selectRouterHelper(TrieNodes* node, std::string address);
public:
    PrefixMatcher();
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};
#endif