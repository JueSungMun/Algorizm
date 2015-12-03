#include "MY_HEADER.h"
#ifdef ALLERGYFRIENDS
/*
	알고리즘 문제명 : 알러지가 심한 친구들
	집들이에 n명의 친구를 초대
	할줄 아는 m가지의 음식중 친구들의 알러지를 고려하여 각 친구들이 최소한 하나씩의 음식은 먹을 수있도록 음식을 준비하는 문제
	제안하는 방법 : 친구들이 가장 많이 먹을 수 있는 음식위주로 선택
					음식 선택후엔 못먹는 친구들만 고려
					음식 데이터 수정 -> 음식을 먹을 수 있는 친구 내용 업데이트 -> 반복
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
		//cout<<"FoodInfo 소멸자 호출"<<endl;
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

		// 임시 객체 생성 후 소멸자가 호출되지만 실제적인 메모리를 해제하는 delete문은 나중에 호출하여
		// 힙 영역에 메모리 해제
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