#include <stdio.h>
typedef struct
{
  int sides;
  float length[10];
} POLYGON;
float perimeter(POLYGON p)
{
  float peri=0.0;
  int i;
  for(i=0;i<p.sides;i++)
    {
      peri+=p.length[i];
    }
  return 0;
}
int main()
{
  POLYGON shape;
  int k;
  float peri;
  scanf("%d",&shape.sides);
  for(k=0;k<shape.sides;k++)
    {
      scanf("%f",&shape.length[k]);
    }
  peri=perimeter(shape);
  printf("\nPerimeter is : %f",peri);
}
