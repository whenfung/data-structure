// 顺序表实现循环队列

#include <iostream>

#define MaxSize 50     // 队列大小 

struct SqQueue {
	int data[MaxSize]; // 存放队列元素 
	int front, rear;   // 队头指针和队尾指针
	
	SqQueue():front(0) , rear(0){}
	bool isEmpty(){
		if(rear == front) return true;
		return false;
	} 
	bool enQueue(int x) {
		if((rear+1) % MaxSize == front) return false; // 队满 
		data[rear]=x;
		rear=(rear + 1) % MaxSize;
		return true;
	}
	bool DeQueue(int &x) {
		if(rear == front) return false;  // 队空
		x = data[front];
		front = (front +1) % MaxSize;
		return true; 
	} 
};

int main(){
	SqQueue q;
	int x;
	q.enQueue(1);
	q.enQueue(2);
	q.DeQueue(x);
	std::cout << x << std::endl;
	q.DeQueue(x);
	std::cout << x << std::endl;
	return 0;
} 
 
