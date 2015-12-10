#include "MY_HEADER.h"

#ifdef HISTOGRAM
/*
	파일 이름 : [JO] Histogram.cpp
	작성자 : 주성문
	목적 : 정보올림피아드 알고리즘 문제 1214번 히스토그램 문제 해결
	       임의의 히스토그램이 주어졌을 때 히스토그램 내에서 사각형으로 이루어진 가장
		   큰 면적의 크기구하기
	사용방식 : 빌드시 main함수 부분을 선택하기 위하여 MY_HEADER.h 필요
	오류처리 : 입력값의 범위 체크 필요
	           n - 히스토그램을 이루는 사각형의 개수 (n <= 100,000)
			   사각형의 높이 = o<= k && k<= 1,000,000,000
			   unsigned로 처리하여 음수인 범위는 제외!
	이력 사항 : [2015-12-09] 재귀형식을 이용하여 문제해결, 최악의 경우 복잡도 O(n^2) 
*/

#include <iostream>
using namespace std;

unsigned long long int Solve(const unsigned int* arr, const unsigned int length);
unsigned long long int GetLeftMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index);
unsigned long long int GetRightMaxArea(const unsigned int* arr, const unsigned int length, const unsigned int pivot, const int index);

int main()
{
	unsigned int n;			// 히스토그램을 이루는 사각형의 개수 ( n<= 100,000 )
	unsigned int* buliding;	// 각 사각형의 높이를 저장할 변수

	cin >> n;
	if(n>= 100000)
		return -1;

	buliding = new unsigned int[n];	//동적 할당, 메모리 해제 필요!

	for(int i=0; i < n; i++)
	{
		cin>>buliding[i];
		if(buliding[i] > 1000000000)
			return -1;
	}

	cout<<Solve(buliding, n)<<endl;

	delete[] buliding;	//동적 할당한 메모리해제
	return 0;
}


/*
	알고리즘 설명 : 현재 인덱스에 해당하는 높이 부분을 기준으로 좌, 우의 높이를 비교
					좌, 우의 높이가 현재 기준 높이보다 클 경우 재귀로 확장하여 넓이 계산
					넓이 (너비가 1이므로 확장 될 수 있는 높이의 개수만큼 더해주면 넓이가 된다)
	알고리즘 분석 : 오름차순으로 정렬된 데이터일 경우 최악의 경우엔 O(n^2)의 복잡도 발생
				    높이의 덧셈 반복으로 인한 오버플로우 발생 예방을 위하여 데이터 형식은 unsigned long long int로 생성
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