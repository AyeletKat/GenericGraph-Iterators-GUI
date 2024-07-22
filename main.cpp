
/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include "complex.hpp"
#include "iterators.hpp"

void drawNode(sf::RenderWindow& window, Node<int>* node, float x, float y, float offset, const sf::Font& font) {
    if (!node) return;

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);

    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(node->value));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10, y + 10);

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

    Tree<int> int_tree;
    Node <int>* root = new Node<int>(0);
    int_tree.add_root(root);

    Node <int>* child1 = new Node<int>(1);
    Node <int>* child2 = new Node<int>(2);
    int_tree.add_sub_node(root, child1);
    int_tree.add_sub_node(root, child2);

    Node <int>* child3 = new Node<int>(3);
    Node <int>* child4 = new Node<int>(4);
    int_tree.add_sub_node(child1, child3);
    int_tree.add_sub_node(child1, child4);

    Node <int>* child5 = new Node<int>(5);
    int_tree.add_sub_node(child2, child5);
    //                    0
    //                  /   \
    //                 1     2
    //                / \     \
    //               3   4     5
    

    //window.setFramerateLimit(60); // Limit frame rate to 60 FPS //to help error
    //Pre-order traversal
    if(int_tree.k==2){
        std::cout << "Pre-order traversal: ";
        for (auto it = int_tree.begin_pre_order(); it != int_tree.end_pre_order(); ++it) {
            if (*it != nullptr)
            std::cout << (*it)->get_value() << " ";
        }
        std::cout << std::endl;
    }

    // PostOrderIterator usage
    if (int_tree.k==2){
        std::cout << "Post-order traversal: ";
        for (auto it = int_tree.begin_post_order(); it != int_tree.end_post_order(); ++it) {
            std::cout << (*it)->get_value() << " ";
        }
        std::cout << std::endl;
    }

    // In-order traversal
    if (int_tree.k == 2){
        std::cout << "In-order traversal: ";
        for (auto it = int_tree.begin_in_order(); it != int_tree.end_in_order(); ++it) {
            std::cout << (*it)->get_value() << " ";
        }
        std::cout << std::endl;
    }

    // BfsIterator usage
    std::cout << "BFS traversal: ";
    for (auto it = int_tree.begin_bfs_scan(); it != int_tree.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // DFSIterator usage
    std::cout << "DFS traversal: ";
    for (auto it = int_tree.begin_dfs_scan(); it != int_tree.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // HeapIterator usage
    std::cout << "Heap traversal: ";
    for (auto it = int_tree.myHeap(); it != HeapIterator<int>(nullptr); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawNode(window, int_tree.root, 400, 50, 200, font);
        window.display();
    }
    return 0;
};
