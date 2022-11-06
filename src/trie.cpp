#include "trie.h"
void Trie::insert(const std::string& str)
{
    // for(size_t i{};i<str.length();i++)
    Node* a{root};
    for(size_t i{};i<str.length();i++)
    {
        a->children.push_back(new Node{str[i],false});
        a = a->children[0];
        
    }
}