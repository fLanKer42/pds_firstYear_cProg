#include <stdio.h>
int main()
{
  int convResult,a,k,base;
  printf("enter the number which has to be converted : ");
  scanf("%d",&a);
  printf("enter the value of the base : ");
  scanf("%d",&base);
  if(a<base)
    printf("\n%d\n",a);
  else
    {
      convResult=0;
      k=1;
      while(a>0)
	{
	  convResult=convResult + k*(a%base);
	  a=a/base;
	  k=k*10;
	}
      printf("\n%d\n",convResult);
    }
  return 0;
}
