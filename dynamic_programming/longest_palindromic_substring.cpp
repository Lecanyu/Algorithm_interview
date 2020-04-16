/*
 * https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 *
 * Find the longest palindromic substring
 *
 * 
 * 
 * Insight:
 * Given a string, it is a palindromic string when it satisfies below condition:
 * if length = 1, it is a palindromic string
 * if length = 2, the first and last character must be the same
 * if length > 2, the first and last character must be the same and str[2 ~ n-1] must be a palindromic
 *
 * So given any string f(n, m),
 *  if str[n] = str[m] and f(n+1, m-1) is a palindromic string
 *		f(n, m) is a palindromic
 *
 * This dynamic programming have O(n^2) time complexity and O(n^2) space complexity
 *
 * The space complexity is unacceptable since the length of a string may be hundreds or thousands.
 *
 *
 *
 * We can optimize the algorithm further.
 * From the insight above, we know any palindromic string can be grown from shorter palindromic substring (the shortest string is the palindromic center).
 * So we design an algorithm which traverse all possible without extra space.
 * we implement this algorithm below (time complexity is O(n^2), space complexity is O(1))
 * 
 *
 * There are some better solution which is based on suffix tree. This problem can be solved in linear time
 * https://www.geeksforgeeks.org/suffix-tree-application-6-longest-palindromic-substring/?ref=rp
 * 
 * 
 */



#include <string>
#include <iostream>
#include <vector>

std::string find_longest_palindromic_substring(std::string& str)
{
	std::string result=str.substr(0, 1);
	int start=0, end=0;

	int low_index, high_index;

	for (int i = 0; i < str.size(); ++i)
	{
		// odd length, i is the center
		low_index = i - 1;
		high_index = i + 1;
		while (low_index >= 0 && high_index < str.size() && str[low_index] == str[high_index])
		{
			int len = high_index - low_index + 1;
			if (len > result.size())
			{
				start = low_index;
				end = high_index;
				result = str.substr(start, len);
			}
			low_index--;
			high_index++;
		}
		
		// even length, i and i+1 are the center
		low_index = i;
		high_index = i + 1;
		while (low_index >= 0 && high_index < str.size() && str[low_index] == str[high_index])
		{
			int len = high_index - low_index + 1;
			if (len > result.size())
			{
				start = low_index;
				end = high_index;
				result = str.substr(start, len);
			}
			low_index--;
			high_index++;
		}
	}

	return result;
}

int main()
{
	std::string str = "forgeeksskeegfor";
	std::cout << find_longest_palindromic_substring(str) << std::endl;
	
	system("pause");
	return 0;
}


