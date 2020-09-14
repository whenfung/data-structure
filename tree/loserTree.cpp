// 败者树的实现，用于 m 路平衡归并 
// 原理：2个子结点比较后的败者（较大值）放入它们的父结点，而胜者（较小值）送到它们父结点的父结点去再作比较
// 败者树每一次维护，必然是从叶子节点到根节点的一条路径
 
#include <iostream>
#include <algorithm> 

using namespace std;

#define M 5       // 5 路平衡树 

void adjust(int loserTree[], int leaves[], int i) {
	int p = (M+i)/2;                            // 叶子结点的父结点 
	while(p > 0 && loserTree[p] >= 0) {         // 这是填充路径的过程 
		if (leaves[i] > leaves[loserTree[p]]) 
			swap(i, loserTree[p]);
		p = p/2;
	} 
	loserTree[p] = i;
}

int main() {
	int leaves[] = {10, 9, 20, 6, 12};       // M 片叶子 
	int loserTree[M];                        // 败者树，这里只包含非叶结点，非叶结点存储叶子结点的索引 
		
	for(int i = 0; i < M; i++)               // 非叶结点全部置空 
		loserTree[i] = -1;
	
	for(int i = M-1; i >= 0; i--)           // 向败者树插入 n 个结点 
		adjust(loserTree, leaves, i);       
	
	leaves[3] = 15;     // 更新第 4 路
	adjust(loserTree, leaves, 3); 
	
	for(int i = 0; i < M; i++)
		cout << loserTree[i] << " ";
	cout << endl; 
	return 0;
} 
