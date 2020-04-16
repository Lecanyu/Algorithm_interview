/*
 * https://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
 * The Longest Increasing Subsequence (LIS) problem is to find the longest subsequence of a given sequence,
 * such that all elements of the subsequence are sorted in increasing order.
 * For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
 *
 * Insight:
 *
 * An intuitive solution:
 * Scan the array and calculate the length of subsequence with the end of current element.
 * The calculation follows:
 * When we evaluate the n-th element, we try to find the longest subsequence from index 1 to n-1 and its element is smaller than the n-th element.
 * Suppose a[..] is original sequence and L(n) is the array for saving calculation results.
 * We will have
 * L(n) = max{L(m)} + 1 where n>m and a[n]>a[m] 
 * if no such m, L(n) = 1
 * However, find such a[m] need to scan from index 1 to n-1. As a result, this algorithm is O(n^2)
 *
 *
 * Improved O(nlogn) version:
 * 
 * 
 */



#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

// Search proper position to update min_ele_array
int binary_search_position(const vector<int>& min_ele_array, int start, int end, int ele)
{
	if(start >= end)
	{
		if (start == 0)
			if (min_ele_array[start] >= ele)
				return 0;
			else
			{
				if (min_ele_array.size() == 1)
					return -1;
				else
					assert(false);	// should not enter this branch
			}
		else
			return -1;
	}

	int mid = (start + end) / 2;
	if(min_ele_array[mid] < ele )
	{
		if (mid + 1 >= min_ele_array.size())
			return -1;
		else if (min_ele_array[mid + 1] >= ele)
			return mid + 1;
		else
			return binary_search_position(min_ele_array, mid + 1, end, ele);
	}
	else
	{
		if(mid-1<0)
			return 0;
		else if (min_ele_array[mid - 1] < ele)
			return mid;
		else
			return binary_search_position(min_ele_array, start, mid - 1, ele);
	}
}

int longest_increased_subsequence(vector<int>& arr)
{
	vector<int> min_ele_array;		// this array saves the minimum last element
	for(int i=0; i<arr.size(); ++i)
	{
		if (i == 0)
			min_ele_array.push_back(arr[i]);
		else
		{
			int pos = binary_search_position(min_ele_array, 0, min_ele_array.size() - 1, arr[i]);
			if (pos == -1)
				min_ele_array.push_back(arr[i]);
			else
				min_ele_array[pos] = arr[i];
		}
	}

	return min_ele_array.size();
}


int main()
{
	//vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
	vector<int> arr = { 3, 10, 2, 1, 20 };
	int len = longest_increased_subsequence(arr);
	cout << "the length of longest increased subsequence: " << len << "\n";

	system("pause");
	return 0;
}