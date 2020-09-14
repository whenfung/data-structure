// 中序线索二叉树的实现 

#include <iostream>
#include <stack> 
#include <queue>

struct TreeNode {
	char val;       
	int ltag, rtag;
	TreeNode *lchild, *rchild;
	TreeNode(char val = '#') 
		: val(val), ltag(0), rtag(0), lchild(NULL), rchild(NULL){}
};

TreeNode* create(char str[], int &i) {
	if (str[i] == '#') return NULL;
	TreeNode* node = new TreeNode(str[i]);
	i++;  
	node->lchild = create(str, i);
	i++;
	node->rchild = create(str, i);
	return node;
}

void inThread(TreeNode* &p, TreeNode* &pre) { 
	// 中序遍历对二叉树线索化的递归算法
	if(p != NULL) {
		inThread(p->lchild, pre);   // 递归，线索化左子树
		if(p->lchild == NULL) {     // 左子树为空，建立前驱线索
			p->lchild = pre;        // 第一个结点的前驱线索为 NULL 
			p->ltag = 1;             
		} 
		if(pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;        // 建立前驱结点的后继线索
			pre->rtag = 1; 
		}
		pre = p;                    // 标记当前结点称为刚刚访问过的结点
		inThread(p->rchild,pre);    // 递归，线索化右子树 
	} 
} 

void createInThread(TreeNode* root) {
	TreeNode* pre = NULL;
	if(root != NULL) {        // 非空二叉树，线索化 
		inThread(root, pre);  // 线索化二叉树 
		pre->rchild = NULL;   // 处理遍历的最后一个结点
		pre->rtag = 1;  
	}
} 

TreeNode* firstNode(TreeNode* p) {
	while(p->ltag == 0) p = p->lchild; // 最左下结点(不一定是叶子结点)
	return p; 
} 

TreeNode* nextNode(TreeNode* p){
	if(p->rtag == 0) return firstNode(p->rchild);
	else return p->rchild;  // rtag=1 直接返回后继结点 
}

void inOrder(TreeNode* root) {
	for(TreeNode* p = firstNode(root); p != NULL; p = nextNode(p))
		std::cout << p->val;
	std::cout << std::endl;
}


int main(){
	char str[] = "ABD###CE#G##FH#I##J##";  // 先序序列 
	int i = 0;
	TreeNode* root = create(str, i); 
	createInThread(root);
	inOrder(root);   // DBAEGCHIFJ
	return 0;
}
