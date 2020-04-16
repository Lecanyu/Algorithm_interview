/*
 * Minimum edit distance, so-called Levenshtein distance 
 * https://www.geeksforgeeks.org/edit-distance-dp-5/
 *
 * if arr1[n] = arr2[m]
 *	 f(n, m) = f(n-1, m-1)
 * else
 *   f(n, m) = min{f(n-1, m-1), f(n, m-1), f(n-1, m)} + 1
 *
 * Obviously, the time complexity is O(m*n).
 * Note that the naive space complexity is O(m*n), but we can actually use an array with size 2*m to record previous result. So space complexity is O(m) or O(n)
 */



#include <iostream>
#include <algorithm>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n)
{
	// If first string is empty, the only option is to 
	// insert all characters of second string into first 
	if (m == 0)
		return n;

	// If second string is empty, the only option is to 
	// remove all characters of first string 
	if (n == 0)
		return m;

	if (str1[m - 1] == str2[n - 1])
		return editDist(str1, str2, m - 1, n - 1);

	return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
		editDist(str1, str2, m - 1, n), // Remove 
		editDist(str1, str2, m - 1, n - 1) // Replace 
	);
}

// Driver program 
int main()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << editDist(str1, str2, str1.length(), str2.length()) << endl;;

	system("pause");
	return 0;
}