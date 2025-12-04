#include<iostream>
#include "HashTable.h"

int main() {
    HashTable<int> dict = HashTable<int>(3);

    std::cout << dict << std::endl;
    std::cout << "dict.capacity(): " << dict.capacity() << std::endl;
    std::cout << "dict.entries(): " << dict.entries() << std::endl; 
    std::cout << std::endl; 

    std::cout << "dict.insert('One', 1) ..." << std::endl;
    dict.insert("One", 1);
    std::cout << "dict.insert('Two', 2) ..." << std::endl;
    dict.insert("Two", 2);
    std::cout << "dict.insert('Three', 3) ..." << std::endl;
    dict.insert("Three", 3);
    std::cout << "dict.insert('Four', 4) ..." << std::endl;
    dict.insert("Four", 4);
    std::cout << "dict.insert('Five', 5) ..." << std::endl;
    dict.insert("Five", 5);
    std::cout << "dict.insert('Six', 6) ..." << std::endl;
    dict.insert("Six", 6);
    std::cout << std::endl; 

    std::cout << std::endl << dict << std::endl;

    std::cout << "dict.search('One'): " << dict.search("One") << std::endl;
    std::cout << "dict['Four']: " << dict["Four"] << std::endl;
    std::cout << "dict.remove('Three'): " << dict.remove("Three") << std::endl;
    std::cout << std::endl; 

    std::cout << std::endl << dict << std::endl;

    try {
        dict.insert("One", 44);
        std::cout << "Oooops! dict.insert('One') did not throw std::runtime_error... :(" << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "dict.insert('One') => throwed std::runtime_error: " << e.what() << std::endl; 
    }

    try {
        dict.search("Ten");
        std::cout << "Oooops! dict.search('Ten') did not throw std::runtime_error... :(" << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "dict.search('Ten') => throwed std::runtime_error: " << e.what() << std::endl; 
    }

    try {
        dict.remove("Ten");
        std::cout << "Oooops! dict.remove('Ten') did not throw std::runtime_error... :(" << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "dict.remove('Ten') => throwed std::runtime_error: " << e.what() << std::endl; 
    }

    return 0;
}
