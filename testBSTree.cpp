#include<iostream>
#include "BSTree.h"

int main()
{
    std::cout << "Creating BSTree<int> bstree ..." << std::endl;
    BSTree<int> bstree = BSTree<int>();
    std::cout << std::endl; 

    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    
    std::cout << "bstree.insert(15)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(15);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(15): ";
                      std::cout << bstree.search(15) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(7)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.insert(7);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(7): ";
                      std::cout << bstree.search(7) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(3)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.insert(3);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(3): ";
                      std::cout << bstree.search(3) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(11)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(11);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(11): ";
                      std::cout << bstree.search(11) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(9)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.insert(9);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(9): ";
                      std::cout << bstree.search(9) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(18)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(18);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(18): ";
                      std::cout << bstree.search(18) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(21)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(21);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(21): ";
                      std::cout << bstree.search(21) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    std::cout << "bstree.insert(20)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(20);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(20): ";
                      std::cout << bstree.search(20) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    try {
        bstree.search(0);
        std::cout << "bstree.search(0) => ERROR! It did not throw std::runtime_error... :(" << std::endl;
    } catch(std::runtime_error &e) {
        std::cout << "bstree.search(0) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        bstree.search(9);
        std::cout << "bstree.search(9) => OK! It did not throw std::runtime_error." << std::endl;
    } catch(std::runtime_error &e) {
        std::cout << "bstree.search(9) => ERROR! It throwed std::runtime_error :( " << std::endl;
    }

    try {
        bstree.insert(9);
        std::cout << "bstree.insert(9) => ERROR! It did not throw std::runtime_error... :(" << std::endl;
    } catch(std::runtime_error &e) {
         std::cout << "bstree.insert(9) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        bstree.remove(50);
        std::cout << "bstree.remove(50) => ERROR! It did not throw std::runtime_error... :(" << std::endl;
    } catch(std::runtime_error &e) {
        std::cout << "bstree.remove(50) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    std::cout << std::endl; 

    std::cout << "bstree.remove(9)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.remove(9);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << "bstree.insert(9)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.insert(9);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << std::endl; 

    std::cout << "bstree.remove(11)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.remove(11);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << "bstree.insert(11)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(11);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << std::endl; 

    std::cout << "bstree.remove(7)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.remove(7);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << "bstree.insert(7)" << std::endl;
    std::cout << "----------------" << std::endl;
    bstree.insert(7);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << std::endl; 

    std::cout << "bstree.remove(15)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.remove(15);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 
    std::cout << "bstree.insert(15)" << std::endl;
    std::cout << "-----------------" << std::endl;
    bstree.insert(15);
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    std::cout << std::endl; 

    return 0;
}
