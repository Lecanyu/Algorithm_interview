/*
 * https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
 * https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
 * 
 * Segment tree is an advanced data structure used for storing information about intervals.
 * This data structure is very efficient to process query and update on interval related problems.
 * 
 * Some typical applications are
 * 1. range sum/min/max query
 * 2. other related problems
 *
 * To implement the segment tree, there are usually two choices: array version vs structure version.
 * Conceptually, they are the same, but array version is more cache friendly while structure version is more memory efficient.
 * The explanation about two version: https://www.quora.com/Whats-the-difference-between-an-array-version-of-segment-tree-and-a-structure-version-of-a-segment-tree
 *
 *
 * The implementation below is a solution for https://leetcode.com/problems/range-sum-query-mutable/
 *
 * I implement segment tree in case the total number is big which will be memory insufficient 
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>

struct SegTreeNode
{
	int sum_;		// attribution
	int low_, high_;	// range

	SegTreeNode* lchild_;
	SegTreeNode* rchild_;

	SegTreeNode():sum_(0), low_(-1),high_(-1), lchild_(NULL), rchild_(NULL){}
	SegTreeNode(int sum, int low, int high) :sum_(sum), low_(low), high_(high), lchild_(NULL), rchild_(NULL) {}
};


class SegTree
{
public:
	SegTreeNode * root_;

	SegTree():root_(NULL){}
	
	SegTree(std::vector<int>& nums)			
	{
		root_ = create(nums, 0, nums.size() - 1);
	}

	void update(int i, int val)
	{
		root_ = update_search(root_, i, val);
	}	

	int sumRange(int i, int j)
	{
		return sum_search(root_, i, j);
	}

private:
	// create segment tree with index in [low, high]
	SegTreeNode * create(std::vector<int>& nums, int low, int high)		
	{
		if (low > high)
			return NULL;

		if (low == high)
		{
			SegTreeNode* node = new SegTreeNode(nums[low], low, high);
			return node;
		}

		SegTreeNode* node = new SegTreeNode();

		int mid = (low + high) / 2;
		SegTreeNode* left_child = create(nums, low, mid);
		SegTreeNode* right_child = create(nums, mid + 1, high);

		node->sum_ = left_child->sum_ + right_child->sum_;
		node->lchild_ = left_child;
		node->rchild_ = right_child;
		node->low_ = low;
		node->high_ = high;

		return node;
	}
	
	// search the node with index i for update
	SegTreeNode * update_search(SegTreeNode* node, int i, int val)
	{
		if (node->low_ == i && node->high_ == i)		// find the node
		{
			node->sum_ = val;
			return node;
		}

		if (node->low_ > i || node->high_ < i)		// the target out of range
			return node;

		// the target in this range
		node->lchild_ = update_search(node->lchild_, i, val);
		node->rchild_ = update_search(node->rchild_, i, val);
		node->sum_ = node->lchild_->sum_ + node->rchild_->sum_;

		return node;
	}

	// search the sum of range [i, j]
	int sum_search(SegTreeNode* node, int low, int high)
	{
		if (low > high)
			return 0;	// no result
		if (low< node->low_ || high>node->high_)
			return 0;

		if (low == node->low_ && high == node->high_)
			return node->sum_;
		
		// left child range
		int left_child_low = node->lchild_->low_;
		int left_child_high = node->lchild_->high_;
		int right_child_low = node->rchild_->low_;
		int right_child_high = node->rchild_->high_;

		if(low > left_child_high)
			return sum_search(node->rchild_, low, high);
		if (high < right_child_low)
			return sum_search(node->lchild_, low, high);
		
		int left_child_sum = sum_search(node->lchild_, low, left_child_high);
		int right_child_sum = sum_search(node->rchild_, right_child_low, high);
		return left_child_sum + right_child_sum;
	}
};


int main()
{
	std::vector<int> arr = { 1,3,5 };
	int sum;
	
	SegTree seg_tree(arr);
	sum = seg_tree.sumRange(0, 2);
	std::cout << sum << "\n";
	
	seg_tree.update(1, 2);
	sum = seg_tree.sumRange(0, 2);
	std::cout << sum << "\n";
	
	system("pause");
	return 0;
}


