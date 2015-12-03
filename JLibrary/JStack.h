#ifndef JSTACK_H
#define JSTACK_H

namespace JLib
{
	template <typename T>
	struct StackData
	{
		T value;
		StackData* prev;
	};

	template <typename T>
	class Stack
	{
		StackData<T>* stPointer;
		unsigned int size;
	public:
		Stack();
		~Stack();
		T Pop();
		unsigned int Size();
		void Push(T input);
		bool IsEmpty();
	};

	template <typename T>
	unsigned int Stack<T>::Size()
	{
		return size;
	}

	template <typename T>
	bool Stack<T>::IsEmpty()
	{
		return (size==0) ? true : false ; 
	}

	template <typename T>
	Stack<T>::Stack()
	{
		stPointer = new StackData<T>;
		stPointer->value = 0;
		stPointer->prev = nullptr;
		size = 0;
	}

	template <typename T>
	Stack<T>::~Stack()
	{

	}

	template <typename T>
	void Stack<T>::Push(T input)
	{
		StackData<T>* temp = new StackData<T>;
		temp->value = input;
		if(IsEmpty())
		{
			temp->prev = nullptr;
		}
		else
		{
			temp->prev = stPointer;
		}
		stPointer = temp;
		size++;
	}

	template <typename T>
	T Stack<T>::Pop()
	{
		T temp; 
		StackData<T>* tempPtr; 

		if(IsEmpty())
		{
			std::cout<<"Stack is Empty"<<std::endl;
			temp = 0;
			return temp;	
		}
		else
		{
			temp = stPointer->value;
			tempPtr = stPointer;
			stPointer = stPointer->prev;
			size--;
			delete tempPtr;	//Èü °´Ã¼ ¾ø¾Ö±â
			return temp;
		}		
	}
}

#endif