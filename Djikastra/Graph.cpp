// Class Graph:

#include <iostream>
#include <vector>
using namespace std;

class Graph {
   public:
    Graph(const int);
    int V();
    int E();
    bool adjacent(int x, int y);
    int* neighbours(int x);
    void add(int x, int y);
    void remove(int x, int y);
    int get_node_value(int x);
    void set_node_value(int x, int a);
    int get_edge_value(int x, int y);
    void set_edge_value(int x, int y, int v);
    
  private:
    int** adj_mat;
    int size;
};

Graph::Graph(const int s) {
    size = s;
    adj_mat = new int*[size];
    for (int i = 0; i< size; i++)
        adj_mat[i] = new int[size];
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            adj_mat[i][j] = -1;
};

//V (G): returns the number of vertices in the graph
int Graph::V() {
    return size;
}

//E (G): returns the number of edges in the graph
int Graph::E() {
    int edge_count = 0;
    for (int i = 0; i< size; i++ ) {
        for (int j = 0; j < size; j++) {
            if ( i!= j && adj_mat[i][j] > 0)
                edge_count++;
        }
    }
    return edge_count;
}

//adjacent (G, x, y): tests whether there is an edge from node x to node y.
bool Graph::adjacent(int x, int y) {
    if (adj_mat[x][y] > 0)
        return true;
    else
        return false;
}

//neighbors (G, x): lists all nodes y such that there is an edge from x to y.
int* Graph::neighbours(int x) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (adj_mat[x][i] > 0)
            cnt++;
    }
    int* neighs = (int*)malloc(cnt*sizeof(int*));
    
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (adj_mat[x][i] > 0) {
            neighs[j] = i;
            j++;
        }
    }
    
    return neighs;
}

//add (G, x, y): adds to G the edge from x to y, if it is not there.
void Graph::add(int x, int y) {
    adj_mat[x][y] = 0;
    adj_mat[y][x] = 0;
}

//delete (G, x, y): removes the edge from x to y, if it is there.
void Graph::remove(int x, int y) {
    adj_mat[x][y] = -1;
    adj_mat[y][x] = -1;
}

//set_node_value( G, x, a): sets the value associated with the node x to a.
void Graph::set_node_value(int x, int a) {
    adj_mat[x][x] = a;
}

//get_node_value (G, x): returns the value associated with the node x.
int Graph::get_node_value(int x) {
    return adj_mat[x][x];
}

//set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.
void Graph::set_edge_value(int x, int y, int v) {
    adj_mat[x][y] = v;
}

//get_edge_value( G, x, y): returns the value associated to the edge (x,y).
int Graph::get_edge_value(int x, int y) {
    return adj_mat[x][y];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    Graph g(5);
    cout << "Number of vertices " << g.V() << endl;
    cout << "Number of edges " << g.E() << endl;
    return 0;
}
