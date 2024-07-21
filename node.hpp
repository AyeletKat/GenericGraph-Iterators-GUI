#ifndef NODE_H
#define NODE_H

#include <vector>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node <T>*> children;//!!! Node <T> * !!!

    Node(T val) : value(val) {}
    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }
    T get_value() {
        return value;
    }
    //N: getvalue, removechildren, operator ==, doesnt have distructor
};

#endif // NODE_H
