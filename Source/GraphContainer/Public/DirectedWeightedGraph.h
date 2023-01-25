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
	bool IsEmpty() const { return true; }

	// Counts the number of nodes in the graph
	int NumNodes() const { return lemon::countNodes(graph); }

	// Adds a node to the graph
	void AddNode(const NodeClass& Node)
	{
		if (HasNode(Node))
		{
			UE_LOG(LogTemp, Error, TEXT("Cannot add the same node twice. No node added to graph."));
			return;
		}

		auto NodeHandle = graph.addNode();
		NodeMap.Add(Node.ID, NodeHandle);
	}

	// Check if the graph contains the given node
	bool HasNode(const NodeClass& Node) const;

	// Adds an edge to the graph from the origin node to the destination node
	void AddEdge(const EdgeClass& Edge, const NodeClass& Origin, const NodeClass& Destination)
	{
		auto o = graph.addNode();
		auto d = graph.addNode();
		auto EdgeHandle = graph.addArc(o, d);
		EdgeMap.Add(Edge.ID, EdgeHandle);
	}

	// Check if the graph contains the given edge
	bool HasEdge(const EdgeClass& Edge) const
	{
		return EdgeMap.Contains(Edge.ID);
	}


private:
	lemon::ListDigraph graph{};

	TMap<FNodeRef, lemon::ListDigraph::Node> NodeMap{};

	TMap<FNodeRef, lemon::ListDigraph::Arc> EdgeMap{};

};


