#include <stdio.h>
int main()
{
  int N,n,i,j,k;
  printf("enter the value of the number N : ");
  scanf("%d",&N);
  for(n=N;n>0;n--)
    {
      for(j=N;j>n;j--)
	{
	  printf("%d",j);
	}
      for(i=0;i<2*n-2;i++)
	{
	  printf("%d",n);
	}
      for(k=n;k<=N;k++)
	{
	  printf("%d",k);
	}
      printf("\n");
    }
  for(n=2;n<=N;n++)
    {
      for(j=N;j>n;j--)
	{
	  printf("%d",j);
	}
      for(i=0;i<2*n-2;i++)
	{
	  printf("%d",n);
	}
      for(k=n;k<=N;k++)
	{
	  printf("%d",k);
	}
      printf("\n");
    }
  return 0;
}
