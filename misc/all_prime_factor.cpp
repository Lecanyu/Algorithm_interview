/*
 * https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
 *
 * 1) While n is divisible by 2, print 2 and divide n by 2.
 * 2) After step 1, n must be odd.
 *	  Now start a loop from i = 3 to square root of n.
 *	  While i divides n, print i and divide n by i.
 *	  After i fails to divide n, increment i by 2 and continue.
 * 3) If n is a prime number and is greater than 2, then n will not become 1 by above two steps.
 *    So print n if it is greater than 2.
 * 
 */

#include <iostream>
#include <vector>


std::vector<int> all_prime_factor(int n)
{
	std::vector<int> result;

	while (n % 2 == 0)
	{
		result.push_back(2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			result.push_back(i);
			n = n / i;
		}
	}

	if (n > 2)
		result.push_back(n);

	return result;
}


int main()
{
	int n = 111;

	auto result = all_prime_factor(n);
	for (auto i : result)
		std::cout << i << " ";
	std::cout << "\n";
	
	system("pause");
	return 0;
}
