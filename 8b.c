#include <stdio.h>

struct _STUDENT{
  char Roll_Number[8],Name[100],Gender;
  int Age;
  float CGPA;
};

float compute_top_cgpa(struct _STUDENT* record,int N,int* num_of_top);
void store_array_of_toppers(struct _STUDENT* record,int N,int* topper_sl_no,float max,int num_of_top);
void print_array_of_students(struct _STUDENT* record,int* topper_sl_no,int num_of_top);

int main()
{
  struct _STUDENT record[100];
  int N,i,num_of_top;
  float max;
  int topper_sl_no[100];
  printf("enter the value of N: \n");
  scanf("%d",&N);
  printf("Enter the particulars of students: \n");
  for(i=0;i<N;i++)
    {
      printf("student no. %d.\nEnter the roll number: \n",i+1);
      scanf("%s",(record+i)->Roll_Number);
      printf("Enter the name: \n");
      scanf("%[^\n]",(record+i)->Name);
      printf("Enter the age: \n");
      scanf("%d",&(record+i)->Age);
      printf("Enter the Gender(M-Male,F-Female,O-Other): \n");
      scanf("%c",&(record+i)->Gender);
      printf("Enter the CGPA: \n");
      scanf("%f",&(record+i)->CGPA);
    }
  max=compute_top_cgpa(record,N,&num_of_top);
  store_array_of_toppers(record,N,topper_sl_no,max,num_of_top);
  print_array_of_students(record,topper_sl_no,num_of_top);
  return 0;
}

float compute_top_cgpa(struct _STUDENT* record,int N,int* count_add)
{
  int i,count;
  float max=0;
  for(i=0;i<N;i++)
    {
      if((record+i)->CGPA>max)
	{
	  max=(record+i)->CGPA;
	  count=0;
	}
      if((record+i)->CGPA==max)
	count++;
    }
  *count_add=count;
  return max;
}

void store_array_of_toppers(struct _STUDENT* record,int N,int* topper_sl_no,float max,int num_of_top)
{
  int i,j=0,k,temp;
  for(i=0;i<N;i++)
    {
      if((record+i)->CGPA==max)
	{
	  topper_sl_no[j]=i;
	  j++;
	}
    }
  
  for(i=0;i<N;i++)
    {
      k=i;
      for(j=i+1;j<N;j++)
	{
	  if((record+k)->Age>(record+j)->Age)
	    k=j;
	}
      temp=topper_sl_no[i];
      topper_sl_no[i]=topper_sl_no[k];
      topper_sl_no[k]=temp;
    }
}

void print_array_of_students(struct _STUDENT* record,int* topper_sl_no,int num_of_top)
{
  int i;
  printf("The records of toppers in ascending order: \n");
  for(i=0;i<num_of_top;i++)
    {
      printf("Roll number: %s. \n",(record+topper_sl_no[i])->Roll_Number);
      printf("Name: %s.\n",(record+topper_sl_no[i])->Name);
      printf("Age: %d.\n",(record+topper_sl_no[i])->Age);
      printf("Gender: %c.\n",(record+topper_sl_no[i])->Gender);
      printf("CGPA: %f.\n",(record+topper_sl_no[i])->CGPA);
    }
}
      
  
  









  
  
  
