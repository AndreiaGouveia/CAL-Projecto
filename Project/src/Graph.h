/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <iostream>
#include "MutablePriorityQueue.h"
#include "Utils.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

//////////////////////////////////////////////////////////
/////           VERTEX                               /////
//////////////////////////////////////////////////////////

template <class T>
class Vertex {
    int id;
    T info;                // contents
    vector<Edge<T> > adj;  // list of outgoing edges
    bool visited;          // auxiliary field used by dfs and bfs
    bool processing;       // auxiliary field used by isDAG
    int indegree;          // auxiliary field used by topsort
    double dist = 0;
    Vertex<T> *path = NULL;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    void addEdge(Vertex<T> *dest, double w);
    bool removeEdgeTo(Vertex<T> *d);
public:
    Vertex(T in);
    friend class Graph<T>;
    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
    T getInfo() const;
    double getDist() const;
    vector <Edge<T>> getEdges();
    Vertex *getPath() const;
    int getID() const;
    void setID(int new_id);
};

template <class T>
vector <Edge<T>> Vertex<T>::getEdges()
{
    return adj;
}


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>

void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
    return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

template <class T>
int Vertex<T>::getID() const {
    return this->id;
}

template <class T>
void Vertex<T>::setID(int new_id) {
    this->id = new_id;
}

template <class T>
bool operator==(Vertex<T> a, Vertex<T> b)
{
    return a.getID()==b.getID();
}

/////////////////////////////////////////////////////////
/////           EDGES                               /////
/////////////////////////////////////////////////////////

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

/////////////////////////////////////////////////////////
/////           GRAPH                               /////
/////////////////////////////////////////////////////////

template <class T>
class Graph {
    vector<Vertex<T> *> vertexSet;    // vertex set

    void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
    Vertex<T> *findVertex(const T &in) const;
    bool dfsIsDAG(Vertex<T> *v) const;
public:
    int getNumVertex() const;
    vector<Vertex<T>*> getVertexSet() const;
    bool addVertex(const T &in);
    bool removeVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w);
    bool removeEdge(const T &sourc, const T &dest);
    vector<T> dfs() const;
    vector<T> bfs(const T &source) const;
    vector<T> topsort() const;
    int maxNewChildren(const T &source, T &inf) const;
    bool isDAG() const;
    vector<T> getPath(const T &origin, const T &dest) const;
    double edgeCost(int i, int j);
    int vertexPrev(int i, int j);
};


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T>*> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return nullptr;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2,w);
    return true;
}

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    return v1->removeEdgeTo(v2);
}

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::dfs() const {
    vector<T> res;
    for (auto v : vertexSet)
        v->visited = false;
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}

/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::bfs(const T & source) const {
    vector<T> res;
    auto s = findVertex(source);
    if (s == nullptr)
        return res;
    queue<Vertex<T> *> q;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        res.push_back(v->info);
        for (auto & e : v->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push(w);
                w->visited = true;
            }
        }
    }
    return res;
}

/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template<class T>
vector<T> Graph<T>::topsort() const {
    vector<T> res;

    for (auto v : vertexSet)
        v->indegree = 0;
    for (auto v : vertexSet)
        for (auto & e : v->adj)
            e.dest->indegree++;

    queue<Vertex<T>*> q;
    for (auto v : vertexSet)
        if (v->indegree == 0)
            q.push(v);

    while( !q.empty() ) {
        Vertex<T>* v = q.front();
        q.pop();
        res.push_back(v->info);
        for(auto & e : v->adj) {
            auto w = e.dest;
            w->indegree--;
            if(w->indegree == 0)
                q.push(w);
        }
    }

    if ( res.size() != vertexSet.size() ) {
        cout << "Ordenacao Impossivel!" << endl;
        res.clear();
        return res;
    }

    return res;
}

/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex and the number of new children.
 */

template <class T>
int Graph<T>::maxNewChildren(const T & source, T &inf) const {
    auto s = findVertex(source);
    if (s == NULL)
        return 0;
    queue<Vertex<T> *> q;
    int maxChildren = 0;
    inf = s->info;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int nChildren=0;
        for (auto & e : v->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                w->visited = true;
                q.push(w);
                nChildren++;
            }
        }
        if (nChildren>maxChildren) {
            maxChildren = nChildren;
            inf = v->info;
        }
    }
    return maxChildren;
}

/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool Graph<T>::isDAG() const {
    for (auto v : vertexSet) {
        v->visited = false;
        v->processing = false;
    }
    for (auto v : vertexSet)
        if (! v->visited)
            if ( ! dfsIsDAG(v) )
                return false;
    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
    v->visited = true;
    v->processing = true;
    for (auto & e : v->adj) {
        auto w = e.dest;
        if (w->processing)
            return false;
        if (! w->visited)
            if (! dfsIsDAG(w))
                return false;
    }
    v->processing = false;
    return true;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    vector<T> res;
    res.push_back(dest);
    Vertex<T>* next = findVertex(dest);
    while((next = next->getPath()) != NULL) {
        if(next->getInfo() == origin) {
            res.push_back(origin);
            break;
        }
        res.push_back(next->getInfo());
    }
    reverse(res.begin(), res.end());
    return res;
}

template<class T>
double Graph<T>::edgeCost(int i, int j) {
    if (i == j)
        return 0;

    for (auto edge : vertexSet[i]->adj)
        if (edge.dest == vertexSet[j])
            return edge.weight;

    return INF;
}
template<class T>
int Graph<T>::vertexPrev(int i, int j) {
    for (auto edge : vertexSet[i]->adj) {
        if (edge.dest == vertexSet[j])
            return j;
    }

    return -1;
}

#endif /* GRAPH_H_ */