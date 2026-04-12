#include<stdio.h>
#define maxsize 5

struct stack{
int top;
int arr[maxsize];
};

struct stack s;
void push(int ele){
    if(s.top+1==maxsize){
        printf("Stack Overflow");
    }
    else{
        s.arr[++s.top]=ele;
        printf("Insertion successfull");
    }
}
void display(){
for(int i=0;i<=s.top;i++){\
    printf("%d\t",s.arr[s.top]);
}
}

int isempty(){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int top(){
    return s.arr[s.top];
}

int pop(){
    return s.arr[s.top--];
}
void main(){
    s.top=-1;
    push(20);
    int num;
    do{
            printf("1.push\n2.pop\n3.top\n4.display\n5.isempty\n6.exit\n");
            scanf("%d",&num);
            switch(num){
            case 1:
                int ele;
                printf("Enter the element:");
                scanf("%d",&ele);
                break;
            case 2:
                if(isempty()){
                    printf("Stack is empty...");
                }
                else{
                    int temp=pop();
                    printf("Popped element is :%d",temp);
                }
                break;
            case 3:
                if(isempty()){
                    printf("Stack is empty...");
                }
                else{
                    int temp=top();
                    printf("Top element is :%d",temp);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("%d",isempty());
                break;

            default:
                break;
            }

    }while(num>5);
}
