/*
 * https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
 * Check the link above for the problem description. 
 *
 * This is a typical dynamic programming problem.
 *
 * Insight:
 * Suppose we already know the best way to cut n-inch rod (the best value is f(n)) 
 * When the rod increase 1 inch and give corresponding value, how can we get the best f(n+1)?
 * Since f(n+1) may come from
 * length(0) + length(n+1)
 * length(1) + length(n)
 * ...
 * length(n) + length(1)
 * total n+1 possible solutions.
 *
 * So the maximum value solution is the best solution
 * that is
 * f(n) = max{f(0)+p(n+1), f(1)+p(n), ..., f(n)+p(1)} where p(k) is the value of length k (this is given by problem description).
 *
 * The time complexity of this algorithm is O(n^2)
 */


#include <iostream>
#include <vector>


int find_max_valuable_cutting(std::vector<int>& value)
{
	std::vector<int> best_value(value.size() + 1, 0);
	best_value[1] = value[0];
	for(int i=2;i<best_value.size();++i)
	{
		int max_v = -99999;
		for(int j=0;j<=i;++j)
		{
			int value_index = i - j - 1;
			int v;
			if (value_index < 0)
				v = 0;
			else
				v = value[value_index];

			int current_value = best_value[j] + v;
			if (current_value > max_v)
				max_v = current_value;
		}
		best_value[i] = max_v;
	}

	return best_value[best_value.size() - 1];
}


int main()
{
	std::vector<int> value = { 3  , 5  , 8  , 9  ,10  ,17  ,17  ,20 };
	int result = find_max_valuable_cutting(value);

	std::cout << "maximum value " << result << "\n";
	
	system("pause");
	return 0;
}