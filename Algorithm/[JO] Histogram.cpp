#include "MY_HEADER.h"

#ifdef HISTOGRAM
/*
	���� �̸� : [JO] Histogram.cpp
	�ۼ��� : �ּ���
	���� : �����ø��ǾƵ� �˰��� ���� 1214�� ������׷� ���� �ذ�
	       ������ ������׷��� �־����� �� ������׷� ������ �簢������ �̷���� ����
		   ū ������ ũ�ⱸ�ϱ�
	����� : ����� main�Լ� �κ��� �����ϱ� ���Ͽ� MY_HEADER.h �ʿ�
	����ó�� : �Է°��� ���� üũ �ʿ�
	           n - ������׷��� �̷�� �簢���� ���� (n <= 100,000)
			   �簢���� ���� = o<= k && k<= 1,000,000,000
			   unsigned�� ó���Ͽ� ������ ������ ����!
	�̷� ���� : [2015-12-09] ��������� �̿��Ͽ� �����ذ�, �־��� ��� ���⵵ O(n^2) 
*/

#include <iostream>
using namespace std;

unsigned long long int Solve(const unsigned int* arr, const unsigned int length);
unsigned long long int GetLeftMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index);
unsigned long long int GetRightMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index);

int main()
{
	unsigned int n;			// ������׷��� �̷�� �簢���� ���� ( n<= 100,000 )
	unsigned int* buliding;	// �� �簢���� ���̸� ������ ����

	cin >> n;
	if(n>= 100000)
		return -1;

	buliding = new unsigned int[n];	//���� �Ҵ�, �޸� ���� �ʿ�!

	for(int i=0; i < n; i++)
	{
		cin>>buliding[i];
		if(buliding[i] > 1000000000)
			return -1;
	}

	cout<<Solve(buliding, n)<<endl;

	delete[] buliding;	//���� �Ҵ��� �޸�����
	return 0;
}


/*
	�˰��� ���� : ���� �ε����� �ش��ϴ� ���� �κ��� �������� ��, ���� ���̸� ��
					��, ���� ���̰� ���� ���� ���̺��� Ŭ ��� ��ͷ� Ȯ���Ͽ� ���� ���
					���� (�ʺ� 1�̹Ƿ� Ȯ�� �� �� �ִ� ������ ������ŭ �����ָ� ���̰� �ȴ�)
	�˰��� �м� : ������������ ���ĵ� �������� ��� �־��� ��쿣 O(n^2)�� ���⵵ �߻�
				    ������ ���� �ݺ����� ���� �����÷ο� �߻� ������ ���Ͽ� ������ ������ unsigned long long int�� ����
*/
unsigned long long int Solve(const unsigned int* arr, const unsigned int length)
{
	unsigned long long int maxArea = GetLeftMaxArea(arr,length, arr[0],0)+GetRightMaxArea(arr,length, arr[0], 0)+arr[0];

	for(int i = 1; i<length; i++)
	{
		unsigned long long int tempArea = GetLeftMaxArea(arr,length,arr[i],i)+GetRightMaxArea(arr,length,arr[i],i)+arr[i];

		if(maxArea<tempArea)
		{
			maxArea = tempArea;
		}	// if-end

	} // for-end

	return maxArea;
}

unsigned long long int GetLeftMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index)
{
	if(index-1 < 0)
		return 0;

	if(arr[index-1] >= pivot)
		return pivot+GetLeftMaxArea(arr,length, pivot,index-1);
	else
		return 0;
}

unsigned long long int GetRightMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index)
{
	if(index+1 == length)
		return 0;
	
	if(arr[index+1] >= pivot)
		return pivot+GetRightMaxArea(arr,length, pivot, index+1);
	else 
		return 0;
}

#endif