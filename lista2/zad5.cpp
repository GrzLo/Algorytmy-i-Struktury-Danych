#include <iostream>

struct lnode
{ 
	int m_key;
	lnode* m_next;
	
	lnode(int key, lnode* next=NULL) :
		m_key(key), 
		m_next(next)
	{}
};

void pushNode(lnode*& L, int key)
{
	lnode* temp = new lnode(key);
	temp->m_next = L;
	L = temp;
}

void print(lnode* L)
{
	while(L != NULL)
	{
		std::cout << L->m_key << " ";
		L = L->m_next;
	}
	std::cout << std::endl;
}

void reverse(lnode*& L)
{
	lnode* curr = L;
	lnode* prev = NULL;
	lnode* next = NULL;
	
	while(curr != NULL)
	{
		next = curr->m_next;
		curr->m_next = prev;
		prev = curr;
		curr = next;
	}
	L = prev;
}

int main()
{
	lnode* myNode = NULL;
	pushNode(myNode, 4);
	pushNode(myNode, 3);
	pushNode(myNode, 2);
	pushNode(myNode, 1);
	
	print(myNode); //1 2 3 4
	reverse(myNode);
	print(myNode); //4 3 2 1
}
