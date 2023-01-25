#include "Misc/AutomationTest.h"
#include "DirectedWeightedGraph.h"
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
public:
	// Unique edge identifier
	int ID{};
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
		TestNode N1{1};
		TestNode N2{2};
		TestEdge E{};

		graph.AddEdge(E, N1, N2);

		TestEqual(TEXT("Graph must contain two nodes"), graph.NumNodes(), 2);
		TestEqual(TEXT("Graph must contain one edge"), graph.NumEdges(), 1);
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
		TestNode N1{0};
		TestNode N2{100};

		graph.AddNode(N1);

		TestFalse(TEXT("Graph must not contain node not present in graph"), graph.HasNode(N2));
	}

	// Cannot add the same node twice
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 100 };

		graph.AddNode(N1);
		graph.AddNode(N1);

		TestEqual(TEXT("Adding node with same ID twice does nothing"), graph.NumNodes(), 1);
	}

	// Graph must contain the edge added to the graph
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 0 };
		TestNode N2{ 1 };
		TestEdge E{ 0 };

		graph.AddEdge(E, N1, N2);

		TestTrue(TEXT("Graph must contain the edge added to the graph"), graph.HasEdge(E));
	}

	// Graph does not contain edge not in graph
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 0 };
		TestNode N2{ 1 };
		TestEdge E1{ 0 };
		TestEdge E2{ 1 };

		graph.AddEdge(E1, N1, N2);

		TestFalse(TEXT("Graph must not contain an edge not in graph"), graph.HasEdge(E2));
	}

	// Cannot add the same node twice
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 1 };
		TestNode N2{ 2 };
		TestNode N3{ 3 };
		TestEdge E{ 1 };

		graph.AddEdge(E, N1, N2);
		graph.AddEdge(E, N2, N3);

		TestEqual(TEXT("Adding edge with same ID twice does nothing"), graph.NumEdges(), 1);
	}

	// Adding two coincident edges yields a graph with 3 nodes and two edges
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 1 };
		TestNode N2{ 2 };
		TestNode N3{ 3 };
		TestEdge E1{ 1 };
		TestEdge E2{ 2 };

		graph.AddEdge(E1, N1, N2);
		graph.AddEdge(E2, N2, N3);

		TestEqual(TEXT("Adding two coincident edges yields 3 nodes in graph"), graph.NumNodes(), 3);
	}

	// FGraphAStar interface tests
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 1 };

		graph.AddNode(N1);

		TestTrue(TEXT("IsValidRef() is true when node is in graph"), graph.IsValidRef(1));
		TestFalse(TEXT("IsValidRef() is false when node is not in graph"), graph.IsValidRef(2));
	}

	// Count the in, out, and incident edges of a node
	{
		DirectedWeightedGraph<TestNode, TestEdge> graph;
		TestNode N1{ 1 };
		TestNode N2{ 2 };
		TestNode N3{ 3 };		
		TestNode N4{ 4 };

		graph.AddEdge(TestEdge{ 1 }, N1, N2);
		graph.AddEdge(TestEdge{ 2 }, N1, N3);
		graph.AddEdge(TestEdge{ 3 }, N1, N1);
		graph.AddEdge(TestEdge{ 4 }, N4, N1);

		TestEqual(TEXT("Count the in-degree of N1"), graph.NumInEdges(N1), 2);
	}

	return true;
}