// 折半插入排序

#include <iostream>

using namespace std;

template<typename T>
void binary_insertion_sort(T arr[], int len) {
	for(int i = 1; i < len; i++ ) {     // n-1 次插入 
		int low = 0;                    // 折半查找下界 
		int high = i-1;                 // 折半查找上界 
		while(low <= high) {            // 折半查找终止条件 
			int mid = (low+high) / 2;   
			if(arr[mid] > temp)
				high = mid - 1;
			else 
				low = mid + 1;
		}
		T temp = arr[i];       // 临时存储插入值 
		for(int j = i-1; j >= high+1; j--) 
			arr[j+1] = arr[j];
		arr[high+1] = temp;  
	}
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    binary_insertion_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
