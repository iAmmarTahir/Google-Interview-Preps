#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    vector<Node> children;
    Node(int value = 0)
    {
        this->value = value;
    }
    void addChildren(int value)
    {
        Node aChild(value);
        children.push_back(aChild);
    }
};

class Graph
{
public:
    vector<Node> nodes;
};

int main()
{
    Graph g;
    g.nodes.push_back(Node(1));
    return 0;
}