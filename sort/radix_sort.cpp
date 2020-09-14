// 基数排序的实现 ，对 10 进制整数进行排序 

#include <iostream>
#include <queue> 

using namespace std;

template<typename T>
int max_bit(T arr[], int len) {
	int d = 1;  // 保存最大位数
	int p = 10; 
	for(int i = 0; i < len; i++)   // 每个数都要判断 
		while(arr[i] >= p){
			p *= 10;
			d++;
		} 
	return d;
}
 
template<typename T>
void radix_sort(T arr[], int len) {
    int d = max_bit(arr, len);                   // d 元组，表示 d 趟排序 
    queue<int> q[10];                            // 10 进制数表示 r 为 10，需要 10 个队列 
	int radix = 1;                               // 最低位优先排序 
	while(d --) {                                // 进行 d 次 排序 
		
		for(int i = 0; i < len; i ++){           // 分配操作 
			int j = (arr[i] / radix) % 10;       // 检测 arr[i] 属于哪个队列 
			q[j].push(arr[i]);                    
		}
		
		int k = 0; 
		for(int i = 0; i < 10; i++) {            // 收集操作，同时清空所有队列 
			while(!q[i].empty()) {
				arr[k++] = q[i].front();
				q[i].pop();
			}
		} 
		radix = radix * 10;
	} 
}

int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    radix_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
