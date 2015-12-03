/*
	���� ǥ�ؿ� ���� 15 by 15 Size�� �������� ����
	�ۡܦ� => size 16byte
*/

#include <iostream>
#include <string.h>

using namespace std;
void InitializeOmokBoard(char board[][31]); //�ٵ����� �ʱ�ȭ �ϴ� �Լ�
void ShowOmokBoard(char board[][31]); //�ٵ����� ����ϴ� �Լ�
void InputOmokBoard(char board[][31]); //�ٵϵ��� �δ� �Լ�
void DecideWin(char board[][31]); // �̱�� ���¸� �����ϴ� �Լ�

int main(void)
{
	char board[16][31]; //�ٵ��� 15*15, �ι��� 1�� ���� +1, ������ 2����Ʈ
	InitializeOmokBoard(board);	//�ʹݿ� ������ �ʱ�ȭ�ϱ�

	while(1)
	{
		system("cls");
		ShowOmokBoard(board); //�ٵ����� �����ִ� �Լ�
		InputOmokBoard(board); //�ٵϵ��� �δ� �Լ�
		DecideWin(board);
		//ShowOmokBoard(board);
	}
	return 0;     
}

void InitializeOmokBoard(char board[][31])
{
	for(int i =1; i<15; i++)
	{
		strcpy(board[i], "������������������������������");
	}
	strcpy(board[0],"������������������������������");
	strncpy(&board[0][0], "��",2);
	strncpy(&board[0][28], "��",2);
	strcpy(board[14],"������������������������������");
	strncpy(&board[14][0], "��",2);
	strncpy(&board[14][28], "��",2);
	//strncpy(board[0], "��",30);
}

// �ٵ��� �׸��� �Լ�
void ShowOmokBoard(char board[][31])
{
	cout<<endl;
	cout<<"      1 2 3 4 5 6 7 8 9 A B C D E F"<<endl;
	cout<<"   1 "<<board[0]<<endl;
	cout<<"   2 "<<board[1]<<endl;
	cout<<"   3 "<<board[2]<<endl;
	cout<<"   4 "<<board[3]<<endl;
	cout<<"   5 "<<board[4]<<endl; 
	cout<<"   6 "<<board[5]<<endl;
	cout<<"   7 "<<board[6]<<endl;
	cout<<"   8 "<<board[7]<<endl;
	cout<<"   9 "<<board[8]<<endl;
	cout<<"   A "<<board[9]<<endl;
	cout<<"   B "<<board[10]<<endl;
	cout<<"   C "<<board[11]<<endl;
	cout<<"   D "<<board[12]<<endl;
	cout<<"   E "<<board[13]<<endl;
	cout<<"   F "<<board[14]<<endl<<endl;

}

// �Է¹��� ��ġ�� �ٵϵ��� �׸��� �Լ�
void InputOmokBoard(char board[][31])
{ 
	int x, y;
	char input[4] = "��";
		cout<<"�ٵϵ��� X��ǥ�� �Է��ϼ��� : ";
		cin>>x;
		cout<<"�ٵϵ��� Y��ǥ�� �Է��ϼ��� : ";
		cin>>y;
	
	if(x>15 || x<1 || y<1 || y>15 ) 
	{
		if(x>15 || x<1)
			cout<<"�Է��Ͻ� x���� ������ �ʰ��ϼ̽��ϴ�. (���� 1 ~ 15)"<<endl;
		if(y>15 || y<1)
			cout<<"�Է��Ͻ� y���� ������ �ʰ��ϼ̽��ϴ�. (���� 1 ~ 15)"<<endl;
		getchar();
		getchar();
		return;
	}

	if(memcmp(&board[x-1][(y-1)*2], input,2) == 0) //���� ��ġ�� �ٵϵ��� �ִ����� Ȯ��
	{
		cout<<"����ġ���� �ٵϵ��� �μ̽��ϴ�."<<endl;
		getchar();
		getchar();
	}
	else strncpy(&board[x-1][(y-1)*2], input,2);
}

void DecideWin(char board[][31]) 
{
	char *widthWinning = NULL;	//���� 5�� �Ǵ��� ��
	char *heightWinning = NULL;	//���� 5�� �Ǵ��� �ľ�
	char height[31];	//������ ������ ������ �迭

	//���ΰ� 5���� �Ǵ��� Ȯ��
	for(int i=0; i<15; i++)
	{
		widthWinning= strstr(board[i],"�ۡۡۡۡ�");
		if(widthWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"�������ϴ�."<<endl; 
			getchar();
			getchar();
			InitializeOmokBoard(board);
		}
	}
	
	//���ΰ� 5���� �Ǵ��� Ȯ��
	for(int j=0; j<15;j++)
	{
		for(int i=0; i<15;i++)
		{
			strncpy(&height[i*2], &board[i][j*2],2);	//�� ���� ������ �迭�� �ֱ�
		}

		heightWinning = strstr(height, "�ۡۡۡۡ�");
		if(heightWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"�������ϴ�."<<endl; 
			getchar();
			getchar();
			InitializeOmokBoard(board);
		}
	}

	//�밢���� 5�� �Ǵ��� Ȯ��
	/*
	for(int j=0; j<15;j++)
	{
		for(int i=0; i<15;i++)
		{
			strncpy(&height[i*2], &board[i][j*2],2);	//�� ���� ������ �迭�� �ֱ�
		}

		heightWinning = strstr(height, "�ۡۡۡۡ�");
		if(heightWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"�������ϴ�."<<endl; 
			getchar();
			getchar();
			InitializeOmokBoard(board);
		}
	}
	*/ 
}

void AIPlayer(char board[][31])
{
	int risk;


}