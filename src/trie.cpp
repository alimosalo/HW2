#include "trie.h"
void Trie::insert(const std::string& str)
{
    Node*  a {root};
    auto init{root->children.size()};
    for(size_t i{};i<str.length();i++)
    {
        // flag =false;
        // for(size_t j{};j<a->children.size();j++)
        // {
        //     // if(a->children[j]->data==str[i])
        //     // {
        //     //     a= a->children[j];
        //     //     flag=true;
        //     //     std::cout<<a->data<<std::endl;
        //     //     counter++;
        //     //     break;
        //     // }
        // }
        if(init==0)
            a->children.push_back(new Node{str[i],false});
            a = a->children[0];
        
    }
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
            for(size_t j{};j<b->children.size();j++)
            {
                if(b->children[j]->data==str[i])
                {
                    b = b->children[j] ; 
                     counter++;
                     
                     same=true;
                }    break; 
            }
            }
            if(same==false)
            {
                if(first==true)
                {
                b->children.push_back(new Node{str[i],false});
                std::cout<<"size_of:"<<str<<';'<<b->children.size()<<std::endl;
                b = b->children[b->children.size()-1];
                    std::cout<<"first: "<<str[i]<<std::endl;

                first = false; 
                loop_end = true; 
                }
                else{
                    b->children.push_back(new Node{str[i],false});
                    std::cout<<str[i]<<std::endl;
                    b = b->children[0];
                    

                }
            }
        }
    }       
        std::cout<<str<<':'<<counter<<std::endl;
        std::cout<<"//////////"<<std::endl;
        
}
