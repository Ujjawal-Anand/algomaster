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

```
