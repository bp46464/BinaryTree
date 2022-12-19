#pragma once
#include"node.h"
#include<algorithm>
template<typename T>
class binary_tree
{
public:
	node<T>* head;
	std::string wynik;

	void add(T);
	T get(T);
	void clear(node<T>*);
	void del(T);
	std::string inOrder(node<T>*);
	void preOrder(node<T>*);
	int height(node<T>*);
};

template<typename T>
inline void binary_tree<T>::add(T element)
{
	node<T>* current_node = new node<T>(element);
	node<T>* hd = head;
	node<T>* wsk = NULL;
	if (hd == NULL)
	{
		head = current_node;
	}
	else
	{
		while (hd != NULL)
		{
			wsk = hd;
			if (element < hd->data)
				hd = hd->prev;
			else
				hd = hd->next;
		}
		if (element < wsk->data)
			wsk->prev = current_node;
		else if (element > wsk->data)
			wsk->next = current_node;
		else if (element == wsk->data)
			return;
	}
}

template<typename T>
inline T binary_tree<T>::get(T element)
{
	node<T>* nod = head;
	while (nod != NULL)
	{
		if (nod->data < element)
		{
			nod = nod->next;
		}
		else if (nod->data > element)
		{
			nod = nod->prev;
		}
		else if (nod->data == element)
		{
			return 1;
		}
	}
	return 0;
}

template<typename T>
inline void binary_tree<T>::clear(node<T>* node)
{
	if (node == NULL)
		return;


	clear(node->prev);
	clear(node->next);

	delete(node);
}

template<typename T>
inline void binary_tree<T>::del(T element)
{
	node<T>* tmp = head;
	node<T>* y = tmp;
	if (tmp == NULL)
		return;
	else
	{
		//szukanie elementu do usunięcia
		while (tmp->data != element)
		{
			if (tmp->data < element)
			{
				y = tmp;
				tmp = tmp->next;
			}
			else
			{
				y = tmp;
				tmp = tmp->prev;
			}
		}
		//przypadki
		//1.Liść
		if (tmp->next == NULL && tmp->prev == NULL)
		{
			if (y->next != NULL)
			{
				delete(y->next);
				y->next = NULL;
			}
			else
			{
				delete(y->prev);
				y->prev = NULL;
			}
		}
		//2.Półliść
		else if ((tmp->next == NULL && tmp->prev != NULL) || (tmp->next != NULL && tmp->prev == NULL))
		{
			if (y->data > tmp->data)
			{
				if (tmp->next != NULL)
				{
					y->prev = tmp->next;
					delete(tmp);
				}
				else
				{
					y->prev = tmp->prev;
					delete(tmp);
				}
			}
			else if (y->data < tmp->data)
			{
				if (tmp->next != NULL)
				{
					y->next = tmp->next;
					delete(tmp);
				}
				else
				{
					y->next = tmp->prev;
					delete(tmp);
				}
			}
		}
		//ogólny
		else if (tmp->next != NULL && tmp->prev != NULL)
		{
			node<T>* z = tmp->prev;//skaczę w lewo, to będzie skakało po następnych next
			node<T>* x = tmp;//poprzedni do z
			node<T>* pomoc;
			//szukam największego po lewej
			while (z->next != NULL)
			{
				x = z;
				z = z->next;
			}

			if (z->prev == NULL)
			{
				tmp->data = z->data;
				delete(z);
			}
			else if (z->prev != NULL)
			{
				tmp->data = z->data;
				pomoc = x->next->prev;
				x->next = pomoc;

				delete(z);
			}
		}

	}

}

template<typename T>
inline std::string binary_tree<T>::inOrder(node<T>* node)//tutaj jest to_string
{
	if (node != NULL)
	{
		inOrder(node->prev);
		wynik += std::to_string(node->data) + " ";
		//std::cout << node->data << " ";
		inOrder(node->next);

		return wynik;
	}
	else
		return "0";
}

template<typename T>
inline void binary_tree<T>::preOrder(node<T>* node)
{
	if (node == NULL)
		return;

	std::cout << node->data << " ";
	preOrder(node->prev);
	preOrder(node->next);
}

template<typename T>
inline int binary_tree<T>::height(node<T>* node)
{

	if (node == NULL)
		return 0;
	else
	{

		int ri = height(node->prev);
		int le = height(node->next);
		//std::cout << le << " " << ri;
		if (le > ri)
			return le + 1;
		else
			return ri + 1;
	}
}
