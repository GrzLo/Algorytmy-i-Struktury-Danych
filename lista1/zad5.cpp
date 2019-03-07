#include <iostream> 

struct lnode
{
	int key;
	lnode* next;
};

int nty(int n, lnode *l)
{
	int index = 1;
	while (l != nullptr)
	{
		//jesli index zgadza się z argumentem podanym w funkcji zwróc wartość
		if (index == n)
		{
			return l->key;
		}
		//w przeciwnym razie idź dalej
		else
		{
			++index;
			l = l->next;
		}
	}
	return 0;
}

int main()
{
	lnode* node1 = new lnode();
	lnode* node2 = new lnode();
	lnode* node3 = new lnode();
	lnode* node4 = new lnode();
	
	node1->key = 5;
	node2->key = 12;
	node3->key = 55;
	node4->key = 7;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	
	
	//dla node1
	std::cout << "Node 1" << std::endl;
	std::cout << "1: " << nty(1, node1) << std::endl;
	std::cout << "2: " << nty(2, node1) << std::endl;
	std::cout << "3: " << nty(3, node1) << std::endl;
	std::cout << "4: " << nty(4, node1) << std::endl;
	std::cout << "5: " << nty(5, node1) << std::endl;
	//dla node2
	std::cout << "Node 2" << std::endl;
	std::cout << "1: " << nty(1, node2) << std::endl;
	std::cout << "2: " << nty(2, node2) << std::endl;
	std::cout << "3: " << nty(3, node2) << std::endl;
	std::cout << "4: " << nty(4, node2) << std::endl;
	std::cout << "5: " << nty(5, node2) << std::endl;
}
