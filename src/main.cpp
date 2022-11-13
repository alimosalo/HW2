#include <iostream>
#include <vector>
#include "trie.h"
template <class... E>
void X(E&&... e) {
    std::vector <std::string> v; 
    int temp[] = {(v.push_back(e), 0)...};
    std::cout<<v[0]<<std::endl;
}
int main(void)
{
    Trie trie{"guy"};
    trie.insert("thatwwe");
    trie.insert("green");
    trie.insert("well");
    // std::vector<Trie::Node*>nodes; 
    // trie.bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    // std::cout<<nodes.size()<<std::endl;
    Trie tree{};

    tree = Trie{"fill","good"};
    Trie truee("ller","test");
    // std::cout<<tree.root->children[0]->data<<std::endl;


}