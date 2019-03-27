#include <iostream>
#include <stack>

struct node
{ 
	int m_x;
	node* m_left;
	node* m_right;
	
	node(int x, node* left=NULL, node* right=NULL) :
		m_x(x), 
		m_left(left), 
		m_right(right)
	{}

	class iterator
	{
	private:
		node* currentNode;
		std::stack<node*> nodeStack;

	public:
		iterator(node* t) :
			currentNode(t)
		{
			pushLeft(t);
		}
		
		iterator begin(node* t)
		{
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
			currentNode = nextNode();
			return currentNode;
		}
		
		bool operator != (const iterator& it)
		{
			return currentNode != it.currentNode;
		}
		
		int operator* ()
		{
				return nodeStack.top()->m_x;
		}
		
		void pushLeft(node* t)
		{
			while(t)
			{
				nodeStack.push(t);
				t = t->m_left;
			}
			
		}
		
		node* nextNode()
		{
			if(!nodeStack.empty())
			{
				node* t1 = nodeStack.top();
				nodeStack.pop();
				pushLeft(t1->m_right);
				if(nodeStack.empty())
				{
					return nullptr;
				}
				return t1;
			}
			else
			{
				return nullptr;
			}
			
		}
	};
};

void insert(node*& t, int x)
{
	node** current = &t;
	
	while(*current)
	{
		if(x < (*current)->m_x)
		{
			current = &((*current)->m_left);
		}
		else
		{
			current = &((*current)->m_right);
		}
	}
	*current = new node(x);
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
	insert(myNode, 44);
	insert(myNode, 11);
	
	
	for(node::iterator it = it.begin(myNode); it != it.end(myNode); it++)
	{
		std::cout << *it << std::endl;
	}
	
}





