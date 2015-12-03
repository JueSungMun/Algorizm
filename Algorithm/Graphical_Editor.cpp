#include <iostream>
using namespace std;

char **GraphicCol;	//그래픽 행
char *GraphicRow;	//그래픽 열

void Show_Graphic(int a, int b);
int main(void)
{
	char choiceCmd;
	int cmd1, cmd2; //그래픽 생성시 사용할 명령어 인자
	while(1)
	{
		cout<<"명령어를 입력해주세요"<<endl;
		cout<<"I 숫자 숫자 : 모든 픽셀을 흰색으로 칠해진 배열 생성"<<endl;
		cout<<"C : 모든 픽셀을 흰색으로 칠해서 표를 지운다"<<endl;
		cout<<"L X Y C : (X,Y) 픽셀을 주어진 색 C로 칠한다" <<endl;
		cout<<"V X Y1 Y2 C : X열에 Y1행과, Y2행 사이에 주어진 색으로 수직 방향 직선을 긋는다."<<endl;
		cin>>choiceCmd;

		switch(choiceCmd)
		{
			int num1,num2,num3;
			char ch1;

			case 'I':
				cin>>cmd1>>cmd2;	//cmd1 행, cmd2 열
				cout<< choiceCmd<<cmd1<<cmd2<<endl;
				//cout<< "cmd1 = "<< cmd1<< "cmd2 = "<< cmd2<<endl;
				GraphicCol = new char*[cmd1];
				GraphicRow = new char[cmd1*cmd2+1];	// 문자열 끝을 위하여 +1 
				for(int i=0; i<cmd1 ;i++)
				{
						//GraphicRow = new char[cmd2];
						GraphicCol[i] = &(GraphicRow[i*cmd2]);
				}

				for(int i=0; i<cmd1; i++)
					for(int j=0 ;j<cmd2; j++)
					{
						GraphicCol[i][j]='0';
					}
				Show_Graphic(cmd1,cmd2);
				break;

			case 'C':
				for(int i=0;i<cmd1; i++)
					for(int j=0;j<cmd2; j++)
					{
						GraphicCol[i][j] ='0';
					}
				Show_Graphic(cmd1,cmd2);
				break;
			case 'L' :
				cin>>num1>>num2>>ch1;
				GraphicCol[num1-1][num2-1] = ch1;
				Show_Graphic(cmd1,cmd2);
				break;
			case 'V' :
				cin>>num1>>num2>>num3>>ch1;
				for(int i = num2; i<=num3; i++)
				{
					GraphicCol[i-1][num1-1] = ch1;
				}
				Show_Graphic(cmd1,cmd2);
				break;
			case 'H' :
				cin>>num1>>num2>>num3>>ch1;
				for(int i = num1; i<=num2; i++)
				{
					GraphicCol[num3-1][i-1] = ch1;
				}
				Show_Graphic(cmd1,cmd2);
				
				break;
			case 'K' :
				break;
			case 'F' :
				break;
			case 'S' :

				break;
			case 'X' :
				delete[] GraphicRow;
				delete[] GraphicCol;
				exit(1);
				break;

			default : 
				cout<<"오타"<<endl;

				break;

		}
	}
	
	return 0;
}

void Show_Graphic(int a, int b)
{
	for(int i=0;i<a; i++)
	{
		for(int j=0;j<b; j++)
		{
			cout<<GraphicCol[i][j];
		}
		cout<<endl;
	}
}

