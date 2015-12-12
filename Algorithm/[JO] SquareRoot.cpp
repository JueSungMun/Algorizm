#include "MY_HEADER.h"

#ifdef SQUAREROOT
/*
	파일 이름 : [JO] SquareRoot.cpp
	작성자 : 주성문
	목적 : 정보올림피아드 알고리즘 문제 1240번 제곱근 문제 해결
	       입력으로 주어진 제곱근의 정수 부분 출력
	사용방식 : 빌드시 main함수 부분을 선택하기 위하여 MY_HEADER.h 필요
	오류처리 : 입력값의 범위 체크 필요
	           2^63-1 이하의 양의 정수 N이 입력
	주의사항 : sqrt와 같은 함수 사용금지
			   stdio.h와 iostream등 입출력 헤더에 있는 함수만 사용 가능
	입출력 예시 : 입력에는 2^63-1 이하 양의 정수 N이 입력   출력에는 N의 제곱근의 정수부분을 출력
				  [input]									[output]
	              8											2
				  16										4
	이력 사항 : 2015-12-12 제곱근 검색은 특정 범위를 순차적으로 루프를 돌며 두수의 제곱이 입력된 값보다 큰지를 확인
			               특정 범위를 줄이는 부분이 중요! (2의 거듭제곱으로 나누어 상한, 하한 추출
								--> 상한과 하한의 범위가 1000이하가 되도록 검색영역을 평균값을 이용하여 분할
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
	검색 영역의 크기를 줄이기 위한 방법 제안
	1. 입력값을 2로 거듭 나눈다.
	2. 나눈 몫이 k라 할 경우, 2^k ~ 2^(k+1) 범위안에 제곱근 위치
	3. 최악의 경우 2^32-1 검색 필요--> 보완 필요
	   최악의 경우 1000번의 검색에서 제곱근을 검출할 수 있도록 검색 범위를 분할해가면서 크기를 줄임
	   범위 : upperBound - lowerBound
*/
DataType ProposedMethod(DataType _uiNum)
{
	//1의 제곱은은 1
	if(_uiNum == 1)
		return 1;

	int iDepth = 0;
	DataType tempNum = _uiNum;
	DataType lowerBound = 0;
	DataType upperBound = 0;
	DataType scope = 0;

	//입력된 값을 2로 거듭 나누어 검색할 상한과 하한을 추출
	do
	{
		tempNum = tempNum/2;
		iDepth++;
	} while(tempNum > 1);

	lowerBound = Pow(2,iDepth/2);
	upperBound = Pow(2,(iDepth/2)+1);
	scope = upperBound - lowerBound;

	//상한과 하한의 범위가 1000이하가 되어 최악의 경우를 보완하기 위한 루프
	while(scope > 1000)
	{
		DataType tempMin = (lowerBound+upperBound)/2;	//상한과 하한의 평균

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

	// 범위가 1000이하인 상한과 하한을 순차적으로 계산하여 제곱근 검색
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
	제곱근을 순차적으로 검색
	1~입력값의/2 위치까지 순차적으로 곱하면서 제곱근 정수부분 검출
	시간복잡도 : O(N/2) --> O(N)
				 입력값의 최대크기가 2^63-1 이므로 최악의 경우엔 2^62-1
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