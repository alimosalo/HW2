#include <iostream>
#include <vector>
class Trie
{
public:
class Node
{
    public:
    Node(char data , bool is_finished);
    std::vector<Node*> childern;
    char data ;
    bool is_finished;
};
    Node* root;
private:

};
#endif
