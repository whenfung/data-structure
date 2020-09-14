// 二叉排序树的实现 

#include <iostream> 

struct Node {
	int key;
	Node *lchild, *rchild;
	Node() : key(0), lchild(NULL), rchild(NULL) {}
};

Node* BST_Search(Node* t, int key, Node* &p){
	// 查找函数返回指向关键字值为 key 的结点指针，若不存在，返回 NULL
	p = NULL; // p 指向被查找结点的双亲，用于插入和删除操作中
	while(t != NULL && key != t->key) {
		p = t;
		if(key < t->key) t = t->lchild;
		else t = t->rchild;
	}
	return t;
}

bool BST_Insert(Node* &t, int k) {
	// 在二叉排序树 t 中插入一个关键字为 k 的结点
	if(t == NULL) {  // 原树为空，新插入的记录为根结点 
		t = new Node;
		t->key = k;
		return true;     // 插入成功 
	} 
	else if(k == t->key)
		return false;     // 树中存在相同关键字的结点
	else if(k < t->key)   // 插入 T 的左子树
		return BST_Insert(t->lchild, k);
	else 
		return BST_Insert(t->rchild, k); 
}

void create_BST(Node* &t, int str[], int n) {
	// 用关键字数组 str[] 建立一个二叉排序树 
	t = NULL;  // 初始时 bt 为空树
	for(int i = 0; i < n; i++)
		BST_Insert(t, str[i]);
}

Node* firstNode(Node* t) {    // 中序遍历的第一个结点
	while(t->lchild != NULL) 
		t = t->lchild;
	return t; 
}

bool delete_Node(Node* &root, int key) {
	Node* parent = NULL;
	Node* p = BST_Search(root, key, parent);
	
	if(p == NULL) return false;
	if(p->lchild == NULL) {   // 待删结点的左结点为空 
		if(parent == NULL)		root = root->rchild;
		else if(parent->lchild == p) parent->lchild = p->rchild;
		else if(parent->rchild == p) parent->rchild = p->rchild;
		
		delete p;
		return true;
	}
	if(p->rchild == NULL) {   // 待删结点的左结点为空 
		if(parent == NULL) 		root = root->lchild;
		else if(parent->lchild == p) parent->lchild = p->lchild;
		else if(parent->rchild == p) parent->rchild = p->lchild;
		
		delete p;
		return true; 
	} 
	Node* q = firstNode(p->rchild);
	p->key = q->key;         // 将 p 的后继 q 的值赋给 p  
	return delete_Node(p->rchild, q->key);  // 删除结点 q 
}

void inOrder(Node* p) {   // 二叉排序树的中序遍历是递增的 
	if(p != NULL) {
		inOrder(p->lchild);
		std::cout << p->key;
		inOrder(p->rchild);
	}
}

int main() {
	int str[] = {2, 1, 5, 6, 4};
	Node* root = NULL;
	create_BST(root, str, 5);
	inOrder(root);
	std::cout << std::endl;
	
	delete_Node(root, 1);
	inOrder(root);
	return 0;
} 
