#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int x = 0) : data(x), next(NULL){}
};

void headInsert(Node* head, int data) {
	// 从表尾到表头逆向建立单链表 L，每次均在头结点之后插入元素
	Node* newNode = new Node(data);
	newNode->next = head->next;
	head->next = newNode; 	 
}

void tailInsert(Node* &tail, int data) {
	Node* newNode = new Node(data); 
	tail->next = newNode; // 尾指针的下一个结点就是新结点
	tail = newNode;  // 更新尾指针，注意入参使用引用
}

void tailDelete(Node* head, Node* &tail){
	for(Node* it = head; it; it = it->next) {
		if(it->next == tail){
			delete tail;
			tail = it;
			return;
		}
	}
} 

Node* getElem(Node* head, int i) {
	// 本算法取出单链表 L (带头结点)中第 i 个为止的结点指针
	if(i == 0) return head;
	if(i < 1) return NULL;
	int j = 1;
	for(Node* it = head->next; it; it = it->next){
		if (j == i)	return it;
		j++;
	}
	return NULL;
}

Node* locateElem(Node* head, int e) {
	// 本算法查找单链表 L (带头结点) 中数据域值等于 e 的结点，否则返回 NULL
	for(Node* it = head->next; it; it = it->next) {
		if(it->data == e) return it;
	}	 
	return NULL;
}

void print(Node* head) {
	for(Node* it = head->next; it; it = it->next) 
		std::cout << it->data << " ";
	std::cout << std::endl;
}

int main(){
	Node* head = new Node;    // 单链表的头结点  
	Node* tail = head;        // 尾插法需要使用尾指针 
	tailInsert(tail, 2);
	tailInsert(tail, 3);
	tailDelete(head, tail);
	tailInsert(tail, 4);
	print(head);
	Node* node = locateElem(head, 2);
	std::cout << node->data << std::endl;
	return 0;
} 
