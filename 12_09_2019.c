#include <stdio.h>
int main()
{
  int arr[100][100],i,j,nrow,ncol;
  printf("enter the number of rows : ");
  scanf("%d",&nrow);
  printf("enter the number of columns : ");
  scanf("%d",&ncol);
  for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf(" enter the element number %d,%d ",i+1,j+1);
	  scanf("%d",&arr[i][j]);
	}
    }
  for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("%d",arr[i][j]);
	}
      printf("\n");
    }
  return 0;
}

  
    
  
