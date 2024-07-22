/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#ifndef TREE_H
#define TREE_H

//#include "node.hpp" // already included in iterators
#include "iterators.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <stack>

template <typename T>
class Tree {
public:
    Node<T>* root;
    int k;

    /**
     * this constructor makes a k-ary tree, if no k provided, it defaults to binary tree
    */
    Tree(int k = 2) : root(nullptr), k(k) {} 
    ~Tree() { delete root; }

    /** add_root method: recieves a pointer to node, makes it the root.
     * if root node for this tree already exists, the previous one is deleted and replaced with the new one.
     */
    void add_root(Node <T>* root_to_be) {
        if (root) {
            delete (root); // check no problems arrise
            root = root_to_be;
        }
        else {root = root_to_be;}
    }
    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent && parent->children.size() < k) { // parent not null and parent has less than k children
            parent->children.push_back(child);
        }
    }


    PreOrderIterator <T> begin_pre_order() {
        return PreOrderIterator<T>(root);
    }
    PreOrderIterator <T> end_pre_order() {
        return PreOrderIterator<T> (nullptr);
    }

    PostOrderIterator<T> begin_post_order() {
        return PostOrderIterator<T> (root);
    }
    PostOrderIterator <T> end_post_order() {
        return PostOrderIterator<T> (nullptr);
    }

    InOrderIterator <T> begin_in_order() {
        return InOrderIterator<T>(root);
    }
    InOrderIterator <T> end_in_order() { 
        return InOrderIterator<T>(nullptr);
    }

    BfsIterator <T> begin_bfs_scan() {
        return BfsIterator<T>(root);
    }
    BfsIterator <T> end_bfs_scan() {
        return BfsIterator<T> (nullptr);
    }

    DFSIterator <T> begin_dfs_scan() {
        return DFSIterator<T> (root);
    }
    DFSIterator <T> end_dfs_scan() {
        return DFSIterator<T>(nullptr);
    }

    HeapIterator <T> start_heap() {
        return HeapIterator<T> (root);
    }
     HeapIterator <T> end_heap() {
        return HeapIterator<T> (nullptr);
    }
    

private:
    Node<T>* find_node(Node<T>* node, T value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        for (auto child : node->children) {
            Node<T>* found = find_node(child, value);
            if (found) return found;
        }
        return nullptr;
    }
};

#endif // TREE_H
