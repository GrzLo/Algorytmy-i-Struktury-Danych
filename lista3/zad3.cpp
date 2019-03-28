#include <iostream>


struct lnode 
{
    int m_key;
    lnode* m_next;
    lnode(int key, lnode *next = NULL) : 
		m_key(key), 
		m_next(next) 
	{
	}
};

void pushNode(lnode*& L, int key)
{
	lnode* temp = new lnode(key);
	temp->m_next = L;
	L = temp;
}

void print(lnode *L) 
{
    while (L != NULL) 
    {
        std::cout << L->m_key << " ";
        L = L->m_next;
    }
    std::cout << std::endl;
}



void insertionSort(lnode *&L) 
{
    if (L && L->m_next) 
    {
        lnode* sorted = NULL;
        lnode* unsorted = L;

        while (unsorted) 
        {
            lnode* val = unsorted;
            unsorted = unsorted->m_next;

            if (!sorted || val->m_key <= sorted->m_key) 
            {
                val->m_next = sorted;
                sorted = val;
            } 
            else 
            {
                lnode* current = sorted;

                while (current) 
                {
                    if (!current->m_next || val->m_key < current->m_next->m_key) 
                    {
                        val->m_next = current->m_next;
                        current->m_next = val;
                        break;
                    }
                    current = current->m_next;
                }
            }
        }
        L = sorted;
    }
}



int main() 
{
	lnode *myNode = NULL;
	
	pushNode(myNode, 8);
	pushNode(myNode, 4);
	pushNode(myNode, 9);
	pushNode(myNode, 1);
	pushNode(myNode, 2);
	pushNode(myNode, 3);
	pushNode(myNode, 7);
	pushNode(myNode, 2);
	pushNode(myNode, 6);
	
	print(myNode); // 6 2 7 3 2 1 9 4 8 
	insertionSort(myNode);
	print(myNode); // 1 2 2 3 4 6 7 8 9
}

