# Maximum-Subarray-Algorithm

## Contents

- [About](#about)
- [Algorithm](#algorithm)
  - [Brute-force-approach](#brute-force-approach)
  - [Divide-and-conquer](#divide-and-conquer)
  - [Dynamic-programming-approach(Kadane's Algorithm)](#dynamic-programming-approach(Kadane's-algorithm)
- [Implementation](#implementaion)
  - [In C](#in-c)
  - [In C++](#in-c++)
  - [In Python](#in-python)
  - [In Java](#in-java)
  - [In JavaScript](#in-javascript)
  - [In Ruby](#in-ruby)

## About

>  the maximum subarray problem is the task of finding the contiguous subarray
> within a one-dimensional array of numbers (containing at least one positive 
> number) which has the largest sum

## Algorithm
=============
### Brute-force-approach
------------------------
### Divide-and-conquer

```
   FIND-MAX-CROSS-SUBARRAY(A,low,mid,high)
     left-sum = -∞
     sum = 0
     for i = mid downto 0
       sum = sum + A[i]
       if sum > left-sum
         left-sum = sum
         max-left = i
     right-sum = -∞
     sum = 0
       for i = mid+1 up to A.length-1
         sum = sum + A[i]
         if sum > right-sum
           right-sum = sum
           max-right = i
     return(max-left,max-right,left-sum+right-sum)


### Dynamic-programming-approach(Kadane's Algorithm)
