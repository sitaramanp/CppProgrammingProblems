// Level order tree traversal

#include<iostream>
#include<queue>

using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	Tree(int v, Tree* l = nullptr, Tree* r = nullptr) : val(v), left(l), right(r) {}
};

void levelOrder(Tree* root)
{
	if(!root)
		return;
	queue<Tree*> treeQ;
	treeQ.push(root);
	while(!treeQ.empty())
	{
		Tree* temp = treeQ.front();
		treeQ.pop();
		cout << temp->val << " ";
		if(temp->left)
			treeQ.push(temp->left);
		if(temp->right)
			treeQ.push(temp->right);
	}	
}

int main()
{
	Tree *root = new Tree(30, new Tree(20, nullptr, new Tree(25)), new Tree(50, new Tree(45), new Tree(60)) );
	levelOrder(root);
	cout << endl;
	return 0;
}