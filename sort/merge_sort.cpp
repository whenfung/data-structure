#include <iostream>

using namespace std;
 
template<typename T>
void merge(T arr[], T temp[], int low, int mid, int high) {
	int i = low, j = mid+1, k = low;
	while(i <= mid && j <= high){   // 谁小谁上 
		if(arr[i] > arr[j]) 
			temp[k++] = arr[j++];
		else
			temp[k++] = arr[i++];
	}
	while(i <= mid) temp[k++] = arr[i++];         // 处理剩余数据 
	while(j <= high) temp[k++] = arr[j++];  
		
	// 拷贝回原数组 
	for(i = low; i <= high; i ++)
        arr[i] = temp[i];
}

template<typename T>
void merge_sort(T arr[], T temp[], int low, int high) {
    if(low < high) {
    	int mid = (low + high) / 2;            // 从中间划分两个子序列 
		merge_sort(arr, temp, low, mid);       // 对左侧子序列进行递归排序 
		merge_sort(arr, temp, mid+1, high);    // 对右侧子序列进行递归排序 
		merge(arr, temp, low, mid, high);      // 归并 
	}
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int temp[11];
    int len = (int) sizeof(arr) / sizeof(*arr);
    merge_sort(arr, temp, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
