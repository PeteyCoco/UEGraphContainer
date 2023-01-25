#include "DirectedWeightedGraph.h"

template<typename NodeClass, typename EdgeClass>
void DirectedWeightedGraph<NodeClass, EdgeClass>::AddNode(const NodeClass& Node)
{
	if (HasNode(Node))
	{
		return;
	}
	NodeMap.Add(Node.ID, LemonAddNode());
}

template<typename NodeClass, typename EdgeClass>
inline bool DirectedWeightedGraph<NodeClass, EdgeClass>::HasNode(const NodeClass& Node) const
{
	return NodeMap.Contains(Node.ID);
}

template<typename NodeClass, typename EdgeClass>
void DirectedWeightedGraph<NodeClass, EdgeClass>::AddEdge(const EdgeClass& Edge, const NodeClass& Origin, const NodeClass& Destination)
{
	if (HasEdge(Edge))
	{
		return;
	}

	AddNode(Origin);
	AddNode(Destination);

	EdgeMap.Add(Edge.ID, LemonAddEdge(ToLemonNode(Origin), ToLemonNode(Destination)));
}

template<typename NodeClass, typename EdgeClass>
bool DirectedWeightedGraph<NodeClass, EdgeClass>::HasEdge(const EdgeClass& Edge) const
{
	return EdgeMap.Contains(Edge.ID);
}

template<typename NodeClass, typename EdgeClass>
bool DirectedWeightedGraph<NodeClass, EdgeClass>::IsValidRef(FNodeRef NodeRef) const
{
	return NodeMap.Contains(NodeRef);
}


