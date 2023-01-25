#include "DirectedWeightedGraph.h"

template<typename NodeClass, typename EdgeClass>
void DirectedWeightedGraph<NodeClass, EdgeClass>::AddNode(const NodeClass& Node)
{
	if (HasNode(Node))
	{
		return;
	}

	auto NodeHandle = graph.addNode();
	NodeMap.Add(Node.ID, NodeHandle);
}

template<typename NodeClass, typename EdgeClass>
inline bool DirectedWeightedGraph<NodeClass, EdgeClass>::HasNode(const NodeClass& Node) const
{
	return NodeMap.Contains(Node.ID);
}

template<typename NodeClass, typename EdgeClass>
void DirectedWeightedGraph<NodeClass, EdgeClass>::AddEdge(const EdgeClass& Edge, const NodeClass& Origin, const NodeClass& Destination)
{
	auto o = graph.addNode();
	auto d = graph.addNode();
	auto EdgeHandle = graph.addArc(o, d);
	EdgeMap.Add(Edge.ID, EdgeHandle);
}

template<typename NodeClass, typename EdgeClass>
bool DirectedWeightedGraph<NodeClass, EdgeClass>::HasEdge(const EdgeClass& Edge) const
{
	return EdgeMap.Contains(Edge.ID);
}


