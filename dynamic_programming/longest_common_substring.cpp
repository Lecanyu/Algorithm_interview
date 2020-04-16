/*
 * https://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
* Given two string, find the longest common substring. The substring is not necessarily contiguous.
* For example,
* str1 = abcdefgh
* str2 = adffvh
* The longest substring is adfh
*
* Insight:
* Suppose we already know the longest common substring f(n, m) between str1 (say its length = n) and str2 (say its length = m),
* Then
* if str1[n+1] == str2[m+1]
*	f(n+1, m+1) = f(n, m) + 1 
* else
*	f(n+1, m+1) = max{f(n+1, m), f(n, m+1)}
*/



#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int longest_common_substring(string& str1, string& str2)
{
	vector<vector<int>> record_array(str1.size(), vector<int>(str2.size(), 0));

	// 1. initialize record_array
	int current = 0;
	for (int i = 0; i<str1.size(); ++i)
	{
		if (str1.at(i) == str2.at(0))
			current = 1;
		record_array[i][0] = current;
	}

	current = 0;
	for(int i=0;i<str2.size();++i)
	{
		if (str2.at(i) == str1.at(0))
			current = 1;
		record_array[0][i] = current;
	}

	// 2. iterative dp
	for(int i=1;i<str1.size();++i)
	{
		for(int j=1;j<str2.size();++j)
		{
			if (str1.at(i) == str2.at(j))
				record_array[i][j] = record_array[i - 1][j - 1] + 1;
			else
				record_array[i][j] = max<int>(record_array[i][j - 1], record_array[i - 1][j]);
		}
	}

	return record_array[str1.size() - 1][str2.size() - 1];
}

int main()
{
	string str1 = "abcdefgh";
	string str2 = "adffvh";

	int result = longest_common_substring(str1, str2);
	cout << "length of longest common substring " << result << "\n";

	system("pause");
	return 0;
}