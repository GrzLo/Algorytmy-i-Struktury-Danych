#include <iostream>

int licznik;

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
			licznik++;
		}
			
		else 
		{
			t1=&((*t1)->m_right);
			licznik++;
		}
	}
			
	*t1=new node(x);
} 

int h(node* t)
{
	if(!t)
	{
		return -1;
	}
	return !t ? 0 : 1 + std::max(h(t->m_left),h(t->m_right));
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



int main(){
	
	node *N = nullptr;
	int n = 10;
	for (int i=1; i<=n; i++)
	{
        insert(N, i);
    }
    
    display(N);
    std::cout << std::endl;
    std::cout << "Głębokość drzewa: " << h(N) << std::endl; 
	std::cout << "Ilość porównań: " << licznik << std::endl;
	return 0;
}
