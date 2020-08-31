#include <stdio.h>
int main()
{
  int n,i,count=1,num=1;
  printf("Enter the value of n: ");
  scanf("%d",&n);
  for(i=0;i<(n*n);i++)
    {
      if(count%n!=0)
	{
	  printf("%d",num);
	  num=(!num);
	  count++;
	}
      else
	{
	  printf("%d",num);
	  num=(!num);
	  printf("\n");
	  count++;
	}
    }
}
  
      
	  
  
