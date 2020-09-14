// 无向图的邻接多重表 

#include <iostream>
#include <vector> 

struct ArcNode {                 // 边表结点 
	bool mark;                   // 访问标记
	int avex, bvex;              // 分别指向该弧的两个结点
	ArcNode *alink, *blink;     // 分别指向两个顶点的下一条边
	int info;                    // 相关信息指针 
	ArcNode(int a, int b, int info) 
		: avex(a), bvex(b), info(info), alink(NULL), blink(NULL), mark(false){}
}; 

struct VNode {                  // 顶点表结点 
	int data;                   // 顶点信息
	ArcNode *firstedge;         // 指向第一条依附该顶点的边 
	VNode() : data(0), firstedge(NULL){};  // 默认构造函数 
	void addArc(int i, ArcNode *newArc){
		if(firstedge == NULL) firstedge = newArc;
		else {
			if(i == newArc->avex)  
				newArc->alink = firstedge;
			else                  
				newArc->blink = firstedge;
			firstedge = newArc;
		}
	} 
	void print(int i){
		ArcNode *it = firstedge;               // 开始遍历 
		while(it != NULL) {
			if(it->avex == i) {                // 边里面 a 表示 i 
				if(!it->mark) {                // 该结点没有被访问过 
					it->mark = true;
					std::cout << it->bvex << " "; 
				} 
				it = it->alink;                // 找下一个和 i 相邻的结点 
			}
			else{                              // 边里面 b 表示 i 
				if(!it->mark) {                // 该结点没有被访问过 
					it->mark = true;
					std::cout << it->avex << " "; 
				} 
				it = it->blink;
			}
		}
		std::cout << std::endl; 
	}
}; 

struct AMLGraph {
	std::vector<VNode> adjmulist;  // 邻接表 
	AMLGraph(int N) {
		adjmulist.resize(N);
	}
	void addArc(int a, int b, int info){
		ArcNode *newArc = new ArcNode(a, b, info);
		adjmulist[a].addArc(a, newArc); 
		adjmulist[b].addArc(b, newArc);
	} 
	void print(){
		for(int i = 0; i < adjmulist.size(); i++) {
			std::cout << i << " : ";
			adjmulist[i].print(i); // 要分辨按 alink 遍历还是 blink 遍历 
		}
		std::cout << std::endl;
	}
}; 

int main() {
	int N, M;    // 结点树 N 和边数 M
	std::cin >> N >> M;
	AMLGraph graph(N);
	int a, b, info;
	for(int i = 0; i < M; i++) {
		std::cin >> a >> b >> info;
		graph.addArc(a, b, info);
	}
	graph.print();
	return 0;
} 


/*
input
5 6
0 1 1
0 3 2
2 1 3
2 3 4
4 1 5 
2 4 6
output
0 : 3 1
1 : 4 2
2 : 4 3
3 :
4 :
*/
