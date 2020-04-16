/*
 * https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
 * Rabin Karp algorithm is a simple hash-based method for pattern matching.
 * The idea is simple and interesting.
 * It is simpler and more intuitive than KMP algorithm
 *
 * Problem description:
 * Given a text string (txt[1~n]), we want to find all positions of matched pattern string (pattern[1~m])
 * For example:
 * txt = "abcdefggghuiiuoppobbv"
 * pattern = "efg"
 *
 * The result should be index=4
 *
 * Naive algorithm:
 * try to match every character one by one, time complexity is O(n*m)
 *
 *
 *
 * Rabin Karp algorithm:
 * Calculate the hash value of given text string and pattern string. If they are the same, there is a match.
 *
 * For example,
 * txt = "abcdefggghuiiuoppobbv"
 * the hash value of substring with length=3 are " hash('abc')=23, hash('bcd')=29, hash('cde')=33 ... hash('bby')=54 ", if the hash value = hash(pattern), we find a match.
 *
 * So the key is how to calculate the hash value efficiently?
 *
 * I use the example above to show this algorithm:
 *
 * 1. initialization
 * hash('abc') = (encoding('a')*26^2 + encoding('b')*26 + encoding('c')) % a_prime_num
 * hash('efg') = (encoding('e')*26^2 + encoding('f')*26 + encoding('g')) % a_prime_num
 * 
 * The encoding function is a mapping (we can use ascii value directly).
 * Since a-z total 26 alphabets, we see the substring as a 26 hex number. We can adjust this value according to actual requirement.
 * a_prime_num is for control the total size of hash value. If pattern is short, we can set a_prime_num=inf to avoid any hash collision.
 *
 *
 * 2. traverse text string
 * we can quickly calculate the hash of following substring like hash('bcd'), hash('cde') ...
 * hash('bcd') = (  ( hash('abc') - encoding('a')*26^2 )*26 + encoding('d')  ) % a_prime_num
 *
 * Note that  hash('abc') - encoding('a')*26^2 may be smaller than 0, we need to process this situation by
 * if hash('bcd')<0
 *	   hash('bcd') + a_prime_num
 *
 * to get the correct hash value.
 * 
 */


#include <string>
#include <iostream>
#include <vector>

std::vector<int> rabin_karp(std::string& text, std::string& pattern)
{
	std::vector<int> result;
	
	int prime = 10001;
	int alphabet_size = 26;

	std::vector<int> hash_value(text.size(), -1);

	int pattern_hash_value = 0;
	int text_hash_value = 0;
	
	// 1. initialization
	for(int i=0; i<pattern.size(); ++i)
	{
		auto c = pattern[i];
		int encoding = c - 'a';
		pattern_hash_value += encoding * pow(alphabet_size, pattern.size() - i - 1);

		c = text[i];
		encoding = c - 'a';
		text_hash_value += encoding * pow(alphabet_size, pattern.size() - i - 1);
	}
	pattern_hash_value = pattern_hash_value % prime;
	hash_value[pattern.size() - 1] = text_hash_value % prime;
	
	if(pattern_hash_value == hash_value[pattern.size() - 1])		// same hash value
	{
		std::string substring = text.substr(0, pattern.size());
		if(substring == pattern)				// verify if it is a collision or a real match. 
			result.push_back(0);
	}
	
	// 2. traverse text string
	for(int i=pattern.size(); i<text.size(); ++i)
	{
		int prev_hash = hash_value[i - 1];
		int prev_encoding = (text[i - pattern.size()] - 'a') * pow(alphabet_size, pattern.size() - 1);

		int current_encoding = text[i] - 'a';
		int current_hash = (prev_hash - prev_encoding)*alphabet_size + current_encoding;
		hash_value[i] = current_hash % prime;

		if (hash_value[i] < 0)
			hash_value[i] += prime;
		
		if(hash_value[i] == pattern_hash_value)						// same hash value
		{
			std::string substring = text.substr(i + 1 - pattern.size(), pattern.size());
			if (substring == pattern)			// verify if it is a collision or a real match. 
				result.push_back(i + 1 - pattern.size());
		}
	}

	return result;
}

int main()
{
	std::string text = "efgabcdefgguefiobvefg";
	std::string pattern = "efg";

	auto result = rabin_karp(text, pattern);

	for (auto pos : result)
		std::cout << "Appear position " << pos << std::endl;
	
	system("pause");
	return 0;
}