#include <iostream>
#include <cmath>

#define N 4                             // 皇后规模 

using namespace std; 
  
int pos[N];                              //  规模不超过 100

void queen(int row);                     // 递归实现 N 皇后问题 
bool isSafe(int row);                    // 判断前 row 行皇后是否会互相攻击 
void print();                            // 输出解 

void queen(int row = 1) {
	for (int i = 1; i <= N; i++) {
		pos[row] = i;
		if (isSafe(row)) {               //前 row 行皇后都符合条件
			if (row == N) print();       //遍历到一组解就输出
			else   queen(row + 1);       //没有找到继续往下找 
		}
	}
}

bool isSafe(int row) {  
	for (int i = 1; i < row; i++) {
		for (int j = i + 1; j <= row; j++) {
			if (abs(pos[i] - pos[j]) == abs(i - j)) return false; // 不在对角线上
			if (pos[i] == pos[j]) return false;                     // 不在同一列
			//由于 i 和 j 肯定不相同，因此不用判断同一行
		}
	}
	return true;
}
	
void print() { 
	for (int i = 1; i <= N; i ++) 
		cout << pos[i] << ' ';
	cout << endl;
}


int main() {
	queen();
	return 0;
}
