# Array

## 697. Degree of an Array
The basic idea is to use a data structure to store the count and the first and last position of the elements in the array. That's because we need to find out the degree first and at the same time note down the first and last position for the second loop. Then in the second loop, we find the subarray with the minimum length.


## 717. 1-bit and 2-bit Characters
We use a cursor to keep up with the start of every character (2 bits or 1 bit). If the value is 1, the current character must be a 2-bit character. So we move the cursor 2 bits. Otherwise, we move 1 bit. At the end, if the cursor is at the last element, the result is true. If the cursor is larger than the index range, the result is false.


## 724. Find Pivot Index
The basic idea is to compare the sum from the left side with the sum from the right side. How to get the right sum? By subtracting the current left sum and the cursor number from the sum of the whole array: `leftSum == rightSum - leftSum - nums[i]`.


