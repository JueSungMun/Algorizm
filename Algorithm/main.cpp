#include "MY_HEADER.h"

#ifdef TEST
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

#endif