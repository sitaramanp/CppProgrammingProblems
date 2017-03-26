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

void levelOrderWithNewLine(Tree* root)
{
	if(!root)
		return;
	queue<Tree*> treeQ;
	treeQ.push(root);
	int thisLevelCount = 1;
	int newLevelCount = 0;
	while(!treeQ.empty())
	{
		Tree* temp = treeQ.front();
		treeQ.pop();
		cout << temp->val << " ";
		thisLevelCount--;
		if(temp->left)
		{
			treeQ.push(temp->left);
			newLevelCount++;
		}
		if(temp->right)
		{
			treeQ.push(temp->right);
			newLevelCount++;
		}
		
		if(thisLevelCount == 0)
		{
			cout << endl;
			thisLevelCount = newLevelCount;
			newLevelCount = 0;
		}
	}	
}

int main()
{
	Tree *root = new Tree(30, new Tree(20, nullptr, new Tree(25)), new Tree(50, new Tree(45), new Tree(60)) );
	levelOrderWithNewLine(root);
	cout << endl;
	return 0;
}