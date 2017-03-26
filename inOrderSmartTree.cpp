// Level order tree traversal

#include<iostream>
#include<queue>
#include<memory>

using namespace std;

template<class T>
class Tree
{
private:
	struct node 
	{
		T val;
		unique_ptr<node> left;
		unique_ptr<node> right;
		node(const T& v)
		{
			val = v;
			left = nullptr;
			right = nullptr;
		}
	};
	
	unique_ptr<node> root;
	
public:
	Tree();
	void insert(const T& v); 
	void insert(unique_ptr<node>& rt, const T& v);
	void traverseInOrder(unique_ptr<node>& rt);	
	void traverseInOrder() { traverseInOrder(root); }
};

template<class T>
Tree<T>::Tree() { root = nullptr; }

template<class T>
void Tree<T>::insert(const T& v)
{
	if(! root)
		root = unique_ptr<node> (new node(v));
	else
		insert(root, v);
}

template<class T>
void Tree<T>::insert(unique_ptr<node>& rt, const T& v)
{
	if(rt->val <= v)
	{
		if(! rt->right)
		{
			rt->right = unique_ptr<node> (new node(v));
			return;
		}
		return insert(rt->right, v);
	}
	else
	{
		if(! rt->left)
		{
			rt->left = unique_ptr<node> (new node(v));
			return;
		}
		return insert(rt->left, v);
	}
	
	return;
}

template<class T>
void Tree<T>::traverseInOrder(unique_ptr<node>& rt)
{
	if(! rt)
		return;
	traverseInOrder(rt->left);
	cout << rt->val << " ";
	traverseInOrder(rt->right);	
}

int main()
{
	Tree<int> bst;
	bst.insert(30);
	bst.insert(20);
	bst.insert(50);
	bst.insert(40);
	bst.insert(45);
	bst.traverseInOrder();
}
