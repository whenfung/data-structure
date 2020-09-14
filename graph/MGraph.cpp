// 图的邻接矩阵存储实现 
// 这里的实现是有向图，无向图反向再添加边即可 

#include <iostream>
#include <vector> 

struct MGraph {
	std::vector<char> vex;                   // 顶点表
	std::vector<std::vector<int>> edge;      // 邻接矩阵，边表 
	int vexnum, arcnum;                      // 图的当前顶点数和弧数 
	MGraph(int n) : vexnum(n), arcnum(0) {
		vex.resize(n);                  
		edge.resize(n);                      // 默认全部元素为 0 
		for(int i = 0; i < n; i ++) {
			edge[i].resize(n);
		}
	}
	void insertEdge(int s, int e, int w) {
		edge[s][e] = w;
	}
	void print(){
		for(int i = 0; i < vexnum; i ++) {
			for(int j = 0; j < edge[i].size(); j ++) {
				std::cout << edge[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}; 

int main() {
	int N, M;     // 顶点个数 N 和弧数 M 
	std::cin >> N >> M;
	MGraph graph(N);
	int s, e, w;
	for(int i = 0; i < M; i++) {
		std::cin >> s >> e >> w;
		graph.insertEdge(s, e, w);
	} 
	graph.print(); 
	return 0;
} 

/*
input 
6 9
0 1 5
1 2 4
2 0 8
2 5 9
3 2 5
3 5 6
4 3 5
5 4 1
5 0 3

output
0 5 0 0 0 0
0 0 4 0 0 0
8 0 0 0 0 9
0 0 5 0 0 6
0 0 0 5 0 0
3 0 0 0 1 0
*/

