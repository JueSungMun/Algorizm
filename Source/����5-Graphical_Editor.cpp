#include <iostream>
using namespace std;

char **GraphicCol;	//�׷��� ��
char *GraphicRow;	//�׷��� ��

void Show_Graphic(int a, int b);
int main(void)
{
	char choiceCmd;
	int cmd1, cmd2; //�׷��� ������ ����� ��ɾ� ����
	while(1)
	{
		cout<<"��ɾ �Է����ּ���"<<endl;
		cout<<"I ���� ���� : ��� �ȼ��� ������� ĥ���� �迭 ����"<<endl;
		cout<<"C : ��� �ȼ��� ������� ĥ�ؼ� ǥ�� �����"<<endl;
		cout<<"L X Y C : (X,Y) �ȼ��� �־��� �� C�� ĥ�Ѵ�" <<endl;
		cout<<"V X Y1 Y2 C : X���� Y1���, Y2�� ���̿� �־��� ������ ���� ���� ������ �ߴ´�."<<endl;
		cin>>choiceCmd;

		switch(choiceCmd)
		{
			int num1,num2,num3;
			char ch1;

			case 'I':
				cin>>cmd1>>cmd2;	//cmd1 ��, cmd2 ��
				cout<< choiceCmd<<cmd1<<cmd2<<endl;
				//cout<< "cmd1 = "<< cmd1<< "cmd2 = "<< cmd2<<endl;
				GraphicCol = new char*[cmd1];
				GraphicRow = new char[cmd1*cmd2+1];	// ���ڿ� ���� ���Ͽ� +1 
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
				cout<<"��Ÿ"<<endl;

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

