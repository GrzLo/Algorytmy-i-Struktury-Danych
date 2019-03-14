#include <iostream>

struct node
{ 
	int m_x;
	node* m_left;
	node* m_right;
	
	node(int x, node* left=NULL, node* right=NULL)
		:m_x(x), m_left(left), m_right(right)
	{}
};

void insert(node *& t, int x)
{
	node **t1=&t;
	while(*t1)
	{
		if(x<(*t1)->m_x)
		{
			t1=&((*t1)->m_left);
		}
		else
		{
			t1=&((*t1)->m_right);
		}
	}
	*t1=new node(x);
}


node* find(node* t,int x)
{
	while(t && t->m_x != x)
	{
		if(x<t->m_x) 
			t = t->m_left; 
		else
			t = t->m_right; 
	}
	return t;
}

void remove(node *&t, int x)
{
	node **t1=&t;
	while (*t1 && (*t1)->m_x!=x)
	{
		if(x<(*t1)->m_x) 
			t1=&((*t1)->m_left); 
		else
			t1=&((*t1)->m_right); 
	}
	if(*t1)
	{
		if((*t1)->m_right && (*t1)->m_left)
		{
			node **t2=&((*t1)->m_right);
			while ((*t2)->m_left)
				t2=&((*t2)->m_left);
			(*t1)->m_x=(*t2)->m_x;
			t1=t2;
		}	
		if((*t1)->m_left==NULL)
		{
			node *d=(*t1)->m_right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    node *d=(*t1)->m_left;	
			delete *t1;
			(*t1)=d;
		}
	}
}

void display(node *t,char z1=' ',char z2=' ')
{
	if(t)
	{
		std::cout<<z1;
		display(t->m_left,'(',')');
		std::cout<<t->m_x;
		display(t->m_right,'[',']');
		std::cout<<z2;
	}
}

int main()
{
	node* t=NULL;
	
	insert(t,3);
	insert(t,4); 
	insert(t,1);
	insert(t,7);
	insert(t,-4);
	insert(t,9);
	insert(t,2);
	

	display(t);
	std::cout << std::endl;
	std::cout << "wyszukaj 9: " << find(t,9)->m_x << std::endl;
	std::cout << "usuń korzeń (" << t->m_x<<"): "; 
	remove(t,t->m_x); 
	std::cout << std::endl;
	display(t); 
	std::cout << std::endl;	 

}

