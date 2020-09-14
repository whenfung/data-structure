// 栈的链式存储结构

#include <iostream>

struct Node { 
	int data;
	Node *next;
};

struct LiStack{
	Node *top;
	LiStack() : top(NULL) {}
	bool StackEmpty(){
		if(top) return true;  // 非空 
		return false;
	}
	bool Push(int x){
		Node* node = new Node();
		node->data = x;
		node->next = top;
		top = node;	
		return true;
	}
	bool Pop(int &x){
		if (top == NULL) return false;
		x=top->data;
		Node* node = top;
		top = node->next;
		delete node;
		return true;
	}
	bool GetTop(int &x){
		if(top == NULL) return false;
		x=top->data;
		return true;
	}
};

int main() {
	LiStack s;
	s.Push(1);
	s.Push(2);
	int x;
	s.Pop(x);
	std::cout << x << std::endl; 
	s.GetTop(x);
	std::cout << x << std::endl;
	return 0;
} 
