#pragma once
#include <lemon/list_graph.h>

/*
*	A container for directed weighted graphs
* 
*	NodeClass and EdgeClass must both have a public member int ID that uniquely
*	identifies the nodes and edges in the graph.
*/
template <typename NodeClass, typename EdgeClass>
class DirectedWeightedGraph
{
public:
	typedef int FNodeRef;

	// Checks whether the graph contains no nodes
	inline bool IsEmpty() const { return true; }

	// Counts the number of nodes in the graph
	inline int NumNodes() const { return lemon::countNodes(graph); }

	// Counts the number of edges in the graph
	inline int NumEdges() const { return lemon::countArcs(graph); }

	// Adds a node to the graph
	void AddNode(const NodeClass& Node);

	// Check if the graph contains the given node
	bool HasNode(const NodeClass& Node) const;

	// Adds an edge to the graph from the origin node to the destination node
	void AddEdge(const EdgeClass& Edge, const NodeClass& Origin, const NodeClass& Destination);

	// Check if the graph contains the given edge
	bool HasEdge(const EdgeClass& Edge) const;

private:
	lemon::ListDigraph graph{};

	TMap<FNodeRef, lemon::ListDigraph::Node> NodeMap{};

	TMap<FNodeRef, lemon::ListDigraph::Arc> EdgeMap{};

};


