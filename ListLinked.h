#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first;
        int n;

    public:
        ListLinked(){
            first = nullptr;
            n = 0;
        }

        ~ListLinked(){
            Node<T>* aux = first;
            while(aux != nullptr){
                Node<T>* temp = aux->next;
                delete aux;
                aux = temp;
            }
        }

        T operator[](int pos){
            return get(pos);
        }

        void insert(int pos, T e) override {
            if(pos < 0 || pos > n){
                throw std::out_of_range("Posición fuera de rango");
            }
            
            Node<T>* nuevo = new Node<T>(e);
            
            if(pos == 0){
                nuevo->next = first;
                first = nuevo;
            } else {
                Node<T>* aux = first;
                for(int i = 0; i < pos - 1; i++){
                    aux = aux->next;
                }
                nuevo->next = aux->next;
                aux->next = nuevo;
            }
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        T remove(int pos) override {
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posición fuera de rango");
            }
            
            T elemento;
            Node<T>* toDelete;
            
            if(pos == 0){
                toDelete = first;
                elemento = first->data;
                first = first->next;
            } else {
                Node<T>* aux = first;
                for(int i = 0; i < pos - 1; i++){
                    aux = aux->next;
                }
                toDelete = aux->next;
                elemento = toDelete->data;
                aux->next = toDelete->next;
            }
            
            delete toDelete;
            n--;
            return elemento;
        }

        T get(int pos) override {
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posición fuera de rango");
            }
            
            Node<T>* aux = first;
            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override {
            Node<T>* aux = first;
            for(int i = 0; i < n; i++){
                if(aux->data == e){
                    return i;
                }
                aux = aux->next;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
            out << "[";
            Node<T>* aux = list.first;
            while(aux != nullptr){
                out << aux->data;
                if(aux->next != nullptr){
                    out << ", ";
                }
                aux = aux->next;
            }
            out << "]";
            return out;
        }
};

#endif
