#include "MY_HEADER.h"
#ifdef MERGESORT
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
#endif