// Level order tree traversal

#include<iostream>
#include<queue>
#include<stack>

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

void zigzagLevelTraversal(Tree* root)
{
	if(!root)
		return;
	stack<Tree*> leftRightStack;
	stack<Tree*> rightLeftStack;
	rightLeftStack.push(root);
	int thisLevelCount = 1;
	int nextLevelCount = 0;
	int leftToRight = 0;
	
	while(!leftRightStack.empty() || !rightLeftStack.empty())
	{
		if(leftToRight && !leftRightStack.empty())
		{
			Tree* temp = leftRightStack.top();
			leftRightStack.pop();
			cout << temp->val << " ";
			if(temp->right)
			{
				rightLeftStack.push(temp->right);
				nextLevelCount++;
			}
			if(temp->left)
			{
				rightLeftStack.push(temp->left);
				nextLevelCount++;
			}
		}
		else if(!rightLeftStack.empty())
		{
			Tree* temp = rightLeftStack.top();
			rightLeftStack.pop();
			cout << temp->val << " ";
			if(temp->left)
			{
				leftRightStack.push(temp->left);
				nextLevelCount++;
			}
			if(temp->right)
			{
				leftRightStack.push(temp->right);
				nextLevelCount++;
			}
		}
		
		--thisLevelCount;
		if(thisLevelCount == 0)
		{
			thisLevelCount = nextLevelCount;
			nextLevelCount = 0;
			leftToRight = 1-leftToRight;
			cout << endl;
		}
	}
}

int main()
{
	//Tree *root = new Tree(30, new Tree(20, nullptr, new Tree(25)), new Tree(50, new Tree(45), new Tree(60)) );
	Tree* root = new Tree(1, new Tree(2, new Tree(4, new Tree(8), new Tree(9)), new Tree(5, new Tree(10), new Tree(11))), 
					new Tree(3, new Tree(6, new Tree(12), new Tree(13)), new Tree(7, new Tree(14), new Tree(15))) );
	levelOrderWithNewLine(root);
	cout << endl;
	zigzagLevelTraversal(root);
	cout << endl;
	return 0;
}