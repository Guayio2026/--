#include<iostream>
using namespace std;
typedef char Vertextype;
typedef int Edgetype;
#define Max_size 100
class Graph
{
public:
	Vertextype Vertex[Max_size];
	Edgetype arc[Max_size][Max_size];
	int Vertex_num;
	int Edge_num;

};
int visited[Max_size];
int queue[Max_size];
int front = 0;
int rear = 0;
void createGraph(Graph* G)
{
	G->Vertex_num = 9;
	G->Edge_num = 15;
	for (int i = 0; i < G->Vertex_num; i++)
	{
		for (int j = 0; j < G->Vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	G->Vertex[0] = 'A';
	G->Vertex[1] = 'B';
	G->Vertex[2] = 'C';
	G->Vertex[3] = 'D';
	G->Vertex[4] = 'E';
	G->Vertex[5] = 'F';
	G->Vertex[6] = 'G';
	G->Vertex[7] = 'H';
	G->Vertex[8] = 'I';
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;
	G->arc[5][6] = 1;
	G->arc[6][7] = 1;
	for (int i = 0; i < G->Vertex_num; i++)
	{
		for (int j = 0; j < G->Vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
void dfs(Graph*G,int i)
{
	visited[i] = 1;
	cout << G->Vertex[i] << endl;
	for (int j = 0; j < G->Vertex_num; j++)
	{
		if (visited[j] == 0 && G->arc[i][j] == 1)
		{
			dfs(G, j);
		}
	}
}
void revisited(Graph*G)
{
	for (int i = 0; i < G->Vertex_num; i++)
	{
		visited[i] = 0;
	}
}
void bfs(Graph* G)
{
	int i = 0;
	visited[i] = 1;
	queue[rear] = i;
	rear = (rear + 1) % Max_size;
	cout << G->Vertex[i] << endl;
	while (front != rear)
	{
		i = queue[front];
		front = (front + 1) % Max_size;
		for (int j = 0; j < G->Vertex_num; j++)
		{
			if (visited[j] == 0 && G->arc[i][j] == 1)//跟i顶点相关联的顶点全部入队
			{
				queue[rear] = j;
				rear = (rear + 1) % Max_size;
				visited[j] = 1;
				cout << G->Vertex[j] << endl;
			}

		}
	}
}
int main()
{
	Graph* G = new Graph;
	createGraph(G);
	dfs(G, 0);
	revisited(G);
	bfs(G);
	return 0;
}