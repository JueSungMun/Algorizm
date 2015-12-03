#include <iostream>
using namespace std;

int main()
{
	int* arr = new int[10];
	
	for(int i = 0; i<10; i++)
		arr[i] = i+1;

	cout<<"array Address : "<<arr<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr[i]<<endl;
	}

	int* arr2 = new int[10];
	
	for(int i = 0; i<10; i++)
		arr2[i] = i+1;


	cout<<"array Address : "<<arr2<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr2[i]<<endl;
	}

	int* arr3 = new int[10];
	
	for(int i = 0; i<10; i++)
		arr3[i] = i+1;


	cout<<"array Address : "<<arr3<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr3[i]<<endl;
	}

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}

/*
// NC Test 스택 메모리 구조 이해 문제
// ptr주소가 100일때 메모리 구조는 어떻게 되는가?
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

int main()
{
	Node n1 = {10,nullptr}, n2 = {20,nullptr},n3 = {30,nullptr},
	     n4 = {40,nullptr}, n5 = {50,nullptr};
	Node* ptr = &n1;
	n1.link = &n2;
	n2.link = &n3;
	n3.link = &n4;
	n4.link = &n5;

	//ptr = &n1;
	cout<<"ptr Address : " <<&ptr<<endl;
	cout<<"n1 Address : " <<&n1<<endl;
	cout<<"n1 Data Address : " <<&n1.data<<endl;
	cout<<"n1 Link Address : " <<&n1.link<<endl;
	cout<<"n2 Address : " <<&n2<<endl;
	cout<<"n2 Data Address : " <<&n2.data<<endl;
	cout<<"n2 Link Address : " <<&n2.link<<endl;
	cout<<"n3 Address : " <<&n3<<endl;
	cout<<"n3 Data Address : " <<&n3.data<<endl;
	cout<<"n3 Link Address : " <<&n3.link<<endl;
	cout<<"n4 Address : " <<&n4<<endl;
	cout<<"n4 Data Address : " <<&n4.data<<endl;
	cout<<"n4 Link Address : " <<&n4.link<<endl;
	cout<<"n5 Address : " <<&n5<<endl;
	cout<<"n5 Data Address : " <<&n5.data<<endl;
	cout<<"n5 Link Address : " <<&n5.link<<endl;

	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;
	ptr = ptr->link;
	cout<<ptr->data;

	return 0;
}
*/

/*

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// Merged Sort에 사용될 데이터 객체 
class Data
{
		public:
			int currentIdx;
			int *data;
			int size;

			Data(int *indata, int insize = 0)
			{
				data = indata;
				size = insize;
				currentIdx = 0;
			}

			void Input(int a)
			{
				data[currentIdx] = a;
				currentIdx++;
			}

			int Size()
			{
				if (size == 0)
					return currentIdx;
				return size; 
			}
};

// Merged Sort 클래스
class MergedSort
{
	private :
		int BUFSIZE;
		int *buff;

		Data *InputData; 

		int *buffIdx;
		int flag;
		int flagidx;
		int inputsize;
		Data *inputData;
		Data *outputData;
		vector<Data *> dataVector;

	public :
		MergedSort() 
		{
			BUFSIZE = 30;
			flag = 0;
			flagidx = 0;
			inputsize = 0;
		};

		void Sort(int *a, int *b, int sizea, int sizeb)
		{
			int bufsize;
			int idx;
			inputData = new Data(a, sizea);
			dataVector.push_back(inputData);

			inputData = new Data(b, sizeb);
			dataVector.push_back(inputData);

			buff = (int *)malloc(sizeof(int)*(sizea + sizeb)); 
			memset(buff, 0x00, sizeof(int)*(sizea+sizeb));
			outputData = new Data(buff);

			bufsize = BUFSIZE - 1;

			int topdoc = -1;
			while(true)
			{
				idx = dataVector[flag]->currentIdx;
				if (inputsize > bufsize)
				{
					printf("Input Buffer Excess\n");
					break;
				}
				if (idx >= dataVector[flag]->size)
				{
					flagidx++;
					flag = flagidx%2;
					idx = dataVector[flag]->currentIdx;
					int max = dataVector[flag]->size;
					while(idx < max)
					{
						outputData->Input(dataVector[flag]->data[idx]);	
						idx++;
					}
					break;
				}
				if (dataVector[flag]->data[idx] > topdoc)
				{
					topdoc = dataVector[flag]->data[idx];
					flagidx++;
					flag = (flagidx)%2;
				}
				else if (dataVector[flag]->data[idx] == topdoc)
				{
					outputData->Input(dataVector[flag]->data[idx]);
					dataVector[flag]->currentIdx++;
					idx =	dataVector[flag]->currentIdx;

					topdoc = dataVector[flag]->data[idx];

					flagidx++;
					flag = flagidx%2;
					dataVector[flag]->currentIdx++;
				}
				else
				{
					outputData->Input(dataVector[flag]->data[idx]);
					dataVector[flag]->currentIdx++;
				}
			}
		}
		Data *get()
		{
			return outputData;
		}
};

int main(int argc, char **argv)
{
	MergedSort *DataSort;
	Data *rtvData;
	int a[] = {1, 5, 6, 8, 10, 22, 24, 29, 31, 33, 49, 50, 100, 200, 400, 410, 412, 413};
	int b[] = {5, 10, 20, 30, 50, 51};

	DataSort = new MergedSort();
	DataSort->Sort(a, b, sizeof(a)/sizeof(int), sizeof(b)/sizeof(int));
	rtvData = DataSort->get();
	printf("Size is %d\n", rtvData->Size());
	for (int i = 0; i < rtvData->Size(); i++)
	{
		printf("%d : %d\n", i, rtvData->data[i]);
	}
}
 */ 

/*
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int digit[3] = {};

	for(int i=1; i<999; i++)
	{
		int temp = i;
		digit[0] = temp/100;
		temp = temp-digit[0]*100;
		digit[1] = temp/10;
		temp = temp-digit[1]*10;
		digit[2] = temp/1;
		if(digit[0] != 0 && digit[0]%7 == 0 || digit[1] != 0 && digit[1]%7 == 0 || digit[2] != 0 && digit[2]%7 == 0)
		{
			count++;
					cout<<digit[0]<<digit[1]<<digit[2]<<endl;
		}
	}
	cout<<"0~999에서 7의 개수 : "<<count<<endl;
	return 0;
}
*/