#include<iostream>
#include<stack>

using namespace std;

typedef struct Tree {
    int val;
    struct Tree *left;
    struct Tree *right;
    Tree(int v, struct Tree* l = NULL, struct Tree* r = NULL): val(v), left(l), right(r) { }
} Tree;

void updateNext(stack<Tree *>& nextStack)
{
    if(nextStack.empty())
        return;

    Tree* t = nextStack.top();
    nextStack.pop();
    if(t->right != NULL)
    {
        t = t->right;
        while(t)
        {
            nextStack.push(t);
            t = t->left;
        }
    }
}

void updatePrev(stack<Tree *>& prevStack)
{
    if(prevStack.empty())
        return;
    Tree *t = prevStack.top();
    prevStack.pop();
    if(t->left != NULL)
    {
        t = t->left;
        while(t)
        {
            prevStack.push(t);
            t = t->right;
        }
    }
}

Tree* getNext(stack<Tree *> & nextStack)
{
    if(nextStack.empty())
        return NULL;
    return nextStack.top();
}

Tree* getPrev(stack<Tree *> & prevStack)
{
    if(prevStack.empty())
        return NULL;
    return prevStack.top();    
}

void findSum(Tree *root, stack<Tree *> & nextStack, stack<Tree *> & prevStack, int num)
{
    Tree * l = getNext(nextStack);
    Tree* r = getPrev(prevStack);
    if( l == r)
        return;
    if(!l || !r)
        return;
	
    if(l->val + r-> val == num)
    {
        cout << "Found. " << l->val << "    " << r->val << endl;
        return;
    }
    if(l->val + r->val < num)
    {
        updateNext(nextStack);
        return findSum(root, nextStack, prevStack, num);
    }
    else
    {
        updatePrev(prevStack);
        return findSum(root, nextStack, prevStack, num);
    }
}

void findSum(Tree *root, int num)
{
    if(! root)
        return;
    stack<Tree *> nextStack;
    stack<Tree *> prevStack;
    Tree * leftR = root;
    while(leftR)
    {
        nextStack.push(leftR);
        leftR = leftR->left;
    }
    
    Tree *rightR = root;
    while(rightR)
    {
        prevStack.push(rightR);
        rightR = rightR->right;
    }
    findSum(root, nextStack, prevStack, num);
}

void inorder(Tree* root)
{
	if(!root)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);	
}

int main()
{
    //Tree * root = new Tree(30, (new Tree(20, new Tree(10, NULL, new Tree(15)))), (new Tree(45, new Tree(40), new Tree(50))));
	Tree* root = new Tree(30, (new Tree(20, (new Tree(10, (new Tree(5)))))));
	inorder(root);
	cout << endl;
    int num;
    cin >> num;
    findSum(root, num);
}
