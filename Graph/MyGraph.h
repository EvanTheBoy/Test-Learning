#pragma once
#include <queue>
#include <Edge.h>
using namespace std;
class MGraph {
private:
	int vertexNum;
	char* vertex;
	int** weight;
	int edgesNum;
	bool* visited;
	int index;
	queue<int>q;

	void dfs(int i);
	void bfs(int i);
	int getNextVertex(int index);
	int getNextVertex(int v1, int v2);
	void sort(Edge arr[]);

public:
	MGraph(int n);
	char getVertexByIndex(int index);
	void dfs();
	void bfs();
	void showGraph();
	void insertEdges(int v1, int v2, int val);
	void addVertex(char vex);
	void release();
	void prim(int v);
	int getPosition(char ch);
	Edge* getEdges();
	int getEnd(int ends[], int i);
	void kruskal();
};