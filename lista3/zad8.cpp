#include <iostream>

struct BSTnode
{
	int m_key;
	int m_rightCount;
	BSTnode* m_left;
	BSTnode* m_right;
	
	BSTnode(int key, BSTnode* left = nullptr,BSTnode* right = nullptr) :
	m_key(key),
	m_left(left),
	m_right(right)
	{
	}
};

void display(BSTnode *t, char z1=' ', char z2=' ') 
{
	if(t)
	{
		std::cout << z1;
		display(t->m_left, '(',')');
		std::cout << t->m_key;
		display(t->m_right, '[',']');
		std::cout << z2;
	}
}

void insert(BSTnode*& t, int key)
{
	if(!t)
	{
		t = new BSTnode(key);
	}
	else
	{
		if(key < t->m_key)
		{
			
			insert(t->m_left, key);
		}
		else
		{
			++t->m_rightCount;
			insert(t->m_right, key);
		}
	}
}

int min(BSTnode* t)
{
	while(t->m_left)
	{
		t = t->m_left;
	}
	return t->m_key;
}

void remove(BSTnode*& t, int key)
{
	if(!t) 
	{
		return;
	}
	if(t->m_key == key)
	{
		if(!t->m_left)
		{
			BSTnode *d = t->m_right;
			delete t;
			t = d;
		}
		else if(!t->m_right)
		{
		    BSTnode *d = t->m_left;	
			delete t;
			t = d;
		}
		else
		{
			t->m_key = min(t->m_right);
			remove(t->m_right, t->m_key);
	    } 
	}
	else
	{
		if(key < t->m_key)
		{
			remove(t->m_left, key);
		}
		else
		{
			--(t->m_rightCount);
			remove(t->m_right, key);
		}
	}
}

BSTnode* ity(BSTnode *t, int i)
{
	if(t)
	{
		BSTnode * t1 = t;
		
		while(t1)
		{
			if(t1->m_rightCount + 1 == i)
			{
				return t1;
			}
			else if(i > t1->m_rightCount)
			{
				i -= (t1->m_rightCount + 1);
				t1 = t1->m_left;
			}
			else
			{
				t1 = t1->m_right;
			}
		}
	}
	return t;
}


int main()
{
	BSTnode* myNode = nullptr;
	insert(myNode, 5);
	insert(myNode, 3);
	insert(myNode, 11);
	insert(myNode, 20);
	insert(myNode, 1);	
	insert(myNode, 4);	
	insert(myNode, 6);	
	insert(myNode, 7);	
	
	std::cout << ity(myNode, 1)->m_key << std::endl;
	
	insert(myNode, 22);	
	
	std::cout << ity(myNode, 1)->m_key << std::endl;
	
	remove(myNode, 22);
	
	std::cout << ity(myNode, 1)->m_key << std::endl;
}

