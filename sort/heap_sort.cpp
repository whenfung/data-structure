#include <iostream>
#include <algorithm>

using namespace std;

// 本函数和堆排序无关，和堆插入有关 
template<typename T>  
void adjust_up(T arr[], int k) {  // 插入一个新元素到堆的最后，然后调整堆 
	T temp = arr[k]; 
	int i = (k+1)/2-1; // 若结点值大于双亲结点，则将双亲结点向下调，并继续向上比较
	while(i>=0 && arr[i] < temp) { // 父结点比新子结点小 
		arr[k] = arr[i];     // 父结点下调
		k = i;
		i = (k+1)/2-1; 
	} 
	arr[k] = temp;    // 复制到最终位置 
} 

template<typename T>
void adjust_down(T arr[], int k, int len) {
	T temp = arr[k];                             // 暂存待更新根结点 
	for (int i = k*2+1; i < len; i = k*2+1) {    // 沿 key 较大的子结点向下筛选 
		if (i+1 < len && arr[i] < arr[i+1])       
			i ++;                                // 取 key 较大的子结点的下标
		if(temp >= arr[i]) break;                // 筛选结束 
		else {                     
			arr[k] = arr[i];                     // 将 arr[i] 调整到双亲结点上 
			k = i;                               // 修改 k 值，进行下一级检测 
		} 
	} 
	arr[k] = temp;           // 被筛选结点的值放入最终位置 
}
 
template<typename T>
void build_max_heap(T arr[], int len) { 
	for(int i = len/2-1; i >= 0; i--) // 从 i=[n/2]-1~1，反复调整堆 
		adjust_down(arr, i, len);
} 

template<typename T>
void heap_sort(T arr[], int len) {
	build_max_heap(arr, len);            // 初始建堆 
	for (int i = len - 1; i > 0; i--) {  // n-1 趟的交换和建堆过程 
		swap(arr[0], arr[i]);            // 输出堆顶元素 (和堆低元素交换) 
		adjust_down(arr, 0, i);          // 这里，把剩下的 i-1 个元素整理成堆 
	}
}

int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
