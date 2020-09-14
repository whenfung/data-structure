#include <iostream>

struct DNode {
	int data;
	DNode* prior;
	DNode* next; 
	DNode(int x = 0) : data(x), prior(NULL), next(NULL){}
};

void headInsert(DNode* head, int data) {
	// 从表尾到表头逆向建立双链表 L，每次均在头结点之后插入元素
	DNode* newNode = new DNode(data);
	newNode->next = head->next;
	head->next->prior = newNode; 
	head->next = newNode;
	newNode->prior = head; 	 
}

void tailInsert(DNode* &tail, int data) {
	DNode* newNode = new DNode(data); 
	tail->next = newNode;   // 尾指针的下一个结点就是新结点
	newNode->prior = tail;  // 头指针指向前一个几点 
	tail = newNode;         // 更新尾指针，注意入参使用引用
}

DNode* getElem(DNode* head, int i) {
	// 本算法取出双链表 L (带头结点)中第 i 个为止的结点指针
	if(i == 0) return head;
	if(i < 1) return NULL;
	int j = 1;
	for(DNode* it = head->next; it; it = it->next){
		if (j == i)	return it;
		j++;
	}
	return NULL;
}

DNode* locateElem(DNode* head, int e) {
	// 本算法查找双链表 L (带头结点) 中数据域值等于 e 的结点，否则返回 NULL
	for(DNode* it = head->next; it; it = it->next) {
		if(it->data == e) return it;
	}	 
	return NULL;
}

void print(DNode* head) {
	for(DNode* it = head->next; it; it = it->next) 
		std::cout << it->data << " ";
	std::cout << std::endl;
}

int main(){
	DNode* head = new DNode;    // 双链表的头结点  
	DNode* tail = head;         // 尾插法需要使用尾指针 
	tailInsert(tail, 2);
	tailInsert(tail, 3);
	tailInsert(tail, 4);
	print(head);
	DNode* node = locateElem(head, 2);
	std::cout << node->data << std::endl;
	return 0;
} 
