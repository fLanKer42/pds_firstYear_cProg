#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

struct Stack {
    char name[100];
    char roll[100];
    float cgpa;
    struct Stack *next;
};

struct Queue {
    struct Stack *S1;
    struct Stack *S2;
};
struct Stack *InitialiseStack ();
int isEmptyStack(struct Stack *top);
void Push(struct Stack **top,char *name,char *roll,float cgpa);
struct Stack Pop(struct Stack **top);
struct Queue *InitialiseQueue();
void AddQueue(struct Queue *Q,char *name,char *roll,float cgpa);
struct Stack DeleteQueue(struct Queue *Q);
void DisplayQueue(struct Queue *Q);
struct Stack FindMaxQueue(struct Queue *Q);



int main() {
    struct Queue *Q = InitialiseQueue();
    Q->S1 = Q->S2 = NULL;
    struct Stack Data;
    int key,i=1;
    char line[100],rollno[100];
    float cg;
    printf("\nEnter 0 to add a student's record.\nEnter 1 to delete a student's record\nEnter 2 to display queue.\nEnter 3 to print record of topper\nEnter 4 to exit.\n");
    while(i) {
      scanf("%d",&key);
      switch(key) {
      case 0:
	printf("Enter the name, rollno. , cgpa");
	scanf("%[^,],%[^,],%f",line,rollno,&cg);
	printf("\n");
	AddQueue(Q,line,rollno,cg);
	break;
      case 1:
	Data=DeleteQueue(Q);
	printf("You have deleted the data of %s\n",Data.name);
	break;
      case 2:
	DisplayQueue(Q);
	break;
      case 3:
	Data=FindMaxQueue(Q);
	printf("The topper is: %s\nRoll number: %s\nCGPA: %f\n",Data.name,Data.roll,Data.cgpa);
	break;
      case 4:
	i=0;
	break;
      default:
	i=0;
	break;
      }
    }
    return 0;
}


struct Stack *InitialiseStack () {
    return NULL;
}

int isEmptyStack(struct Stack *top) {
    return (top == NULL);
}
void Push(struct Stack **top,char *line,char *rollno,float cg) {
    struct Stack *newNode = (struct Stack*) malloc(sizeof(struct Stack));
    if(!newNode)
        return;
    newNode->cgpa = cg;
    strcpy(newNode->name,line);
    strcpy(newNode->roll,rollno);
    newNode->next = (*top);
    *top = newNode;
}

struct Stack Pop(struct Stack **top) {
    struct Stack *temp;
    struct Stack ret;

    if(isEmptyStack(*top)) {
        printf("Empty Stack.\n");
        return (*InitialiseStack());
    }

    temp = *top;
    ret.cgpa = (*top)->cgpa;
    strcpy(ret.name,(*top)->name);
    strcpy(ret.roll,(*top)->roll);
    (*top) = (*top)->next;
    free(temp);
    return ret;
}
struct Queue *InitialiseQueue() {
    struct  Queue  *newNode = (struct Queue *) malloc(sizeof(struct  Queue ));
    return newNode;
}


void AddQueue(struct Queue *Q,char *name,char *roll,float cgpa) {
    struct Stack temp;
    if(!isEmptyStack(Q->S2))
        Push(&Q->S1,name,roll,cgpa);
    else {
        while(!isEmptyStack(Q->S2)) {
	  temp=Pop(&Q->S2);
	  Push(&Q->S1,temp.name,temp.roll,temp.cgpa);
        }
        Push(&Q->S1,name,roll,cgpa);
    }
       
}

void DisplayQueue(struct Queue *Q) {
    struct Stack temp;
    if(!isEmptyStack(Q->S1)) {
        while(!isEmptyStack(Q->S1)) {
	  temp=Pop(&Q->S1);
	  printf("Name: %s.\n",temp.name);
	  printf("Roll: %s.\n",temp.roll);
	  printf("CGPA: %f.\n",temp.cgpa);
	  Push(&Q->S2,temp.name,temp.roll,temp.cgpa);
	}
    }
    else {
      while(!isEmptyStack(Q->S2)) {
	  temp=Pop(&Q->S2);
	  Push(&Q->S1,temp.name,temp.roll,temp.cgpa);
      }
      while(!isEmptyStack(Q->S1)) {
	  temp=Pop(&Q->S1);
	  printf("Name: %s.\n",temp.name);
	  printf("Roll: %s.\n",temp.roll);
	  printf("CGPA: %f.\n",temp.cgpa);
	  Push(&Q->S2,temp.name,temp.roll,temp.cgpa);
	}
    }
}
  
struct Stack DeleteQueue(struct Queue *Q) {
    struct Stack temp;
    if(!isEmptyStack(Q->S2)) {
        return Pop(&Q->S2);
    }
    else {
        while(!isEmptyStack(Q->S1)) {
	  temp=Pop(&Q->S1);
	  Push(&Q->S2,temp.name,temp.roll,temp.cgpa);
        }
        return Pop(&Q->S2);
    }
}
struct Stack FindMaxQueue(struct Queue *Q) {
    struct Stack temp,topper;
    float MAX_CG=0;
    if(!isEmptyStack(Q->S1)) {
        while(!isEmptyStack(Q->S1)) {
	  temp=Pop(&Q->S1);
	  if(temp.cgpa>=MAX_CG) {
	    topper=temp;
	    MAX_CG=temp.cgpa;
	  }
	  Push(&Q->S2,temp.name,temp.roll,temp.cgpa);
	}
    }
    else {
        while(!isEmptyStack(Q->S2)) {
	  temp=Pop(&Q->S2);
	  if(temp.cgpa>=MAX_CG) {
	    topper=temp;
	    MAX_CG=temp.cgpa;
	  }
	  Push(&Q->S1,temp.name,temp.roll,temp.cgpa);
	}
    }
    return topper;
}
	
  
