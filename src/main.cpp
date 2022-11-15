#include <iostream>
#include <gtest/gtest.h>
#include "trie.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        Trie copy{"well","copy"};
        Trie main{copy};
        copy.root->children[1]->data = 'b';
        std::cout<<main.root->children[1]->data<<std::endl;
        std::cout<<copy.root->children[1]->data<<std::endl;

    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    
}