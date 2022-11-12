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
            if(i==str.length()-1)
                a->is_finished=true;
        }
    }
    //other times 
    Node* b{root};
    int counter{};
    size_t c{};
    bool same;
    bool first{true} ;
    bool loop_end{false};
    std::cout<<"string length: "<<str.length()<<std::endl;
    if(init!=0)
    {
        for(size_t i{};i<str.length();i++)
        {
            same =false ; 
            if(loop_end==false)
            {
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
            if(i==str.length()-1)
            {
                b->is_finished = true;
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
    {
        std::cout<<"there are same"<<std::endl;
        return true;
    }
    return false;
}
void Trie::bfs(std::function<void(Node*& node)> func)
{
    Node* _root{root};
    Node* next{root}; 
    std::vector <Node*> b; 
    
    size_t counter{};
    b.push_back(next);
    size_t i{} ;
    size_t saver{};
    while((_root=b[counter]))
    {
        for(auto x:_root->children)
        {
            std::cout<<x->data<<std::endl;
            if(x==nullptr) {break;}
            b.push_back(x);
            
        }
        std::cout<<"end"<<std::endl;
        counter++;
    }
       std::cout<<b.size()<<std::endl; 
    for(auto x:b)
    {
        func(x);
    }
    
}
Trie::Trie(const Trie& trie)
{
    size_t counter{};
    Node * copy{new Node{'\0',false}};
    Node * a{copy};
    Node * main{trie.root};
    std::vector<Node*> copy_vec;
    std::vector<Node*> vec;
    for(int i{};i<main->children.size();i++)
    {
        copy->children.push_back(new Node{main->children[i]->data,main->children[i]->is_finished});
    std::cout<<copy->children[i]->data<<std::endl;
        copy_vec.push_back(copy->children[i]);
        vec.push_back(main->children[i]);
        if(main->children[i+1]==nullptr)
        {
            while(vec[counter]->is_finished==true)
            {
                std::cout<<"end: "<<vec[counter]->data<<std::endl;
                counter++;
                if(vec[counter+1]==nullptr)
                {break;}
            }
            copy=copy_vec[counter];
            main=vec[counter];
            
            counter++ ; 
            i =-1 ; 
        }
    } 
    root =a ;

}




