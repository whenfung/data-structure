#include <iostream>

struct Node {  // 队列结点 
	int data;
	Node *next;
};

struct LinkQueue{
	Node *front, *rear;
	LinkQueue() {
		front = new Node();
		rear = front;
		rear->next = NULL;  // 初始为空 
	}
	bool isEmpty(){
		if(front == rear) return true;
		return false;
	}
	void EnQueue(int x){
		Node *node = new Node();
		node->data = x;
		node->next = NULL;
		rear->next = node;
		rear = node;
	}
	bool DeQueue(int &x){
		if(front == rear) return false; // 空队
		Node *p = front->next;
		x = p->data;
		front->next = p->next;
		if(rear == p) rear = front; // 若原队列中只有一个结点，删除后变空
		delete p;
		return true; 
	}
};

int main(){
	LinkQueue q;
	int x;
	q.EnQueue(1);
	q.EnQueue(2);
	q.DeQueue(x);
	std::cout << x << std::endl;
	q.DeQueue(x);
	std::cout << x << std::endl;
	return 0;
}
