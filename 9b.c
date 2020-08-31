#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct _STUD_RECORD
{
  char Name[80];
  char Roll_no[80];
  float cgpa;
  char dob[10];
};

int readStudentRecords(struct _STUD_RECORD *arr);
void sortStudentRecords(struct _STUD_RECORD *arr,int n);
int getStudentMaxCGPA(struct _STUD_RECORD *arr,int n,struct _STUD_RECORD *top);
struct _STUD_RECORD getYoungestStudent(struct _STUD_RECORD *arr,int n);
int getRecord(struct _STUD_RECORD *arr,int n,char key[],int *pos);
int comparedob(char d1[],char d2[]);


int main()
{
  int n,i,pos;
  struct _STUD_RECORD *A,*top,y_stud;
  FILE *fptr;
  char roll[80];
  char filename[]="output1.dat";
  fptr=fopen(filename,"w");
  if(fptr==NULL)
    {
      printf("error in file creation. \n");
    }
  n=readStudentRecords(A);
  sortStudentRecords(A,n);
  fprintf(fptr,"Students with maximum cgpa. \n");
  for(i=0;i<getStudentMaxCGPA(A,n,top);i++)
    {
      fprintf(fptr,"%s \n",top[i].Name);
    }
  fprintf(fptr,"Youngest Student: \n");
  y_stud=getYoungestStudent(A,n);
  fprintf(fptr,"%s \n",y_stud.Name);
  fprintf(fptr,"list of all students. \n");
  for(i=0;i<n;i++)
    {
      fprintf(fptr,"%s \n",A[i].Name);
    }
  fclose(fptr);
  while(1)
    {
      printf("enter a roll number: \nenter 0 to break: \n ");
      scanf("%s",roll);
      if(strcmp(roll,"0")!=0)
	if(getRecord(A,n,roll,&pos)<0)
	  {
	    printf("No record found! \n");
	  }
	else
	  {
	    printf("name: %s. \nroll no.: %s.\ncgpa: %f.\nDOB: %s.\n",A[pos].Name,A[pos].Roll_no,A[pos].cgpa,A[pos].dob);
	  }
      else
	break;
    }
  return 0;
}

int readStudentRecords(struct _STUD_RECORD *arr)
{
  int n,i;
  char cgpa[10];
  FILE *fptr;
  fptr=fopen("input.dat","r");
  if(fptr==NULL)
    {
      printf("error in opening file.\n");
    }
  fscanf(fptr,"%d",&n);
  for(i=0;i<n;i++)
    {
      fgets((arr+i)->Name,80,fptr);
      fgets((arr+i)->Roll_no,80,fptr);
      fgets(cgpa,10,fptr);
      arr[i].cgpa=strtof(cgpa,NULL);
      fgets((arr+i)->dob,10,fptr);
    }
  fclose(fptr);
  return n;
}

void sortStudentRecords(struct _STUD_RECORD *arr,int n)
{
  int i,j,k;
  struct _STUD_RECORD temp;
  for(i=0;i<n;i++)
    {
      k=i;
      for(j=i+1;j<n;j++)
	{
	  if((strcmp((arr+k)->Roll_no,(arr+j)->Roll_no))>0)
	    {
	      k=j;
	    }
	}
      temp=arr[i];
      arr[i]=arr[k];
      arr[k]=temp;
    }
}

int getStudentMaxCGPA(struct _STUD_RECORD *arr,int n,struct _STUD_RECORD *top)
{
  int i,count=1,j=0;
  float max=0;
  for(i=0;i<n;i++)
    {
      if(arr[i].cgpa>max)
	max=arr[i].cgpa;
      if(arr[i].cgpa==max)
	count++;
    }
  for(i=0;i<n;i++)
    {
      if(arr[i].cgpa==max)
	{
	  top[j]=arr[i];
	  j++;
	}
    }
  return j;
}

int comparedob(char d1[],char d2[])
{
  if(d1[6]>d2[6])
    return 1;
  if(d1[6]<d2[6])
    return 2;
  if(d1[7]>d2[7])
    return 1;
  if(d1[7]<d2[7])
    return 2;
  if(d1[8]>d2[8])
    return 1;
  if(d1[8]<d2[8])
    return 2;
  if(d1[9]>d2[9])
    return 1;
  if(d1[9]<d2[9])
    return 2;
  if(d1[3]>d2[3])
    return 1;
  if(d1[3]<d2[3])
    return 2;
  if(d1[4]>d2[4])
    return 1;
  if(d1[4]<d2[4])
    return 2;
  if(d1[0]>d2[0])
    return 1;
  if(d1[0]<d2[0])
    return 2;
  if(d1[1]>d2[1])
    return 1;
  if(d1[1]<d2[1])
    return 2;
}
  


struct _STUD_RECORD getYoungestStudent(struct _STUD_RECORD *arr,int n)
{
  int i,youngest=0;
  for(i=1;i<n;i++)
    {
      if(comparedob(arr[i].dob,arr[youngest].dob)==2)
	youngest=i;
    }
  return arr[youngest];
}

int getRecord(struct _STUD_RECORD *arr,int n,char key[],int *pos)
{
  int start=0,end,comp_res,count=0,k=0,i;
  end=n;
  for(i=0;i<log2(n);i++)
    {
      comp_res=strcmp(arr[(start+end)/2].Roll_no,key);
      if(comp_res==0)
	{
	  *pos=(start+end)/2;
	  count++;
	  k=1;
	  break;
	}
      if(comp_res<0)
	start=((start+end)/2)+1;
      if(comp_res>0)
	end=((start+end)/2)-1;
      count++;
    }
  if(k==0)
    return (count*(-1));
  if(k==1)
    return count;
}


  
    


  
	  
  
  
      
      
      
  
