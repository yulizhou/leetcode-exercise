# leetcode-exercise

## 1. Two Sum
First loop creates the mapping from array elements to cooresponding indices. The second loop if the condition met.

## 26. Remove Duplicates from Sorted Array
We maintain two pointers: one points to the "new" array and the other one is the iterator `j`. When the `j` pointer finds duplicate, it skips it and if it finds a new element, the first pointer will increase and copy the new found element over.

## 27. Remove Element
Quite similar to problem 26. We use two pointers.

## 35. Search Insert Position
Nothing to say. A regular approach has O(n). A better one is to use binary search with O(logn).

## 38. Count and Say
The most difficult part of this problem is to figure out the rule. Basically starting from the 2nd layer, each layer is a string describing the number of consecutive numbers in the previous string.

## 53. Maximum Subarray
[Reference](https://discuss.leetcode.com/topic/5000/accepted-o-n-solution-in-java)
Best solution so far is from Jon Bentley's code in 1984. The post explains it well. 

## 66. Plus One
There are three cases here. If the last digit is not 9, then we can just plus one and return. If all digits are 9, then all digits need to be set to 0 and we add one digit 1 to the front. If only a few consecutive 9s at the latter part of the digit array, then we set all 9s to 0s and add one to the first non-nine digit counting backwards.

## 70. Climbing Stairs
Similar to No.66, it's a dynamic programming problem. The status `dp[i]` is the number of distinct steps at step i. To reach step i, we have to start from i-1 or i-2. So the transition function is `dp[i] = dp[i - 1] + dp[i - 2]`. 

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

## 448. Find All Numbers Disappeared in an Array
With O(n) time and O(1) space limitation, we can only do one or more sequential for loops without hash tables. From the problem, the value of the element can also represent an index of the array. So we can come up with a way to put every value to the corresponding index position and get the ones that are not aligne as our answer. 

## 485. Max Consecutive Ones
Nothing much to say. 

## 532. K-diff Pairs in an Array
Since it's a counting problem, we consider using a hash table. Basically we record the frequency of each element. Then we try to find out if the element plus k is also in the hash table.

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

## 628. Maximum Product of Three Numbers
The complication here is the negative numbers. So the answer is either the largest three or the smallest two times the largest number. 

## 643. Maximum Average Subarray I
Start with the sum of the first k elements and slide the window. 

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

## 686. Repeated String Match
If we list all scenarios, we can see that in order to contain B, string A must be repeated at least `B.length() / A.length() + 2` times. 

## 695. Max Area of Island
There are two sub problems: one is how to visit all elements and the other one is how to explore the surrounding elements of one element. The first problem can be solved simply by iterating over the grid. The second problem can be solved recursively by visiting each of the four directions. The base case of the recursion is when the element is out of the grid or is visited. Otherwise we increase the currently counting island size by 1, mark it as visited, and continue visiting surrounding elements. 

## 697. Degree of an Array
The basic idea is to use a data structure to store the count and the first and last position of the elements in the array. That's because we need to find out the degree first and at the same time note down the first and last position for the second loop. Then in the second loop, we find the subarray with the minimum length.

## 717. 1-bit and 2-bit Characters
We use a cursor to keep up with the start of every character (2 bits or 1 bit). If the value is 1, the current character must be a 2-bit character. So we move the cursor 2 bits. Otherwise, we move 1 bit. At the end, if the cursor is at the last element, the result is true. If the cursor is larger than the index range, the result is false.

## 724. Find Pivot Index
The basic idea is to compare the sum from the left side with the sum from the right side. How to get the right sum? By subtracting the current left sum and the cursor number from the sum of the whole array: `leftSum == rightSum - leftSum - nums[i]`.
