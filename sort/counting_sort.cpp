#include <iostream>

using namespace std;
 
template<typename T>
void counting_sort(T arr[], int len) {
	T min = arr[0], max = arr[0];     // 1. 找出最大值和最小值
	for(int i = 1; i < len; i ++) {
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	} 
	
	int buckets_len = max - min + 1; 
	T* buckets = new T[buckets_len];     // 2. 建立计数数组（桶）并置零 
	for (int i = 0; i < buckets_len; i ++) 
		buckets[i] = 0;
		
	for(int i = 0; i < len; i ++) {      // 3. 对每一个数继续计数归类 
		buckets[arr[i] - min] ++ ;
	}
	
	int j = 0;                          // 4. 排序，按顺序从桶里面取东西 
	for(int i = 0; i < buckets_len; i ++){
		while(buckets[i]) {
			buckets[i] --;
			arr[j++] = i + min;
		} 
	} 
	
    delete[]buckets;
}

int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    counting_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
