// is balanced b-tree in single pass

#include<iostream>

using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	
	Tree(int v, Tree* l = nullptr, Tree* r = nullptr) : val(v), left(l), right(r) { } 
};

bool isBalanced(Tree* root, int& depth)
{
	if(!root)
	{
		depth = 0;
		return true;
	}
	
	int l, r;
	bool isLBalanced = isBalanced(root->left, l);
	bool isRBalanced = isBalanced(root->right, r);
	if(isLBalanced && isRBalanced)
	{
		int diff = abs(l-r);
		if(diff == 0 || diff == 1)
		{
			depth = max(l,r)+1;
			return true;
		}
	}
	return false;
}

bool isBalanced(Tree* root)
{
	int depth  = 0;
	return isBalanced(root, depth);
}
