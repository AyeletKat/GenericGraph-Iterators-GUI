
/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include "complex.hpp"

// to print colorful \ bold text to terminal :)
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
void drawNode(sf::RenderWindow& window, Node<complex>* node, float x, float y, float offset, const sf::Font& font) {
    if (!node) return;

    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(x, y);

    sf::Text text;
    text.setFont(font);
    text.setString((*node).toString());
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(x + 17, y + 17);

    window.draw(circle);
    window.draw(text);

    for (size_t i = 0; i < node->children.size(); ++i) {
        if (!node->children[i]) continue;
        
        float childX = x + (i - node->children.size() / 2.0) * offset;
        float childY = y + 100;
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(childX + 20, childY + 20))
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->children[i], childX, childY, offset / 2, font);
    }
}


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }

    Tree<complex> ctree;
    complex c0(5.0, 9.6);
    Node <complex>* root = new Node<complex>(c0);
    ctree.add_root(root);

    complex c1(-3.9, 4.0);
    Node <complex>* child1 = new Node<complex>(c1);
    complex c2(0.0,8.1);
    Node <complex>* child2 = new Node<complex>(c2);
    ctree.add_sub_node(root, child1);
    ctree.add_sub_node(root, child2);

    complex c3(2.56, 8.3);
    Node <complex>* child3 = new Node<complex>(c3);
    complex c4(-7.87, 12.3);
    Node <complex>* child4 = new Node<complex>(c4);
    ctree.add_sub_node(child1, child3);
    ctree.add_sub_node(child1, child4);

    complex c5(3.72, 2.56);
    Node <complex>* child5 = new Node<complex>(c5);
    ctree.add_sub_node(child2, child5);
    //                    0
    //                  /   \
    //                 1     2
    //                / \     \
    //               3   4     5
    

    //scanning the tree using Pre-order method
    if(ctree.k==2){
        std::cout << MAGENTA << "Pre-order traversal: " << RESET;
        for (auto it = ctree.begin_pre_order(); it != ctree.end_pre_order(); ++it) {
            if (*it != nullptr)
                std::cout << ((*it)->get_value()) << " ";
        }
        std::cout << std::endl;
    }

    // scanning the tree using Post Order method
    if (ctree.k==2){
        std::cout << YELLOW << "Post-order traversal: " << RESET;
        for (auto it = ctree.begin_post_order(); it != ctree.end_post_order(); ++it) {
            std::cout << (*it)->get_value() << " ";
        }
        std::cout << std::endl;
    }

    // scanning the tree using In-order traversal method
    if (ctree.k == 2){
        std::cout << GREEN << "In-order traversal: " << RESET;
        for (auto it = ctree.begin_in_order(); it != ctree.end_in_order(); ++it) {
            std::cout << (*it)->get_value() << " ";
        }
        std::cout << std::endl;
    }

    // scanning the tree using Bfs algorithm
    std::cout << RED <<"BFS traversal: " << RESET;
    for (auto it = ctree.begin_bfs_scan(); it != ctree.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // scanning the tree using DFS algorithm
    std::cout << BLUE << "DFS traversal: " << RESET;
    for (auto it = ctree.begin_dfs_scan(); it != ctree.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // showing what is the order of nodes of the tree if it was to turn to minimum heap
    if (ctree.k == 2){
    std::cout << CYAN << "Heap traversal: " << RESET;
    for (auto it = ctree.start_heap(); it != ctree.end_heap(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;
    }


// Tree<int> int_tree;
//     Node <int>* root = new Node<int>(0);
//     int_tree.add_root(root);

//     Node <int>* child1 = new Node<int>(1);
//     Node <int>* child2 = new Node<int>(2);
//     int_tree.add_sub_node(root, child1);
//     int_tree.add_sub_node(root, child2);

//     Node <int>* child3 = new Node<int>(3);
//     Node <int>* child4 = new Node<int>(4);
//     int_tree.add_sub_node(child1, child3);
//     int_tree.add_sub_node(child1, child4);

//     Node <int>* child5 = new Node<int>(5);
//     int_tree.add_sub_node(child2, child5);
//     //                    0
//     //                  /   \
//     //                 1     2
//     //                / \     \
//     //               3   4     5
    

//     //window.setFramerateLimit(60); // Limit frame rate to 60 FPS //to help error
//     //Pre-order traversal
//     if(int_tree.k==2){
//         std::cout << "Pre-order traversal: ";
//         for (auto it = int_tree.begin_pre_order(); it != int_tree.end_pre_order(); ++it) {
//             if (*it != nullptr)
//             std::cout << (*it)->get_value() << " ";
//         }
//         std::cout << std::endl;
//     }

//     // PostOrderIterator usage
//     if (int_tree.k==2){
//         std::cout << "Post-order traversal: ";
//         for (auto it = int_tree.begin_post_order(); it != int_tree.end_post_order(); ++it) {
//             std::cout << (*it)->get_value() << " ";
//         }
//         std::cout << std::endl;
//     }

//     // In-order traversal
//     if (int_tree.k == 2){
//         std::cout << "In-order traversal: ";
//         for (auto it = int_tree.begin_in_order(); it != int_tree.end_in_order(); ++it) {
//             std::cout << (*it)->get_value() << " ";
//         }
//         std::cout << std::endl;
//     }

//     // BfsIterator usage
//     std::cout << "BFS traversal: ";
//     for (auto it = int_tree.begin_bfs_scan(); it != int_tree.end_bfs_scan(); ++it) {
//         std::cout << (*it)->get_value() << " ";
//     }
//     std::cout << std::endl;

//     // DFSIterator usage
//     std::cout << "DFS traversal: ";
//     for (auto it = int_tree.begin_dfs_scan(); it != int_tree.end_dfs_scan(); ++it) {
//         std::cout << (*it)->get_value() << " ";
//     }
//     std::cout << std::endl;

//     // HeapIterator usage
//     std::cout << "Heap traversal: ";
//     for (auto it = int_tree.start_heap(); it != int_tree.end_heap(); ++it) {
//         std::cout << (*it)->get_value() << " ";
//     }
//     std::cout << std::endl;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //drawNode(window, ctree.root, 400, 50, 200, font);
        drawNode(window, ctree.root, 400, 50, 200, font);
        window.display();
    }
    return 0;
};
