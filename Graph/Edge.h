#pragma once
#include <cstdio>
using namespace std;
class Edge {
public:
	char start;
	char end;
	int weight;

	void init(char start, char end, int weight);
	Edge();
};