#pragma once
#include <iostream>
using namespace std;

const int MAX_VERTEX = 10;
const int MAX_EDGE = 100;

struct EdgeType
{
	int from, to, weight;
};

class EdgeGraph
{
private:
	int vertex[MAX_VERTEX];
	int vertexNum, edgeNum;
	EdgeType edge[MAX_EDGE];
	int parent[MAX_VERTEX];

	void buildGraph();

	int findRoot(int index);

	void display(EdgeType currEdge);

public:
	EdgeGraph(int vexNum, int edNum);

	void Kruskal();

};