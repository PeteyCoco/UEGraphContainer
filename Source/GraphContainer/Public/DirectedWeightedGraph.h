#pragma once
#include <lemon/list_graph.h>

/*
*	A container for directed weighted graphs
* 
*	NodeClass and EdgeClass must both have a public integer member variable 'ID' that uniquely
*	identifies the nodes and edges in the graph.
*/
template <typename NodeClass, typename EdgeClass>
class DirectedWeightedGraph
{
public:
	// Aliases for the node and edge ID integer variable
	typedef int FNodeRef;
	typedef int FEdgeRef;

private:
	// Aliases for Lemon's internal types
	typedef lemon::ListDigraph::Node LemonNode;
	typedef lemon::ListDigraph::Arc LemonEdge;

	inline LemonNode ToLemonNode(const NodeClass& Node) const { return NodeMap[Node.ID]; }

	inline LemonNode LemonAddNode() { return graph.addNode(); }

	inline LemonEdge LemonAddEdge(const LemonNode& Origin, const LemonNode& Destination) { 
		return graph.addArc(Origin, Destination); 
	}

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

	// Counts the number of incoming edges on a node
	inline int NumInEdges(const NodeClass& Node) const { return lemon::countInArcs(graph, ToLemonNode(Node)); }

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


