#include <iostream>
#include <vector>
#include <string>
class Trie
{
public:
//constroctor
   Trie()
   {
    root =new Node {'\0',true};
   }
//Node
class Node
{ 
    public:
    Node(char data , bool is_finished):data{data},
    is_finished{is_finished} {}
    std::vector<Node*> children{};
    char data;
    bool is_finished;
};
// member function
void insert(const std::string& );
//member var
    Node* root;
private:

};

