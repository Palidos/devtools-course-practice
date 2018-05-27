// Copyright 2018 Mezina Margarita

#ifndef MODULES_DIJKSTRA_ALGORITHM_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_ALGORITHM_INCLUDE_GRAPH_H_

class Graph {
 protected:
    int n;
    double** graph_matrix;
 public:
    Graph();
    Graph(int count_vertex, double** matrix);
    Graph(const Graph& copy);
    ~Graph();
    int GetCount() const;
    double GetWeight(int first, int last) const;
    void AddVertex();
    void AddEdge(int first, int last, double weight);
    void DeleteEdge(int first, int last);
    void DeleteVertex(int vertex);
    double FindDistance(int start, int finish) const;
    bool operator==(const Graph& g) const;
    Graph& operator=(const Graph& g);
};

#endif  // MODULES_DIJKSTRA_ALGORITHM_INCLUDE_GRAPH_H_
