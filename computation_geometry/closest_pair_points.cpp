/*
 * https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
 * This problem has strong application background.
 *
 * It can be solved by divide and conquer
 * Best time complexity is O(nlogn)
 * 
 * This problem is not easy to figure out the best solution.
 * But the naive solution is easy:
 * Just calculate the distance between all pairs and find the minimum one. Time complexity is O(n^2)
 *
 * Divide and conquer solution (you can also check the link above for explanation):
 * 1. iteratively divide all points
 * 2. conquer each division (i.e. calculate the distance between point pair)
 * 3. combine two division (i.e. select the minimum distance and calculate the distance cross the divide boundary)
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

struct Point2D
{
	double x, y;
	int index;		// index in original array
	Point2D():x(0),y(0), index(-1){}
	Point2D(double a, double b,int c):x(a),y(b), index(c){}
};

struct cmp_Point2D_x
{
	bool operator()(const Point2D& p1, const Point2D& p2)
	{
		if (p1.x < p2.x)
			return true;
		else if (p1.x == p2.x && p1.y < p2.y)
			return true;
		else
			return false;
	}
};

struct cmp_Point2D_y
{
	bool operator()(const Point2D& p1, const Point2D& p2)
	{
		if (p1.y < p2.y)
			return true;
		else if (p1.y == p2.y && p1.x < p2.x)
			return true;
		else
			return false;
	}
};

struct Distance
{
	int i, j;
	double distance;
	Distance():i(-1),j(-1),distance(0){}
	Distance(int a, int b, double d):i(a),j(b),distance(d){}
};


Distance find_closest_pair(const std::vector<Point2D>& points, int start, int end)
{
	Distance result;

	if(end - start<2)		// only one point in a division, no distance
	{
		Distance d(start, start, 99999);
		return d;
	}
	else					// multiple points in a division.
	{
		// 1. iteratively divide
		int mid = (start + end) / 2;
		Distance d1 = find_closest_pair(points, start, mid);
		Distance d2 = find_closest_pair(points, mid, end);

		// 2. conquer
		Distance min_distance;
		if (d1.distance < d2.distance)
			min_distance = d1;
		else
			min_distance = d2;

		// 3. combine.
		// 1) get the points in the given strip [x_min, x_mid], [x_mid, x_max]
		double x_mid = points[mid].x;
		double x_min = x_mid - min_distance.distance;
		double x_max = x_mid + min_distance.distance;

		std::vector<int> left_part, right_part;
		std::vector<Point2D> within_strip;
		for(int i=start;i<mid;i++)
		{
			assert(points[i].x <= x_mid);
			if (points[i].x >= x_min)
			{
				left_part.push_back(i);
				within_strip.push_back(points[i]);
			}
		}
		for(int i=mid;i<end;++i)
		{
			assert(points[i].x >= x_mid);
			if (points[i].x <= x_max)
			{
				right_part.push_back(i);
				within_strip.push_back(points[i]);
			}
		}

		// 2) traverse left part and right part (slow version) => this algorithm is O(n^2)
		/*for(int i=0; i<left_part.size();++i)
		{
			for(int j=0;j<right_part.size();++j)
			{
				Point2D left_p = points[left_part[i]];
				Point2D right_p = points[right_part[j]];
				double d_x = abs(right_p.x - left_p.x);
				double d_y = abs(right_p.y - left_p.y);
				if(d_x < min_distance.distance && d_y < min_distance.distance)
				{
					double dis = sqrt(d_x * d_x + d_y * d_y);
					if(dis<min_distance.distance)
					{
						min_distance.distance = dis;
						min_distance.i = points[left_part[i]].index;
						min_distance.j = points[right_part[j]].index;
					}
				}
			}
		}*/

		// 2) sort y-coordinator (quicker version)  => this algorithm is O(n(logn)^2)
		std::sort(within_strip.begin(), within_strip.end(), cmp_Point2D_y());
		for(int i=0;i<within_strip.size();++i)
		{
			for(int j=i+1; j<within_strip.size();++j)
			{
				if(j-i>7)		// we only need to check at most 7 points.  
					break;
				Point2D p1 = within_strip[i];
				Point2D p2 = within_strip[j];
				double d_x = abs(p1.x - p2.x);
				double d_y = abs(p1.y - p2.y);
				if (d_x < min_distance.distance && d_y < min_distance.distance)
				{
					double dis = sqrt(d_x * d_x + d_y * d_y);
					if (dis<min_distance.distance)
					{
						min_distance.distance = dis;
						min_distance.i = within_strip[i].index;
						min_distance.j = within_strip[j].index;
					}
				}
			}
		}
		
		return min_distance;
	}
}

int main()
{
	// test data
	std::vector<Point2D> points;
	points.push_back(Point2D(0, 0, 0));
	points.push_back(Point2D(0.5, 0.5, 1));
	points.push_back(Point2D(2, 2, 2));
	points.push_back(Point2D(0, 2, 3));
	points.push_back(Point2D(2, 0, 4));
	points.push_back(Point2D(-1, 0, 5));
	points.push_back(Point2D(-1, -1, 6));

	// sort all points
	std::sort(points.begin(), points.end(), cmp_Point2D_x());
	Distance result = find_closest_pair(points, 0, points.size());

	std::cout << "The minimum pair is point " << result.i << " <-> point " << result.j << ", distance: " << result.distance << std::endl;
	
	system("pause");
	return 0;
}
