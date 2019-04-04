#include <iostream>

struct BSTnode
{
	int m_key;
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
	BSTnode **t1=&t;
	while(*t1)
	{
		if(key < (*t1)->m_key)
		{
			t1 = &((*t1)->m_left);
		}
		else
		{
			t1 = &((*t1)->m_right);
		}
	}
	*t1 = new BSTnode(key);
}

int poziom(BSTnode* t, int klucz)
{
	int level = 0;
	
	while(t && klucz != t->m_key)
	{
		if(klucz < t->m_key)
		{
			t = t->m_left;
		}
		else
		{
			t = t->m_right;
		}
		++level;
	}
	if(t)
	{
		return level +1;
	}
	else
	{
		return 0;
	}
}



int main()
{
	BSTnode* myNode = nullptr;
	BSTnode* myNode2 = nullptr;
	insert(myNode, 5);
	insert(myNode, 3);
	insert(myNode, 2);
	insert(myNode, 8);
	insert(myNode, 1);	
	insert(myNode, 4);	
	insert(myNode, 6);	
	insert(myNode, 7);	
	
	display(myNode);
	
	std::cout << std::endl;
	std::cout << poziom(myNode, 5) << std::endl;
	std::cout << poziom(myNode, 3) << std::endl;
	std::cout << poziom(myNode, 8) << std::endl;
	std::cout << poziom(myNode, 2) << std::endl;
	std::cout << poziom(myNode, 4) << std::endl;
	std::cout << poziom(myNode, 6) << std::endl;
	std::cout << poziom(myNode, 1) << std::endl;
	std::cout << poziom(myNode, 7) << std::endl;
	
	std::cout << poziom(myNode, -3) << std::endl;
	std::cout << poziom(myNode, 15) << std::endl;
	std::cout << poziom(myNode, 0) << std::endl;
}
