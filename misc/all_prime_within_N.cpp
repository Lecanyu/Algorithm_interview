/*
 * https://www.geeksforgeeks.org/program-to-print-first-n-prime-numbers/
 *
 * 1. traverse
 * 2. judge if a number is a prime.
 *
 * 
 */

#include <iostream>
#include <vector>

bool is_a_prime(int num)
{
	if (num < 2)
		return false;
	
	for(int i=2;i<=sqrt(num);++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}


std::vector<int> all_prime_within_N(int n)
{
	std::vector<int> result;
	for(int i=2;i<=n;++i)
	{
		if (is_a_prime(i))
			result.push_back(i);
	}

	return result;
}


int main()
{
	int n = 100;
	auto result = all_prime_within_N(n);

	for (auto i : result)
		std::cout << i << " ";
	std::cout << "\n";

	system("pause");
	return 0;
}