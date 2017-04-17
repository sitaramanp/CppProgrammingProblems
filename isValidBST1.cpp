// Is valid BST using inorder approach

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

bool isValidBST(Tree* root, int& prev)
{
	if(! root)
		return true;
	return(isValidBST(root->left, prev) && prev <= root->val && isValidBST(root->right, prev=root->val));

}

int main()
{
	Tree* root = new Tree(30, new Tree(20, new Tree(15, nullptr, new Tree(16)), new Tree(25)), new Tree(40, nullptr, new Tree(60)));
	int prev = numeric_limits<int>::min();
	cout << isValidBST(root, prev) << endl;
	return 0;
}