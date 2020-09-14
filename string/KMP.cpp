// KMP 算法的实现

#include <iostream>
#include <string>

void set_next(const std::string& T, int next[]) {
	int i = 0;                   // 重叠串计算从 0 开始 
	int j = -1;                   
	next[0] = -1;                // 前一个元素的部分匹配值整体右移，next[0] 设置为 -1 为了后面的迭代 
	while(i < T.length()) {
		if(j == -1 || T[i] == T[j]) {  // 这里代表了两种情况，分别是无匹配和匹配值增加 
			next[++i] = ++j;
		}
		else                           // 失配就重新调整重叠部分 
			j = next[j];
	}
}

int Index_KMP(const std::string& S, const std::string& T, int pos) {
	int *next = new int[T.length()];
	set_next(T, next);
	
	int i = pos;
	int j = 0;
	while(i < S.length() && j < T.length()) {
		if(j == -1 || S[i] == T[j]) {   // 无匹配 或 匹配成功 
			++i; ++j;
		}
		else                           // 第 i 个字符匹配失败，移动重叠部分 
			j = next[j];    
	}
	
	delete next;  // 销毁 next 数组 
	
	if(j == T.length())
		return i-T.length();
	else 
		return -1; 
}
int main(){
	std::string S = "ababcabcacbab";
	std::string T = "abcac";
	std::cout << Index_KMP(S, T, 0) << std::endl;
	return 0;
} 
