/*
	국제 표준에 맞춰 15 by 15 Size로 오목판을 제작
	○●┼ => size 16byte
*/

#include <iostream>
#include <string.h>

using namespace std;
void InitializeOmokBoard(char board[][31]); //바둑판을 초기화 하는 함수
void ShowOmokBoard(char board[][31]); //바둑판을 출력하는 함수
void InputOmokBoard(char board[][31]); //바둑돌을 두는 함수
void DecideWin(char board[][31]); // 이기는 상태를 점검하는 함수

int main(void)
{
	char board[16][31]; //바둑판 15*15, 널문자 1개 포함 +1, ┼문자 2바이트
	InitializeOmokBoard(board);	//초반에 오목판 초기화하기

	while(1)
	{
		system("cls");
		ShowOmokBoard(board); //바둑판을 보여주는 함수
		InputOmokBoard(board); //바둑돌을 두는 함수
		DecideWin(board);
		//ShowOmokBoard(board);
	}
	return 0;     
}

void InitializeOmokBoard(char board[][31])
{
	for(int i =1; i<15; i++)
	{
		strcpy(board[i], "├┼┼┼┼┼┼┼┼┼┼┼┼┼┤");
	}
	strcpy(board[0],"┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬");
	strncpy(&board[0][0], "┌",2);
	strncpy(&board[0][28], "┐",2);
	strcpy(board[14],"┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴");
	strncpy(&board[14][0], "└",2);
	strncpy(&board[14][28], "┘",2);
	//strncpy(board[0], "┬",30);
}

// 바둑판 그리는 함수
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

// 입력받은 위치에 바둑돌을 그리는 함수
void InputOmokBoard(char board[][31])
{ 
	int x, y;
	char input[4] = "○";
		cout<<"바둑돌의 X좌표를 입력하세요 : ";
		cin>>x;
		cout<<"바둑돌의 Y좌표를 입력하세요 : ";
		cin>>y;
	
	if(x>15 || x<1 || y<1 || y>15 ) 
	{
		if(x>15 || x<1)
			cout<<"입력하신 x값이 범위를 초과하셨습니다. (범위 1 ~ 15)"<<endl;
		if(y>15 || y<1)
			cout<<"입력하신 y값이 범위를 초과하셨습니다. (범위 1 ~ 15)"<<endl;
		getchar();
		getchar();
		return;
	}

	if(memcmp(&board[x-1][(y-1)*2], input,2) == 0) //같은 위치에 바둑돌이 있는지를 확인
	{
		cout<<"그위치에는 바둑돌을 두셨습니다."<<endl;
		getchar();
		getchar();
	}
	else strncpy(&board[x-1][(y-1)*2], input,2);
}

void DecideWin(char board[][31]) 
{
	char *widthWinning = NULL;	//행이 5개 되는지 파
	char *heightWinning = NULL;	//열이 5개 되는지 파악
	char height[31];	//각열의 내용을 저장할 배열

	//가로가 5개가 되는지 확인
	for(int i=0; i<15; i++)
	{
		widthWinning= strstr(board[i],"○○○○○");
		if(widthWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"끝났습니다."<<endl; 
			getchar();
			getchar();
			InitializeOmokBoard(board);
		}
	}
	
	//세로가 5개가 되는지 확인
	for(int j=0; j<15;j++)
	{
		for(int i=0; i<15;i++)
		{
			strncpy(&height[i*2], &board[i][j*2],2);	//각 열의 내용을 배열에 넣기
		}

		heightWinning = strstr(height, "○○○○○");
		if(heightWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"끝났습니다."<<endl; 
			getchar();
			getchar();
			InitializeOmokBoard(board);
		}
	}

	//대각선이 5개 되는지 확인
	/*
	for(int j=0; j<15;j++)
	{
		for(int i=0; i<15;i++)
		{
			strncpy(&height[i*2], &board[i][j*2],2);	//각 열의 내용을 배열에 넣기
		}

		heightWinning = strstr(height, "○○○○○");
		if(heightWinning != NULL)
		{
			system("cls");
			ShowOmokBoard(board);
			cout<<"끝났습니다."<<endl; 
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