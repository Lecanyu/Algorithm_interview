/*
 * https://www.geeksforgeeks.org/pattern-searching-using-suffix-tree/
 * This post gives a nice conceptual introduction about suffix tree.
 *
 * A Suffix Tree for a given text is a compressed trie for all suffixes of the given text.
 * The key feature of suffix tree:
 * 1. it is a compressed trie tree.
 * 2. it represents all possible suffixes of the given text.
 * 3. searching in suffix tree is easy and similar with standard trie tree.
 *
 * There are a lot of applications and algorithms by using suffix tree to obtain optimal time complexity.
 * 1) Pattern Searching
 * 2) Finding the longest repeated substring
 * 3) Finding the longest common substring
 * 4) Finding the longest palindrome in a string
 *
 * Using suffix tree is easy but efficiently build a suffix tree is a little bit complicated.
 * The abstract steps are:
 * 1) Generate all suffixes of given text.
 * 2) Consider all suffixes as individual words and build a compressed trie.
 *
 * For the specific algorithm to build suffix tree, please see https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/ 
 * 
 * 
 */



