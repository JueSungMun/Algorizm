#include "MY_HEADER.h"
#ifdef ALLERGYFRIENDS
/*
	알고리즘 문제명 : 알러지가 심한 친구들
	집들이에 n명의 친구를 초대
	할줄 아는 m가지의 음식중 친구들의 알러지를 고려하여 각 친구들이 최소한 하나씩의 음식은 먹을 수있도록 음식을 준비하는 문제
	제안하는 방법 : 친구들이 가장 많이 먹을 수 있는 음식위주로 선택
					음식 선택후엔 못먹는 친구들만 고려
					음식 데이터 수정 -> 음식을 먹을 수 있는 친구 내용 업데이트 -> 반복
	문제점 : 가장 많이 먹을 수 있는 음식의 수의 경우가 여러가지일때 모두 고려해야 답
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

void ShowState(const list<string>& dataList);
void ShowState(const list<string>* dataList, const int& foodNum);
int TestCase(const list<string>& _friendList, const list<string>* _foodList, const int numOfFood);
int SelectFood(const list<string>& _friendList, const list<string>* _foodList, const int numOfFood, list<string> eatedFrinedList, int step);

int main()
{
	int testCase;	// 테스트 케이스의 개수를 저장할 변수
	int friendNum;	// 친구수를 저장할 변수
	int foodNum;	// 할 수 있는 음식 개수를 저장할 변수
	int* output;	// 결과를 저장하고 출력할 변수
	int outputIdx = 0;	

	cin>>testCase;
	if(testCase > 50 || testCase < 0)
		return -1;

	output = new int[testCase];

	for(int testIdx = 0; testIdx < testCase; testIdx++)
	{
		// 알고리즘 테스트를 진행할 데이터를 입력받는 부분

		cin>>friendNum;
		if(friendNum > 50 || friendNum < 0)
			return -1;

		cin>>foodNum;
		if(foodNum > 50 || foodNum < 0)
			return -1;

		list<string> friendList;

		for(int i = 0; i<friendNum; i++)
		{
			string temp = "";
			cin>>temp;
			friendList.push_back(temp);
		}

		list<string>* foodList = new list<string>[foodNum];
		for(int i = 0; i<foodNum; i++)
		{
			int numofFood;
			cin>> numofFood;
			for(int j = 0; j<numofFood; j++)
			{
				string temp;
				cin>>temp;
				foodList[i].push_back(temp);
			}
		}

		// 알고리즘 테스트 부분
		int result = TestCase(friendList, foodList, foodNum);
		output[outputIdx++] = result;
		cout<<result<<endl;
		delete[] foodList;
	}

	/*
	for(int i = 0; i<testCase; i++)
	{
		cout<<output[i]<<endl;
	}
	*/
	delete[] output;

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

void ShowState(const list<string>* dataList, const int& foodNum) 
{
	list<string>* showList = const_cast<list<string>*>(dataList);
	list<string>::iterator iter;
	for(int i = 0; i<foodNum; i++)
	{
		cout<<"Size : "<<showList[i].size()<<" -> ";
		for(iter = showList[i].begin(); iter!= showList[i].end(); iter++)
		{
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
}

int TestCase(const list<string>& _friendList, const list<string>* _foodList, const int numOfFood)
{
	//매개변수 값의 변화를 막기 위해 const로 형변환하여 입력받은 데이터를 알고리즘 적용을 위하여 지역 변수에 복사하는 과정
	list<string> friendList;
	friendList.assign(_friendList.begin(), _friendList.end());

	list<string>* foodList = new list<string>[numOfFood];
	for(int i = 0; i<numOfFood; i++)
		foodList[i].assign(_foodList[i].begin(), _foodList[i].end());

	vector<int> optFood;
	optFood.push_back(foodList[0].size());
	optFood.push_back(0);

	int result = 0;

	//가장 많이 먹을 수 있는 음식 찾기 (여러개인지 중복체크도 함께)
	//vector의 첫번째 인덱스엔 최대로 많이 먹을 수 있는 음식, 나머지 인덱스엔 음식이 저장되어 있는 인덱스번호들
	for(int i = 1; i<numOfFood; i++)
	{
		if(foodList[i].size() > optFood[0])
		{
			optFood.clear();
			optFood.push_back(foodList[i].size());
			optFood.push_back(i);
		}
		else if(foodList[i].size() == optFood[0])
		{
			optFood.push_back(i);
		}
	}

	//동적 프로그래밍 방식으로 풀이
	//eatedFriendList에 음식을 먹을 수 있는 친구들 목록 추가, 음식 고르는 가지수 저장
	if(optFood.size() > 2)
	{
		list<string> eatedFriendList;
		int index = optFood[1];
		for(list<string>::iterator tempIter = foodList[index].begin(); tempIter != foodList[index].end(); tempIter++)
		{
			eatedFriendList.push_back(*tempIter);
		}
		result = SelectFood(friendList, foodList, numOfFood, eatedFriendList, 1);

		for(int i = 2; i<optFood.size(); i++)
		{
			list<string> eatedFriendList;
			int index = optFood[i];
			for(list<string>::iterator tempIter = foodList[index].begin(); tempIter != foodList[index].end(); tempIter++)
			{
				eatedFriendList.push_back(*tempIter);
			}
			int tempResult = SelectFood(friendList, foodList, numOfFood, eatedFriendList, 1);
			if(result > tempResult)
				result = tempResult;
		}
	}
	else
	{
		list<string> eatedFriendList;
		int index = optFood[1];
		for(list<string>::iterator tempIter = foodList[index].begin(); tempIter != foodList[index].end(); tempIter++)
		{
			eatedFriendList.push_back(*tempIter);
		}
		result = SelectFood(friendList, foodList, numOfFood, eatedFriendList, 1);
	}
	delete[] foodList;
	return result;
}

int SelectFood(const list<string>& _friendList, const list<string>* _foodList, const int numOfFood, list<string> eatedFriendList, int step)
{
	if(eatedFriendList.size() >= _friendList.size())
	{
		return step;
	}

	list<string>* foodList = new list<string>[numOfFood];
	for(int i = 0; i<numOfFood; i++)
		foodList[i].assign(_foodList[i].begin(), _foodList[i].end());
	
	//음식 목록에서 이미 먹을 수 있는 친구들 목록 제거
	for(int i = 0; i<numOfFood; i++)
	{
		for(list<string>::iterator eatFriendIter = eatedFriendList.begin(); eatFriendIter != eatedFriendList.end(); eatFriendIter++)
		{
			foodList[i].remove(*eatFriendIter);
		}
	}

	vector<int> optFood;
	optFood.push_back(foodList[0].size());
	optFood.push_back(0);

	//나머지 음식 중 남은 친구들을 가장 많이 먹일 수 있는 음식 목록 검색
	for(int i = 1; i<numOfFood; i++)
	{
		if(foodList[i].size() > optFood[0])
		{
			optFood.clear();
			optFood.push_back(foodList[i].size());
			optFood.push_back(i);
		}
		else if(foodList[i].size() == optFood[0])
		{
			optFood.push_back(i);
		}
	}
	
	//재귀형식으로 최적의 음식수 찾기
	list<string> tempList;
	int result = 0;
	if(optFood.size() > 2)
	{
		int index = optFood[1];
		tempList.clear();
		tempList.assign(eatedFriendList.begin(), eatedFriendList.end());
		for(list<string>::iterator tempIter = foodList[index].begin(); tempIter != foodList[index].end(); tempIter++)
		{
			tempList.push_back(*tempIter);
		}
		result = SelectFood(_friendList, _foodList, numOfFood, tempList, ++step);

		for(int i = 2; i<optFood.size(); i++)
		{
			tempList.clear();
			tempList.assign(eatedFriendList.begin(), eatedFriendList.end());

			int index = optFood[i];
			for(list<string>::iterator tempIter = foodList[index].begin(); tempIter != foodList[index].end(); tempIter++)
			{
				tempList.push_back(*tempIter);
			}
			int tempResult = SelectFood(_friendList, _foodList, numOfFood, tempList, ++step);
			if(result > tempResult)
				result = tempResult;
		}
	}
	else
	{
		tempList.clear();
		tempList.assign(eatedFriendList.begin(), eatedFriendList.end());

		for(list<string>::iterator tempIter = foodList[optFood[1]].begin(); tempIter != foodList[optFood[1]].end(); tempIter++)
		{
			tempList.push_back(*tempIter);
		}
		result = SelectFood(_friendList, _foodList, numOfFood, tempList, ++step);
	}
	delete[] foodList;
	return result;
}

#endif

/*
	//힙에 동적 메모리할당시 new A[10]; 하면 10개의 A가 생성되고 임시 객체로써 바로 소멸자 호출됨
	//하지만 delete[] A를 하기 전까진 힙에 생성된 메모리는 해제되지 않은 상태로 유지되고 동적할당시 지정한 포인터를 이용하여
	//힙 영역에 있는 객체를 가리킨다. 실질적인 메모리 해제는 포인터를 이용하여 delete를 할 경우에 일어난다.

	알고리즘 문제명 : 알러지가 심한 친구들
	집들이에 n명의 친구를 초대
	할줄 아는 m가지의 음식중 친구들의 알러지를 고려하여 각 친구들이 최소한 하나씩의 음식은 먹을 수있도록 음식을 준비하는 문제
	제안하는 방법 : 친구들이 가장 많이 먹을 수 있는 음식위주로 선택
					음식 선택후엔 못먹는 친구들만 고려
					음식 데이터 수정 -> 음식을 먹을 수 있는 친구 내용 업데이트 -> 반복
*/

/*
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
	list<FoodInfo>::iterator iter = foodlist.begin();
	mostLarge = iter->size;
	for(iter; iter!= foodlist.end(); iter++)
	{
		if(iter->size > mostLarge)
		{
			mostLarge = iter->size;
		}
	}
	cout<<mostLarge<<endl;

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
*/