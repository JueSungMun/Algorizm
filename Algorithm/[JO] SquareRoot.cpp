#include "MY_HEADER.h"

#ifdef SQUAREROOT
/*
	���� �̸� : [JO] SquareRoot.cpp
	�ۼ��� : �ּ���
	���� : �����ø��ǾƵ� �˰��� ���� 1240�� ������ ���� �ذ�
	       �Է����� �־��� �������� ���� �κ� ���
	����� : ����� main�Լ� �κ��� �����ϱ� ���Ͽ� MY_HEADER.h �ʿ�
	����ó�� : �Է°��� ���� üũ �ʿ�
	           2^63-1 ������ ���� ���� N�� �Է�
	���ǻ��� : sqrt�� ���� �Լ� ������
			   stdio.h�� iostream�� ����� ����� �ִ� �Լ��� ��� ����
	����� ���� : �Է¿��� 2^63-1 ���� ���� ���� N�� �Է�   ��¿��� N�� �������� �����κ��� ���
				  [input]									[output]
	              8											2
				  16										4
	�̷� ���� : 2015-12-12 ������ �˻��� Ư�� ������ ���������� ������ ���� �μ��� ������ �Էµ� ������ ū���� Ȯ��
			               Ư�� ������ ���̴� �κ��� �߿�! (2�� �ŵ��������� ������ ����, ���� ����
								--> ���Ѱ� ������ ������ 1000���ϰ� �ǵ��� �˻������� ��հ��� �̿��Ͽ� ����
*/

#include <iostream>
using namespace std;

typedef long long unsigned int DataType;
DataType LinearSearchSquareRoot(DataType _uiNum);
DataType ProposedMethod(DataType _uiNum);
DataType Pow(DataType _uiNumA, DataType _uiNumB);

int main()
{
	DataType uiNumbOfData;
	cin>>uiNumbOfData;
	
	cout<<ProposedMethod(uiNumbOfData)<<endl;

	return 0;
}

/*
	�˻� ������ ũ�⸦ ���̱� ���� ��� ����
	1. �Է°��� 2�� �ŵ� ������.
	2. ���� ���� k�� �� ���, 2^k ~ 2^(k+1) �����ȿ� ������ ��ġ
	3. �־��� ��� 2^32-1 �˻� �ʿ�--> ���� �ʿ�
	   �־��� ��� 1000���� �˻����� �������� ������ �� �ֵ��� �˻� ������ �����ذ��鼭 ũ�⸦ ����
	   ���� : upperBound - lowerBound
*/
DataType ProposedMethod(DataType _uiNum)
{
	//1�� �������� 1
	if(_uiNum == 1)
		return 1;

	int iDepth = 0;
	DataType tempNum = _uiNum;
	DataType lowerBound = 0;
	DataType upperBound = 0;
	DataType scope = 0;

	//�Էµ� ���� 2�� �ŵ� ������ �˻��� ���Ѱ� ������ ����
	do
	{
		tempNum = tempNum/2;
		iDepth++;
	} while(tempNum > 1);

	lowerBound = Pow(2,iDepth/2);
	upperBound = Pow(2,(iDepth/2)+1);
	scope = upperBound - lowerBound;

	//���Ѱ� ������ ������ 1000���ϰ� �Ǿ� �־��� ��츦 �����ϱ� ���� ����
	while(scope > 1000)
	{
		DataType tempMin = (lowerBound+upperBound)/2;	//���Ѱ� ������ ���

		if(tempMin*tempMin>_uiNum)
			upperBound = tempMin;
		else if(tempMin*tempMin<_uiNum)
			lowerBound = tempMin;
		else
		{
			lowerBound = tempMin;
			upperBound = tempMin;
		}
		scope = upperBound-lowerBound;
	}

	// ������ 1000������ ���Ѱ� ������ ���������� ����Ͽ� ������ �˻�
	DataType i=0;
	for(i = lowerBound; i<upperBound; i++)
	{
		if(i*i > _uiNum)
			break;
	}

	return i-1;
}

DataType Pow(DataType a, DataType b)
{
	DataType result = a;
	for(int i =1 ; i<b; i++)
	{
		result *= a;
	}
	return result;
}

/*
	�������� ���������� �˻�
	1~�Է°���/2 ��ġ���� ���������� ���ϸ鼭 ������ �����κ� ����
	�ð����⵵ : O(N/2) --> O(N)
				 �Է°��� �ִ�ũ�Ⱑ 2^63-1 �̹Ƿ� �־��� ��쿣 2^62-1
*/
DataType LinearSearchSquareRoot(DataType input)
{
	DataType index = 1;

	if(input > 3)
	{
		DataType step = input/2;
	
		while(index*index > input)
		{
			index++;
		}
	}
	return index;
}

#endif