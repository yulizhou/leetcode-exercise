# leetcode-exercise

## 1. Two Sum
First loop creates the mapping from array elements to cooresponding indices. The second loop if the condition met.

## 2. Add Two Numbers
The algorithm is simple enough. The only thing is to understand how to manipulate linked list.

## 3. Longest Substring Without Repeating Characters
We can use set and sliding window technique to do this. Basically we maintain a sliding window. For each window, we add all chars into the set and then extend the right side of the window. 

## 5. Longest Palindromic Substring
Each subtring palindrome search is a DP problem. We start from the assumed palindrome center and spread out to left and right. The status P(i, j) is a boolean that says if a subtring i to j is a palindrome. The transition function is:
```
// single char
If i == j, 
P(i, j) = true

// two same chars
If i + 1 = j && S[i] == S[j],
P(i, j) = true

// more than two chars
If i + 1 < j && S[i] == S[j] && P(i+1, j-1)
P(i, j) = true
```

## 8. String to Integer (atoi)
[Reference](https://discuss.leetcode.com/topic/2666/my-simple-solution/2)
The problem description is quite vague. The reference handles the overflow well with a magic number '7'. 

## 9. Palindrome Number
The tricky part is we cannot use extra space. Otherwise we can convert to string and manipulate it. So the problem now is how to get the first and last digit. We can use / and % to solve.

## 11. Container With Most Water
The key point here is that multiple containers can form one large container. We can maintain two pointers from left and right end of the array. During the movement to the center, we save the largest area obtained. 

## 12. Integer to Roman
We can just list all possible notations. 

## 13. Roman to Integer
As long as we understand how Roman number works, the solution is pretty straightforward. The tricky part to me is how to interpret "VIV" (it's 9, not 11). 

## 14. Longest Common Prefix
We use two pointers, one for each chracter position in strings and one for each string. Then we loop over and check if there is any difference.

## 15. 3Sum
Basically we sort the array first. Then we set the target to be 0-nums[k]. Then we use two pointers to find the two numbers that can sum up to be the target.

## 16. 3Sum Closest
This problem is similar to the last one. The only difference is that we need to maintain a diff for the absolute difference. 

## 17. Letter Combinations of a Phone Number
[Reference](http://www.cnblogs.com/grandyang/p/4452220.html)
We can't use multiple for loops because we'll get performance issue. Since this is a combination problem, we can use the tree structure. We treat each character as a node and do a BFS/DFS search for each combination.

## 18. 4Sum
Seems like there is no better solution other than applying the previous 3sum process and add one more for loop.

## 19. Remove Nth Node From End of List
[Reference](http://www.cnblogs.com/grandyang/p/4606920.html)
An very interesting solution that maintains two pointers with a fixed distance of n to find the nth element from the end of the list. 

## 20. Valid Parentheses
This is a very easy problem with stack. If we encounter a left parenthesis, we push. If right, we check if the stack is empty. If it is empty, we return false. Otherwise we check the top one if it's the pairing one. If it is, then we pop and continue.

## 21. Merge Two Sorted Lists
One way is to create a new list and iterate over two lists and put the smaller value first. But I think the recursion method is more intuitive. Basically, if the current l1 value is smaller than the current l2 value, we just make the `l1->next` be the next call of the funtion but with the next l1 value and the current l2 value. The base cases are l1 or l2 finished iteration. So we simply return l2 and l1 respectively.

## 22. Generate Parentheses
n parenthesis must have n left ones and n right ones. So we can maintain two counters for each. Note that since the last symbol must be the right parenthesis, if we use recursion, then one of the base case is to check if left is larger than right. If it is, the result is invalid. The whole combination can be represented as a tree. We can just search the tree with recursion.

## 24. Swap Nodes in Pairs
The algorithm is simple. But the linking operation could be very confusing without a visual. Basically we need to maintain a LinkNode as a iterating cursor, a copy LinkNode to avoid manipulating the original head cursor, and a temporary node to store the necessary information.

## 26. Remove Duplicates from Sorted Array
We maintain two pointers: one points to the "new" array and the other one is the iterator `j`. When the `j` pointer finds duplicate, it skips it and if it finds a new element, the first pointer will increase and copy the new found element over.

## 27. Remove Element
Quite similar to problem 26. We use two pointers.

## 28. Implement strStr()
Let's not use `find()`. We can maintain two pointers, one iterating each character and one iterating over the needle.

## 31. Next Permutation
The solution is from the Leetcode dicussion. It's very clever. We need to understand two rules. First, for an all decending array, we need to return the reverse. Second, for any number `nums[i]` and the decending array on its right, we need to find the smallest next number from the right and swap with `nums[i]` and reverse the rest of the right array. Then we can iterate from the end of the array starting with `nums.size()-2` and its right array of `nums.size()-1`.

Why the second rule? Assuming we have a descending array on the right of `nums[i]` and `nums[i+1]` is greater than `nums[i]`, because we are looking for the next smallest permutation, we need to find the next smallest number from the right to make the array larger. So we find one from the right and do the swap. Then because we need to make the new right array as small as possible, we just do the reverse.

## 34. Search for a Range
[Reference](https://leetcode.com/problems/search-for-a-range/solution/)
Since the problem requires a O(logn) solution, we must use binary search. Since we need to know the left and right bounding index for the range, so we have to use parallel binary searches, one searching for the left index and one for the right. The core is that when we are searching for the left index and find one, we know that the left bounding index is not on the right. So we just search again on the left with updated right searching index parameter.

## 35. Search Insert Position
Nothing to say. A regular approach has O(n). A better one is to use binary search with O(logn).

## 36. Valid Sudoku
[Reference](https://discuss.leetcode.com/topic/8241/my-short-solution-by-c-o-n2/11)
The algorithm is not hard. We just need to iterate over each row, column, and subcells to see if they follow the rules. The only thing difficult for me is to figure out how to map subcells to a range from 0 to 9: `k = i / 3 * 3 + j / 3`.

## 38. Count and Say
The most difficult part of this problem is to figure out the rule. Basically starting from the 2nd layer, each layer is a string describing the number of consecutive numbers in the previous string.

## 39. Combination Sum
[Reference](http://www.cnblogs.com/grandyang/p/4419259.html)
This is another combination problem. The basic thought for the solution is to use recursion to search a tree, which is a different tree in different settings. Here we need to use `target-current` as a node and search from the current index and to the right (because we can use repeat numbers).

## 40. Combination Sum II
Basically it's the same as problem 40. The only difference is to avoid duplication.

## 43. Multiply Strings
[Reference](http://www.cnblogs.com/TenosDoIt/p/3735309.html)
The referenced solution has a O(n^2) time. There are also other solutions with less time complexity.

## 46. Permutations
This is quite similar to other combination problems. Basically we still use a recursion-based DFS search to go over each branch. The only difference is that we need to maintain a visited vector because we want unique combinations. 

A good source of these kinds of problems in Java: [link](https://discuss.leetcode.com/topic/46162/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partioning)

## 47. Permutations II
This problem is similar to the above. The only difference is to use `set` and an `if` to make sure the uniqueness.

## 48. Rotate Image
There are several ways to do this. The simpliest way I found is to transpose first and then reverse each row. 

## 49. Group Anagrams
The most intuitive way is to maintain a hash table or map that has the list of groups of anagrams. The key here is to find a way to see if a string is an anagram of a group of other anagram strings. One way is to use the sorted string as a key in the map. This requires an extra O(nlogn) time. A better way is to use the counting of 26 letters in a string as the key. This only has O(n) time.

## 50. Pow(x, n)
Never use a for loop to multiple each x. Instead, there are many implementations can make it more efficient. One key thing is to make sure the result can handle n with `int_min`.

## 53. Maximum Subarray
[Reference](https://discuss.leetcode.com/topic/5000/accepted-o-n-solution-in-java)
Best solution so far is from Jon Bentley's code in 1984. The post explains it well. 

## 54. Spiral Matrix
There are two ways. One is to iterate over each element and create a turning decision for he index. The other one is to use layers and put each outer rows and columns into the result array. Each way needs to understand how the index changes.

## 55. Jump Game
The solution section has a very detailed thought process. This is a kind of dynamic programming problem and greedy algo to be specific because we only want a true or false but not the shortest path to the last index. 

## 56. Merge Intervals
The solution is quite straightforward. We need to sort asecending first to make sure we can find the correct next set of intervals. Then we check if the upper bound of one interval is larger than the lower bound of the next interval. If it is, then we can merge them by reset the upper bound of the resulting interval to the max of the upper bounds of the first and second interval.

## 58. Length of Last Word
The trick part is that we may have string with trailing spaces. After getting rid of them, it's easy to just iterate over the last non-space chars.

## 59. Spiral Matrix II
It's similar to problem 54 and this one is simpler. The basic idea is to go over each edge of the loop, from outer ones to inner ones. We just need to find the change pattern of the index. 

## 60. Permutation Sequence
[Excellent explaination](http://www.cnblogs.com/grandyang/p/4358678.html)

## 61. Rotate List
This is easier than rotating an array because we can just modify the next pointer. Basically we make a circle first. Then we find the right position to cut. 

## 62. Unique Paths
This is a typical dp problem. The status `dp[i][j]` is the total number of paths until the current cell. The transition function is `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`, from up and left cells.

## 63. Unique Paths II
This one is very similar to the last one. The only difference is that we need to consider three extra situations: 1. the current cell is a block; 2. the top cell is a block and the left one is not; 3. the left cell is a block and the top one is not.

## 64. Minimum Path Sum
It's a typical dp problem. The only thing is that we need to initialize the min lengths on the edges first. 

## 66. Plus One
There are three cases here. If the last digit is not 9, then we can just plus one and return. If all digits are 9, then all digits need to be set to 0 and we add one digit 1 to the front. If only a few consecutive 9s at the latter part of the digit array, then we set all 9s to 0s and add one to the first non-nine digit counting backwards.

## 67. Add Binary
All summation problems are quite similar. The basic components are: 1. find a way to extract numbers from right to left; 2. calculate the carry using division and floor; 3. calculate the result on a particular position using modular. 

## 69. Sqrt(x)
[Reference](http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html)
Use Newton's method. 

## 70. Climbing Stairs
Similar to No.66, it's a dynamic programming problem. The status `dp[i]` is the number of distinct steps at step i. To reach step i, we have to start from i-1 or i-2. So the transition function is `dp[i] = dp[i - 1] + dp[i - 2]`. 

## 71. Simplify Path
The basic idea is to use a stack or stack-like structure and a string split to process every component of the path sequentially. In C++, we can use `stringstream` for this kind of thing.

## 88. Merge Sorted Array
[Reference](http://www.cnblogs.com/grandyang/p/4059650.html)
Basically we start from the end of the merged array with the length of `m+n`. We put whichever element is larger to the current cursor and work backwards. If the all elements in `nums1` are smaller than `nums2`, then we are done. Otherwise, we put elements from `nums2` to the front of the merged array by replacing the old `nums1` elements.

## 118. Pascal's Triangle
Use the triangle's attribute to iteratively generate elements.

## 119. Pascal's Triangle II
If O(K) space, then we have to update the previous calculated row and calculate the next row. So we need to use the attribute that the kth element on nth row equals the k-1 element on n-1 row plus k element on n-1 row. Another attribute is that the number of elements on nth row (one indexing, not zero) is n. Then we create two loops, one loops over rows and the other one calculates each element on a row. The intermediate process of the code looks like the following:
```
i=0, layer=1
res = [1, 0, 0, 0]


i=1, layer=2
j=3
res[3]=res[3]+res[2], res = [1, 0, 0, 0]
j=2
res[2]=res[2]+res[1], res = [1, 0, 0, 0]
j=1
res[1]=res[1]+res[0], res = [1, 1, 0, 0]


i=2, layer=3
j=3
res[3]=res[3]+res[2], res = [1, 1, 0, 0]
j=2
res[2]=res[2]+res[1], res = [1, 1, 1, 0]
j=1
res[1]=res[1]+res[0], res = [1, 2, 1, 0]

......
```

## 121. Best Time to Buy and Sell Stock
Basically we want to find the smallest price followed by a price that can give a max profit. So a for loop can be seen as following the timeline forward. If we find a small price, then it's the new minimum price. If we find a higher price, then we want to know if it can give a higher max profit. 

## 122. Best Time to Buy and Sell Stock II
The test cases of OJ may have missed some cases. The most intuitive way is to check if the next price higher than the current price and buy & sell if it is. Otherwise we do nothing. This solution passes OJ but there's a situation that we may not have the chance to sell because there's a consecutive downfall.  

## 167. Two Sum II - Input array is sorted
The basic idea is that if a sum is smaller than the target, then the smaller number must be too small and should be a larger number. If a sum is larger than the target, then the larger number must be too large and should be smaller. Based on the logic, we can maintain two pointers from two ends of the array and iterating to the middle. This only works if the array is sorted. 

## 169. Majority Element
Sort the array and then get the middle element.

## 189. Rotate Array
There are many ways to solve this. Here the reserve way is the most intuitive and simple way, in my opinion, to solve it, with O(1) space.

## 198. House Robber
Since our final answer depends on previous selection of houses to rob, we can consider this a dynamic programming problem. The status `dp[i]` is the current maximum money robbed. The transition function is choosing the maximum among two options: the current ith house and the (i-2)th house or just the (i-1)th house. The function is `dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]`. 

## 217. Contains Duplicate
Pretty straightfoward. We use a hash table (`unordered_map` in C++) to store the element visited in order to obtain a O(n) time and space.

## 219. Contains Duplicate II
We're still using `unordered_map` here. There are three cases. For a given element, if it's the first time we see it, simply add to the hash table along with the current index. If we find it in the hash table, then we check to see if the difference between the current pointer position and the previous recorded index is less than k. If it is, then we simply return true. If not, since the next time we will only compare the next index of this element (if more) with the current one, then we need to overwrite the recorded index in the hash table. 

## 268. Missing Number
We "cheat" by using the Gaussian way to calculate the sum. The solution has O(n) time and O(1) space.

## 283. Move Zeroes
When facing array-element-movement problems, a very powerful tool is using two pointers. Here we have a regular pointer iterating over the array and a slow pointer that points to the supposed-to-be index of non-zero elements in the ideal resulting array.

## 303. Range Sum Query - Immutable
At first I didn't fully understand the problem. I was thinking writing one function that finds the sum each time when an array and a range were given. However, if we want to call it as a method of an object and also achieve O(n) time, we have to save the sum somewhere and query the result when necessary. So we can just use cumulative sum.

## 414. Third Maximum Number
Basically we maintain three variables for the largest three elements. If at the end we only have two distinct valid values then we return the largest element. Otherwise we return the third largest one.

## 434. Number of Segments in a String
The problem is not hard, but there are some corner cases to be aware of. Originally I assumed the input string must have words and spaces but missed the case that the string only has spaces or lots of trailing spaces. 

## 443. String Compression
This solution is from Leetcode. The basic idea is to maintain 3 pointers pointing to the beginning of a group, the end of a group, and the number of writing operation (i.e. a character and its count). 

## 448. Find All Numbers Disappeared in an Array
With O(n) time and O(1) space limitation, we can only do one or more sequential for loops without hash tables. From the problem, the value of the element can also represent an index of the array. So we can come up with a way to put every value to the corresponding index position and get the ones that are not aligne as our answer. 

## 459. Repeated Substring Pattern
First we need to understand one rule that each substring cannot be longer than half of the original string. Otherwise the original string cannot be divided into multiple substrings. Based on that, we can iterate over each substring from the first half of the original string with whose length can be divided by the original string, and concatenate and compare with the original string.

## 485. Max Consecutive Ones
Nothing much to say. 

## 520. Detect Capital
Nothing much to say. 

## 532. K-diff Pairs in an Array
Since it's a counting problem, we consider using a hash table. Basically we record the frequency of each element. Then we try to find out if the element plus k is also in the hash table.

## 541. Reverse String II
My original thought was to divide the string into k substrings and reverse when it's 2k, 4k, etc. Then I found out we could just use 2k as the division instead of k. 

## 551. Student Attendance Record I
The logic of this problem is very simple. There are many ways to do it. The solution here uses some string functions.

## 557. Reverse Words in a String III
There is a way to solve this with `reverse()` and `stringstream`. But it's not hard to only use simple string tools. Basically we just maintain two pointers, one for the start of a word and one for the end of a word. Then we find each word and swap to reverse characters.

## 561. Array Partition I
The key point here is that we need to make sure the pair of elements are as close to each other as possible so that we won't lose a large number when putting a very large and very small number together. So we can simply sort the array first and get each consecutive pairs.

## 566. Reshape the Matrix
A straightforward way is to iterate over the original matrix and maintain two pointers as the new row and new column pointing to the corresponding position in the new matrix.

## 581. Shortest Unsorted Continuous Subarray
[Reference](https://discuss.leetcode.com/topic/89282/java-o-n-time-o-1-space/5)
[Reference](http://www.cnblogs.com/grandyang/p/6876457.html)
There are many approaches. This one has O(nlogn) for time complexity and O(n) for space. There's another way that can achieve O(n) time and O(1) space.

## 605. Can Place Flowers
Just iterate over the array and find spot that has both empty adjacent elements. 

## 606. Construct String from Binary Tree
We need to understand every case. If both left and right exist, we return the current val and left and right values in parenthesis. If only left exists, we only return the current val and the left value in parenthesis. If only right exists, we need to return the current value, an empty parenthesis and the right value in parenthesis. If neither left nor right exists, we only return the current value.

## 628. Maximum Product of Three Numbers
The complication here is the negative numbers. So the answer is either the largest three or the smallest two times the largest number. 

## 643. Maximum Average Subarray I
Start with the sum of the first k elements and slide the window. 

## 657. Judge Route Circle
There are many ways to solve this. I think it's intuitive to see this in a coordinate system. If we come back to the origin, then it's circle. 

## 661. Image Smoother
Iterate over each pixel and for each pixel, iterate over each surrounding pixel. Make sure to deal with boundaries.

## 665. Non-decreasing Array
[Reference](http://www.cnblogs.com/grandyang/p/7565424.html)
We have several cases here. We only do soemthing when we found the current element is less than the previous one (`b > current`), because we assume previous pairs are solved and should be `a <= b`.
```cpp
// case 1
// a <= b > current && a <= current
b = current;

// case 2
// a <= b > current && a > current
current = b;

// case 3
// b is the 1st element in the array
b = current;
```

## 674. Longest Continuous Increasing Subsequence
Since we only care about the longest subsequence, we can start from the first element and return the first matched result. We check if the current element is larger than the previous one and increase the counter if it is. Otherwise we reset the counter to 1. 

## 680. Valid Palindrome II
The tricky part of this problem is that when we encounter a different pair of characters from left and right, we don't know which one we should delete. So we need to see both. The solution is a greedy algorithm because we think the previous status returns the optimal solution, rather than having us choose (e.g. max or min). 

## 686. Repeated String Match
If we list all scenarios, we can see that in order to contain B, string A must be repeated at least `B.length() / A.length() + 2` times. 

## 695. Max Area of Island
There are two sub problems: one is how to visit all elements and the other one is how to explore the surrounding elements of one element. The first problem can be solved simply by iterating over the grid. The second problem can be solved recursively by visiting each of the four directions. The base case of the recursion is when the element is out of the grid or is visited. Otherwise we increase the currently counting island size by 1, mark it as visited, and continue visiting surrounding elements. 

## 696. Count Binary Substrings
[Reference](http://www.cnblogs.com/grandyang/p/7716150.html)
The essense of this problem is to understand how we increase the count. Every time we encounter a different digit, if the previous number of consecutive digits is greater or equal to the current number of consecutive digits (e.g. 110 or 01), we increase the total count. So we need to maintain a previous digit counting. 

## 697. Degree of an Array
The basic idea is to use a data structure to store the count and the first and last position of the elements in the array. That's because we need to find out the degree first and at the same time note down the first and last position for the second loop. Then in the second loop, we find the subarray with the minimum length.

## 717. 1-bit and 2-bit Characters
We use a cursor to keep up with the start of every character (2 bits or 1 bit). If the value is 1, the current character must be a 2-bit character. So we move the cursor 2 bits. Otherwise, we move 1 bit. At the end, if the cursor is at the last element, the result is true. If the cursor is larger than the index range, the result is false.

## 724. Find Pivot Index
The basic idea is to compare the sum from the left side with the sum from the right side. How to get the right sum? By subtracting the current left sum and the cursor number from the sum of the whole array: `leftSum == rightSum - leftSum - nums[i]`.

## 733. Flood Fill
This is just a tree problem. Both BFS or DFS are fine. I used DFS. However OJ gave me Runtime error I haven't figured out why. The algorithms seems sound. 
