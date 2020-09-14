// 折半查找算法实现

#include <iostream>

struct SeqList{
	int *elem;
	int TableLen;
};

int Binary_Search(SeqList L, int key) {
	// 在有序表 L 中查找关键字 key 的元素，若存在则返回其位置，不存在则返回 -1
	int low=0, high = L.TableLen-1, mid;
	while(low <= high) {
		mid = (low + high) /2;   // 取中间位置
		if(L.elem[mid] == key) 
			return mid;          // 查找成功则返回所在位置
		else if(L.elem[mid] > key)
			high = mid -1;      // 从前半部分继续查找
		else 
			low = mid + 1;    // 从后半部分继续查找 
	} 
	return -1; 
}

int main(){
	
	return 0;
} 
