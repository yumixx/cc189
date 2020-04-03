#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

enum Vstate {VISITED, UNVISITED};

template <typename Tv>
struct Vertex {
    Tv data;
    int inDegree;
    Vstate state;

    Vertex(Tv const& d) : data(d), inDegree(0), state(UNVISITED) {}
};

template <typename Te>
struct Edge
{
    Te data;

    Edge(Te const& e) : data(e) {}
};

template<typename Tv, typename Te>
class Graph {
public:
    Graph() {n = e = 0;}
    ~Graph() {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                delete E[i][j];
            }
        }
    }

    int insert(Tv const& vertex) {
        for(int i = 0; i < n; ++i) {
            E[i].push_back(NULL);
        }
        n++;
        E.push_back(vector<Edge<Te>*>(n, (Edge<Te>*)NULL));
        V.push_back(Vertex<Tv>(vertex));
        return V.size()-1;
    }

    bool exists(int i, int j) {
        return (0<=i) && (i<n) && (0<=j) && (j<n) && E[i][j] != NULL;
    }

   void remove(int i) {
        for(int j = 0; j < n; ++j) {
            if(exists(i,j)) {
                delete E[i][j];
                V[j].inDegree--;
            }
        }
        E.erase(E.begin()+i);
        n--;
        Tv vBak = V[i].data;
        V.erase(V.begin()+i);
        for(int j = 0; j < n; ++j) {
            Edge<Te>* edge = E[j][i];
            E[j].erase(E[j].begin()+i);
            if(edge != NULL) {
                delete edge;
            }
        }
        //return vBak;
    }

    int inDegree(int i) {
        return V[i].inDegree;
    }

    int index(Tv const& vertex) {
        for(int i = 0; i < V.size(); ++i) {
            if(vertex == V[i].data) {
                return i;
            }
        }

        return -1;
    }

    void insert(Te const& edge, int i, int j) {
        if(exists(i, j)) {
            return;
        }
        E[i][j] = new Edge<Te> (edge);
        ++e;
        V[j].inDegree++;
    }

    void remove(int i, int j) {
        delete E[i][j];
        E[i][j] = NULL;
        e--;
        V[j].inDegree--;
    }

    vector<Vertex<Tv> > findZeroInDegree() {
        vector<Vertex<Tv> > zeroInDegree;
        for(int i = 0; i < V.size(); ++i) {
            if(inDegree(i) == 0) {
                zeroInDegree.push_back(V[i]);
            }
        }

        return zeroInDegree;
    }

    int vertexNum () {
        return n;
    }

    int edgeNum() {
        return e;
    }

    Vertex<Tv>& vertex(int i) {
        return V[i];
    }

    vector<Vertex<Tv>> findAdjacents (int i) {
        vector<Vertex<Tv>> adjacents;

        for(int j = 0; j < n; ++j) {
            if(exists(i,j)) {
                adjacents.push_back(V[j]);
            }
        }

        return adjacents;
    }

private:
    vector<Vertex<Tv> > V;
    vector<vector<Edge<Te>* > > E;
    int n;
    int e;
};


Graph<char, int> buildGraph(string projects, vector<string> dependencies) {
    Graph<char, int> graph;
    for(char v : projects) {
        graph.insert(v);
    }

    for(string e : dependencies) {
        char first = e[0];
        char second = e[1];
        int fisrtIdx = graph.index(first);
        int secondIdx = graph.index(second);
        graph.insert(1, fisrtIdx, secondIdx);
    }

    return graph;
}


vector<char> buildOrder(string projects, vector<string> dependencies) {

    Graph<char, int> graph = buildGraph(projects, dependencies);

    vector<char> order;

    while(graph.vertexNum() > 0) {
        vector<Vertex<char> > zeroInDegree = graph.findZeroInDegree();
        for(Vertex<char> vertex : zeroInDegree) {
            order.push_back(vertex.data);
            int idx = graph.index(vertex.data);
            graph.remove(idx);
        }
    }

    return order;
}

template <typename Tv, typename Te>
void dfs(Graph<Tv, Te>& graph, int i, stack<Tv>& s) {
    graph.vertex(i).state = VISITED;
    
    vector<Vertex<Tv>> adjacents = graph.findAdjacents(i);
    for(int j = 0; j < adjacents.size(); ++j) {
        if(adjacents[j].state == UNVISITED) {
            int idx = graph.index(adjacents[j].data);
            dfs(graph, idx, s);
        }
    }
    
    s.push(graph.vertex(i).data);
}


vector<char> buildOrder2(string projects, vector<string> dependencies) {

    Graph<char, int> graph = buildGraph(projects, dependencies);

    vector<char> order;
    stack<char> tempStack;

    for(int i = 0; i < graph.vertexNum(); ++i) {
        if(graph.vertex(i).state != VISITED) {
            dfs(graph, i, tempStack);
        }
    }

    while(!tempStack.empty()) {
        char c = tempStack.top();
        order.push_back(c);
        tempStack.pop();
    }

    return order;
}


int main() {

    string projects{"abcdefg"};
    vector<string> dependencies {{"fc"}, {"fa"}, {"fb"}, {"ca"}, {"ba"}, {"ae"}, {"be"}, {"dg"}};

    vector<char> order = buildOrder(projects, dependencies);

    for(char c : order) {
        cout << c << " ";
    }
    cout << endl;

    vector<char> order2 = buildOrder2(projects, dependencies);

    for(char c : order2) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
