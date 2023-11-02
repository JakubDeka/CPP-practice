#include "Graph.h"



int main()
{
	Graph graph = Graph();
	graph.addVertex("a");
	graph.addVertex("a");
	graph.addVertex("b");
	graph.addEdge("a", "b");
	graph.addEdge("a", "b");
	graph.printGraph();
}