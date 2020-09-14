// 有向图的十字链表

#include <iostream>
#include <vector>

struct ArcNode {                                 // 弧结点，记录弧的信息 
	int sv, ev;                                  // 该弧的起点和终点 
	int info;                                    // 弧的信息 
	ArcNode *slink, *elink;                      // 指向起点相同的弧结点和指向终点相同的弧结点 
	ArcNode(int s, int e, int info)            
		: sv(s), ev(e), info(info), slink(NULL), elink(NULL) {};
};

struct VNode {                                  // 顶点表结点
	int data;                                   // 顶点信息 
	ArcNode *start, *end;                       // 作为起点的弧链表和作为终点的弧链表 
	VNode() : data(0), start(NULL), end(NULL) {};
	void addStart(ArcNode *newArc) {            // 添加起点相同的弧 
		if(start == NULL) start = newArc;
		else {
			newArc->slink = start;              // 往头部插入更快 
			start = newArc;     
		}
	}
	void addEnd(ArcNode *newArc) {
		if(end == NULL) end = newArc;
		else {
			newArc->elink = end;    // 往头部插入更快 
			end = newArc; 
		}
	} 
	void print(){  
		for(auto it = start; it != NULL; it = it->slink)
			std::cout << it->ev << " ";
		std::cout << std::endl;
	}
}; 

struct GLGraph {
	std::vector<VNode> vex;     // 所有顶点
	GLGraph(int N) {
		vex.resize(N);          // 顶点存储结构 
	}
	void addArc(int s, int e, int info) {
		ArcNode *newArc = new ArcNode(s, e, info);
		vex[s].addStart(newArc);   // 以 s 为起点的弧 
		vex[e].addEnd(newArc);     // 以 e 为终点的弧 
	}
	void print(){
		for(int i = 0; i < vex.size(); i++) {
			std::cout << i << " : ";
			vex[i].print(); 
		}
		std::cout << std::endl;
	}
}; 

int main() {
	int N, M;      // 结点个数 N 和边数 M
	std::cin >> N >> M;
	GLGraph graph(N);
	int s, e, w;
	for(int i = 0; i < M; i++){
		std::cin >> s >> e >> w;
		graph.addArc(s, e, w);
	}
	graph.print();
	return 0;
} 

/*
input
4 7 
0 1 1
0 2 2
2 1 3
2 3 4
3 2 5
3 1 6
3 0 7
output 
0 : 2 1
1 :
2 : 3 1
3 : 0 1 2
*/
