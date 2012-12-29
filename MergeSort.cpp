/*
 * Program Name: MergeSort.cpp
 * Create Date: 2012/12/29 18:21
 * Author: Jiajie.Chen
 * Description: Merge sort, realized in recursive algorithm.
 */

#include <iostream>
using namespace std;

const int n = 10;
int temp[n] = {0};

template <class Type>
int MergeSort(Type array[], int left, int right);

template <class Type>
int Merge(Type array[], Type temp[], int left, int middle, int right);

template <class Type>
int Copy(Type array[], Type temp[], int left, int right); 

template <class Type>
void Swap(Type a, Type b);

int main(void)
{
	int array[n] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	MergeSort(array, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}


template <class Type>
int MergeSort(Type array[], int left, int right)
{
	if (left < right) 
	{
		int middle = (left + right) / 2;

		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);
		Merge(array, temp, left, middle, right);
		Copy(array, temp, left, right);
	}


	return 0;
}

template <class Type>
int Merge(Type array[], Type temp[], int left, int middle, int right)
{
	/*Merge array[left:middle] & array[middle+1:right]*/
	int i = left, j = middle + 1, k = left;

	while ((i <= middle) && (j <= right))
	{
		if (array[i] <= array[j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
		}
	}

	if (i > middle)
   	{
		for (int t = j; t <= right; t++) {
			temp[k++] = array[t];
		}	
	} 
	else 
	{
		for (int t = i; t <= middle; t++) {
			temp[k++] = array[t];
		}
	}

	return 0;
}

template <class Type>
int Copy(Type array[], Type temp[], int left, int right)
{
	while (left <= right) 
	{
		array[left] = temp[left];
		left++;
	}

	return 0;
}

template <class Type>
void Swap(Type& a, Type& b)
{
	Type t;

	t = a;
	a = b;
	b = t;

	return ;
}
