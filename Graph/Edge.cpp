#include <Edge.h>
using namespace std;

Edge::Edge()
{
	this->start = 0;
	this->end = 0;
	this->weight = 0;
}

void Edge::init(char start, char end, int weight)
{
	this->start = start;
	this->end = end;
	this->weight = weight;
}
