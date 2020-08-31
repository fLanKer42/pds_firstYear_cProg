#include <stdio.h>
#define MAX 100000
int main()
{
  int n,i,j,k=0,arr[MAX],minVal,minCount;
  printf("enter number of daisy flowers : ");
  scanf("%d",&n);
  printf("\n enter the number of petals on each flower : ");
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  while(n>0)
    {
      minVal=arr[0];
      minCount=1;
      for(i=1;i<n;i++)
	{
	  if(arr[i]==minVal)
	    {
	      minCount++;
	    }
	  else if(arr[i]<minVal)
	    {
	      minVal=arr[i];
	      minCount=1;
	    }
	}
      for(i=n-1;i>=0;i--)
	{
	  if(arr[i]==minVal)
	    {
	      for(j=i+1;j<n;j++)
		{
		  arr[j-1]=arr[j];
		}
	    }
	}
      n=n-minCount;
      for(i=0;i<n;i++)
	{
	  arr[i]=arr[i]-minVal;
	}
      k++;
      printf("\n ---iteration %d : \n",k);
      printf("   number of flowers with minimum petals is %d \n",minCount);
      printf("   petal numbers of remaining flowers = ");
      if(n)
	{
	  for(i=0;i<n;i++)
	    {
	      printf("%d",arr[i]);
	    }
	}
      else
	printf("NIL");
    }
  return 0;
}
      
	    
		  
  
      
