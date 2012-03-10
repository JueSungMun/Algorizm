/*
	2011�� 8�� 30�� ������
	����2 : ����ã��
	�Է�: ���� ������ ���ڹ����� �����ȴ�. �� ���ڹ��� ù��° �ٿ��� ���� ��� ���� ������ ��Ÿ���� �ΰ��� ���� n�� m
		 (0<n,m <=100)�� ����ִ�. �� ���� �ٺ��ʹ� n���� �ٿ� ���ļ� �� �ٸ��� ��Ȯ�ϰ� m������ ���ڰ� ���������
		 �̴� ���ڹ��� ��Ÿ����.
		 ���ڰ� ���� ĭ�� '.'����, ���ڴ� '*'���� ǥ�õǸ� �̶� ����ǥ�� ���� �ʴ´�. n =m=0�� ���� �Է��� �������� ��Ÿ���� ���̹Ƿ�
		 ������ ó������ �ʴ´�.
	
	���: �� ���ڹ翡 ���� Field #x:��� �����ִ� �޽����� ����Ѵ�. �̶� x�� �ʵ� ��ȣ�� ��Ÿ���� 1���� �����Ѵ�.
		  �״��� �ٺ��ʹ� n���� �ٿ� ���ļ� '.' ���� ��� ��ĭ�� ������ ĭ�� ����ִ� ������ ������ ����Ѵ�.
		  �� ���ڹ翡 ���� ��� ���̿��� �ݵ�� ������ �ϳ��� �־���Ѵ�
		  
	>>�Է¿�							>>��¿�

	4 4								Field #1:
	*...							*100
	....							2210
	.*..							1*10
	....							1110
	
	3 5								Field #2:
	**...							**100
	.....							33200
	.*...							1*100
	0 0  //����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InsertInput(int n, int m, char * arr);
void ShowInput(int n, int m, char * arr);
void MakeMine(int n, int m, char * arr);

int main(void)
{
	int n=0,m=0;	//n = ��, m = ��		0<n,m<100
	char *arr;		//����� ���� ���� �迭�� ǥ��
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
		printf("%d��° �ε��� : %c\n", i, *(arr+i));
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