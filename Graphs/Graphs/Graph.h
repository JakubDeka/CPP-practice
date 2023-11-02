#ifndef GRAPH_H
#define GRAPH_H
#include <array>
#include <vector>
//#include "Auxiliary.h"
#include <iostream>

class Graph
{
	private:
		std::vector<std::string> vertices;
		std::vector<std::array<std::string, 2>> edges;
		int findVertex(std::string);
		int findEdge(std::string, std::string);

	public:
		//Graph();
		
		std::vector<std::string> getVertices();
		int getNumberOfVertices();
		int getNumberOfEdges();
		std::vector<std::array<std::string, 2>> getEdges();
		void printGraph(); 
		
		void addVertex(std::string);
		void addEdge(std::string, std::string);
		void removeEdge(std::string, std::string);
		void removeVertex(std::string);

		
};
#endif