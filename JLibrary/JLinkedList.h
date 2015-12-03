#ifndef JLINKEDLIST_H
#define JLINKEDLIST_H

/*
	1. Head부터 데이터 입력 (PushBack할경우) -> prev pointer is nullptr
	   Tail에는 데이터 입력 X -> next pointer is nullptr
*/
#include <iostream>
#include "JSortLib.h"

namespace JLib
{
	template <typename T>
	struct DataType
	{
		T data;
		DataType* prev;
		DataType* next;
	};
	
	template <typename T>
	class LinkedList
	{
	private:
		DataType<T>* head;
		DataType<T>* tail;
		unsigned int size;
	public:
		const DataType<T>* iterator;
		LinkedList();
		~LinkedList();
		void PushBack(const T input);
		void PushFront(const T input);
		const DataType<T>* Search(const T input);
		const DataType<T>* Search(unsigned int index);
		void Modify(const DataType<T>* pivot, T value);
		void InsertLeft(const DataType<T>* pivot, const T value);
		void InsertRight(const DataType<T>* pivot, T value);
		bool Delete(const DataType<T>* input);
		unsigned int Size();
		void ShowData();
	};
	
	template <typename T>
	void LinkedList<T>::InsertRight(const DataType<T>* pivot, const T value)
	{
		DataType<T>* temp = new DataType<T>;
		temp->data = value;
		temp->prev = const_cast<DataType<T>*>(pivot);
		temp->next = pivot->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
		size++;
	}

	template <typename T>
	void LinkedList<T>::InsertLeft(const DataType<T>* pivot, const T value)
	{
		DataType<T>* temp = new DataType<T>;
		temp->data = value;
		temp->prev = pivot->prev;
		temp->next = const_cast<DataType<T>*>(pivot);
		temp->prev->next = temp;
		temp->next->prev = temp;
		size++;
	}

	template <typename T>
	void LinkedList<T>::Modify(const DataType<T>* pivot, T value)
	{
		DataType<T>* temp = const_cast<DataType<T>*>(pivot);
		temp->data = value;
	}

	template <typename T>
	unsigned LinkedList<T>::Size()
	{
		return size;
	}

	template <typename T>
	const DataType<T>* LinkedList<T>::Search(const T input)
	{
		DataType<T>* ptr = head;

		for(int i=0; i<size; i++)
		{
			if(ptr->data == input)
			{
				return ptr;
			}
			ptr = ptr->next;
		}
		return nullptr;
	}

	template <typename T>
	const DataType<T>* LinkedList<T>::Search(unsigned int index)
	{
		if(index > size-1)
			return nullptr;

		if(index ==0)
		{
			return head;
		}
		else if(index == size-1)
		{
			return tail;
		}

		DataType<T>* ptr = head->next;

		for(int i=1; i<size-1; i++)
		{
			if(i == index)
			{
				return ptr;
			}
			ptr = ptr->next;
		}
		return nullptr;
	}

	template <typename T>
	void LinkedList<T>::ShowData()
	{
		std::cout<<"Size Of List : "<<size<<std::endl;
		DataType<T>* ptr = head;

		for(int i=0; i<size; i++)
		{
			std::cout<<ptr->data<<std::endl;
			ptr = ptr->next;
		}
	}

	template <typename T>
	LinkedList<T>::LinkedList()
	{
		head = new DataType<T>;
		tail = new DataType<T>;

		head->data = 0;
		head->next = nullptr;
		head->prev = nullptr;
		tail->data = 0;
		tail->next = nullptr;
		tail->prev = nullptr;
		size = 0;
	}

	template <typename T>
	LinkedList<T>::~LinkedList()
	{
		while(Delete(head->next));
		std::cout<<head->data<<" 삭제"<<std::endl;
		std::cout<<tail->data<<" 삭제"<<std::endl;
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	template <typename T>
	void LinkedList<T>::PushBack(const T input)
	{
		DataType<T>* temp = new DataType<T>;
		temp->data = input;
		
		if(size == 0)
		{
			head->data = temp->data;
			head->next = tail;
			tail->prev = head;
		}
		else
		{
			tail->prev->next = temp;
			temp->prev = tail->prev;
			tail->prev = temp;
			temp->next = tail;
		}
		size++;
	}

	template <typename T>
	void LinkedList<T>::PushFront(const T input)
	{
		DataType<T>* temp = new DataType<T>;
		temp->data = input;
		
		if(size == 0)
		{
			head->data = temp->data;
			head->next = tail;
			tail->prev = head;
		}
		else
		{
			Swap(head->data, temp->data);
			temp->prev = head;
			temp->next = head->next;
			temp->next->prev = temp;
			head->next = temp;
		}
		size++;
	}

	template <typename T>
	bool LinkedList<T>::Delete(const DataType<T>* input)
	{
		//Head, Tail은 소멸자에서 삭제
		if(input->next == nullptr)
			return false;
		else if(input->prev == nullptr)
			return false;
		DataType<T>* temp = const_cast<DataType<T>*>(input);
		temp->prev->next = input->next;
		temp->next->prev = temp->prev;
		std::cout<<input->data<<" 삭제"<<std::endl;
		delete input;
		size--;
		return true;
	}
}

#endif