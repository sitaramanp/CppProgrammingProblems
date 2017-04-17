// find largest BST in a BT. result would have number of nodes of the larget BST found

#include<iostream>
#include<limits>

using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	
	Tree(int v, Tree* l= nullptr, Tree* r= nullptr): val(v), left(l), right(r) { }
};

bool largestBST(Tree* root, int& min, int& max, int& ans)
{
	if(! root)
	{
		min = numeric_limits<int>::max();
		max = numeric_limits<int>::min();
		ans = 0;
		return true;
	}
	
	int leftMin;
	int leftMax;
	int leftAns = 0;
	bool leftBST = largestBST(root->left, leftMin, leftMax, leftAns);
	
	int rightMin;
	int rightMax;
	int rightAns = 0;
	bool rightBST = largestBST(root->right, rightMin, rightMax, rightAns);
	
	bool overAll = false;
	if(leftBST && rightBST)
	{
		if(root->val >= leftMax && root->val <= rightMin)
		{
			overAll = true;
			ans = leftAns + rightAns + 1;
			min = root->val < leftMin? root->val : leftMin;
			max = root->val > rightMax? root->val : rightMax;
		}
	}
	if(!overAll)
		ans = leftAns>rightAns? leftAns : rightAns;
		

	return overAll;
}

int largestBST(Tree* root)
{
	int min;
	int max;
	int ans = 0;
	
	largestBST(root, min, max, ans);
	return ans;
}

int main()
{
	//Tree* root = new Tree(30, new Tree(20, new Tree(15, nullptr, new Tree(16)), new Tree(25)), new Tree(40, nullptr, new Tree(60)));
	Tree* root = new Tree(12, new Tree(6, new Tree(5)), new Tree(9, new Tree(8), new Tree(10)) );
	cout << largestBST(root) << endl;
	return 0;
}