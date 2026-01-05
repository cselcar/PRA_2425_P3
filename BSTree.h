#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <stdexcept>

// =====================
// Nodo del BST
// =====================
template <class T>
class BSNode {
public:
    T elem;
    BSNode<T>* left;
    BSNode<T>* right;

    BSNode(const T& e) : elem(e), left(nullptr), right(nullptr) {}
};

// =====================
// Árbol Binario de Búsqueda
// =====================
template <class T>
class BSTree {
private:
    BSNode<T>* root;
    int n;  // Contador de elementos

    // Inserción recursiva
    BSNode<T>* insert(BSNode<T>* node, const T& e) {
        if (node == nullptr) {
            n++;
            return new BSNode<T>(e);
        }
        if (e == node->elem) {
            throw std::runtime_error("Elemento duplicado");
        }
        if (e < node->elem) {
            node->left = insert(node->left, e);
        } else {
            node->right = insert(node->right, e);
        }
        return node;
    }

    // Búsqueda recursiva
    T search(BSNode<T>* node, const T& e) const {
        if (node == nullptr) {
            throw std::runtime_error("Elemento no encontrado");
        }
        if (e == node->elem) {
            return node->elem;
        }
        if (e < node->elem) {
            return search(node->left, e);
        } else {
            return search(node->right, e);
        }
    }

    // Búsqueda del mínimo
    BSNode<T>* findMin(BSNode<T>* node) const {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Eliminación recursiva
    BSNode<T>* remove(BSNode<T>* node, const T& e) {
        if (node == nullptr) {
            throw std::runtime_error("Elemento no encontrado");
        }

        if (e < node->elem) {
            node->left = remove(node->left, e);
        } else if (e > node->elem) {
            node->right = remove(node->right, e);
        } else {
            // Nodo encontrado
            if (node->left == nullptr) {
                BSNode<T>* tmp = node->right;
                delete node;
                n--;
                return tmp;
            }
            if (node->right == nullptr) {
                BSNode<T>* tmp = node->left;
                delete node;
                n--;
                return tmp;
            }
            BSNode<T>* tmp = findMin(node->right);
            node->elem = tmp->elem;
            node->right = remove(node->right, tmp->elem);
        }
        return node;
    }

    // Impresión inorder
    void print_inorder(std::ostream& out, BSNode<T>* node) const {
        if (node == nullptr) return;
        print_inorder(out, node->left);
        out << node->elem << " ";
        print_inorder(out, node->right);
    }

    // Liberar memoria
    void clear(BSNode<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BSTree() : root(nullptr), n(0) {}

    ~BSTree() {
        clear(root);
    }

    int size() const {
        return n;
    }

    T search(const T& e) const {
        return search(root, e);
    }

    void insert(const T& e) {
        root = insert(root, e);
    }

    void remove(const T& e) {
        root = remove(root, e);
    }

    bool empty() const {
        return root == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTree<T>& bst) {
        bst.print_inorder(out, bst.root);
        return out;
    }
};

#endif // BSTREE_H
