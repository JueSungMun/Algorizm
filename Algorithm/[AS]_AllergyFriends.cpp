#include "MY_HEADER.h"
#ifdef ALLERGYFRIENDS
/*
	�˰��� ������ : �˷����� ���� ģ����
	�����̿� n���� ģ���� �ʴ�
	���� �ƴ� m������ ������ ģ������ �˷����� ����Ͽ� �� ģ������ �ּ��� �ϳ����� ������ ���� ���ֵ��� ������ �غ��ϴ� ����
	�����ϴ� ��� : ģ������ ���� ���� ���� �� �ִ� �������ַ� ����
					���� �����Ŀ� ���Դ� ģ���鸸 ���
					���� ������ ���� -> ������ ���� �� �ִ� ģ�� ���� ������Ʈ -> �ݺ�
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef struct FoodInfo
{
	string* address;
	int size;
	~FoodInfo()
	{
		//cout<<"FoodInfo �Ҹ��� ȣ��"<<endl;
	}
}FoodInfo;

void ShowState(const list<string>& dataList);
void ShowState(const list<FoodInfo>& dataList);


int main()
{
	int testCase;
	int friendNum;
	int foodNum;

	cin>>testCase;
	cin>>friendNum;
	cin>>foodNum;

	list<string> friendList;

	for(int i = 0; i<friendNum; i++)
	{
		string temp = "";
		cin>>temp;
		friendList.push_back(temp);
	}
	
	list<FoodInfo> foodlist;
	for(int i = 0; i<foodNum; i++)
	{
		FoodInfo temp;
		cin>> temp.size;

		// �ӽ� ��ü ���� �� �Ҹ��ڰ� ȣ������� �������� �޸𸮸� �����ϴ� delete���� ���߿� ȣ���Ͽ�
		// �� ������ �޸� ����
		string* foods = new string[temp.size];
		for(int j = 0; j<temp.size; j++)
		{
			cin>>foods[j];
		}
		//cout<<"Temporal Object Address : "<<foods<<endl;
		temp.address = foods;
		foodlist.push_back(temp);
	}
	
	int mostLarge = 0;
	for(int i = 0; i<foodlist.size(); i++)
	{
		//mostLarge = foodlist.
	}

	ShowState(friendList);
	ShowState(foodlist);
	return 0;
}

void ShowState(const list<string>& dataList) 
{
	list<string> showList = const_cast<list<string>&>(dataList);
	list<string>::iterator iter;
	for(iter = showList.begin(); iter != showList.end(); iter++)
	{
		cout<<*iter<<endl;
	}
}

void ShowState(const list<FoodInfo>& dataList) 
{
	list<FoodInfo> showList = const_cast<list<FoodInfo>&>(dataList);
	
	list<FoodInfo>::iterator ptrIter;
	for(ptrIter = showList.begin(); ptrIter != showList.end(); ptrIter++)
	{
		for(int j = 0; j<ptrIter->size; j++)
		{
			cout<<ptrIter->address[j]<<endl;
		}
		//cout<<"Deleted Object Address : "<<ptrIter->address<<endl;
		delete[] ptrIter->address;
	}
}

#endif