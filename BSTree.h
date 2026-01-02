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

    // Inserción recursiva
    BSNode<T>* insert(BSNode<T>* n, const T& e) {
        if (n == nullptr) {
            return new BSNode<T>(e);
        }
        if (e == n->elem) {
            throw std::runtime_error("Elemento duplicado");
        }
        if (e < n->elem) {
            n->left = insert(n->left, e);
        } else {
            n->right = insert(n->right, e);
        }
        return n;
    }

    // Búsqueda del mínimo
    BSNode<T>* findMin(BSNode<T>* n) const {
        while (n && n->left != nullptr) {
            n = n->left;
        }
        return n;
    }

    // Eliminación recursiva
    BSNode<T>* remove(BSNode<T>* n, const T& e) {
        if (n == nullptr) return nullptr;

        if (e < n->elem) {
            n->left = remove(n->left, e);
        } else if (e > n->elem) {
            n->right = remove(n->right, e);
        } else {
            // Nodo encontrado
            if (n->left == nullptr) {
                BSNode<T>* tmp = n->right;
                delete n;
                return tmp;
            }
            if (n->right == nullptr) {
                BSNode<T>* tmp = n->left;
                delete n;
                return tmp;
            }
            BSNode<T>* tmp = findMin(n->right);
            n->elem = tmp->elem;
            n->right = remove(n->right, tmp->elem);
        }
        return n;
    }

    // Impresión inorder
    void print_inorder(std::ostream& out, BSNode<T>* n) const {
        if (n == nullptr) return;
        print_inorder(out, n->left);
        out << n->elem << " ";
        print_inorder(out, n->right);
    }

    // Liberar memoria
    void clear(BSNode<T>* n) {
        if (!n) return;
        clear(n->left);
        clear(n->right);
        delete n;
    }

public:
    BSTree() : root(nullptr) {}

    ~BSTree() {
        clear(root);
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

