#include <iostream>
#include <queue>

#define N 10
#define START 1
#define END   8 

// 迷宫, 1 代表障碍，0 代表通路
int maze[][10] = {            
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct Node{
	int i;
	int j;
	Node(int i = 1, int j = 1) : i(i), j(j) {}
	Node(Node& other) {
		i = other.i;
		j = other.j;
	}
};

bool BFS(int i, int j){
	std::queue<Node> q;
	q.push(Node(i.j));
	Node currentNode(i,j);
	while(!q.empty()) {
		
	}
	return false;
}

int main() {
	BFS(START,START);
	return 0;
}
