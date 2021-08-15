#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <MyGraph.h>
#include <Edge.h>
using namespace std;

int main()
{
	char vertex[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	MGraph* graph = new MGraph(9);
	for (char ch : vertex) {
		graph->addVertex(ch);
	}
	graph->insertEdges(0, 1, 12);
	graph->insertEdges(0, 2, 8);
	graph->insertEdges(0, 3, 3);
	graph->insertEdges(1, 6, 3);
	graph->insertEdges(2, 4, 5);
	graph->insertEdges(4, 8, 7);
	graph->insertEdges(7, 8, 4);
	graph->insertEdges(3, 7, 2);
	graph->insertEdges(3, 5, 16);
	graph->insertEdges(5, 6, 1);
	graph->showGraph();
	//cout << "广度优先遍历结果为:" << ":" << endl;
	//graph->bfs();
	//graph->prim(0);
	graph->kruskal();
	graph->release();
	delete graph;
	return 0;
}
