#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

  struct substruct {	//using struct to return multiple values from the function
	int max_sum;
	int max_left;
	int max_right;
   };

  struct substruct max_cross_subarray(int *A,int low,int mid,int high) {
	struct substruct sub;
	int i;
	int  left_sum, right_sum;
	left_sum = right_sum =  INT_MIN;
	int sum = 0;
	sub.max_left = sub.max_right = 0;
	for(i = mid; 	i >=0; i--) {
	  sum = sum + A[i];
	  if(sum > left_sum) {
	    left_sum = sum;
	    sub.max_left = i;
           }
          }
        sum = 0;
        for(i = mid+1; i < high; i++) {
	  sum = sum + A[i];
	  if(sum > right_sum) {
	    right_sum = sum;
	    sub.max_right = i;
	   }
	}
        sub.max_sum = left_sum + right_sum;
	return sub;
      }

  struct substruct max_subarray(int *A,int low,int high) {
       struct substruct sub;
	if(low == high) { //base-case
	  sub.max_sum = A[low];
	  sub.max_left = low;
	  sub.max_right = high;
	  return sub; 
            }
	else {
	  int mid = low + (high-low)/2;
	 
          struct substruct sub1 = max_subarray(A,low,mid);
          struct substruct sub2 = max_subarray(A,mid+1,high);
	      struct substruct sub3 = max_cross_subarray(A,low,mid,high);
	 
          int left_low = sub1.max_left;
	      int left_high = sub1.max_right;
	      int left_sum = sub1.max_sum;
	 
          int right_low = sub2.max_left;
          int right_high = sub2.max_right;
          int right_sum = sub2.max_sum;
	 
          int cross_low = sub3.max_left;
          int cross_high = sub3.max_right;
          int cross_sum = sub3.max_sum;
          
          if(left_sum > right_sum && left_sum > cross_sum) {
            sub.max_left = left_low;
	       sub.max_right = left_high;
	       sub.max_sum = left_sum;
	    return sub;
	     }
   
          else if(right_sum > left_sum && right_sum > cross_sum) {
	        sub.max_left = right_low;
            sub.max_right = right_high;
            sub.max_sum = right_sum;
            return sub;
             }

	  else {
	        sub.max_left = cross_low;
            sub.max_right = cross_high;
            sub.max_sum = cross_sum;
            return sub;
             }
	 }
      }

  int main() {
	struct substruct sub;
	int n;
	int i;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n*sizeof(int));
        printf("\n Enter the numbers: ");
        for(i=0; i<n;i++)
         scanf("%d", &arr[i]);
        sub = max_subarray(arr,0,n);
        printf("\n Sum of max-subarray: %d\n lower-index: %d\n upper-index: %d", sub.max_sum,sub.max_left,sub.max_right);
       return 0; 
    }
