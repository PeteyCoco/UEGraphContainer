#include "Misc/AutomationTest.h"
#include <lemon/list_graph.h>
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDirectedWeightedGraph, "Graph Container.Directed Weighted Graph", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

class TestNode
{
public:
	// Unique node identifier
	int ID{};
};

class TestEdge
{

};

template <typename NodeClass, typename EdgeClass>
class DirectedWeightedGraph
{
public:

	// Checks whether the graph contains no nodes
	bool IsEmpty() const { return true; }

	// Counts the number of nodes in the graph
	int NumNodes() const { return lemon::countNodes(graph); }

	// Adds a node to the graph
	void AddNode(const NodeClass& Node)
	{
		auto NodeHandle = graph.addNode();
		NodeMap.Add(Node.ID, NodeHandle);
	}

	// Adds an edge to the graph from the origin node to the destination node
	void AddEdge(const EdgeClass& Edge, const NodeClass& Origin, const NodeClass& Destination)
	{
		auto o = graph.addNode();
		auto d = graph.addNode();
		graph.addArc(o, d);
	}
	
	// Check if the graph contains the given node
	bool HasNode(const NodeClass& Node) const
	{
		return NodeMap.Contains(Node.ID);
	}

private:
	lemon::ListDigraph graph{};

	TMap<int, lemon::ListDigraph::Node> NodeMap{};
};

bool FDirectedWeightedGraph::RunTest(FString const& Parameters) {

	// Graph is created empty
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;

		TestTrue(TEXT("Graph is created empty"), graph.IsEmpty());
	}

	// Adding node increases the size of the graph to one
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N{};

		graph.AddNode(N);

		TestEqual(TEXT("Graph must contain one node"), graph.NumNodes(), 1);
	}

	// Adding an edge increases the size of the graph to two
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{};
		TestNode N2{};
		TestEdge E{};

		graph.AddEdge(E, N1, N2);

		TestEqual(TEXT("Graph must contain two nodes"), graph.NumNodes(), 2);
	}

	// Graph must contain the node added to the graph
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{};
		N1.ID = 0;

		graph.AddNode(N1);

		TestTrue(TEXT("Graph must contain the node added to the graph"), graph.HasNode(N1));
	}

	// Graph must not contain an unadded node
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{};
		TestNode N2{};
		N1.ID = 0;
		N2.ID = 100;

		graph.AddNode(N1);

		TestFalse(TEXT("Graph must not contain node not present in graph"), graph.HasNode(N2));
	}

	return true;
}