//203165
//Abhishek Wahane
//A4 Batch
//Pizza delivery - Queue

#include <stdio.h>
#include <stdlib.h>
struct Pizza                                      //Creating a structure named pizza
{
    int ID,qty;
    char name[20];
    char address[30];
};
struct Pizza p[3];                                //Declaring necessary variables
int rear=-1;
int front=-1;
int ID=1;
int is_empty()                                    //Function to check if queue is empty
{
    if(rear==front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_full()                                      //Function to check if queue is full
{
    if(rear==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void place_order()                                    //Accepting data in queue
{
    if(is_full()==0)
    {
        rear++;
        p[rear].ID=ID++;
        printf("\nEnter name:");
        scanf("%s",p[rear].name);
        printf("\nEnter address:");
        scanf("%s",p[rear].address);
        printf("\nEnter quantity:");
        scanf("%d",&p[rear].qty);
    }
    else
    {
        printf("\nOrder is full!!");
    }
}
void dispatch_order()                                //Removing an element from queue
{
    if(is_empty()==0)
    {
        front++;
        printf("\nThe dispatched order is: ");
        printf("\nID: %d",p[front].ID);
        printf("\nNAME: %s",p[front].name);
        printf("\nADDRESS: %s",p[front].address);
        printf("\nQUANTITY: %d",p[front].qty);
    }
    else
    {
        printf("\nNo more orders to be dispatched!!");
    }
}
void display()                                        //Displaying the queue
{
    printf("\nThe pending orders are: ");
    for(int i=front+1;i<=rear;i++)
    {
        printf("\nID: %d",p[i].ID);
        printf("\nNAME: %s",p[i].name);
        printf("\nADDRESS: %s",p[i].address);
        printf("\nQUANTITY: %d",p[i].qty);
    }
}

int main()
{
    int c;
    do
    {
        printf("\nMenu:");                             
        printf("\n1.Place order \n2.Dispatch order \n3.Display pending orders \n4.EXIT");
        printf("\nEnter choice");
        scanf("%d",&c);
        switch(c)
        {
        case 1: place_order();
                break;
        case 2: dispatch_order();
                break;
        case 3: display();
                break;
        case 4: return 0;
                break;
        default: return EXIT_SUCCESS;
        }
    }
    while(c<4);
}


/*

OUTPUT:


Menu:
1.Place order 
2.Dispatch order 
3.Display pending orders 
4.EXIT
Enter choice1

Enter name:Abhishek

Enter address:Kothrud

Enter quantity:2

Menu:
1.Place order 
2.Dispatch order 
3.Display pending orders 
4.EXIT
Enter choice3

The pending orders are: 
ID: 1
NAME: Abhishek
ADDRESS: Kothrud
QUANTITY: 2
Menu:
1.Place order 
2.Dispatch order 
3.Display pending orders 
4.EXIT
Enter choice2

The dispatched order is: 
ID: 1
NAME: Abhishek
ADDRESS: Kothrud
QUANTITY: 2
Menu:
1.Place order 
2.Dispatch order 
3.Display pending orders 
4.EXIT
Enter choice4


*/
