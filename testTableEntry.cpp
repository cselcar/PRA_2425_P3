#include <iostream>
#include "TableEntry.h"

int main(){
    std::cout << std::boolalpha; // configuramos cout para mostrar true/false en lugar de 0/1.

    TableEntry<int> e1("Catorze", 14);
    TableEntry<int> e2("Trenta-tres", 33);
    TableEntry<int> e3("Trenta-tres", 123);

    std::cout << "e1: " << e1 << std::endl;
    std::cout << "e2: " << e2 << std::endl;
    std::cout << "e3: " << e3 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "e1 == e2 ? " << (e1 == e2) << std::endl;
    std::cout << "e1 != e2 ? " << (e1 != e2) << std::endl;
    std::cout << std::endl;
    std::cout << "e1 == e3 ? " << (e1 == e3) << std::endl;
    std::cout << "e1 != e3 ? " << (e1 != e3) << std::endl;
    std::cout << std::endl;
    std::cout << "e2 == e3 ? " << (e2 == e3) << std::endl;
    std::cout << "e2 != e3 ? " << (e2 != e3) << std::endl;
    return 0;
}
