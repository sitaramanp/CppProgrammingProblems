// Is valid BST with range check

#include<iostream>
#include<limits>

using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	
	Tree(int v, Tree* l = nullptr, Tree* r = nullptr): val(v), left(l), right(r) { }
};

bool isValidBST(Tree* root, int min, int max)
{
	if(! root)
		return true;
	if(root->val > max || root->val < min)
		return false;
	return (isValidBST(root->left, min, root->val) && 
			 isValidBST(root->right, root->val, max));
}

bool isValidBST(Tree* root)
{
	int min = numeric_limits<int>::min();
	int max = numeric_limits<int>::max();
	return isValidBST(root, min, max);
}

int main()
{
	Tree* root = new Tree(30, new Tree(20, new Tree(15, nullptr, new Tree(16)), new Tree(25)), new Tree(40, nullptr, new Tree(60)));
	
	cout << isValidBST(root) << endl;
}