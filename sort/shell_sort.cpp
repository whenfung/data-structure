#include <iostream>

using namespace std;
 
template<typename T>
void insertion_sort(T arr[], int len, int step) {
    T temp;
    for (int i = step; i < len; i += step) { // 从第 2 个开始插入 
		temp = arr[i];
		int j = i-step;
		//与已排序的数逐一比较，大于temp时，该数向后移动 step 个单位 
		while(( j >= 0 ) && (arr[j] > temp)){
			arr[j+step]=arr[j];
			j -= step;
		}  
		arr[j+step] = temp;  // 将其 temp 插入到合适的位置 
	}
}

template<typename T>
void shell_sort(T arr[], int len){
	for(int step = len/2; step; step /= 2){ // 初始步长定为 len/2 比较合适 
		for(int i = 0; i < step; i++){
			insertion_sort(&arr[i], len - i, step);  // 对第 i 组进行插入排序 
		} 
	}
} 

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    shell_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
