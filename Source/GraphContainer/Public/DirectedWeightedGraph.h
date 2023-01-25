#pragma once
#include <lemon/list_graph.h>

/*
*	A container for directed weighted graphs
* 
*	NodeClass and EdgeClass must both have a public member variable 'ID' that uniquely
*	identifies the nodes and edges in the graph.
*/
template <typename NodeClass, typename EdgeClass>
class DirectedWeightedGraph
{
public:
	typedef int FNodeRef;
	typedef int FEdgeRef;

	typedef lemon::ListDigraph::Node LemonNode;
	typedef lemon::ListDigraph::Arc LemonEdge;


private:
	inline LemonNode ToLemonNode(const NodeClass& Node) const { return NodeMap[Node.ID]; }

public:
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

	/////////////////////////
	// FGraphAStar interface
	////////////////////////
	
	// Returns true if a node with the given reference is in the graph
	bool IsValidRef(FNodeRef NodeRef) const;

private:
	lemon::ListDigraph graph{};

	TMap<FNodeRef, LemonNode> NodeMap{};

	TMap<FEdgeRef, LemonEdge> EdgeMap{};

};


