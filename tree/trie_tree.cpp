/*
* https://www.youtube.com/watch?v=-urNrIAQnNo gives an explanation
*
* The feature of trie tree:
* 1. the character represents edge
* 2. node has an attribute which indicates whether the path forms a string
*
* The implementation below is a solution for https://leetcode.com/problems/implement-trie-prefix-tree/
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


struct TrieTreeNode
{
	std::unordered_map<char, TrieTreeNode*> childrens_;		// edges
	bool isWord_;		// vertex's attribute

	TrieTreeNode():isWord_(false){}
};

class Trie {
public:
	TrieTreeNode* root_;
	
	/** Initialize your data structure here. */
	Trie()
	{
		root_ = new TrieTreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(std::string word)
	{
		TrieTreeNode* temp = root_;
		
		for(int i=0;i<word.size();++i)
		{
			char c = word.at(i);
			if(temp->childrens_.find(c) == temp->childrens_.end())
			{
				temp->childrens_[c] = new TrieTreeNode();	
				temp = temp->childrens_[c];
			}
			else
			{
				temp = temp->childrens_[c];
			}
		}
		temp->isWord_ = true;
	}

	/** Returns if the word is in the trie. */
	bool search(std::string word)
	{
		TrieTreeNode* temp = root_;
		for(int i=0;i<word.size();++i)
		{
			char c = word.at(i);
			if (temp->childrens_.find(c) == temp->childrens_.end())
				return false;
			else
				temp = temp->childrens_[c];
		}

		if(temp->isWord_)
			return true;
		else
			return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string prefix)
	{
		TrieTreeNode* temp = root_;
		for (int i = 0; i<prefix.size(); ++i)
		{
			char c = prefix.at(i);
			if (temp->childrens_.find(c) == temp->childrens_.end())
				return false;
			else
				temp = temp->childrens_[c];
		}
		
		return true;
	}
};


int main()
{
	Trie* trie = new Trie();
	trie->insert("apple");
	std::cout << trie->search("apple") << "\n";		// returns true
	std::cout << trie->search("app") << "\n";		// returns false
	std::cout << trie->startsWith("app") << "\n";	// returns true
	
	trie->insert("app");
	std::cout << trie->search("app") << "\n";    // returns true

	system("pause");
	return 0;
}