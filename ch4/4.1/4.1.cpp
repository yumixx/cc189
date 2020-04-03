#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef enum {UNVISITED, VISITING, VISITED} Vstate;

template <typename T>
struct Node
{
    T data;
    vector<Node*> adjacentList;
    Vstate state;

    Node(T d) : data(d), state(UNVISITED) {}

    void addAdjacentNode(Node<T>* node) {
        adjacentList.push_back(node);
    }

    vector<Node<T>* > getAdjacentList() {
        return adjacentList;
    }
};

template <typename T>
struct Graph
{
    vector<Node<T>* > graphNodes;
};

template <typename T>
bool findRoute(Graph<T> graph, Node<T>* start, Node<T>* end) {

    queue<Node<int>* > bfs;
    bfs.push(start);
    start->state = VISITING;

    while(!bfs.empty()) {
        Node<int>* node = bfs.front();
        bfs.pop();
        vector<Node<T>* > adjacents = node->getAdjacentList();
        for(Node<int>* adj : adjacents) {
            if(adj == end) return true;
            if(adj->state == UNVISITED) {
                bfs.push(adj);
                adj->state = VISITING;
            }
        }
        node->state = VISITED;
    }

    return false;
}

int main() {

    Graph<int> graph;

    for(int i = 1; i < 9; ++i) {
        Node<int>* node = new Node<int>(i);
        graph.graphNodes.push_back(node);
    }

    graph.graphNodes[0]->adjacentList = {graph.graphNodes[1], graph.graphNodes[2], graph.graphNodes[3]};
    graph.graphNodes[1]->adjacentList = {graph.graphNodes[6]};
    graph.graphNodes[2]->adjacentList = {graph.graphNodes[1], graph.graphNodes[4]};
    graph.graphNodes[3]->adjacentList = {graph.graphNodes[4]};
    graph.graphNodes[4]->adjacentList = {};
    graph.graphNodes[5]->adjacentList = {graph.graphNodes[4], graph.graphNodes[6]};
    graph.graphNodes[6]->adjacentList = {graph.graphNodes[7]};
    graph.graphNodes[7]->adjacentList = {graph.graphNodes[5]};

    bool isFound = findRoute(graph, graph.graphNodes[5], graph.graphNodes[5]);
    cout << isFound << endl;

    isFound = findRoute(graph, graph.graphNodes[0], graph.graphNodes[4]);
    cout << isFound << endl;
    
    isFound = findRoute(graph, graph.graphNodes[3], graph.graphNodes[2]);
    cout << isFound << endl;

    return 0;

}
