/*
	LCD 디스플레이
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
		memset(string, -1, sizeof(char)*10);	 //String버퍼값을 초기화
	}
	return 0;
}

void LCD_Display(int size, char string[])
{
	for(int j=1 ; j<=size*2+3; j++)
	{
		for(int k = 0; k<=9; k++)
		{
			switch(string[k]) // 각숫자별로 한 행에 대하여 그리기
			{
				case '1' : 
					// 한열
					if(j !=1 && j !=size*2+3 && j !=size+2)	//맨위 가운데, 맨밑에 대하여 그리기
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
					// 첫줄
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위 가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//우측 그리기/
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else	//나머지 좌측 그리기
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					break;

				case '3':
					//첫줄
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위 가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else 	//우측 그리기/
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '4':
					//첫줄
					if(j == 1 || j == size*2+3)
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					else if(j == size+2)	//맨위 가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if(2<=j && j<size+2 )	//우측 그리기
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					else	//나머지 좌측 그리기
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '5':
					// 첫줄
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위 가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//좌측 그리기/
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					else	//나머지 우측 그리기
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '6':
					// 첫줄
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위 가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2 <=j && j < size +2 )	//좌측 그리기/
					{
						cout<<"| ";
						for(int i=1;i<size+2;i++) cout<<" ";
					}
					else	//나머지 우측 그리기
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '7':
					// 첫줄
					if(j == 1)	//맨위 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if(j == size+2 || j == size*2+3) //가운데 맨마지막 빈공간 만들기
					{
						for(int i=1;i<=size+2;i++) cout<<" ";
						cout<<" ";
					}
					else //나머지 우측 그리기
					{
						for(int i=1;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;
				case '8':
					// 첫줄
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위,가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else //양쪽 그리기/
					{
						cout<<"|";
						for(int i=2;i<size+2;i++) cout<<" ";
						cout<<"| ";
					}
					break;

				case '9':
					if(j == 1 || j==size*2+3 || j == size+2)	//맨위,가운데, 맨밑에 대하여 그리기
					{
						cout<<" ";
						for(int i=1; i<=size; i++) cout<<"-";
						cout<<"  ";
					}
					else if( 2<=j && j < size+2) //양쪽 그리기/
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
					// 첫줄
					if(j == 1 || j==size*2+3)	//맨위, 맨밑에 대하여 그리기
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
					else //양쪽 그리기/
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