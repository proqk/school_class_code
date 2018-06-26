#include <stdio.h>
#include <queue>
#include "AdjMatGraph.h"
using namespace std;

void InitGraph(Graph *g){
	g->n = 0;
	for (int i = 0; i < MAX_V; i++){
		for (int j = 0; j < MAX_V; j++){
			g->map[i][j] = 0;
		}
	}
}

void InsertVertex(Graph *g, int v){
	if (v > MAX_V){
		printf("최대 정점 개수 초과 근데 이거 왜함");
		return;
	}
	g->n = v;
}

void InsertEdge(Graph *g, int v1, int v2){
	if (g->n <= v1 || g->n <= v2){
		printf("\n그래프에 없는 정점임\n");
		return;
	}
	g->map[v1][v2] = 1;
	g->map[v2][v1] = 1;
}

void DisplayGraph(Graph *g){
	for (int i = 0; i < g->n; i++){
		for (int j = 0; j < g->n; j++){
			printf("%d ", g->map[i][j]);
		}
		printf("\n"); 
	}
}

void DFS(Graph *g, int v){
	g->visited[v] = 1;
	printf("%c ", v + 'A');
	
	for (int i = 0; i < g->n; i++){
//		printf("EE");
		if (!g->visited[i] && g->map[v][i]){
//			printf(">>%d\n", g->map[v][i]);
			DFS(g, i);
		}
	}
}

void BFS(Graph *g, int v){
	queue<int> q;
	q.push(v);
	g->visited[v] = 1;

	while (!q.empty()){
		v = q.front();
		q.pop();
		printf("%c ", v + 'A');
		for (int i = 0; i < g->n; i++){
			if (!g->visited[i] && g->map[v][i]){
				q.push(i);
				g->visited[i] = 1;
			}
		}
	}
}

int main(){
	Graph g;
	InitGraph(&g);
	InsertVertex(&g, 7); //정점의 개수가 7개인 무방향 그래프
//	printf(">>%d\n", g.n);
	InsertEdge(&g, 0, 2); //연결할 두 정점의 번호
	InsertEdge(&g, 0, 1);
	InsertEdge(&g, 1, 4);
	InsertEdge(&g, 1, 3);
	InsertEdge(&g, 3, 6);
	InsertEdge(&g, 4, 6);
	InsertEdge(&g, 5, 6);

	printf("g의 인접행렬 표현\n");
	DisplayGraph(&g);

	for (int i = 0; i < g.n; i++){
		g.visited[i] = 0; //방문기록 초기화
	}

	printf("\n\n깊이우선탐색결과\n");
	DFS(&g, 0);

	for (int i = 0; i < g.n; i++){
		g.visited[i] = 0; //방문기록 초기화
	}

	printf("\n\n너비우선탐색결과\n");
	BFS(&g, 0);
}                                                                                                                                                  
