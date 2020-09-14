// 平衡二叉树的实现 

#include <iostream>

struct Node {
	int data;
	int bf;     // 平衡因子，-1,0,1
	Node *lchild, *rchild;
	Node() : data(0), bf(0), lchild(NULL), rchild(NULL){} 
};

// LL 平衡旋转 (右单旋转) 
void LL_Rotate(Node* &t) {
	Node l = t->lchild;      // t 的左子结点赋给临时指针 l 
	t->lchild = l->rchild;   // t 的左指针空出来后指向 l 的右子结点 
	l->rchild = t;           // l 的右指针空出来后指向 t 
	t = l;                   // t 的左子结点成为根结点 
}


// RR 平衡旋转 (左单旋转) 
void RR_Rotate(Node* &t) {
	Node* r = t->rchild;     // t 的右子结点赋给临时变量 r 
	t->rchild = r->lchild;   // t 的右指针空出来后指向 r 的左子结点 
	r->lchild = t;           // r 的左指针空出来后指向 t 
	t = r;                   // t 的左子结点成为根结点 
}

// LR 平衡旋转 (先左后右双旋转)
void LR_Rotate(Node* &t) {
	RR_Rotate(t->lchild);
	LL_Rotate(t);
}

// RL 平衡旋转 (先右后左双旋转) 
void RL_Rotate(Node* &t) {
	LL_Rotate(t->rchild);
	RR_Rotate(t);
}

bool AVL_Insert(Node* &t, int k) {  // 待实现 
	
} 

void create_AVL(Node* &root, int str[], int n){
	root = NULL;
	for(int i = 0; i < n; i++) 
		AVL_Insert(root, str[i]);
}

void inOrder(Node* p) {
	if(p != NULL) {
		inOrder(p->lchild);
		std::cout << p->data;
		inOrder(p->rchild);
	}
}

int main(){
	int str[] = {2, 1, 5, 6, 4};
	Node* root = NULL;
	create_AVL(root, str, 5);
	inOrder(root);
	return 0;
} 
