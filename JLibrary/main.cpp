#include "JSortLib.h"
#include "JLinkedList.h"
#include "JStack.h"
#include "JQueue.h"
#include "JBinaryTree.h"
//#include "JSortLib.cpp"	//템플릿 분할 컴파일시 cpp선언은 메인에 해줘야함!

using namespace JLib;

int main()
{
	BinaryTree<int> bt;
	bt.Insert(10);
	bt.Insert(5);
	bt.Insert(17);
	bt.Insert(1);
	bt.Insert(6);
	bt.Insert(14);
	bt.Insert(21);
	bt.ShowTheTree();
	std::cout<<std::endl;
	bt.Delete(5);
	bt.ShowTheTree();
	/*	list test
	LinkedList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.ShowData();
	list.iterator = list.Search(2);

	if(list.iterator != nullptr)
	{
		std::cout<<list.iterator->data<<std::endl;
	}
	else
		std::cout<<"데이터를 찾을 수 없습니다"<<std::endl;
	list.InsertLeft(list.iterator, 300);
	list.InsertRight(list.iterator, 400);
	list.Modify(list.iterator, 10000);
	list.ShowData();
	*/
	/* selection sort test
	int arr[] = {15, 16, 7, 8, 9, 10};
	char arr2[] = {'a', 'b', 'c', 'd', 'e'};

	SelectionSort(arr2, 5);
	for(int i=0; i<5; i++)
	{
		std::cout<<arr2[i]<<std::endl;
	}
	*/
	return 0;
}