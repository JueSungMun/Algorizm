/*
	LCD ���÷���
*/
#include <iostream>
using namespace std;

void LCD_Display(int size, char string[]);

int main(void)
{
	int size;
	char string[10];
	while(1)
	{
		cin>>size>>string;
		cout<<"size = "<<size<<endl<<"string = "<<string<<endl;
		if(size==0 && strcmp(string,"0")==0) exit(1);
		LCD_Display(size, string);
		memset(string, -1, sizeof(char)*10);	 //String���۰��� �ʱ�ȭ
	}
	return 0;
}

void LCD_Display(int size, char string[])
{
	for(int j=1 ; j<=size*2+3; j++)
	{
		for(int k = 0; k<=9; k++)
		{
			switch(string[k]) // �����ں��� �� �࿡ ���Ͽ� �׸���
			{
				case '1' : 
					// �ѿ�
					if(j !=1 && j !=size*2+3 && j !=size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					break;

				case '2':
					// ù��
					if(j == 1 || j==size*2+3 || j == size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//���� �׸���/
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else	//������ ���� �׸���
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					break;

				case '3':
					//ù��
					if(j == 1 || j==size*2+3 || j == size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else 	//���� �׸���/
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '4':
					//ù��
					if(j == 1 || j == size*2+3)
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					else if(j == size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if(2<=j && j<size+2 )	//���� �׸���
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else	//������ ���� �׸���
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '5':
					// ù��
					if(j == 1 || j==size*2+3 || j == size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//���� �׸���/
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					else	//������ ���� �׸���
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '6':
					// ù��
					if(j == 1 || j==size*2+3 || j == size+2)	//���� ���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//���� �׸���/
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					else	//������ ���� �׸���
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '7':
					// ù��
					if(j == 1)	//���� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if(j == size+2 || j == size*2+3) //��� �Ǹ����� ����� �����
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					else //������ ���� �׸���
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;
				case '8':
					// ù��
					if(j == 1 || j==size*2+3 || j == size+2)	//����,���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else //���� �׸���/
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '9':
					if(j == 1 || j==size*2+3 || j == size+2)	//����,���, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2<=j && j < size+2) //���� �׸���/
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '0':
					// ù��
					if(j == 1 || j==size*2+3)	//����, �ǹؿ� ���Ͽ� �׸���
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if(j == size+2)
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					else //���� �׸���/
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				default:
					break;
			}
		}
		cout<<endl;
	}

}