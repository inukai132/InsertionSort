// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> insertion(vector<int> numbers)
{
	vector<int> sorted(numbers);
	int size = sorted.size();
	for (int i = 1; i < size; i++)
	{
		int t = sorted[i];
		int j;
		for (j = i-1; j >= 0 && t < sorted[j]; j--)
		{
			sorted[j + 1] = sorted[j];
		}
		sorted[j + 1] = t;
	}
	return sorted;
}

vector<int> doSort(int length, int iterations)
{
	srand(time(NULL));
	
	vector<int> numbers(length,0);
	vector<int> numbersSorted(length,0);
	vector<int> times(iterations,0);

	for (int i = 0; i < iterations; i++)
	{

		for (int i = 0; i < length; i++)
		{
			int t = rand() % INT16_MAX;
			numbers[i] = t;
		}

		int startTime = clock();

		for (int j = 1; j < length; j++)
		{
			numbersSorted = insertion(numbers);
		}

		int endTime = clock();

		for (int j = 1; j < length; j++)
		{
			if (numbersSorted[j] < numbersSorted[j - 1])
				return vector<int>(1,-1);
		}

		times[i] = endTime - startTime;
	}

	return times;
}

double average(vector<int> v)
{
	int sum = 0;
	for each (int element in v)
	{
		sum += element;
	}
	return sum / v.size();
}

int main()
{
	int len, iter;
	cout << "How big will the array be? ";
	cin >> len;
	cout << "How many iterations do you want? ";
	cin >> iter;

	vector<int> times = doSort(len, iter);

	if (times[0] == -1)
		cout << "The list was not sorted";
	else
	{
		cout << endl << endl << "Longest clock time was " << *max_element(begin(times), end(times));
		cout << endl << endl << "Smallest clock time was " << *min_element(begin(times), end(times));
		cout << endl << endl << "Average clock time was " <<  average(times);
	}

	cin >> iter;

    return 0;
}
