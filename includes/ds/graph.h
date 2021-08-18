#ifndef GRAPH_DS_H
#define GRAPH_DS_H

// Directed
// Undirected
// Weighted
// Unweighted

// SelfLoop
// MultiEdge
// Simple graph

// min number of edges
// max num of edges
// dense graph
// sparse graph

// path, walk, trail
// get path
// simple path
// closed walk
// length of walk, path
// cycle
// simple cycle
// is acyclic
// directed, undiredted (DAG)
// is tree

// not connected
// is connected
// is strongly connected
// weakly connected

// edge list
// adjancey matrix
// adjancey list

// Custom Headers

// Standard Headers
#include <iostream>
#include <vector>

// Graph ELement struct for storing data
template <typename T>
struct GraphElement
{
    T data;
    GraphElement(T data_ = NULL) : data(data_) {}
};

// Graph Neighbour struct for storing pointer to the other Element and the Distance
template <typename T>
struct GraphNeighbour
{
    GraphElement<T> *pointer;
    float distance;
    GraphNeighbour(GraphElement<T> *pointer_ = NULL, float dis = 0) : pointer(pointer_), distance(dis) {}
};

// Graph Node struct for storing an Element with all of its neigbours
template <typename T>
struct GraphNode
{
    GraphElement<T> *element;
    std::vector<GraphNeighbour<T> *> neighbours;
    GraphNode(GraphElement<T> *element_ = NULL) : element(element_) {}
};

// Graph Class to store list of GraphNodes
template <typename T>
class Graph
{
private:
    std::vector<GraphNode<T> *> nodes;

public:
    Graph();
    bool is_empty();
    bool contains(T val);
    void add_node(T val);
};

#endif // GRAPH_DS_H
