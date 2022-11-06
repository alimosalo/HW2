#include <iostream>
#include "trie.h"
int main(void)
{

    Trie::Node node{'a',false};
    Trie::Node child1{'b',true};
    Trie::Node child2{'c',false};
    node.children.push_back(&child1);
    Trie trie {};
    trie.insert("there");
    trie.insert("does");
    trie.insert("that");
    std::cout<<trie.root->children.size()<<std::endl;
    std::cout<<trie.root->children[0]->children[0]->children[0]->data<<std::endl;

}