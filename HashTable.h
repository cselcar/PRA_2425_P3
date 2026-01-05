#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        List<TableEntry<V>>** table;
        
        int h(std::string key){
            int sum = 0;
            for (size_t i = 0; i < key.length(); i++) {
                sum += int(key.at(i));
            }
            return sum % max;
        }

    public:
        HashTable(int size){
            n = 0;
            max = size; 
            table = new List<TableEntry<V>>*[size];
            for(int i = 0; i < size; i++){
                table[i] = new ListLinked<TableEntry<V>>();
            }
        }
        
        ~HashTable() {
            for(int i = 0; i < max; i++){
                delete table[i];
            }
            delete [] table;
        }
        
        int capacity() {
            return max;
        }
        
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "============" << std::endl << std::endl;
            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==" << std::endl << std::endl;
                out << "List => [" << th.table[i]->size() << " elementos]" << std::endl << std::endl;
            }
            out << "=============" << std::endl << std::endl;
            return out;	
        }
        
        V operator[](std::string key) {
            return search(key);
        }

        void insert(std::string key, V value) override {
            int pos = h(key);
            List<TableEntry<V>>* posicion = table[pos];

            for (int i = 0; i < posicion->size(); i++) {
                if (posicion->get(i).key == key) {
                    throw std::runtime_error("Clave ya existe: " + key);
                }
            }
            posicion->prepend(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            int idx = h(key);
            List<TableEntry<V>>* posicion = table[idx];
            
            for (int i = 0; i < posicion->size(); i++) {
                TableEntry<V> entry = posicion->get(i);
                if (entry.key == key) {
                    return entry.value;
                }
            }
            throw std::runtime_error("Clave no encontrada: " + key); 
        }

        V remove(std::string key) override {
            int pos = h(key);
            List<TableEntry<V>>* posicion = table[pos];
            
            for (int i = 0; i < posicion->size(); i++) {
                TableEntry<V> entry = posicion->get(i);
                if (entry.key == key) {
                    V value = entry.value;
                    posicion->remove(i);
                    n--;
                    return value;
                }
            }
            
            throw std::runtime_error("Clave no encontrada: " + key);
        }

        int entries() override {
            return n;
        }        
};

#endif
