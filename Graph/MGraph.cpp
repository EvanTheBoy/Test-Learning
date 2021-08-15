#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <MyGraph.h>
using namespace std;

MGraph::MGraph(int n)
{
	this->vertexNum = n;
	this->vertex = new char[n];
	this->weight = new int* [n]();
	this->visited = new bool[n]();
	for (int i = 0; i < n; ++i) {
		this->weight[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			weight[i][j] = INT_MAX;
		}
	}
	this->edgesNum = 0;
	this->index = 0;
}

void MGraph::showGraph()
{
	int len = this->vertexNum;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << this->weight[i][j] << " ";
		}
		cout << endl;
	}
}

void MGraph::addVertex(char vex)
{
	vertex[this->index++] = vex;
}

char MGraph::getVertexByIndex(int index)
{
	return this->vertex[index];
}

void MGraph::insertEdges(int v1, int v2, int val)
{
	weight[v1][v2] = val;
	weight[v2][v1] = val;
	++edgesNum;
}

void MGraph::dfs(int i)
{
	int len = this->vertexNum;
	cout << getVertexByIndex(i) << " ";
	visited[i] = true;
	int next = getNextVertex(i);
	while (next != -1)
	{
		if (!visited[next]) {
			dfs(next);
		}
		next = getNextVertex(i, next);
	}
}

void MGraph::dfs()
{
	int len = this->vertexNum;
	for (int i = 0; i < len; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

void MGraph::bfs(int i)
{
	cout << getVertexByIndex(i) << " ";
	int head;
	int neighbor;
	this->visited[i] = true;
	q.push(i);
	while (!q.empty())
	{
		head = q.front();
		q.pop();
		neighbor = getNextVertex(head);
		while (neighbor != -1)
		{
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				cout << getVertexByIndex(neighbor) << " ";
				q.push(neighbor);
			}
			neighbor = getNextVertex(head, neighbor);
		}
	}
}

void MGraph::bfs()
{
	int len = this->vertexNum;
	for (int i = 0; i < len; ++i) {
		if (!visited[i]) {
			bfs(i);
		}
	}
}

int MGraph::getNextVertex(int index)
{
	int len = this->vertexNum;
	for (int i = 0; i < len; ++i) {
		if (weight[index][i] != INT_MAX) {
			return i;
		}
	}
	return -1;
}

int MGraph::getNextVertex(int v1, int v2)
{
	int len = this->vertexNum;
	for (int i = v2 + 1; i < len; ++i) {
		if (weight[v1][i] != INT_MAX) {
			return i;
		}
	}
	return -1;
}

void MGraph::prim(int v)
{
	int count = 0;
	int num = this->vertexNum;
	int minWeight = INT_MAX;
	this->visited[v] = true;
	int h1 = -1;
	int h2 = -1;
	for (int k = 1; k < num; ++k) {
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				if (this->visited[i] && !this->visited[j] && this->weight[i][j] < minWeight) {
					minWeight = this->weight[i][j];
					h1 = i; 
					h2 = j; 
				}
			}
		}
		count += this->weight[h1][h2];
		printf("边:<%c,%c> 权值:%d\n", this->vertex[h1], this->vertex[h2], this->weight[h1][h2]);
		visited[h2] = true;
		minWeight = INT_MAX;
	}
	cout << "最小生成树的权值为:" << count << endl;
}

int MGraph::getPosition(char ch)
{
	int len = this->vertexNum;
	for (int i = 0; i < len; ++i) {
		if (this->vertex[i] == ch) {
			return i;
		}
	}
	return -1;
}

Edge* MGraph::getEdges()
{
	int index = 0;
	int num = this->vertexNum;
	Edge* edge = new Edge[this->edgesNum];
	for (int i = 0; i < num; ++i) {
		for (int j = i + 1; j < num; ++j) {
			if (this->weight[i][j] != INT_MAX) {
				edge[index++].init(this->vertex[i], this->vertex[j], this->weight[i][j]);
			}
		}
	}
	return edge;
}

int MGraph::getEnd(int ends[], int i)
{
	while (ends[i] != 0)
	{
		i = ends[i];
	}
	return i;
}

void MGraph::sort(Edge arr[])
{
	for (int i = this->edgesNum - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j + 1].weight < arr[j].weight) {
				Edge temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void MGraph::kruskal()
{
	int total = 0;
	int edgesNum = this->edgesNum;
	int* ends = new int[this->vertexNum]();
	Edge* edge = getEdges();
	sort(edge);
	for (int i = 0; i < edgesNum; ++i) {
		int p1 = getPosition(edge[i].start);
		int p2 = getPosition(edge[i].end);
		int m = getEnd(ends, p1);
		int n = getEnd(ends, p2);
		if (m != n) {
			ends[m] = n;
			total += edge[i].weight;
			printf("边:<%c,%c> 权值:%d\n", edge[i].start, edge[i].end, edge[i].weight);
		}
	}
	cout << "最小生成树的权值:" << total << endl;
	delete[] edge;
}

void MGraph::release()
{
	int len = vertexNum;
	for (int i = 0; i < len; ++i) {
		delete[]weight[i];
	}
	weight = NULL;
	delete[] visited;
	delete[] vertex;
}
