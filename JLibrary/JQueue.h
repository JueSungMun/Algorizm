#ifndef JQUEUE_H
#define JQUEUE_H

namespace JLib
{
	template <typename T>
	struct QueueData
	{
		T value;
		QueueData<T>* prev;
		QueueData<T>* next;
	};

	template <typename T>
	class Queue
	{
	private:
		QueueData<T>* front;
		QueueData<T>* rear;
		unsigned int size;
	public:
		Queue();
		void Enqueue(T input);
		T Dequeue();
		unsigned int Size();
	};

	template <typename T>
	unsigned int Queue<T>::Size()
	{
		return size;
	}

	template <typename T>
	Queue<T>::Queue()
	{
		size = 0;
	}

	template <typename T>
	T Queue<T>::Dequeue()
	{
		if(size==0)
		{
			std::cout<<"Queue is Empty"<<std::endl;
			return 0;
		}
		else
		{
			QueueData<T>* temp = front;
			T tempValue = front->value;
			front = front->next;
			size--;
			delete temp;
			return tempValue;
		}
	}

	template <typename T>
	void Queue<T>::Enqueue(T input)
	{
		QueueData<T>* temp = new QueueData<T>;
		temp->value = input;

		if(size == 0)
		{
			front = temp;
			rear = temp;
			front->prev = nullptr;
		}
		else
		{
			temp->prev = rear;
			rear = temp;
			temp->prev->next = rear;
		}
		size++;
	}
}
#endif