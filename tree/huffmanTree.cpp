// 利用哈夫曼树压缩英文序列，并解码 

#include <iostream>

struct Node {
	int weight;   // 权值域
	int lchild, rchild, parent;  // 左右指针，双亲指针 
};

void selectMin(Node a[], int n, int &j, int &k) {
	for (int i = 0; i < n; i++) {  // 初始化 j 
		if(a[i].parent == -1) {
			j = i;
			break;
		}
	}
	for(int i = 0; i < n; i++) {  // 挑出最小的根结点赋给 j 
		if(a[i].parent == -1 && a[j].weight > a[i].weight)
			j = i; 
	}
	for(int i = 0; i < n; i++) {  // 初始化  k 
		if(a[i].parent == -1 && i != j) {
			k = i;
			break;
		} 
	} 
	for(int i = 0; i < n; i++) {  // 挑出第二小的根结点给 k 
		if(a[i].parent == -1 && a[k].weight > a[i].weight && i != j) {
			k = i;
		} 
	}
} 

void createTree(Node huffTree[], int w[], int n) {
	for(int i = 0; i < 2*n-1; i++) {  // 初始化，所有结点均没有双亲和孩子  
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	for (int i = 0; i < n; i++) {    // 构造 n 棵单结点二叉树 
		huffTree[i].weight = w[i]; 
	}
	
	for(int i = n; i < 2*n-1; i++) {  // n-1 次合并 
		int j, k;
		selectMin(huffTree, i, j, k); // 查找权值最小的两个根结点，下标为 j, k
		// 将 j、k 合并，且 j 和 k 的双亲为 i
		huffTree[j].parent = i;
		huffTree[k].parent = i;
		huffTree[i].lchild = j;
		huffTree[i].rchild = k;
		huffTree[i].weight = huffTree[j].weight + huffTree[k].weight;  
	} 
}

void print(Node huffTree[], int n) {
	std::cout << "index weight  parent  lChild  rChild" << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << i << "\t";
        std::cout << huffTree[i].weight << "\t";
        std::cout << huffTree[i].parent << "\t";
        std::cout << huffTree[i].lchild << "\t";
        std::cout << huffTree[i].rchild << std::endl;
	}
}

int main() {
	int w[] = { 5, 29, 7, 8, 14, 23, 3, 11 }; // 权值集合 8 个 
	Node huffTree[15];      // 存储结构 : 2n-1 个结点
	createTree(huffTree, w, 8);      
	print(huffTree, 15);  
	return 0;
} 
