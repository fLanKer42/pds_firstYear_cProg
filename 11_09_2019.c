#include <stdio.h>
void square(int a[],int b);

int main()
{
  int a[100],i,n;
  printf("enter the number of elements in the array : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("\n enter the element number %d : ",i+1);
      scanf("%d",&a[i]);
    }
  square(a,n);
  printf("\nNew array is : ");
  for(i=0;i<n;i++)
    {
      printf("\n %d",a[i]);
    }
}
void square(x,size)
  int x[],size;
{
  int i;
  for(i=0;i<size;i++)
    {
      x[i]=x[i]*x[i];
    }
  printf("\n");
  return;
}
