#include "MY_HEADER.h"
#ifdef NC_POINTER

// NC Test 스택 메모리 구조 이해 문제
// ptr주소가 100일때 메모리 구조는 어떻게 되는가?
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = {10,nullptr}, n2 = {20,nullptr},n3 = {30,nullptr},
	     n4 = {40,nullptr}, n5 = {50,nullptr};
	Node* ptr = &n1;
	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	//ptr = &n1;
	cout<<"ptr Address : " <<&ptr<<endl;
	cout<<"n1 Address : " <<&n1<<endl;
	cout<<"n1 Data Address : " <<&n1.data<<endl;
	cout<<"n1 Link Address : " <<&n1.link<<endl;
	cout<<"n2 Address : " <<&n2<<endl;
	cout<<"n2 Data Address : " <<&n2.data<<endl;
	cout<<"n2 Link Address : " <<&n2.link<<endl;
	cout<<"n3 Address : " <<&n3<<endl;
	cout<<"n3 Data Address : " <<&n3.data<<endl;
	cout<<"n3 Link Address : " <<&n3.link<<endl;
	cout<<"n4 Address : " <<&n4<<endl;
	cout<<"n4 Data Address : " <<&n4.data<<endl;
	cout<<"n4 Link Address : " <<&n4.link<<endl;
	cout<<"n5 Address : " <<&n5<<endl;
	cout<<"n5 Data Address : " <<&n5.data<<endl;
	cout<<"n5 Link Address : " <<&n5.link<<endl;

	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;

	return 0;
}

#endif