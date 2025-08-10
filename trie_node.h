#ifndef PREP_TRIE_NODE_H
#define PREP_TRIE_NODE_H

#include <map>
using std::map;

struct TrieNode {
    char ch;
    bool word_end;
    map<char, TrieNode *> children;
    TrieNode(): ch('\0'), word_end(false) {}
};

#endif // PREP_TRIE_NODE_H
