/*****
 *section 13
 *M/C No. : 83
 *Roll No. : 19QD30004
 *Name : Dhruv Rai
 *Assignment no. : 8A
 *Description : program to remove multiple occurances in an array.
 *****/
#include <stdio.h>
#include<stdlib.h>
int main()
{
  int n,i,A[100],count=0,d,t;
  int*p;
  printf("enter value of integer n : ");
  scanf("%d",&n);
  printf("\n enter the elements of the array:\n");
  for(i=0;i<n;i++)
    {
      printf("enter element number %d : ",i+1);
      scanf("%d",&A[i]);
    }
  if((p=(int*)malloc((count+1)*sizeof(int)))==NULL)
    {
      printf("\nMemory cnnot be allocated");
      exit(1);
    }
  for(i=0;i<n;i++)
    {
      t=0;
      for(d=0;d<count;d++)
	{
	  if(A[i]==*(p+d))
	    t++;
	}
      if(t==0)
	{
	  *(p+count)=A[i];
	  count++;
	  p=realloc(p,count);
	}
    }
  printf("\n new array of size %d is :",count);
  for(i=0;i<count;i++)
    {
      printf("%d",*(p+i));
    }
}
  
  
      
	
	    
  
  
