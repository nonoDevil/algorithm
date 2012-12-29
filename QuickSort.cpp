/*
 * Program Name: QuickSort.cpp
 * Create Date: 2012/12/29 16:29
 * Author: Jiajie.Chen
 * Description: Quick sort
 */

#include <iostream>
using namespace std;

const int n = 10;

template <class Type>
int QuickSort(Type array[], int left, int right);
template <class Type>
void Swap(Type& a, Type& b);

int main(void)
{
	int array[n] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	QuickSort(array, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}


template <class Type>
int QuickSort(Type array[], int left, int right)
{
	int i = 0, j = 0;
	int pivot = 0;	
	
	if (left < right)
	{
		do 
		{
			i = left;
			j = right + 1;
			pivot = array[left];
			do {
				i++;		
			} while (array[i] < pivot);
			do {
				j--;
			} while (array[j] > pivot);
			if (i < j) {
				Swap(array[i], array[j]);
			}
		} while (i < j);
		Swap(array[left], array[j]);
		QuickSort(array, left, j - 1);
		QuickSort(array, j + 1, right);
	}

	return 0;
}

template <class Type>
void Swap(Type& a, Type& b)
{
	Type t;

	t =	a;
	a =	b;
	b = t;

	return ;
}


