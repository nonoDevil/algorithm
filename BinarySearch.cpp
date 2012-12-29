/*
 * Program Name: BinarySearch.cpp
 * Create Date: 2012/12/29 13:11
 * Author: Jiajie.Chen
 * Description: An algorithm of search.  User binary search.
 */

#include <iostream>
using namespace std;

const int n = 10;

template <class Type>
int BinarySearch(Type array[], const Type& x, int n);

int main(void)
{
	int array[n] = {1, 3, 4, 5, 6, 7, 9, 11, 13, 14};
	int x = 0, ret = 0;

	cout << "Please input an integer: " << endl;
	cin >> x;

	ret = BinarySearch(array, x, n);
	if (-1 == ret) {
		cout << "Can not find " << x << " !" <<endl;
	} else {
		cout << "Found" << x << ", is arrary[" << ret << "] ." << endl;
	}

	return 0;
}

template <class Type>
int BinarySearch(Type array[], const Type& x, int n)
{
	int left = 0;
	int right = n - 1;
	int middle = 0;

	while (left <= right) 
	{
		middle = (left + right) / 2;
		if (x == array[middle]) {
			return middle;
		}
		if (x > array[middle]) {
			left = middle + 1;
		} else {
			right = middle - 1;			
		}
	}

	return -1;
}
