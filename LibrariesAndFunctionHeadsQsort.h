#pragma once
//Necessary Included Libaries
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;

//Templated 3-way quicksort partition algorithm, sorting less than and 
// greater than values to recurse on and leaving values equal to pivot in middle.
template<typename type>
pair<int, int> threeWayPartition(vector<type>& array, int start, int end)
{
	int leftPart = start;
	int index = start;
	int rightPart = end;

	int mid = start + (end - start) / 2;

	type pivot = array[mid];

	//For all unvisited values
	for (index; index <= rightPart; index++)
	{
		//If less than pivot, swap to beginning of equals section
		if (array[index] < pivot)
		{
			swap(array[index], array[leftPart]);
			leftPart++;
		}
		//If greater than, swap to end of equals section
		else if (array[index] > pivot)
		{
			swap(array[index], array[rightPart]);
			rightPart--;
			index--;
		}
	}

	return { leftPart, rightPart };
}

//Templated quicksort function recurring until data is sorted.
template<typename type>
void quickSort(vector<type>& array, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	pair<int, int> splitIndices = threeWayPartition(array, start, end);

	quickSort(array, start, splitIndices.first - 1);
	quickSort(array, splitIndices.second + 1, end);
}