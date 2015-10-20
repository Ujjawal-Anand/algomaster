# Maximum-Subarray-Algorithm

## Contents

- [About](#about)
- [Algorithm](#algorithm)
  - [Brute-force-approach](#brute-force-approach)
  - [Divide-and-conquer](#divide-and-conquer)
  - [Dynamic-programming-approach(Kadane's Algorithm)](#dynamic-programming-approach(Kadane's-algorithm))
- [Implementation](#implementaion)
  - [In C](#in-c)
  - [In C++](#in-c++)
  - [In Python](#in-python)
  - [In Java](#in-java)
  - [In JavaScript](#in-javascript)
  - [In Ruby](#in-ruby)

## About

 From wikipedia
> The maximum subarray problem is the task of finding the contiguous subarray
> within a one-dimensional array of numbers (containing at least one positive 
> number) which has the largest sum

## Algorithm
------------------------
### Brute-force-approach

### Divide-and-conquer
> ##### Key concepts
> - The maximum subarray problem is interesting only when the array contains some negative number
> - After dividing the array into two subarrays A[low...mid] and A[mid+1...high]  and hence divide and conquer apporach.The resulting maximum subarray a[i...j]  must line in exactly one of three following places
>   1. In A[low..mid], so that low<=i<=j<=mid
>   2. In A[mid+1...high], so that mid+1<=i<=j<=high, or
>   3. crossing the midpoint  low<=i<=j<=high
> - Find maximum subarrays of A[low...mid] and A[mid+1...high] recursivly, because these two subproblems are smaller instances of problem of finding a maximum subarray.



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

  FIND-MAX-SUBARRAY(A,low,high)
    if(low == high)   //base-case of recursion
      return(low,high,A[low])
    else mid = (low+high)/2
      (left-low,left-high,left-sum) = FIND-MAX-SUBARRAY(A,low,mid)
      (right-low,right-high,right-sum) = FIND-MAX-SUBARRAY(A,mid+1,high)
      (cross-low,cross-high,cross-sum) = FIND-MAX-CROSS(A,low,mid,high)
     
      if (left-sum > right-sum and left-sum > cross-sum)
        return(left-low,left-high,left-sum)  // the max-subarray lies entirely in left sub-part
      else if (right-sum > left-sum and right-sum > cross-sum)
        return(right-low,right-high,right-sum) //the max-subarray lies entirely in right sub-part
      else
        return(cross-low,cross-high,cross-sum) //the max-subarray crosses the mid-point
```
### Dynamic-programming-approach(Kadane's Algorithm)

----------------------------------------------------

## Implementation
-----------------------------------------------------
### In C

### In C++

### In Python

### In Java

### In Javascript

### In Ruby

------------------------------------------------
