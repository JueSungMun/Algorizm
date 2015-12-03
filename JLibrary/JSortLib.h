/*
	����ؾ��� ������ Ÿ�� 
	Standard Data TYPE : int, float, double, char, string
	User Defined TYPE : class, structure
	1. main�� cpp������ �߰��Ͽ� ���ø� ���� ������ ����� Ư��ȭ ó���� ������ ���� �߻�
	   �ذ���-�Ϲ� ���ø� ���Ǵ� .h�� ����
	            ���ø� Ư��ȭ�� ���Ǻδ� .cpp�� ����
				https://wikidocs.net/488
*/

#ifndef JSORTLIB_H
#define JSORTLIB_H

#include <iostream>

namespace JLib
{
	/*
		http://www.joinc.co.kr/modules/moniwiki/wiki.php/Site/Database/algorithm/Quick_Sort
		http://egloos.zum.com/wrice/v/3097929

	*/

	/*
	template <typename T>
	void InsertSort(T arr[], int lengthT);

	template <typename T>
	void BubbleSort(T arr[], int lengthT);
	*/
	template <typename T>
	void SelectionSort(T arr[], int lengthT)
	{
		for(int i=0; i<lengthT-1; i++)
		{
			for(int j=i+1; j< lengthT; j++)
			{
				if(arr[i] > arr[j])
				{
					Swap(arr[i], arr[j]);
				}
			}
		}
	}

	template <>
	void SelectionSort(char arr[], int lengthT);

	template <typename T>
	void Swap(T& value1, T& value2)
	{
		T temp = value1;
		value1 = value2;
		value2 = temp;
	}
}

#endif