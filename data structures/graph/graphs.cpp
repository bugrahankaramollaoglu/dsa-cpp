#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>

/* graphs represent relationships between objects.
They consist of nodes (or vertices) and edges (or arcs)
that connect pairs of nodes. Graphs can be directed or
undirected, weighted or unweighted. */

/* Graphs can be represented in various ways. Two common methods are:
	1. Adjacency Matrix
	2. Adjacency List 	*/

class Graph
{
private:
	int V;							 // Number of vertices
	std::vector<std::list<int>> adj; // Adjacency list

public:
	Graph(int V);									 // Constructor
	void addEdge(int v, int w);						 // Add an edge to the graph
	void BFS(int s);								 // Breadth-First Search
	void DFS(int s);								 // Depth-First Search
	void DFSUtil(int v, std::vector<bool> &visited); // Utility function for DFS
	void printGraph();								 // Print the graph
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

// Add an edge to the graph
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list
	adj[w].push_back(v); // Add v to w’s list, since the graph is undirected
}

// Breadth-First Search
void Graph::BFS(int s)
{
	std::vector<bool> visited(V, false);
	std::queue<int> queue;

	visited[s] = true;
	queue.push(s);

	while (!queue.empty())
	{
		s = queue.front();
		std::cout << s << " ";
		queue.pop();

		for (auto adjecent : adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push(adjecent);
			}
		}
	}
	std::cout << std::endl;
}

// Depth-First Search
void Graph::DFSUtil(int v, std::vector<bool> &visited)
{
	visited[v] = true;
	std::cout << v << " ";

	for (auto adjecent : adj[v])
	{
		if (!visited[adjecent])
		{
			DFSUtil(adjecent, visited);
		}
	}
}

void Graph::DFS(int v)
{
	std::vector<bool> visited(V, false);
	DFSUtil(v, visited);
	std::cout << std::endl;
}

// Print the graph
void Graph::printGraph()
{
	for (int v = 0; v < V; ++v)
	{
		std::cout << "\n Adjacency list of vertex " << v << "\n head ";
		for (auto x : adj[v])
		{
			std::cout << "-> " << x;
		}
		std::cout << std::endl;
	}
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(5); // 5 vertices numbered from 0 to 4

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	std::cout << "Graph adjacency list:" << std::endl;
	g.printGraph();

	std::cout << "\nBreadth First Traversal starting from vertex 0:" << std::endl;
	g.BFS(0);

	std::cout << "\nDepth First Traversal starting from vertex 0:" << std::endl;
	g.DFS(0);

	return 0;
}
