#include <iostream>
#include <algorithm>

using namespace std;
 
template<typename T>
void selection_sort(T arr[], int len) {
    for (int i = 0; i < len - 1; i++) { // n-1 轮循环 
        int min = i;
    	for(int j = i+1; j < len; j++)  // 将最小的下标记录在 min 上 
    		if(arr[min] > arr[j])
    			min = j;
		if(min != i) swap(arr[i], arr[min]);   // 将最小的放到前面 
	}
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    selection_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
