#include "trie.h"
void Trie::insert(const std::string& str)
{
    //first time calling;
    Node*  a {root};
    auto init{root->children.size()};
    if(init==0)
    {
        for(size_t i{};i<str.length();i++)
        {
            a->children.push_back(new Node{str[i],false});
            a = a->children[0];
        }
    }
    //other times 
    Node* b{root};
    int counter{};
    size_t c{};
    bool same;
    bool first{true} ;
    bool loop_end{false};
    if(init!=0)
    {
        for(size_t i{};i<str.length();i++)
        {
            same =false ; 
            if(loop_end==false)
            {
            // std::cout<<"latter"<<std::endl;
            for(size_t j{};j < b->children.size();j++)
            {
                std::cout<<root->children.size()<<"and j= "<<j<<std::endl;
                if(b->children[j]->data==str[i])
                {
                std::cout<<str<<": "<<str[i]<<"=="<<b->children[j]->data<<std::endl;
                    b = b->children[j] ; 
                     counter++;
                     
                     same=true;
                    break; 
                }
            }
            }
            if(same==false)
            {
                if(first==true)
                {
                b->children.push_back(new Node{str[i],false});
                b = b->children[b->children.size()-1];

                first = false; 
                loop_end = true; 
                }
                else{
                    b->children.push_back(new Node{str[i],false});
                    b = b->children[0];
                    

                }
            }
            if(str[i+1]=='\0')
            {
                b->is_finished =true;
            }
        }
    }       
        std::cout<<str<<':'<<counter<<std::endl;
        std::cout<<"//////////"<<std::endl;
        
}
//search function//////////////////////
bool Trie::search(const std::string& query)
{
    Node* a{root};
    bool is_same{false};
    for(size_t i{};i<query.length();i++)
    {
        is_same =false;
        for(size_t j{};j<a->children.size();j++)
        {
                
                if(a->children[j]->data==query[i])
                {
                    std::cout<<query[i]<<"=="<<a->children[j]->data<<std::endl;
                    std::cout<<"is_finished"<<a->is_finished<<std::endl;
                    if(a->children[j]->is_finished==true)
                        std::cout<<"this is the end of it"<<std::endl;
                    if(a->children[j]->is_finished==true)
                        is_same =true;
                    a=a->children[j];
                }
              
            
        }
    }
    if(is_same)
        std::cout<<"there are same"<<std::endl;
        return true;
    return false;
}

