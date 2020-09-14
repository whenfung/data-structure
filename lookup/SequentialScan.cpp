// 线性表的顺序查找实现

#include <iostream>

struct SSTable {  // 查找表的数据结构 
	int *elem;    // 元素存储空间基址，建表时按实际长度分配，0 号单位留空
	int TableLen; // 表的长度 
};

int Search_Seq(SSTable ST, int key) {
	// 在顺序表 ST 中顺序查找关键字为 key 的元素。 
	ST.elem[0] = key;   // "哨兵" 
	for(int i = ST.TableLen; ST.elem[i] != key; --i);  
	return i;  // 若表中不存在关键字为 key 的元素，将查找到 i 为 0 时退出 for 循环 
} 

int main() {
	
	return 0;
} 
