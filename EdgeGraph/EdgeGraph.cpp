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
		cout << "�����붥����ţ�";
		cin >> vertex;
		this->vertex[i] = vertex;
		cout << endl;
	}

	for (int j = 0; j < edgeNum; j++)
	{
		cout << "������ߵ���㡢�յ���Ȩֵ��";
		cin >> edge[j].from >> edge[j].to >> edge[j].weight;
		cout << endl;
	}
	
}

void EdgeGraph::Kruskal()
{
	//sort(edge[]);//��Ҫ���������㷨����edge��С��������Ȼ��for loop����edge���飬������������edge��ΪMST

	int vertex1, vertex2;
	int num = 0;
	//ѭ������edge����
	for (int i = 0; i < edgeNum; i++)
	{
		//Ѱ��from��to���������root
		vertex1 = findRoot(edge[i].from);
		vertex2 = findRoot(edge[i].to);
		//�����ʼ����from���������to��root����ͬһ����˵�����ǲ�����ͬһ�������ϣ�����edge����MST������
		if (vertex1 != vertex2)
		{
			display(edge[i]);
			parent[vertex2] = vertex1;//������findRoot��Ѱ��root�ڵ�
			
			//��¼MST�е�ǰ�ıߵ����������num��������vertexNum-1����˵��MST�Ѿ���vertexNum���ڵ㣨MST�ı��������ڽڵ�����-1����MST�Ѿ���������ǰ�˳�ѭ��
			num++;
			if (num == vertexNum - 1)
				return;
		}
	}
}

//�ݹ�Ѱ�Ҹ��ڵ�
int EdgeGraph::findRoot(int index)
{
	//���ĳ���ڵ��parent��-1����˵����������Ǹ��ڵ㣬���ظýڵ�����index
	if (parent[index] == -1)
		return index;
	else//���������Ǹ��ڵ㣬�ݹ�ýڵ�ĸ��ڵ㣬ֱ��Ѱ�ҵ����ڵ�Ϊֹ
		findRoot(parent[index]);
}

void EdgeGraph::display(EdgeType currEdge)
{
	cout << "��" << currEdge.from << ", " << currEdge.to << "��" << currEdge.weight << endl;
}

int main()
{
	int vexNum, edNum;
	cout << "�����붥��������" << endl;
	cin >> vexNum;

	cout << "�������ڱ�������" << endl;
	cin >> edNum;

	EdgeGraph eg(vexNum,edNum);

	eg.Kruskal();
	return 0;
}