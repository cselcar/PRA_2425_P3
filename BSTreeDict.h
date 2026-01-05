#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSNode.h"
#include "TableEntry.h"

template <typename V> 
class BSTreeDict : public Dict<V> {
    private:
        BSNode<TableEntry<V>>* root;
        int nelem;

        BSNode<TableEntry<V>>* search(BSNode<TableEntry<V>>* n, std::string key) const {
            if (n == nullptr) {
                throw std::runtime_error("Key not found!");
            } else if (n->elem.key < key) {
                return search(n->right, key);
            } else if (n->elem.key > key) {
                return search(n->left, key);
            } else {
                return n;
            }
        }

        BSNode<TableEntry<V>>* insert(BSNode<TableEntry<V>>* n, std::string key, V value) {
            if (n == nullptr) {
                nelem++;
                return new BSNode<TableEntry<V>>(TableEntry<V>(key, value));
            } else if (n->elem.key == key) {
                throw std::runtime_error("Key already exists!");
            } else if (n->elem.key < key) {
                n->right = insert(n->right, key, value);
            } else {
                n->left = insert(n->left, key, value);
            }
            return n;
        }

        void print_inorder(std::ostream &out, BSNode<TableEntry<V>>* n) const {
            if (n != nullptr) {
                print_inorder(out, n->left);
                out << n->elem << " ";
                print_inorder(out, n->right);
            }
        }

        BSNode<TableEntry<V>>* remove(BSNode<TableEntry<V>>* n, std::string key) {
            if (n == nullptr) {
                throw std::runtime_error("Key not found!");
            } else if (n->elem.key < key) {
                n->right = remove(n->right, key);
            } else if (n->elem.key > key) {
                n->left = remove(n->left, key);
            } else {
                // Nodo encontrado
                if (n->left != nullptr && n->right != nullptr) {
                    // Dos hijos: reemplazar con el máximo del subárbol izquierdo
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                } else {
                    // Un hijo o ninguno
                    BSNode<TableEntry<V>>* temp = n;
                    n = (n->left != nullptr) ? n->left : n->right;
                    delete temp;
                }
                nelem--;
            }
            return n;
        }

        TableEntry<V> max(BSNode<TableEntry<V>>* n) const {
            if (n == nullptr) {
                throw std::runtime_error("Empty tree!");
            } else if (n->right != nullptr) {
                return max(n->right);
            } else {
                return n->elem;
            }
        }

        BSNode<TableEntry<V>>* remove_max(BSNode<TableEntry<V>>* n) {
            if (n->right == nullptr) {
                BSNode<TableEntry<V>>* temp = n->left;
                delete n;
                return temp;
            } else {
                n->right = remove_max(n->right);
                return n;
            }
        }

        void delete_cascade(BSNode<TableEntry<V>>* n) {
            if (n != nullptr) {
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:
        BSTreeDict() : root(nullptr), nelem(0) {}

        ~BSTreeDict() {
            delete_cascade(root);
        }

        int entries() override {
            return nelem;
        }

        V search(std::string key) override {
            return search(root, key)->elem.value;
        }

        V operator[](std::string key) {
            return search(key);
        }

        void insert(std::string key, V value) override {
            root = insert(root, key, value);
        }

        V remove(std::string key) override {
            BSNode<TableEntry<V>>* node = search(root, key);
            V value = node->elem.value;
            root = remove(root, key);
            return value;
        }

        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bst) {
            bst.print_inorder(out, bst.root);
            return out;
        }
};

#endif
