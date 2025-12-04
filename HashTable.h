#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../P1/PRA_2425_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

template <typename V>
class HashTable: public Dict<V> {

    private:
	    int n;
	    int max;
	    ListLinked<TableEntry<V>>* table;
	    int h(std::string key){
	    	int sum = 0;
        	for (int i = 0; i < key.length(); i++) {
            		sum += int(key.at(i));
        	}
        	return sum % max;
	    }

    public:
	    HashTable(int size){
	    	n = 0;
		max = size; 
	    	table = new ListLinked<TableEntry<V>>[size];
	    }
	    ~HashTable() {
	    	delete [] table;
	    }
	    int capacity() {
	    	return max;
	    }
	    friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
	    	out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << endl;
		out << "============" << endl << endl;
		for (int i = 0; i < th.max; i++) {
            		out << "== Cubeta " << i << " ==" << endl << endl;
            		out << "List => " << th.table[i] << endl << endl;
        	}
		out << "=============" << endl << endl;
        	return out;	
	    }
	    V operator[](std::string key) {
	    	return seach(key);
	    }

	void insert(string key, V value) override{
		int pos = h(key);
        	ListLinked<TableEntry<V>>& posicion = table[pos];

        	for (int i = 0; i < posicion.size(); i++) {
            		if (posicion.get(i).key == key) {
                		throw std::runtime_error("Clave no encontrada: " + key);
            		}
        	}
        	posicion.prepend(TableEntry<V>(key, value));
        	n++;
	}


	V search(string key) override{
		int idx = h(key)
		int pos = table[idx].search(TableEntry<V>(key));
        
        	for (int i = 0; i < posicion.size(); i++) {
            		TableEntry<V> entry = posicion.get(i);
            		if (entry.key == key) {
                		return table[idx].get(pos).value;
            		}
        	}
        	throw std::runtime_error("Clave no encontrada: " + key); 
	}


	V remove(string key) override{
		int pos = h(key);
        	ListLinked<TableEntry<V>>& posicion = table[pos];
        
        	for (int i = 0; i < posicion.size(); i++) {
            		TableEntry<V> entry = posicion.get(i);
            		if (entry.key == key) {
                		V value = entry.value;
                		posicion.remove(i);
                		n--;
                		return value;
            		}
        	}
    
        	throw std::runtime_error("Clave no encontrada: " + key);
	}


	int entries() override{
		return n;
	}        

};

#endif
