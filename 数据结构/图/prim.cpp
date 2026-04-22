#include<iostream>
#include<climits>
using namespace std;
typedef int Edgetype;
typedef char Vertextype;
#define Max_size 100
#define M INT_MAX
class Graph
{
public:
	Vertextype vertex[Max_size];
	Edgetype arc[Max_size][Max_size];
	int Edge_num;
	int Vertex_num;
};
void createGraph(Graph* G)
{
	G->Edge_num = 8;
	G->Vertex_num = 9;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	for (int i = 0; i < G->Vertex_num; i++)
	{
		for (int j = 0; j < G->Vertex_num; j++)
		{
			G->arc[i][j] = M;
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
		}
	}
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;
	for (int i = 0; i < G->Vertex_num; i++)
	{
		for (int j = 0; j < G->Vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
void prim(Graph* G)
{
	int i, j, k;
	k = 0;
	int min = M;
	int weight[Max_size];
	int vex_index[Max_size];weight[0] = 0;
		vex_index[0] = 0;for (i = 1; i < G->Vertex_num; i++)
		{
			weight[i] = G->arc[0][i];
			vex_index[i] = 0;//值表示出发点，下标表示终点
		}
	for (i = 1; i < G->Vertex_num; i++)
	{
		j = 0;
		k = 0;
		min = M;
		
		
		while (j < G->Vertex_num)
		{
			if (weight[j] < min && weight[j] != 0)
			{
				min = weight[j];
				k = j;
			}
			j++;
		}
		cout << "("<<G->vertex[vex_index[k]]<<G->vertex[k]<<")" << endl;
		weight[k] = 0;//k顶点已经加入最小生成树
		for (j = 0; j < G->Vertex_num; j++)
		{
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];
				vex_index[j] = k;//vex_indx[终点]=起点
			}
		}

	}
}
int main()
{
	Graph* G=new Graph;
	createGraph(G);
	prim(G);
	return 0;
}
