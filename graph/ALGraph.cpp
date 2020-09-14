// 图的邻接表
// 这里具体实现的是有向图，无向图的话还需要加反向边 

#include <iostream>
#include <vector> 
#include <list>

struct ArcNode {         // 边表结点 
	int adjvex;          // 该弧所指向的顶点的位置
	int info;            // 网的边权值 
	ArcNode(int adjvex = 0, int info = 0) : adjvex(adjvex), info(info){} 
}; 

struct VNode {                         // 顶点表结点 
	int data;                          // 顶点信息
	std::list<ArcNode> adjarc;         // 邻边 
	VNode() : data(0) {}  // 初始化 
	void addArc(int i, int info) {
		adjarc.push_back(ArcNode(i, info)); 
	}
	void print(){
		for(auto& arc : adjarc)
			std::cout << arc.adjvex << " ";
		std::cout << std::endl;
	}
}; 

struct ALGraph {
	std::vector<VNode> vertices;   // 邻接表
	int vexnum, arcnum;            // 图的顶点数和弧数 
	ALGraph (int N) : vexnum(N) {
		vertices.resize(N);   
		arcnum = 0;
	}
	void initVex();       // 初始化顶点，如果顶点需要存储信息的话 
	void insertArc(int start, int end, int info) {
		arcnum ++;
		vertices[start].addArc(end, info); 
	}  
	void print() {
		std::cout << "vexnum : " << vexnum << std::endl;
		std::cout << "arcnum : " << arcnum << std::endl;
		for(int i = 0; i < vexnum; i++) {
			std::cout << i << " : ";
			vertices[i].print();
		}
	} 
}; 

int main(){
	int N, M;       // N 个结点，M 条边      
	std::cin >> N >> M;  
	ALGraph graph(N);
	int s, e, d;
	for(int i = 0; i < M; i++) {
		std::cin >> s >> e >> d;
		graph.insertArc(s, e, d); 
	}
	graph.print();
	return 0;
} 

/*
input
6 8
0 1 3
0 3 4
3 1 6
1 4 2
4 3 3
2 4 3
2 5 8
5 5 7

output
0 : 1 3
1 : 4
2 : 4 5
3 : 1
4 : 3
5 : 5
*/ 
