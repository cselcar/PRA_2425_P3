#include "BSTreeDict.h"
#include<iostream>

int main() {
        std::cout << "Creating BSTreeDict<int> dict ..." << std::endl;
	BSTreeDict<int> dict = BSTreeDict<int>();
	std::cout << std::endl; 

	std::cout << "dict.entries(): " << dict.entries() << std::endl; 				    
        std::cout << "cout << dict: " << std::endl << dict << std::endl;
	std::cout << std::endl; 

	std::cout << "dict.insert('c', 3) ..." << std::endl;
	dict.insert("c", 3);
	std::cout << "dict.insert('f', 6) ..." << std::endl;
	dict.insert("f", 6);
	std::cout << "dict.insert('a', 1) ..." << std::endl;
	dict.insert("a", 1);
	std::cout << "dict.insert('b', 2) ..." << std::endl;
	dict.insert("b", 2);
	std::cout << "dict.insert('d', 4) ..." << std::endl;
	dict.insert("d", 4);
	std::cout << "dict.insert('e', 5) ..." << std::endl;
	dict.insert("e", 5);
	std::cout << std::endl;

        std::cout << "cout << dict: " << std::endl << dict << std::endl;

	std::cout << "dict.search('a'): " << dict.search("a") << std::endl;
	std::cout << "dict['d']: " << dict["d"] << std::endl;
	std::cout << "dict.remove('c'): " << dict.remove("c") << std::endl;
	std::cout << std::endl; 
	std::cout << std::endl << dict << std::endl;
        try {
		dict.insert("a", 44);
		std::cout << "ERROR! dict.insert('a') did not throw std::runtime_error... :(" << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << "dict.insert('a') => OK! throwed std::runtime_error: " << e.what() << std::endl; 
	}
	try {
		dict.search("j");
		std::cout << "ERROR! dict.search('j') did not throw std::runtime_error... :(" << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << "dict.search('j') => OK! throwed std::runtime_error: " << e.what() << std::endl; 
	}
	try {
		dict.remove("c");
		std::cout << "ERROR! dict.remove('c') did not throw std::runtime_error... :(" << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << "dict.remove('c') => OK! throwed std::runtime_error: " << e.what() << std::endl;										
	}
	return 0;
}
