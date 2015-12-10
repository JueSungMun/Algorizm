#include "MY_HEADER.h"

#ifdef QUICKSORT
/*
	���� �̸� : [JO] QuickSort.cpp
	�ۼ��� : �ּ���
	���� : �����ø��ǾƵ� �˰��� ���� 1972�� ������ ���� �ذ�
	       �Է����� �־��� �ڿ������� �������� �Ǵ� ������������ �����Ͽ� ���
	����� : ����� main�Լ� �κ��� �����ϱ� ���Ͽ� MY_HEADER.h �ʿ�
	����ó�� : �Է°��� ���� üũ �ʿ�
	           n - ������ �ڿ����� ���� (1<= n <= 50,000)
			   �ڿ��� n�� ���� : 10�� ������ ��
	����� ���� : [input]									[output]
	              5	 ������ ����							1
				  0	 ���Ĺ��(0-��������, 1-��������)		2
				  9											5
				  2											9
				  5											100
				  1
				  100
	�̷� ���� :  2015-12-10 ��Ű�ǵ�ƿ� ����� quicksort �˰����� �����Ͽ� ����, �ӵ� ���� �ʿ� (pivot���� ���)
*/

#include <iostream>
#include <fstream>

using namespace std;
#define DATA_SIZE_THRESHOLD 50000	// ������ ������ ũ���� �Ӱ�ġ
#define DATA_THRESHOLD 100000000	// �� ������ ũ���� �Ӱ�ġ

void QuickSort(unsigned int* _uiDataList, int _startIdx, int _endIdx, bool _bIsDecendingOrder);
void Swap(unsigned int& _uiData1, unsigned int& _uiData2);
void ShowDataList(unsigned int* _uiDataList, unsigned int _uiNumOFData);

int main()
{
	unsigned int uiNumOfData;	// ������ �ڿ����� ����, ui : unsigned int �ǹ�
	unsigned int* uiDataList;	// ������ ������ ����Ʈ

	bool bIsDecendingOrder;		// ���Ĺ�� (0�ϰ�� ��������, 1�� ��� ��������), b : bool �ǹ�

	bool useOfFileStream = false;	//������ �Է� ��� ���� (����, �ܼ��Է�)

	if(useOfFileStream)	//���� �Է��� ���
	{
		ifstream fileStream;
		fileStream.open("quicksortData.txt");
		fileStream>>uiNumOfData;
		if(uiNumOfData > DATA_SIZE_THRESHOLD)
			return -1;

		fileStream>>bIsDecendingOrder;
		uiDataList = new unsigned int[uiNumOfData];	// ������ ������ ����Ʈ �����Ҵ�, delete[] �ʿ�

		for(int i=0; i<uiNumOfData; i++)
		{
			fileStream>>uiDataList[i];
			if(uiDataList[i] > DATA_THRESHOLD)
				return -1;
		}

		fileStream.close();
	}
	else	// �ܼ� �Է�
	{
		cin>>uiNumOfData;
		if(uiNumOfData > DATA_SIZE_THRESHOLD)
			return -1;

		cin>>bIsDecendingOrder;

		uiDataList = new unsigned int[uiNumOfData];	// ������ ������ ����Ʈ �����Ҵ�, delete[] �ʿ�

		for(int i=0; i<uiNumOfData; i++)
		{
			cin>>uiDataList[i];
			if(uiDataList[i] > DATA_THRESHOLD)
				return -1;
		}
	}

	QuickSort(uiDataList, 0, uiNumOfData-1, bIsDecendingOrder);

	ShowDataList(uiDataList, uiNumOfData);
	
	delete[] uiDataList;
	return 0;
}

void QuickSort(unsigned int* _uiDataList, int _startIdx, int _endIdx, bool _bIsDecendingOrder)
{
	if( (_endIdx-_startIdx) <= 0 || _endIdx <= _startIdx)
		return;

	unsigned int pivot = _uiDataList[_endIdx];		//�Էµ� �迭�� �� �� ���Ҹ� pivot���� ����

	int i=_startIdx;
	int j= _endIdx-1;
	int pivotIdx = _endIdx;

	if(_bIsDecendingOrder)	// �������� ����
	{
		while( !(i==j) )
		{
			if(_uiDataList[i] < pivot && _uiDataList[j] > pivot)
			{
				Swap(_uiDataList[i], _uiDataList[j]);
			}
			else if(_uiDataList[i] >= pivot)
			{
				i++;
			}
			else if(_uiDataList[j] <= pivot)
			{
				j--;
			}
		}
		if(pivot > _uiDataList[j])
		{
			Swap(_uiDataList[j], _uiDataList[_endIdx]);
			pivotIdx = j;
		}
		else
			pivotIdx = _endIdx;
	}	//outer if-end
	else	// �������� ����
	{
		while( !(i==j) )
		{
			if(_uiDataList[i] > pivot && _uiDataList[j] < pivot)
			{
				Swap(_uiDataList[i], _uiDataList[j]);
			}
			else if(_uiDataList[i] <= pivot)
			{
				i++;
			}
			else if(_uiDataList[j] >= pivot)
			{
				j--;
			}
		}

		if(pivot < _uiDataList[j])
		{
			Swap(_uiDataList[j], _uiDataList[_endIdx]);
			pivotIdx = j;
		}
		else
			pivotIdx = _endIdx;
	}	// outer else-end
	
	//pivot�� �������� ���ľȵ� �¿� �κп� ���� ��� ȣ��
	QuickSort(_uiDataList, _startIdx, pivotIdx-1,_bIsDecendingOrder);
	QuickSort(_uiDataList, pivotIdx+1, _endIdx,_bIsDecendingOrder);	
}

// �� ������ ���� ��ȯ�ϴ� �Լ�
void Swap(unsigned int& _uiData1, unsigned int& _uiData2)
{
	unsigned int temp = _uiData1;
	_uiData1 = _uiData2;
	_uiData2 = temp;
}

// ������ ������ ����ϴ� �Լ�
void ShowDataList(unsigned int* _uiDataList, unsigned int _uiNumOFData)
{
	for(int i=0; i<_uiNumOFData; i++)
	{
		cout<<_uiDataList[i]<<endl;
	}
}
#endif