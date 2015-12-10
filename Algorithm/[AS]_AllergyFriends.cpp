#include "MY_HEADER.h"
#ifdef ALLERGYFRIENDS
/*
	�˰��� ������ : �˷����� ���� ģ����
	�����̿� n���� ģ���� �ʴ�
	���� �ƴ� m������ ������ ģ������ �˷����� ����Ͽ� �� ģ������ �ּ��� �ϳ����� ������ ���� ���ֵ��� ������ �غ��ϴ� ����
	�����ϴ� ��� : ģ������ ���� ���� ���� �� �ִ� �������ַ� ����
					���� �����Ŀ� ���Դ� ģ���鸸 ���
					���� ������ ���� -> ������ ���� �� �ִ� ģ�� ���� ������Ʈ -> �ݺ�
	������ : ���� ���� ���� �� �ִ� ������ ���� ��찡 ���������϶� ��� ����ؾ� ��
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
	int testCase;	// �׽�Ʈ ���̽��� ������ ������ ����
	int friendNum;	// ģ������ ������ ����
	int foodNum;	// �� �� �ִ� ���� ������ ������ ����
	int* output;	// ����� �����ϰ� ����� ����
	int outputIdx = 0;	

	cin>>testCase;
	if(testCase > 50 || testCase < 0)
		return -1;

	output = new int[testCase];

	for(int testIdx = 0; testIdx < testCase; testIdx++)
	{
		// �˰��� �׽�Ʈ�� ������ �����͸� �Է¹޴� �κ�

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

		// �˰��� �׽�Ʈ �κ�
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
	//�Ű����� ���� ��ȭ�� ���� ���� const�� ����ȯ�Ͽ� �Է¹��� �����͸� �˰��� ������ ���Ͽ� ���� ������ �����ϴ� ����
	list<string> friendList;
	friendList.assign(_friendList.begin(), _friendList.end());

	list<string>* foodList = new list<string>[numOfFood];
	for(int i = 0; i<numOfFood; i++)
		foodList[i].assign(_foodList[i].begin(), _foodList[i].end());

	vector<int> optFood;
	optFood.push_back(foodList[0].size());
	optFood.push_back(0);

	int result = 0;

	//���� ���� ���� �� �ִ� ���� ã�� (���������� �ߺ�üũ�� �Բ�)
	//vector�� ù��° �ε����� �ִ�� ���� ���� �� �ִ� ����, ������ �ε����� ������ ����Ǿ� �ִ� �ε�����ȣ��
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

	//���� ���α׷��� ������� Ǯ��
	//eatedFriendList�� ������ ���� �� �ִ� ģ���� ��� �߰�, ���� ���� ������ ����
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
	
	//���� ��Ͽ��� �̹� ���� �� �ִ� ģ���� ��� ����
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

	//������ ���� �� ���� ģ������ ���� ���� ���� �� �ִ� ���� ��� �˻�
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
	
	//����������� ������ ���ļ� ã��
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
	//���� ���� �޸��Ҵ�� new A[10]; �ϸ� 10���� A�� �����ǰ� �ӽ� ��ü�ν� �ٷ� �Ҹ��� ȣ���
	//������ delete[] A�� �ϱ� ������ ���� ������ �޸𸮴� �������� ���� ���·� �����ǰ� �����Ҵ�� ������ �����͸� �̿��Ͽ�
	//�� ������ �ִ� ��ü�� ����Ų��. �������� �޸� ������ �����͸� �̿��Ͽ� delete�� �� ��쿡 �Ͼ��.

	�˰��� ������ : �˷����� ���� ģ����
	�����̿� n���� ģ���� �ʴ�
	���� �ƴ� m������ ������ ģ������ �˷����� ����Ͽ� �� ģ������ �ּ��� �ϳ����� ������ ���� ���ֵ��� ������ �غ��ϴ� ����
	�����ϴ� ��� : ģ������ ���� ���� ���� �� �ִ� �������ַ� ����
					���� �����Ŀ� ���Դ� ģ���鸸 ���
					���� ������ ���� -> ������ ���� �� �ִ� ģ�� ���� ������Ʈ -> �ݺ�
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