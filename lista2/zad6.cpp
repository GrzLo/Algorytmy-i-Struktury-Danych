#include <iostream>

static int counter = 0;

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

lnode* merge(lnode* L1, lnode* L2)
{
	lnode* newNode = NULL;
	
	while(L1 || L2)
	{
		if(!L1)
		{
			pushNode(newNode, L2->m_key);
			L2 = L2->m_next;
		}
		else if(!L2)
		{
			pushNode(newNode, L1->m_key);
			L1 = L1->m_next;
		}
		else
		{
			if(L1->m_key < L2->m_key)
			{
				pushNode(newNode, L1->m_key);
				L1 = L1->m_next;
				++counter;
			}
			else
			{
				pushNode(newNode, L2->m_key);
				L2 = L2->m_next;
				++counter;
			}
		}
	}
	
	reverse(newNode);
	return newNode;
}

int main()
{
	lnode* myNode1 = NULL;
	pushNode(myNode1, 7);
	pushNode(myNode1, 5);
	pushNode(myNode1, 3);
	pushNode(myNode1, 1);
	
	lnode* myNode2 = NULL;
	pushNode(myNode2, 8);
	pushNode(myNode2, 4);
	pushNode(myNode2, 2);
	
	print(myNode1); //1 3 5 7
	print(myNode2); //2 4 8
	
	lnode* myNode3 = merge(myNode1, myNode2);
	print(myNode3); //1 2 3 4 5 7 8
		
	std::cout << counter << std::endl; //6
}
