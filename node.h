//node.h
#pragma once
#include<iostream>
template<typename T>
class node
{
public:
	T data;
	node<T>* next;
	node<T>* prev;

	node();
	node(T);

};

template<typename T>
inline node<T>::node()
{
	data = NULL;
	prev = NULL;
	next = NULL;
}

template<typename T>
inline node<T>::node(T dane)
{
	data = dane;
	prev = NULL;
	next = NULL;
}