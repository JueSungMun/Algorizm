/*
	2011년 8월 30일 월요일
	문제2 : 지뢰찾기
	입력: 임의 개수의 지뢰밭으로 구성된다. 각 지뢰밭의 첫번째 줄에는 각각 행과 열의 개수를 나타내는 두개의 정수 n과 m
		 (0<n,m <=100)이 들어있다. 그 다음 줄부터는 n개의 줄에 걸쳐서 각 줄마다 정확하게 m개씩의 문자가 들어있으며
		 이는 지뢰밭을 나타낸다.
		 지뢰가 없는 칸은 '.'으로, 지뢰는 '*'으로 표시되며 이때 따옴표는 쓰지 않는다. n =m=0인 줄은 입력이 끝났음을 나타내는 것이므로
		 그줄은 처리하지 않는다.
	
	출력: 각 지뢰밭에 대해 Field #x:라고 적혀있는 메시지를 출력한다. 이때 x는 필드 번호를 나타내며 1에서 시작한다.
		  그다음 줄부터는 n개의 줄에 걸쳐서 '.' 문자 대신 그칸에 인접한 칸에 들어있는 지뢰의 개수를 출력한다.
		  각 지뢰밭에 대한 출력 사이에는 반드시 빈줄이 하나씩 있어야한다
		  
	>>입력예							>>출력예

	4 4								Field #1:
	*...							*100
	....							2210
	.*..							1*10
	....							1110
	
	3 5								Field #2:
	**...							**100
	.....							33200
	.*...							1*100
	0 0  //종료
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InsertInput(int n, int m, char * arr);
void ShowInput(int n, int m, char * arr);
void MakeMine(int n, int m, char * arr);

int main(void)
{
	int n=0,m=0;	//n = 행, m = 열		0<n,m<100
	char *arr;		//행렬의 값을 동적 배열로 표현
	scanf("%d %d",&n,&m);
	arr = (char *)malloc(sizeof(char)*n*m);
	InsertInput(n, m, arr);
	ShowInput(n, m, arr);	
	MakeMine(n, m, arr);
}
void InsertInput(int n, int m, char * arr)
{
	int i;
	for(i=0; i<n*m;i++)
	{
		if(i%m == 0)
			{
				getchar();
			}
		scanf("%c", (arr+i));
	}
}

void ShowInput(int n, int m, char * arr)
{
	int i;
	for(i=0;i<n*m ; i++)
	{
		printf("%d번째 인덱스 : %c\n", i, *(arr+i));
	}
	printf("\n\n");
}

void MakeMine(int n, int m, char * arr)
{
	int i;
	char *mine = (char *)malloc(sizeof(char)*n*m);
	memset(mine,0,sizeof(char)*n*m);
	for(i=0;i<n*m;i++)
	{
		if(*(arr+i) == '*')
		{
			if(i%m == 0)
			{
				*(mine+i-m) = (*(mine+i-m))++;
				*(mine+i-m+1) = (*(mine+i-m+1))++;
				*(mine+i) = '*';
				*(mine+i+1) = (*(mine+i+1))++;
				*(mine+i+m) = (*(mine+i+m))++;
				*(mine+i+m+1) = (*(mine+i+m+1))++;			
			
			}
			else if(i%m == m-1)
			{
				*(mine+i-m-1) = (*(mine+i-m-1))++;
				*(mine+i-m) = (*(mine+i-m))++;
				*(mine+i-1) = (*(mine+i-1))++;
				*(mine+i) = '*';
				*(mine+i+m-1) = (*(mine+i+m-1))++;
				*(mine+i+m) = (*(mine+i+m))++;
			}
			else
			{
				*(mine+i-m-1) = (*(mine+i-m-1))++;
				*(mine+i-m) = (*(mine+i-m))++;
				*(mine+i-m+1) = (*(mine+i-m+1))++;
				*(mine+i-1) = (*(mine+i-1))++;
				*(mine+i) = '*';
				*(mine+i+1) = (*(mine+i+1))++;
				*(mine+i+m-1) = (*(mine+i+m-1))++;
				*(mine+i+m) = (*(mine+i+m))++;
				*(mine+i+m+1) = (*(mine+i+m+1))++;
			}
		}
	}
	for(i=0;i<n*m ; i++)
	{
		if(i%m == 0)
		{
			printf("\n\n");
		}
		if(*(arr+i) == '*')
			printf("%c", *(arr+i));
		else
			printf("%d", *(mine+i));
	}
	printf("\n\n");
}