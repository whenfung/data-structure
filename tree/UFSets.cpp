// 树的应用-并查集 

#include <iostream> 

#define SIZE 100

int UFSets[SIZE];  // 并查集定义

void initial(int s[]) {
	for(int i = 0; i < SIZE; i++) {
		s[i] = -1; 
	}
} 

int Find(int s[], int x) {
	while(s[x] >= 0)   // 循环寻找 x 的根
		x=s[x];
	return x;          // 根的 s[] 小于 0 
}

void Union(int s[], int root1, int root2) {
	// 要求 root1 与 root2 是不同的，且表示子集合的名字
	s[root2] = root1;        // 将根 root2 连接到另一根 root1 的下面 
} 

int main(){
	return 0;
} 

 
