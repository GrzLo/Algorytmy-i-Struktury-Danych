#include <iostream>

struct node
{ 
	int m_x;
	node* m_left;
	node* m_right;
	node* m_parent;
	
	node(int x, node* left=NULL, node* right=NULL, node* parent=NULL) :
		m_x(x), 
		m_left(left), 
		m_right(right),
		m_parent(parent)
	{}
	
class iterator
{
private:
	node* currentNode;

public:
	iterator(node* t) :
		currentNode(t)
	{
	}
	
	iterator begin(node* t)
	{
		if(t)
		{
			while(t->m_left)
			{
				t = t->m_left;
			}
		}
		return iterator(t);
	}
	
	iterator end(node* t)
	{
		return iterator(NULL);
	}
	
	iterator& operator = (node* t)
	{
		this->currentNode = t;
		return *this;
	}
	
	iterator operator ++ (int)
	{
		currentNode = nextNode(this->currentNode);
		return currentNode;
	}
	
	bool operator != (const iterator& it)
	{
		return currentNode != it.currentNode;
	}
	
	int operator* ()
	{
		return currentNode->m_x;
	}
	
	node* nextNode(node* t)
	{
		node* t1 = t;
		if(t->m_right == NULL)
		{
			while(t->m_parent != NULL && t1->m_x > t->m_parent->m_x)
			{
				
				t = t->m_parent;
			}
			return t->m_parent;
		}
		else
		{
			t = t->m_right;
			while (t->m_left != NULL && t->m_left->m_x > t1->m_x)
			{
				t = t->m_left;
			}
		return t;
		}
	}
};
};

void display(node *t, char z1 = ' ', char z2 = ' ')
{
	if(t)
	{
		std::cout << z1;
		display(t->m_left,'(',')');
		std::cout << t->m_x;
		display(t->m_right,'[',']');
		std::cout << z2;
	}
}

node* find(node* t,int x)
{
	while(t && t->m_x != x)
	{
		if(x < t->m_x && t->m_left)
		{
			t = t->m_left;
		} 
		else if(x > t->m_x && t->m_right)
		{
			t = t->m_right;
		}
		else
		{
			return NULL;
		}
	}
	
	return t; 
}

void printParent(node* t, int x)
{
	node* res = find(t, x);
	
	if(res)
	{
		if(res->m_parent)
		{
			std::cout << "The parent of " << x << " is: " << res->m_parent->m_x << std::endl;
		}
		
		else
		{
			std::cout << "The element is the root" << std::endl;
		}
	}
	else
	{
		std::cout << "Element not found" << std::endl;
	}
}


void insert(node*& t, int x)
{
	node** current = &t;
	node** parent = NULL;
	
	while(*current)
	{
		parent = current;
		if(x < (*current)->m_x)
		{
			current = &((*current)->m_left);
		}
		else
		{
			current = &((*current)->m_right);
		}
	}
	
	if(parent != NULL)
	{
		*current = new node(x, NULL, NULL, *parent);
	}
	else
	{
		*current = new node(x);
	}

}

void remove(node *&t, int x)
{
	node **t1 = &t;
	
	while(*t1 && (*t1)->m_x != x)
	{
		if(x < (*t1)->m_x && (*t1)->m_left)
		{
			t1 = &((*t1)->m_left);
		} 
		else if(x > (*t1)->m_x && (*t1)->m_right)
		{
			t1 = &((*t1)->m_right);
		}
		else
		{
			std::cout << "Element not found, cannot remove" << std::endl;
			return;
		}
	}
	
	if((*t1)->m_right && (*t1)->m_left)
	{
		node **t2 = &((*t1)->m_right);
		while ((*t2)->m_left)
		{
			t2 = &((*t2)->m_left);
		}
		(*t1)->m_x = (*t2)->m_x;
		t1 = t2;
	}	
	if((*t1)->m_left == NULL)
	{
		node* d = (*t1);
		(*t1) = d->m_right;
		if(d->m_right)
		{
			(*t1)->m_parent = d->m_parent;
		}
		
	}
	else
	{
		node* d = (*t1);
		(*t1) = d->m_left;
		(*t1)->m_parent = d->m_parent;
	}
}




int main()
{
	node* myNode = NULL;
	
	insert(myNode, 15);
	insert(myNode, 6); 
	insert(myNode, 2); 
	insert(myNode, 10);
	insert(myNode, 8);
	insert(myNode, 7);
	insert(myNode, 9);
	insert(myNode, 12);
	insert(myNode, 17);
	insert(myNode, 20);
	
	
	for(node::iterator it = it.begin(myNode); it != it.end(myNode); it++)
	{
		std::cout << *it << std::endl;
	}
}
