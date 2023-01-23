#include "Misc/AutomationTest.h"
#include <lemon/list_graph.h>
#include "Tests/AutomationEditorCommon.h"

template<typename BundledVertex, typename BundledEdge>
class TDirectedWeightedGraph
{
public:
	bool IsEmpty() const { return true; }
};

class FTestVertex
{

};

class FTestEdge
{

};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDirectedWeightedGraph, "Graph Container.Directed Weighted Graph", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FDirectedWeightedGraph::RunTest(FString const& Parameters) {

	// Graph is created empty
	{
		lemon::ListDigraph h{};

		TestTrue(TEXT("Graph is created empty"), lemon::countNodes(h) == 0);
	}

	return true;
}