#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <utility>
class Trie
{
public:
//constroctor

   Trie()
   {
    std::cout<<this<<std::endl;
    root =new Node {'\0',false};
   }
   Trie(Trie&&);
   Trie( Trie& );
   template<typename ... T>
   Trie(T&& ... e)
   {
    
    std::vector <std::string> vec; 
    int temp[] = {(vec.push_back(e),0)...};
    root = new Node {'\0',false};
    for(auto x:vec)
    {
        this->insert(x);
    }


   }
   

// destructor
~Trie()
{   
    if(root == nullptr) return;
    std::vector<Node*> nodes;
    this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    for(const auto& node : nodes)
    {
        delete node;
    }
}
//operator
void operator=(const Trie& trie);
void operator=( Trie&& trie);
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

