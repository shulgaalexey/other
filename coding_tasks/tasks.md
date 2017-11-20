Some common algorithm problems asked in Technical Interviews :
-	Save all leaf nodes of a Binary tree in a Doubly Linked List by using Right node as Next node and Left Node as Previous Node. (tree_to_list.cpp)
-	Given an array,find the maximum j – i such that arr[j] > arr[i] (calc_max_dist.cpp)
-	Remove Alternate Duplicate characters from a char array you have to do it in Place.Like keeping only the odd occurences of each character. (remove_dubl.cpp)
1.	Example: Input: “you got beautiful eyes”
2.	Output: ”you gtbeaiful es”
3.	Allowed Time Complexity was O(n) and Space Complexity was O(1)
-	In a file there are 1 million words . Find 10 most frequent words in that file.
-	Find all nodes at k-distance from a given node in a binary tree
-	Clone a linked list with next and random pointer
-	Serialise and Deserialise a linked list with next and random pointer.
-	Construct a binary tree from given inorder and preorder traversals.
-	Return a tree such that each internal node stores sum of all its child nodes. Each leaf node stores zero.
-	How will you implement linked list with 1 million nodes? How will you access 999999 th node? Give some optimal design strategy and implementation.
-	Reversal of Linked List in groups of K.
-	Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
-	Check whether given binary tree is balanced or not. Definition was no two leaves should have height difference of greater than one.
-	Remove duplicates from string in place in O(n).
-	Connect nodes on same level in a binary tree.
-	Find sum of data of all leaves of a binary tree on same level and then multiply sums obtained of all levels.
-	Given a matrix of characters and a word.
you have to count the number of occurrences of that word in that matrix. you can move to any of the eight valid directions from current position.
-	You are given an string as input which represents a path. You have to normalize that path inplace(NO EXTRA SPACE).
1.	e.g.input : "\a\b\c\..\..\file.txt" output: "\a\file.txt"
-	Least common ancestor of two nodes in a binary tree
-	Given two sorted arrays (with repetitive elements) find the kth minimum number from both arrays.
-	Given the root to a binary tree, a value n and k.Find the sum of nodes at distance k from node with value n
-	Find an element in a rotated array
-	The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.
1.	For example, if the given array is {100, 180, 260, 310, 40, 535, 695},
2.	the maximum profit can earned by buying on day 0, selling on
3.	day 3. Again buy on day 4 and sell on day 6.
4.	If the given array of prices is sorted in decreasing order,
5.	 then profit cannot be earned at all.
-	Given two linked lists both represent a number. Create a linked list that contains its sum.
-	Given a binary search tree , print the path which has the sum equal to k and has minimum hops. i.e if there are multiple paths with the sum equal to k then print the path with minimum number of nodes.
-	A MxN matrix containing integers (positive, negative and zero’s). For every position containing 0, mark the corresponding row and column as 0.
-	Rotate MxN matrix by 90 degress.
-	Find the nth number that contains the digit k or is divisible by k. (2 <= k <= 9)
-	Write a program to connect next left node in a binary tree. Also first node of each level should be pointing to last node of next level? (Without using Queue)
-	Convert a binary tree to its sum tree(each node is the sum of its children)
-	Given a directed graph. Construct another graph from given graph such that if path exists from vertices A to vertices B and from B to C, then path from A to C and from C to A also should exists.
-	Implement hashmap on your own. Write good hashing function for string.
-	Given an array, arrange the elements such that the number formed by concatenating the elements is highest.
1.	E.g.: input = [9, 93, 24, 6],
2.	the output should be: [9,93,6,24].
3.	 This is because if you concatenate all the numbers,
4.	993624 is the highest number that can be formed.
-	Given a string, find the longest substring which is palindrome.
-	Given that integers are read from a data stream. Find median of elements read so for in efficient way. For simplicity assume there are no duplicates.
-	Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.
-	Given unsorted array and a number K. Find 2 numbers such that sum is K.
-	Given n-ary tree. zigzag level order traversal.
-	Given string s and string t find whether all permutation of t is present as substring in s.
-	Design a stack which holds an integer value such that getMinimum() function should return the minimum element in the stack. Implement popMin() function which would pop minimum element from the original stack.
-	Given a set of intervals like 5-10, 15-20, 25-40, 30-45, 50-100. Find the ith smallest number in these intervals. Assume there are no duplicate numbers.
1.	e.g:  1st smallest number = 5	  6th smallest number = 10
2.	7th smallest number = 15 and so on.
-	Given an array which is first strictly increasing and then strictly decreasing. Find an element in this array.
-	Given a string example : shoppingwithflipkartiseasy, Now we are given this string and a dictionary containing valid words , now we need to break the sentence into words separated by space. Output : shopping with flipkart is easy
-	Given a series 2,3,4,5,6,8,9,10,……, here in this series all the numbers are present which have factors only and only either 2,3 or 5. Need to write a node to generate nth number for the series . With best approach and complexity
-	Given a tree with edge weights, find any path in the tree with maximum sum of edges.
-	Merge k sorted arrays.
-	Given a maze, a start point and end point find the shortest path to reach the end point from the starting point.
-	Given a sentence and a set of characters. Find the minimum window within which the set of characters can be found in the sentence in any order.
-	You are given a string of 0’s and 1’s you have to find the number of substrings in the string which starts and end with a 1.
1.	eg : input : 0010110010 output : 6
-	You are given a mapping like a -> 1, b-> 2… z-> 26. You have to print all possible combinations of a given number using the above information.
1.	eg : input : 121 output : aba,la,au
-	Given a dictionary of 50,000 words. Given a phrase without spaces, add spaces to make it a proper sentence.
1.	e.g:input:  thequickbrownfoxjumpoverlazydog
2.	output: the quick brown fox jump over lazy dog
-	Given an unsorted array of n integers which can contain integers from 1 to n. Some elements can be repeated multiple times and some other elements can be absent from the array. Count frequency of all elements that are present and print the missing elements.
1.	Examples:Input: arr[] = {2, 3, 3, 2, 5}
2.	Output: Below are frequencies of all elements
3.	1 -> 0        2 -> 2        3 -> 2        4 -> 0        5 -> 1
-	Get the next bigger number using the same digits of a number.
Eg, For 123456, next number would be 123465
-	Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands
1.	Input : mat[][] =
2.	{{1, 1, 0, 0, 0},
3.	 {0, 1, 0, 0, 1},
4.	  {1, 0, 0, 1, 1},
5.	  {0, 0, 0, 0, 0},
6.	 {1, 0, 1, 0, 1}}
7.	Output : 5
-	Given two strings in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string. Find minimum number of characters to be deleted to make both the strings anagram?
If two strings contains same data set in any order then strings are called Anagrams.
1.	Examples:
2.
3.	Input : str1 = "bcadeh" str2 = "hea"
4.	Output: 3
5.	We need to remove b, c and d from str1.
6.
7.	Input : str1 = "cddgk" str2 = "gcd"
8.	Output: 2
9.
10.	Input : str1 = "bca" str2 = "acb"
11.	Output: 0
-	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
1.	Examples:
2.
3.	Input: arr[]   = {2, 0, 2}
4.	Output: 2
5.	Structure is like below
6.	| |
7.	|_|
8.	We can trap 2 units of water in the middle gap.
9.
10.	Input: arr[]   = {3, 0, 0, 2, 0, 4}
11.	Output: 10
12.	Structure is like below
13.	     |
14.	|    |
15.	|  | |
16.	|__|_|
17.	We can trap "3*2 units" of water between 3 an 2,
18.	"1 unit" on top of bar 2 and "3 units" between 2
19.	and 4.  See below diagram also.
20.
21.	Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
22.	Output: 6
23.	       |
24.	   |   || |
25.	_|_||_||||||
26.	Trap "1 unit" between first 1 and 2, "4 units" between
27.	first 2 and 3 and "1 unit" between second last 1 and last 2
•	Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
Insert
Remove
Replace
All of the above operations are of equal cost.
1.	Examples:
2.
3.	Input:   str1 = "geek", str2 = "gesek"
4.	Output:  1
5.	We can convert str1 into str2 by inserting a 's'.
6.
7.	Input:   str1 = "cat", str2 = "cut"
8.	Output:  1
9.	We can convert str1 into str2 by replacing 'a' with 'u'.
10.
11.	Input:   str1 = "sunday", str2 = "saturday"
12.	Output:  3
13.	Last three and first characters are same.  We basically
14.	need to convert "un" to "atur".  This can be done using
15.	below three operations.
16.	Replace 'n' with 'r', insert t, insert a
•	Given a string with repeated characters, task is rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
1.	Examples:
2.
3.	Input: aaabc
4.	Output: abaca
5.
6.	Input: aaabb
7.	Output: ababa
8.
9.	Input: aa
10.	Output: Not Possible
11.
12.	Input: aaaabc
13.	Output: Not Possible
-	This problem is know as Clock angle problem where we need to find angle between hands of an analog clock at a given time.
1.	Examples:Input:  h = 12:00, m = 30.00
2.	Output: 165 degreeInput:  h = 3.00, m = 30.00 Output: 75 degree

