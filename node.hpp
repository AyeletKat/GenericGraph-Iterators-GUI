/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#ifndef NODE_H
#define NODE_H

#include <vector>
# include <string>
#include <sstream>
#include <iostream>

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
    T& get_value() {
        return value;
    }

    //N: getvalue, removechildren, operator ==, doesnt have distructor

    std::string toString() {
        std::ostringstream oss;
        oss.precision(2);
        oss << std::fixed << std::setprecision(2)<< value;
        return oss.str();
    }
};

// Providing overload for std::to_string for Node class
namespace std {
    template <typename T>
    std::string to_string(const Node<T>& node) {
        return node.toString();
    }
}

#endif // NODE_H
