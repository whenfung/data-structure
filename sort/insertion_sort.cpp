#include <iostream>

using namespace std;
 
template<typename T>
void insertion_sort(T arr[], int len) {
    T temp;
    for (int i = 1; i < len; i++) { // 默认第一个为有序数组，剩下的一个一个插入到前面去 
		temp = arr[i];
		int j = i-1;
		//与已排序的数逐一比较，大于 temp 时，该数移后
		while(( j >= 0 ) && (arr[j] > temp)){
			arr[j+1]=arr[j];
			j--;
		}  
		arr[j+1] = temp;  // 将其 temp 插入到空出的位置 
	}
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
