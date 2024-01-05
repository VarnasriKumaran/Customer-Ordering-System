//CODE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
//1
struct user{
	int userid;
	char name[20];
	char city[20];
	struct user *next;
	
};

int id ;
char uname[20] ;
char ucity[20] ;
struct user *head=NULL;
void beginsert();
void display();


//2
void enqueue();
void dequeue();
void show();
int orderid[size];
int n;
int rear=-1,front=-1;
int final;
//3
struct node{
	int userid;
	char foodname1[20];
	char foodname2[20];
	struct node *next;
};
struct node *h;  
void beginsert2();
void display2();
int user;
char f1[20],f2[20];


struct list{
	int price;
	char name[20];
	struct node *next;
};
struct list *a;  
void beginsert3();
void display3();
void search();
int price;
char f[20];

int t1,t2,t3;
int temp,qty;

int check(char str[10]);

int main()
{
	
    
	
	int choice;
	while(1){
		printf("\n ----------------------------------------------------\n ");
		printf("Enter the operation that you want to do in the system");
		printf("\n _______________THE MENU____________ \n ");
		printf(" \n-------- User module------- \n  1. User details insert \n 2. User Display \n -------Adminstrative module -------\n");
		printf("3.Order Id enter \n 4. process order (ready to delivery ) \n 5. View the order list \n ");
		printf("6.Enter the order \n 7. display the order \n ADMIN \n 8.Enter the food \n 9. Display the food .\n 10. Exit \n  ");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				beginsert();
				break;
			case 2:
				display();
				break;
			case 3:
				enqueue();
				break;
			case 4:
				dequeue();
				break;
			case 5:
				show();
				break;
			case 6:
				beginsert2();
				break;
			case 7:
				display2();
				break;
			case 8:
				beginsert3();
				break;
			case 9: 
			display3();
			break;
				
			case 10:
				return 0;
				break;
		
		}
		
	}
	//return 0;
}

//null
//void  insertatlast(struct user** head)

	void beginsert()  
    {  
        struct user *ptr;  
        int item;  
        ptr = (struct user *) malloc(sizeof(struct user *));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW");  
        }  
	printf("\n Enter the user ID:");
	scanf("%d \n ",&id );
	
	printf("\n Enter the user name :");
	scanf("%s \n ",uname );
	
	printf("\n Enter the user city :");
	scanf("%s \n ",ucity );
	
	ptr->userid=id;
	strcpy(uname,ptr->name);
	//strcpy(ustreet,ptr->street);
	strcpy(ucity,ptr->city);
	//strcpy(ustate,ptr->state);
	//strcpy(ucountry,ptr->country);
}
	void display()  
    {  
        struct user *ptr;  
        ptr = head;  
        if(ptr == NULL)  
        {  
            printf("Nothing to print");  
        }  
        else  
        {  
            printf("\nprinting values . . . . .\n");  
            while (ptr!=NULL)  
            {  
                printf("\n%d",ptr->userid); 
				printf("\n %s",ptr->name) ;
      //          printf("\n%d",ptr->street);  
                printf("\n%s",ptr->city);  
        //        printf("\n%d",ptr->state);  
          //      printf("\n%d",ptr->country);  
                
                ptr = ptr -> next;  
            }  
        }  
    }    
    
   
void enqueue()
{
    int ordernumber;
    if (rear == size - 1)
       printf("The order of the meals is over  \n");
    else
    {
        if (front == - 1)
        front = 0;
        
        printf("Enter the order number to be inserted in the orderlist \n : ");
        scanf("%d", &ordernumber);
        rear = rear + 1;
        orderid[rear]=ordernumber;
    }
} 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("The order of the meal is empty  \n");
        return ;
    }
    else
    {
        printf("The completed order is  %d \n", orderid[front]);
        final=orderid[front];
        front = front + 1;
        //return final;
    }
} 
void show()
{
    
    if (front == - 1)
        printf("The order of the meal  is empty ");
    else
    {
    	printf("The order list : \n process the order");
        for (int i = front; i <= rear; i++)
            printf("%d ", orderid[i]);
        printf("\n");
    }
}




    
    void beginsert2()  
    {  
        struct node *ptr;  
        ptr = (struct node *) malloc(sizeof(struct node *));  
        
        if(ptr == NULL)  
        {  
            printf("\nThe order list is full ");  
        }  
        
        else  
        {  
        		FILE  *fileptr;
	    fileptr = fopen("order.txt", "w");
	if (fileptr == NULL) {
        printf("File couldn't be opened \n");
        fclose(fileptr);
        exit(0);
    }
       printf("\nEnter userid \n");            
            scanf("%d",&user);
            char  x=user;    
            ptr->userid= user;  
            printf("\n Enter the food name ");
            scanf("%s",f1);
            t1=check(f1);
            strcpy(ptr->foodname1,f1);
            
            printf("\n Enter the second food name ");
            scanf("%s",f2);
            t2=check(f2);
            strcpy(ptr->foodname2,f2);
            
            t3=t1+t2;
            printf("\n The total amount :: %d",t3);
            
            fputs(f1,fileptr);
            fputs(f2,fileptr);
            
        }  
         
    } 
/*    void display2()  
    {  
        struct node *ptr;  
        ptr = h;  
        if(ptr == NULL)  
        {  
            printf("Nothing to print");  
        }  
        else  
        {  
            printf("\nprinting values . . . . .\n");  
            while (ptr!=NULL)  
            {  
                printf("\nThe order of user id  %d is ready \n user id %d: ",ptr->userid,ptr->userid);  
                printf("\n Food 1:%s",ptr->foodname1);  
                printf("\n food 2:%s",ptr->foodname2);  
                ptr = ptr -> next;  
            }  
        }  
    }*/    

/*void display2()  
{
	struct node *ptr=h;
	while(ptr != NULL)
	{
		if(ptr->userid == final)
		{
			printf("%d",ptr ->userid);
			printf("%s",ptr ->foodname1);
			printf("%s",ptr ->foodname2);
		}
		ptr= ptr->next ;
	}
	
}*/
void display2()  
{
	struct node *ptr=h;
	
	while(ptr != NULL)
	{
		if(ptr->userid == final)
		{
			printf("\nThe order of user id  %d is ready \n user id %d: ",ptr->userid,ptr->userid);  
            printf("\n Food 1:%s",ptr->foodname1);  
            //printf("\n The amount %d",t1);
        	printf("\n food 2:%s",ptr->foodname2);  
        	//printf("\n The amount %d",t2);
        	//printf("\n The Total amount %d",t3);
		}
		ptr= ptr->next ;
	}
	printf("Order is not ready");
	
}

void beginsert3()  
    {  
        struct list *b;  
        b = (struct list *) malloc(sizeof(struct list *));  
        if(b == NULL)  
        {  
            printf("\nThe order list is full ");  
        }  
        
        else  
        {  
        
            printf("Enter the price ");
            scanf("%d",&price);
            b->price=price;
            
            printf(" \n Enter the food name ");
            scanf("%s",f);
            
            strcpy(b->name,f);
            
            a= b;  
            printf("\nNode inserted \n order is placed");  
        }  
         
    } 
   
   
    void display3()  
    {  
        struct list *b;  
        b = a;  
        if(b == NULL)  
        {  
            printf("Nothing to print");  
        }  
        else  
        {  
            printf("\nprinting values . . . . .\n");  
            while (b!=NULL)  
            {  
                printf("%d",price);
                printf("%s",b->name);
                break;
               // b = b -> next;  
            }  
        }  
    }

int  check(char str[20]){
    struct list *b=a;
	while(b != NULL)
	{
		if(strcmp(str,b->name)==0)
		{
		    printf("\n The food is present in the list ");
		    printf("\n Enter the quanity you need");
		    scanf("%d",&qty);
		    printf("\n The price %d",b->price);
		    temp=qty*price;
		    printf("\n The amount %d",temp);
		    return temp;
		    
		//	break;
		}
		//b= b->next ;
	}
	printf("Order is not ready");
	//return temp;
}
