#include "Misc/AutomationTest.h"
#include <lemon/list_graph.h>
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDirectedWeightedGraph, "Graph Container.Directed Weighted Graph", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

class TestVertex
{
public:
	// Set the ID of the Vertex
	void SetID(int value) { ID = value; }

private:
	int ID{};
};

class TestEdge
{

};

template <typename VertexClass, typename EdgeClass>
class DirectedWeightedGraph
{
public:

	// Checks whether the graph contains no nodes
	bool IsEmpty() const { return true; }

	// Counts the number of vertices in the graph
	int NumVertices() const { return lemon::countNodes(graph); }

	// Adds a node to the graph
	void AddVertex(TestVertex& Vertex)
	{
		auto Node = graph.addNode();
		Vertex.SetID(graph.id(Node));
	}

private:
	lemon::ListDigraph graph{};
};

bool FDirectedWeightedGraph::RunTest(FString const& Parameters) {

	// Graph is created empty
	{
		DirectedWeightedGraph<TestVertex, TestEdge> graph;

		TestTrue(TEXT("Graph is created empty"), graph.IsEmpty());
	}

	// Adding node increases the size of the graph to one
	{
		DirectedWeightedGraph<TestVertex, TestEdge> graph;
		TestVertex V{};

		graph.AddVertex(V);

		TestEqual(TEXT("Graph must contain one node"), graph.NumVertices(), 1);
	}

	return true;
}