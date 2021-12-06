#include "EdgeGraph.h"

EdgeGraph::EdgeGraph(int vexNum, int edNum)
{
	this->vertexNum = vexNum;
	this->edgeNum = edNum;

	for (int i = 0; i < vertexNum; i++)
	{
		parent[i] = -1;
	}

	buildGraph();
}

void EdgeGraph::buildGraph()
{
	int vertex;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << "请输入顶点序号：";
		cin >> vertex;
		this->vertex[i] = vertex;
		cout << endl;
	}

	for (int j = 0; j < edgeNum; j++)
	{
		cout << "请输入边的起点、终点与权值：";
		cin >> edge[j].from >> edge[j].to >> edge[j].weight;
		cout << endl;
	}
	
}

void EdgeGraph::Kruskal()
{
	//sort(edge[]);//需要补充排序算法，将edge从小到大排序，然后for loop整个edge数组，将满足条件的edge作为MST

	int vertex1, vertex2;
	int num = 0;
	//循环整个edge数组
	for (int i = 0; i < edgeNum; i++)
	{
		//寻找from与to两个顶点的root
		vertex1 = findRoot(edge[i].from);
		vertex2 = findRoot(edge[i].to);
		//如果起始顶点from与结束顶点to的root不是同一个，说明他们不属于同一个树集合，这条edge满足MST的条件
		if (vertex1 != vertex2)
		{
			display(edge[i]);
			parent[vertex2] = vertex1;//用于在findRoot中寻找root节点
			
			//记录MST中当前的边的数量，如果num的数量是vertexNum-1，则说明MST已经有vertexNum个节点（MST的边数量等于节点数量-1），MST已经完整，提前退出循环
			num++;
			if (num == vertexNum - 1)
				return;
		}
	}
}

//递归寻找根节点
int EdgeGraph::findRoot(int index)
{
	//如果某个节点的parent是-1，则说明它本身就是根节点，返回该节点的序号index
	if (parent[index] == -1)
		return index;
	else//否则他不是根节点，递归该节点的父节点，直到寻找到根节点为止
		findRoot(parent[index]);
}

void EdgeGraph::display(EdgeType currEdge)
{
	cout << "（" << currEdge.from << ", " << currEdge.to << "）" << currEdge.weight << endl;
}

int main()
{
	int vexNum, edNum;
	cout << "请输入顶点数量：" << endl;
	cin >> vexNum;

	cout << "请输入邻边数量：" << endl;
	cin >> edNum;

	EdgeGraph eg(vexNum,edNum);

	eg.Kruskal();
	return 0;
}