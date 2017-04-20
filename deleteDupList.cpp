// Delete duplicate from SORTED linked list. Result will be list where all elements are distinct

#include<iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
	
	Node(int v) : val(v), next(nullptr) { }
};

Node* deleteDup(Node* head)
{
	if(!head)
		return nullptr;
	Node* p = head;
	Node* q = nullptr;
	
	while(p)
	{
		q=p;
		while(p && p->val == q->val)
                {
			Node* r = p;
			p = p->next;
			delete r;
		}
		q->next = p;
	}
	return head;
}

