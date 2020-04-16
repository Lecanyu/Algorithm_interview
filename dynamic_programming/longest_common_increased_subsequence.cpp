/*
 * https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/?ref=rp
 * Given two arrays, find length of the longest common increasing subsequence [LCIS]
 *
 * For example
 * arr1 = [3, 4, 10, 9, 2]
 * arr2 = [5, 3, 8, 9, 10, 2, 1]
 *
 * The longest common increased subsequence should be 3, 10 or 3, 9
 * 
 * The link above gives a solution but it is very counter-intuitive for me. 
 * 
 * Insight:
 * It's hard to figure out the best solution.
 * But if you are inspired by LCS and LIS problem, you may figure out a solution with O(n^3).
 * that is
 * if arr1[n] = arr2[m]
 *	f(n, m) = max{f(n-1, m-i)} with i = 1,2,3,...,m-1 and arr1[n] > arr2[m-i] 
 * else
 *  f(n, m) = max{f(n-1, m), f(n, m-1)}
 *
 * Why this algorithm is O(n^3)?
 * When arr1[n] = arr2[m], we have to traverse from i= 1 to m-1 and find the max f(n-1, m-i)
 *
 *
 * Improved solution O(n^2)
 *   This solution is simple in code but it is not natural to figure out.
 *	 I implement this solution below.
 *	 TODO: provide a natural insight/explanation for this solution.
 *
 *   
 */


#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

int longest_common_increased_subsequence(std::vector<int>& arr1, std::vector<int>& arr2)
{
	std::vector<int> length_array(arr2.size(), 0);

	for(int i=0;i<arr1.size();++i)
	{
		int current = 0;
		for(int j=0;j<arr2.size();++j)
		{
			if(arr1[i] == arr2[j])
			{
				length_array[j] = current + 1;
			}
			else
			{
				if (arr1[i] > arr2[j] && length_array[j] > current)
					current = length_array[j];
			}
		}
	}

	return *std::max_element(length_array.begin(), length_array.end());
}

int main()
{
	std::vector<int> arr1 = { 3,4,10,9,2, 15, 8 ,20 };
	std::vector<int> arr2 = { 5,3,8,9,10,2,1, 15,1,20,1 };

	int result = longest_common_increased_subsequence(arr1, arr2);
	std::cout << "the length of LCIS " << result << "\n";
	
	system("pause");
	return 0;
}


