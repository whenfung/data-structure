#include <iostream>

#define MAXSIZE 50

template<typename ElemType> // 模板参数为数组元素类型和数组长度 
struct SqList {                         // 顺序表类型定义 
	ElemType data[MAXSIZE];              // 顺序表的元素  
	int maxSize, length;                 // 顺序表的最大长度和当前长度 
	SqList() : maxSize(MAXSIZE),length(0) {}
}; 

template<typename ElemType> // 模板参数为数组元素类型和数组长度 
struct SeqList {                         // 顺序表类型定义 
	ElemType *data;                      // 指向动态分配数组的指针  
	int maxSize, length;                 // 顺序表的最大长度和当前长度 
    SeqList() : maxSize(MAXSIZE),length(0) {
    	data = new ElemType[MAXSIZE];
    }
}; 

template<typename ElemType>
bool ListInsert(SqList<ElemType> &L, int i, ElemType e) {
	// 本算法实现将元素 e 插入到顺序表 L 中第 i 个位置
	if(i<1 || i > L.length+1)  // 判断 i 的范围是否有效 
		return false; 
	if(L.length >= L.maxSize)  // 当前存储空间已满，不能插入
		return false;
	for(int j = L.length; j >= i; j--) // 将第 i 个元素及之后的元素后移
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;     // 在位置 i 处放入 e
	L.length ++; 
	return true; 
}

template<typename ElemType>
bool ListDelete(SqList<ElemType> &L, int i, ElemType &e) {
	// 本算法实现删除顺序表 L 中第 i 个位置的元素
	if(i<1 || i > L.length) // 判断 i 的范围是否有效
		return false;
	e = L.data[i-1];
	for(int j = i; j < L.length; j++) // 将第 i 个位置后的元素前移
		L.data[j-1] = L.data[j];
	L.length --;                     // 线性表长度减 1
	return true; 
}

template<typename ElemType>
int LocateElem(SqList<ElemType> L, ElemType e) {
	// 本算法实现查找顺序表中值为 e 的元素，如果查找成功，返回元素位序，否则返回 0 
	for(int i = 0; i < L.length; i++)  
		if (L.data[i] == e)
			return i+1;  // 下标为 i 的元素值等于 e，返回其位序 i+1 
	return 0;    // 退出循环，说明查找失败。 
}		
 

template<typename ElemType>
void PrintList(SqList<ElemType> L) { 
	for(int i = 0; i < L.length; i++)
		std::cout << L.data[i] << " ";
	std::cout << std::endl;
}

int main(){
	int e;
	SqList<int> L;
	ListInsert(L,1,1);
	ListInsert(L,1,2);
	ListInsert(L,2,3);
	ListDelete(L,1,e);
	std::cout << LocateElem(L, 1) << std::endl; 
	PrintList(L);
	return 0;
}
