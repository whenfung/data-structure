#include <iostream>

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

bool DFS(int i, int j){
	maze[i][j] = 1;   // 访问过的置一，表示不再访问 
	if(i == END && j == END) return true;
	if(!maze[i][j-1] && DFS(i, j-1)) {  // up 
		std::cout << "(" << i << "," << j-1 << ")" << std::endl;
		return true;
	} 
	if(!maze[i][j+1] && DFS(i, j+1)) { // down 
		std::cout << "(" << i << "," << j+1 << ")" << std::endl;
		return true;
	}
	if(!maze[i+1][j] && DFS(i+1, j)) { // right 
		std::cout << "(" << i+1 << "," << j << ")" << std::endl;
		return true;
	}
	if(!maze[i-1][j] && DFS(i-1, j)) { // left 
		std::cout << "(" << i-1 << "," << j << ")" << std::endl;
		return true;
	} 
	return false;
}

int main() {
	DFS(START,START);
	return 0;
}
