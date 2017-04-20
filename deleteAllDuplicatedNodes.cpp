// If a node is duplicated in sorted linked list, delete all the nodes having that value

#include<iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
	
	Node(int v): val(v), next(nullptr) { }
};

Node* deleteAllDuplicates(Node* head)
{
	if(!head)
		return nullptr;
	
	Node* ret = nullptr;
	Node* p = head;
	Node* q = nullptr;
	Node* lastToDelete = nullptr;
	Node* lastInList = nullptr;
	
	while(p)
	{
		
		q = p;
		p = p->next;
		while(p && p->val == q->val)
		{
			if(!lastToDelete)
				lastToDelete = q;
			Node* r = p;
			p = p->next;
			delete r;
		}
		
		if(! ret)
		{
			ret = q;
			ret->next = nullptr;
			lastInList = q;
		}
		
		if(lastToDelete)
		{
			if(ret == lastToDelete)
				lastInList = ret = nullptr;
			
			delete lastToDelete;
			lastToDelete = nullptr;
			q = nullptr;
		}
		
		if(lastInList && q)
		{
			lastInList->next = q;
			lastInList = q;
			lastInList->next = nullptr;
		}
		
	}
	return ret;
}
