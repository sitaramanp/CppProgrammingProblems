// BST to soreted double LinkedList

#include<iostream>

using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	
	Tree(int v, Tree* l = nullptr, Tree* r = nullptr) : val(v), left(l), right(r) { }
};

void convertBstToLLCore(Tree* root, Tree** prev)
{
	if(!root)
		return ;
	convertBstToLLCore(root->left, prev);
	if(*prev)
	{
		(*prev)->right = root;
		root->left = *prev;
	}
	*prev = root;
	convertBstToLLCore(root->right, prev);			
}

Tree* convertBstToLL(Tree* root)
{
	Tree* prev = nullptr;
    convertBstToLLCore(root, &prev);
	while(prev && prev->left != nullptr)
		prev = prev->left;
	return prev;
}

