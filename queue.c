#include <stdio.h>
#include <stdbool.h>
#define max 3

void insert(int val, int *front,int *rear, int q[]){
      if(*rear==max-1){
          printf("queue is full\n");
          }
      else{
          if(*rear==-1 && *front==-1){
             *front=0;

            }
          (*rear)++;
          q[*rear]=val;
          printf("%d inserted into queue\n",val);
          }
    }

void delete(int *rear,int *front,int q[]){
     if(*front==-1 || *front>*rear){
        printf("queue is empty\n");
    }
     else{
        if(*rear==-1 || *front==-1){
             *front=0;
             *rear=0;
            }
        int val=q[*front];
        (*front)++;
        printf("%d deleted from queue\n",val);
        }
    }

void display(int rear,int front,int q[]){
     for(int i=front;i<=rear;i++){
        printf("%d\n",q[i]);
    }
}

void main(){
   int front=-1;
   int rear=-1;
   int q[max];
   int n;


while(true){
    printf("1.insert into queue\n2. delete from queue\n3. display queue\n");
   scanf("%d",&n);
  if(n==1){
       int c;
       printf("enter element to be inserted");
       scanf("%d",&c);
       insert(c,&front,&rear,q);
}
  else if(n==2){
       delete(&rear,&front,q);
  }
  else if(n==3){
       display(rear,front,q);
  }
  else{
    printf("invalid input\n");
}
}
}
