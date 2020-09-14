// 迭代实现 N 皇后问题 

#include <iostream>
#include <cmath>

using namespace std; 

void queen(int);                        
bool isSafe(int*, int);                  // 判断前 row 行皇后是否会互相攻击 
void print(int*, int);                   // 输出解 

void queen(int n) { 
	int* pos = new int[n];   
	int row = 1;
	pos[1] = 1;
	while (row > 0) {                     // 递归终止条件转化为循环终止条件 
		if (row <= n && pos[row] <= n) {  // 向前递归 
			if (!isSafe(pos, row)) {      // 如果不安全调整位置 
				pos[row] ++;
			}
			else                          // 如果安全进入下一行开始寻找  
			{
				row++;
				pos[row] = 1;
			}
		}
		else    // 找到解 
		{
			if (row > n) print(pos, n);
			row--;
			pos[row]++;
		}
	}
	delete[]pos;
}

bool isSafe(int* pos ,int row) {  
	for (int i = 1; i < row; i++) {
		for (int j = i + 1; j <= row; j++) {
			if (abs(pos[i] - pos[j]) == abs(i - j)) return false;   // 不在对角线上
			if (pos[i] == pos[j]) return false;                     // 不在同一列
			//由于 i 和 j 肯定不相同，因此不用判断同一行
		}
	}
	return true;
}
	
void print(int* pos, int n) { 
	for (int i = 1; i <= n; i++) {
		cout << pos[i] << ' ';
	}
	cout << endl;
}


int main() {
	queen(4);
	return 0;
}
