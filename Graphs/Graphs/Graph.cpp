#include "Graph.h"

std::vector<std::string> Graph::getVertices()
{
	return vertices;
}

int Graph::getNumberOfVertices()
{
	return getVertices().size();
}

std::vector<std::array<std::string, 2>> Graph::getEdges()
{
	return edges;
}

int Graph::getNumberOfEdges()
{
	return getEdges().size();
}

//int Graph::findVertex(std::string vertex)
//{
//	int index = 0;
//	for (std::string current_vertex : vertices)
//	{
//		if (vertex == current_vertex)
//		{
//			return index;
//		}
//		index += 1;
//	}
//}
//
//int Graph::findEdge(std::string vertex_one, std::string vertex_two)
//{
//	int index = 0;
//	std::string current_vertex_one, current_vertex_two;
//	for (std::array<std::string, 2> current_edge : edges)
//	{
//		current_vertex_one = current_edge[0];
//		current_vertex_two = current_edge[1];
//		if ((current_vertex_one == vertex_one and current_vertex_two == vertex_two) or
//			(current_vertex_two == vertex_one and current_vertex_one == vertex_two))
//		{
//			return index;
//		}
//		index += 1;
//	}
//	return index;
//}

void Graph::addVertex(std::string vertex)
{
	std::vector<std::string>::iterator it = std::find(vertices.begin(), vertices.end(), vertex);
	if (!(it != vertices.end()))
	{
		vertices.push_back(vertex);
		std::cout << "Added vertex '" << vertex << "'" << std::endl;
	}
	else {
		std::cout << "Vertex '" << vertex << "' already present." << std::endl;
	}
}

void Graph::addEdge(std::string vertex_one, std::string vertex_two)
{
	std::array<std::string, 2> edge = { vertex_one, vertex_two };
	std::vector<std::array<std::string, 2>>::iterator it = std::find(edges.begin(), edges.end(), edge);
	if (!(it != edges.end()))
	{
		edges.push_back({ vertex_one, vertex_two });
		std::cout << "Added edge (" << vertex_one << " - " << vertex_two << ")" << std::endl;
	}
	else {
		std::cout << "Edge ('" << edge[0] << "' - '" << edge[1] << "') already present." << std::endl;
	}
}

void Graph::removeEdge(std::string vertex_one, std::string vertex_two)
{
	std::array<std::string, 2> edge = { vertex_one, vertex_two };
	std::vector<std::array<std::string, 2>>::iterator it = std::find(edges.begin(), edges.end(), edge);
	// Check if the element was found
	if (it != edges.end()) {
		// Erase the element using the iterator
		edges.erase(it);
	}
	else {
		std::cout << "Edge ('" << edge[0] << "' - '" << edge[1] << "') not found." << std::endl;
	}
}
void Graph::removeVertex(std::string vertex)
{
	std::vector<std::string>::iterator it = std::find(vertices.begin(), vertices.end(), vertex);
	if (it != vertices.end()) {
		vertices.erase(it);
	}
	else {
		std::cout << "Vertex '" << vertex << "' not found." << std::endl;
	}
}

void Graph::printGraph()
{
	std::cout << "Vertices: \n";
	for (std::string vertex : vertices)
	{
		std::cout << vertex << std::endl;
	}
	std::cout << "Edges: \n";
	for (std::array<std::string, 2> edge : edges)
	{
		std::cout << "('" << edge[0] << "' - '" << edge[1] << "')" << std::endl;
	}
}