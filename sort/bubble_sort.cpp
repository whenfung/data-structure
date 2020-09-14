#include <iostream>
#include <algorithm>

using namespace std;
 
template<typename T>
void bubble_sort(T arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
    	bool flag = false;
        for (int j = len-1; j > i; j--)   // 从后往前冒泡 
	        if (arr[j-1] > arr[j]) {        // 小的往前挤 
	            swap(arr[j-1], arr[j]);
				flag = true;
			}
		if(flag == false) return;   // 本趟遍历未发生交换，说明表已有序 
	}
}
int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
