/* 顺序栈的实现 
	栈顶指针指向的是栈顶元素
*/	


#include <iostream>

#define MaxSize 50
 
struct SqStack {
	int data[MaxSize];
	int top;
	
	SqStack() : top(-1){}  // 顺序栈的初始化
	bool StackEmpty(){
		if(top == -1)      // 栈空 
			return true;
		return false;      
	} 
	bool Push(int x) {  	
		if(top == MaxSize-1)  // 栈满，报错
			return false;
		data[++top] = x;      // 先指针 +1，再入栈
		return true; 
	}
	bool Pop(int &x) {
		if(top == -1)       // 栈空，报错
			return false;
		x=data[top--];      // 先出栈，指针再 -1 
		return true; 
	}
	bool GetTop(int &x) {
		if(top == -1)      // 栈空 ，报错 
			return false;
		x=data[top];      // x 记录栈顶元素
		return true; 
	}
}; 

int main(){
	SqStack s; 
	s.Push(1);
	s.Push(2);
	int x;
	s.Pop(x);
	std::cout << x << std::endl;
	s.Pop(x);
	std::cout << x << std::endl;	
	return 0;
}
