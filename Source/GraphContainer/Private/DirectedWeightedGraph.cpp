#include "DirectedWeightedGraph.h"

template<typename NodeClass, typename EdgeClass>
inline bool DirectedWeightedGraph<NodeClass, EdgeClass>::HasNode(const NodeClass& Node) const
{
	return NodeMap.Contains(Node.ID);
}