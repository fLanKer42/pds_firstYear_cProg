#include <stdio.h>
float avg(int*,int);

int main()
{
  int x[100],i,n;
  printf("enter the value of number of entries : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("\n enter the entry number %d : ",i+1);
      scanf("%d",&x[i]);
    }
  printf("\n Average is %f",avg(x,n));
}
float avg(int*p, int size)
{
  int i,sum=0;
  for(i=0;i<size;i++)
    {
      sum=sum+*(p+i);
    }
  return ((float) sum/size);
}
