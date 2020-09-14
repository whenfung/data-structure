// 二叉树的非递归遍历实现 

#include <iostream>
#include <stack> 
#include <queue>

struct TreeNode {
	char val;
	TreeNode *lchild;
	TreeNode *rchild;
	TreeNode(char val = '#') : val(val), lchild(NULL), rchild(NULL){}
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

void preOrder(TreeNode* node){
	if (node == NULL) return;
	
	std::cout << node->val;
	preOrder(node->lchild);
	preOrder(node->rchild);
} 

void inOrder(TreeNode* node){
	if (node == NULL) return;
	
	inOrder(node->lchild);
	std::cout << node->val;
	inOrder(node->rchild);
} 

void inOrder2(TreeNode* root) {  // 非递归实现中序遍历 
	std::stack<TreeNode*> s;	
	TreeNode* p = root;
	while(p || !s.empty()){
		if(p) {
			s.push(p);
			p = p->lchild;      // 往左走 
		}
		else {
			p = s.top();
			s.pop();
			std::cout << p->val;
			p = p->rchild;      // 往右走 
		}
	}
	std::cout << std::endl;
}

void lastOrder(TreeNode* node){
	if (node == NULL) return;
	
	lastOrder(node->lchild);
	lastOrder(node->rchild);
	std::cout << node->val;
}

void destroy (TreeNode* node){
	if(node){
		destroy(node->lchild);
		destroy(node->rchild);
		delete node;
	}
}

int main(){
	char str[] = "ABD###CE#G##FH#I##J##";  // 先序序列 
	int i = 0;
	TreeNode* root = create(str, i);
	inOrder2(root); 
	inOrder(root);
	destroy(root);
	return 0;
}
