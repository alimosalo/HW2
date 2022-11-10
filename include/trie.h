#include <iostream>
#include <vector>
#include <string>
#include <functional>
class Trie
{
public:
//constroctor
   Trie()
   {
    root =new Node {'\0',false};
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
bool search(const std::string& );
void bfs(std::function<void(Node*& node)> func);
//member var
    Node* root;
private:

};

