/*
 * 返回数组的任一峰值
	1、比相邻元素大即为峰值
	2、相邻元素不相等
	3、首尾元素，只要大于一个相邻元素即为峰值
	4、时间复杂度O(logN)
 */

#include <iostream>
#include <vector>

int find_the_peak(std::vector<int>& arr, int start, int end)
{
	int mid = (start + end) / 2;

	if(mid-1<0)
	{
		return arr[mid];
	}
	if(mid+1>=arr.size())
	{
		return arr[mid];
	}

	if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
		return arr[mid];

	if(arr[mid]>arr[mid-1])		//increasing right side
	{
		return find_the_peak(arr, mid, end);
	}
	else	//increasing left side
	{
		return find_the_peak(arr, start, mid);
	}
	
}

int main()
{
	//std::vector<int> arr = { 1,2,3,4,5,6,7 };
	//std::vector<int> arr = { 5,4,3,2,1 };
	std::vector<int> arr = { 5, 8,9,-1,10,2,1 };
	int result = find_the_peak(arr, 0, arr.size());

	std::cout << "the peak number " << result << std::endl;

	system("pause");
	return 0;
}




