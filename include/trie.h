#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstdarg>
class Trie
{
public:
//constroctor

   Trie()
   {
    std::cout<<this<<std::endl;
    root =new Node {'\0',false};
   }
   template <typename ...T>
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
   

   Trie(const Trie& );
// destructor
~Trie()
{   std::cout<<"call distruct"<<std::endl;
    if(root == nullptr) return;
    std::vector<Node*> nodes;
    this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
        std::cout<<"yoooo"<<std::endl;
    for(const auto& node : nodes)
    {
        delete node;
    }
    std::cout<<"endl"<<std::endl;
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

