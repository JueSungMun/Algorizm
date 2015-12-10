#include "MY_HEADER.h"

#ifdef QUICKSORT
/*
	파일 이름 : [JO] QuickSort.cpp
	작성자 : 주성문
	목적 : 정보올림피아드 알고리즘 문제 1972번 퀵정렬 문제 해결
	       입력으로 주어진 자연수들을 오름차순 또는 내림차순으로 정렬하여 출력
	사용방식 : 빌드시 main함수 부분을 선택하기 위하여 MY_HEADER.h 필요
	오류처리 : 입력값의 범위 체크 필요
	           n - 정렬할 자연수의 개수 (1<= n <= 50,000)
			   자연수 n의 범위 : 10억 이하의 수
	입출력 예시 : [input]									[output]
	              5	 데이터 개수							1
				  0	 정렬방식(0-오름차순, 1-내림차순)		2
				  9											5
				  2											9
				  5											100
				  1
				  100
	이력 사항 :  2015-12-10 위키피디아에 기재된 quicksort 알고리즘을 참고하여 구현, 속도 개선 필요 (pivot선택 방법)
*/

#include <iostream>
#include <fstream>

using namespace std;
#define DATA_SIZE_THRESHOLD 50000	// 정렬할 데이터 크기의 임계치
#define DATA_THRESHOLD 100000000	// 각 데이터 크기의 임계치

void QuickSort(unsigned int* _uiDataList, int _startIdx, int _endIdx, bool _bIsDecendingOrder);
void Swap(unsigned int& _uiData1, unsigned int& _uiData2);
void ShowDataList(unsigned int* _uiDataList, unsigned int _uiNumOFData);

int main()
{
	unsigned int uiNumOfData;	// 정렬할 자연수의 개수, ui : unsigned int 의미
	unsigned int* uiDataList;	// 정렬할 데이터 리스트

	bool bIsDecendingOrder;		// 정렬방식 (0일경우 오름차순, 1일 경우 내림차순), b : bool 의미

	bool useOfFileStream = false;	//데이터 입력 방식 선택 (파일, 콘솔입력)

	if(useOfFileStream)	//파일 입력일 경우
	{
		ifstream fileStream;
		fileStream.open("quicksortData.txt");
		fileStream>>uiNumOfData;
		if(uiNumOfData > DATA_SIZE_THRESHOLD)
			return -1;

		fileStream>>bIsDecendingOrder;
		uiDataList = new unsigned int[uiNumOfData];	// 정렬할 데이터 리스트 동적할당, delete[] 필요

		for(int i=0; i<uiNumOfData; i++)
		{
			fileStream>>uiDataList[i];
			if(uiDataList[i] > DATA_THRESHOLD)
				return -1;
		}

		fileStream.close();
	}
	else	// 콘솔 입력
	{
		cin>>uiNumOfData;
		if(uiNumOfData > DATA_SIZE_THRESHOLD)
			return -1;

		cin>>bIsDecendingOrder;

		uiDataList = new unsigned int[uiNumOfData];	// 정렬할 데이터 리스트 동적할당, delete[] 필요

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

	unsigned int pivot = _uiDataList[_endIdx];		//입력된 배열의 맨 끝 원소를 pivot으로 선택

	int i=_startIdx;
	int j= _endIdx-1;
	int pivotIdx = _endIdx;

	if(_bIsDecendingOrder)	// 내림차순 정렬
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
	else	// 오름차순 정렬
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
	
	//pivot을 기준으로 정렬안된 좌우 부분에 대해 재귀 호출
	QuickSort(_uiDataList, _startIdx, pivotIdx-1,_bIsDecendingOrder);
	QuickSort(_uiDataList, pivotIdx+1, _endIdx,_bIsDecendingOrder);	
}

// 두 데이터 값을 교환하는 함수
void Swap(unsigned int& _uiData1, unsigned int& _uiData2)
{
	unsigned int temp = _uiData1;
	_uiData1 = _uiData2;
	_uiData2 = temp;
}

// 데이터 내용을 출력하는 함수
void ShowDataList(unsigned int* _uiDataList, unsigned int _uiNumOFData)
{
	for(int i=0; i<_uiNumOFData; i++)
	{
		cout<<_uiDataList[i]<<endl;
	}
}
#endif