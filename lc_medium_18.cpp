// #lc-medium-18

#include "markers.h"

#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using std::string;
using std::map;
using std::vector;

// Passed 59 test cases on LC.
string longest_word_in_dict(vector<string>& words);

int main()
{
    __BEGIN

    vector<string> dict = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    std::cout << longest_word_in_dict(dict) << std::endl;

    __END
}

struct TrieNode {
    char ch;
    bool word_end;
    map<char, TrieNode *> children;
    TrieNode(): ch('\0'), word_end(false) {}
};

template<typename T>
T *allocate()
{
    T *p = new T;
    if (p == nullptr) std::exit(1);
    return p;
}

void trie_search_dfs_rec(TrieNode *current, string prefix, string &longest)
{
    if (current == nullptr || !current->word_end) return;

    if (longest.length() < prefix.length()+1)
    {
        longest = prefix+current->ch;
    }

    if (longest.length() == prefix.length()+1 && (prefix+current->ch < longest))
    {
        longest = prefix+current->ch;
    }

    for (auto child : current->children)
    {
        trie_search_dfs_rec(child.second, prefix+current->ch, longest);
    }
}

string trie_search_dfs(TrieNode *root)
{
    if (root == nullptr) return "";

    string longest;
    for (auto child : root->children)
    {
        trie_search_dfs_rec(child.second, "", longest);
    }

    return longest;
}

string longest_word_in_dict(vector<string>& words)
{
    if (words.empty()) return "";

    TrieNode *root = allocate<TrieNode>();
    for (const string& word : words)
    {
        if (word.empty()) continue;

        TrieNode *current = root;
        for (char ch : word)
        {
            map<char, TrieNode *>::iterator res = current->children.find(ch);
            if (res == current->children.end())
            {
                TrieNode *new_node = allocate<TrieNode>();
                new_node->ch = ch;
                current->children[ch] = new_node;
                current = new_node;
            }
            else
            {
                current = res->second;
            }
        }
        current->word_end = true;
    }

    return trie_search_dfs(root);
}
