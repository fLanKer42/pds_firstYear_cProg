#include <stdio.h>
int factorial(int m)
{
  int i,temp=1;
  for(i=1;i<=m;i++)
    temp=temp*i;
  return(temp);
}
void main()
{
  int n;
  printf("enter a number : ");
  scanf("%d",&n);
  printf("\n %d ! = %d\n",n,factorial(n));
}
