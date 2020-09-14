#include <iostream>

using namespace std;

template<typename T>
int partition(T arr[], int low, int high) {
	T pivot = arr[low];
    while(low < high){
		while (low < high && arr[high] >= pivot) --high;  
		arr[low] = arr[high];  // 将比枢轴值小的元素挪到左端 
		while (low < high && arr[low] <= pivot)  ++ low; 
		arr[high]=arr[low];    // 将比枢轴值大的元素挪到右端 
	} 
	arr[low] = pivot;   // 枢轴元素存放到最终位置 
	return low;         // 返回存放枢轴的最终位置 
} 

template<typename T>
void quick_sort(T arr[], int low, int high) {
    if (low < high) {   // 递归条件 
    	// partition() 将表 T[low~high] 划分为满足条件的两个子表 
		int pivotPos = partition(arr, low, high);
		quick_sort(arr, low, pivotPos-1);
		quick_sort(arr, pivotPos+1, high);  
	}  
}

int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    quick_sort(arr, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
