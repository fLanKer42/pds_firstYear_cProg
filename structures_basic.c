#include <stdio.h>
int main()
{
  struct tag
  {
    char name[30];
    int Roll_number;
    int marks;
  }a[45];
  int i,x=3,r,k;
  for(i=1;i<=29;i++)
    {
      printf("enter name : ");
      scanf("%s", a[i].name);
      printf("\n enter roll number : ");
      scanf("%d", &a[i].Roll_number);
      printf("\n enter marks : ");
      scanf("%d", &a[i].marks);
      printf("\n if you want to terminate the process press 1 else press any other number");
      scanf("%d",&x);
      k=i;
      if(x==1)
	break;
      else
	continue;
    }
  printf("\n your entries have been recorded");
  printf("\n the class list is as follows : ");
  for(r=1;r<=k;r++)
    {
      printf("\n %d . name: %s",i,a[r].name);
      printf("\n      roll number: %d",a[r].Roll_number);
      printf("\n      marks: %d \n \n \n",a[r].marks);
    }
  printf("\n end of document");
  return 0;
}
