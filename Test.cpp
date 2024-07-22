/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include <sstream>
#include <vector>

TEST_CASE("Test tree traversals") {
    Tree<int> tree;
    Node<int>* root = new Node<int>(0);
    tree.add_root(root);

    Node<int>* child1 = new Node<int>(1);
    Node<int>* child2 = new Node<int>(2);
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);

    Node<int>* child3 = new Node<int>(3);
    Node<int>* child4 = new Node<int>(4);
    tree.add_sub_node(child1, child3);
    tree.add_sub_node(child1, child4);

    Node<int>* child5 = new Node<int>(5);
    tree.add_sub_node(child2, child5);
    
    // Expected results
    std::vector<int> expected_pre_order = {0, 1, 3, 4, 2, 5};
    std::vector<int> expected_post_order = {3, 4, 1, 5, 2, 0};
    std::vector<int> expected_in_order = {3, 1, 4, 0, 2, 5};
    std::vector<int> expected_bfs = {0, 1, 2, 3, 4, 5};
    std::vector<int> expected_dfs = {0, 1, 3, 4, 2, 5};
    std::vector<int> expected_heap = {0, 1, 2, 3, 4, 5}; // Assuming min-heap

    std::vector<int> actual_values;

    SUBCASE("Pre-order traversal") {
        actual_values.clear();
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_pre_order);
    }

    SUBCASE("Post-order traversal") {
        actual_values.clear();
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_post_order);
    }

    SUBCASE("In-order traversal") {
        actual_values.clear();
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_in_order);
    }

    SUBCASE("BFS traversal") {
        actual_values.clear();
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        actual_values.clear();
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_dfs);
    }

    SUBCASE("Heap traversal") {
        actual_values.clear();
        for (auto it = tree.start_heap(); it != tree.end_heap(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_heap);
    }
}

TEST_CASE("Test k-ary tree traversals") {
    Tree<int> tree(3); // Creating a k-ary tree with k=3
    Node<int>* root = new Node<int>(0);
    tree.add_root(root);

    Node<int>* child1 = new Node<int>(1);
    Node<int>* child2 = new Node<int>(2);
    Node<int>* child3 = new Node<int>(3);
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(root, child3);

    Node<int>* child4 = new Node<int>(4);
    Node<int>* child5 = new Node<int>(5);
    tree.add_sub_node(child1, child4);
    tree.add_sub_node(child1, child5);

    Node<int>* child6 = new Node<int>(6);
    tree.add_sub_node(child2, child6);

    // Expected results
    std::vector<int> expected_pre_order = {0, 1, 4, 5, 2, 6, 3};
    std::vector<int> expected_post_order = {4, 5, 1, 6, 2, 3, 0};
    std::vector<int> expected_bfs = {0, 1, 2, 3, 4, 5, 6};
    std::vector<int> expected_dfs = {0, 1, 4, 5, 2, 6, 3};
    std::vector<int> expected_heap = {0, 1, 2, 3, 4, 5, 6}; // Assuming min-heap

    std::vector<int> actual_values;

    SUBCASE("Pre-order traversal") {
        actual_values.clear();
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_pre_order);
    }

    SUBCASE("Post-order traversal") {
        actual_values.clear();
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_post_order);
    }

    SUBCASE("BFS traversal") {
        actual_values.clear();
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        actual_values.clear();
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_dfs);
    }

    SUBCASE("Heap traversal") {
        actual_values.clear();
        for (auto it = tree.start_heap(); it != tree.end_heap(); ++it) {
            actual_values.push_back((*it)->get_value());
        }
        CHECK(actual_values == expected_heap);
    }
}

TEST_CASE("Testing the complex class") {
    SUBCASE("Test default constructor") {
        complex c;
        CHECK(c.getReal() == 0);
        CHECK(c.getImg() == 0);
    }

    SUBCASE("Test parameterized constructor") {
        complex c(3.0, 4.0);
        CHECK(c.getReal() == 3.0);
        CHECK(c.getImg() == 4.0);
    }

    SUBCASE("Test addition operator") {
        complex c1(1.0, 2.0);
        complex c2(3.0, 4.0);
        complex result = c1 + c2;
        CHECK(result.getReal() == 4.0);
        CHECK(result.getImg() == 6.0);
    }

    SUBCASE("Test greater than operator") {
        complex c1(1.0, 2.0);
        complex c2(3.0, 4.0);
        CHECK(c2 > c1);
        CHECK_FALSE(c1 > c2);
    }

    SUBCASE("Test toString method") {
        complex c(1.5, -2.5);
        CHECK(c.toString() == "1.50 - 2.50i");
    }

    SUBCASE("Test output operator") {
        complex c(1.5, -2.5);
        std::ostringstream oss;
        oss << c;
        CHECK(oss.str() == "1.50 - 2.50i");
    }
}

TEST_CASE("testing complex class functions"){
    complex c1(1.0, 2.0);
    complex c2(3.0, 4.0);
    complex result = c1 + c2;
    CHECK(result.getReal() == 4.0);
    CHECK(result.getImg() == 6.0);

}
TEST_CASE("Testing the Node class") {
    SUBCASE("Test constructor and get_value") {
        Node<int> node(10);
        CHECK(node.get_value() == 10);
    }

    SUBCASE("Test toString method") {
        Node<double> node(3.14159);
        CHECK(node.toString() == "3.14");
    }

    SUBCASE("Test add child") {
        Node<int> parent(1);
        Node<int>* child1 = new Node<int>(2);
        Node<int>* child2 = new Node<int>(3);
        parent.children.push_back(child1);
        parent.children.push_back(child2);

        CHECK(parent.children.size() == 2);
        CHECK(parent.children[0]->get_value() == 2);
        CHECK(parent.children[1]->get_value() == 3);
    }

    SUBCASE("Test destructor") {
        Node<int>* parent = new Node<int>(1);
        parent->children.push_back(new Node<int>(2));
        parent->children.push_back(new Node<int>(3));
        
        delete parent; // Should delete children as well
    }
}

