#include <stdio.h>
#include <stddef.h>
int main()
{
  int x,y;
  int *p;
  x=10;
  p=&x;
  y=*p;
  printf("\n %d is stored in the location %ls \n",x,&x);
  printf("\n %d is stored in the location %ls \n",*&x,&x);
  printf("%d is stored in the location %ls \n",*p,p);
  printf("%d is stored in the location %ls \n",y,&*p);
  printf("%d is stored in the location %ls \n",y,&y);

  *p=25;
  printf("\n now x=%d \n",x);
  return 0;
}
  
