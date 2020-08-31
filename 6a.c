#include <stdio.h>
#include <stdlib.h>

int sum_sqr_digits(int number);
/* function to sum squares of digits of a number*/
void sort(int *A, int *B, int N);
/*function to sort the sum_sqr_digits array in asscending order and making corresponding changes in the original array*/
  
int main()
{
  int i,N;
  int *A,*B;
  /*A is the input array and B is the sum_sqr_digits array*/
  printf("enter the value of N: \n");
  scanf("%d",&N);
  A=(int*)malloc(N*sizeof(int));                         
  B=(int*)malloc(N*sizeof(int));
  /*input*/
  for(i=0;i<N;i++)                                      
    {
      printf("Enter a number: \n");
      scanf("%d",&A[i]);
    }
  /*calling sum_sqr_digits*/
  for(i=0;i<N;i++)
    {
      B[i]=sum_sqr_digits(A[i]);
    }
  sort(A,B,N);
  /*output*/
  for(i=0;i<N;i++)
    {
      printf("(%d,%d)\n",A[i],B[i]);
    }
  return 0;
  
 
}

void sort(int *A,int *B,int N)
{
  /*comparing each element(using a loop) with the elements ahead of it and replacing it with the lowest one*/
  int i,j,temp_A,temp_B,k;
  for(i=0;i<N;i++)
    {
      k=i;
      for(j=i+1;j<N;j++)
	{
	  if(B[k]>B[j])
	    k=j;
	}
      temp_A=A[i];
      temp_B=B[i];
      A[i]=A[k];
      A[k]=temp_A;
      B[i]=B[k];
      B[k]=temp_B;
    }
}

int sum_sqr_digits(int num)
{
  /*squaring the remainder of num/10 and then calling the same function for num/10*/
  int r;
  r=num%10;
  r=r*r;
  if(num==0)
    return 0;
  else
    return (r+sum_sqr_digits(num/10));
}


  
