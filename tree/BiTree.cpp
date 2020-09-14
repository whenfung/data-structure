#include <iostream>
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

void lastOrder(TreeNode* node){
	if (node == NULL) return;
	
	lastOrder(node->lchild);
	lastOrder(node->rchild);
	std::cout << node->val;
}

void levelOrder(TreeNode* node){
	std::queue<TreeNode*> q;
	q.push(node);
	while(!q.empty()){
		TreeNode* currentNode = q.front();
		q.pop();
		std::cout << currentNode->val;
		
		if(currentNode->lchild) q.push(currentNode->lchild);
		if(currentNode->rchild) q.push(currentNode->rchild);
	}
}

int depth(TreeNode* node) {
	if(node == NULL) return 0;
	
	int leftDepth = depth(node->lchild);
	int rightDepth = depth(node->rchild);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int nodeNum(TreeNode* node) {
	if(node == NULL) return 0;
	return 1 + nodeNum(node->lchild) + nodeNum(node->rchild);
}

int leafNum(TreeNode* node){
	if(node == NULL) return 0;
	if(node->lchild == NULL && node->rchild == NULL) return 1;
	return leafNum(node->lchild) + leafNum(node->rchild);
}

bool isBalanced(TreeNode* node) {
	if(node == NULL) return true;
	
	int leftDepth = depth(node->lchild);
	int rightDepth = depth(node->rchild);
	
	if(leftDepth - rightDepth <= 1 && rightDepth - leftDepth <= 1) { // 两个非负数相差不超过 1 
		return isBalanced(node->lchild) && isBalanced(node->rchild);
	} 
	return false;
}

void addNode(TreeNode* root, TreeNode* node){
	node->lchild = root->lchild;
	root->lchild = node;
}

void destroy (TreeNode* node){
	if(node){
		destroy(node->lchild);
		destroy(node->rchild);
		delete node;
	}
}

int main(){
	char str[] = "ABD###CE#G##FH#I##J##";
	int i = 0;
	TreeNode* root = create(str, i);
	std::cout << isBalanced(root) << std::endl;
	destroy(root);
	return 0;
}
