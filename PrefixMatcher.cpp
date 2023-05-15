// collaborated with Armaan Bahree a1843711 and Aiden Martin a1702878
#include <string>
#include <iostream>

#include "PrefixMatcher.h"

using namespace std;

TrieNodes::TrieNodes() {
    for (int i = 0; i < MAX_NODE; i++) {
        children[i] = nullptr;
    }
    routerNumber = -1;
}

void PrefixMatcher::insertHelper(TrieNodes* node, string address, int routerNumber) {
    for (char c : address) {
        int index = c - '0';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNodes();
        }
        node = node->children[index];
    }
    node->routerNumber = routerNumber;
}

int  PrefixMatcher::selectRouterHelper(TrieNodes* node, string address) {
    int routerNumber = node->routerNumber;
    for (char c : address) {
        int index = c - '0';
        if (node->children[index] == nullptr) {
            break;
        }
        node = node->children[index];
        if (node->routerNumber != -1) {
            routerNumber = node->routerNumber;
        }
    }
    return routerNumber;
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNodes();
}

    void PrefixMatcher::insert(string address, int routerNumber) {
    insertHelper(root, address, routerNumber);
}

    int PrefixMatcher::selectRouter(string networkAddress) {
    return selectRouterHelper(root, networkAddress);
}