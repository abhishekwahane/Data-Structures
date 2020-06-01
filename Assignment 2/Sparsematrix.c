//203165
//Abhishek Wahane
//A4 Batch
//Sparse Matrix

#include<stdio.h>

void accept(int mat[10][10] ,int m ,int n )
{

    printf("Enter the elements ");
    for(int i=0; i<m ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int mat[10][10] ,int m ,int n)
{

    for(int i=0; i<m ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            printf(" %d " , mat[i][j]);
        }
        printf("\n");
    }
}

void compact(int mat[10][10] ,int m ,int n , int cmat[10][10])
{
    cmat[0][0]= m ;
    cmat[0][1]= n ;
    int k=1;
    for(int i=0; i<m ; i++)
        {
            for(int j=0; j<n ; j++)
            {
            if(mat[i][j]!=0)
            {
                cmat[k][0]= i ;
                cmat[k][1]= j ;
                cmat[k][2]= mat[i][j] ;
                k++;
            }
            }
        }

    cmat[0][2]= k-1;
    display( cmat , k , 3);
}


int simple_transpose(int cmat[10][10] , int ctmat[10][3] ,int m, int n )
{


 ctmat[0][0]=cmat[0][1];
 ctmat[0][1]=cmat[0][0];
 ctmat[0][2]=cmat[0][2];


 int q=1;
 for(int col=0 ; col<cmat[0][1] ; col ++)
 {
     for (int p=1 ; p<=cmat[0][2] ; p++)
     {

         if(cmat[p][1]==col)
         {
             ctmat[q][0]=cmat[p][1];
              ctmat[q][1]=cmat[p][0];
              ctmat[q][2]=cmat[p][2];

              q=q+1;
         }
     }
 }
 for(int i=0; i<q ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            printf(" %d " , ctmat[i][j]);
        }
        printf("\n");
    }

}

void fast_transpose (int cmat[10][10] , int ctmat[10][10])
{

    int s[20] , h[20], m, n, t;
    ctmat[0][0]=cmat[0][1];
     ctmat[0][1]=cmat[0][0];
     ctmat[0][2]=cmat[0][2];
m = cmat[0][0];
n =cmat[0][1];
t =cmat[0][2];
   for( int i=0 ; i< n ; i++ )
     {
    s[i]=0;
     }

     for( int i=1 ; i<= t ; i++ )
         {
        s[cmat[i][1]] = s[cmat[i][1]] +1 ;
         }

h[0]=1;

for( int i=1 ; i< n ; i++ )
     {
    h[i]=h[i-1] + s[i-1];
     }



for(int i=1 ; i<= t ; i++ )
     {
    int q = h[cmat[i][1]];
    ctmat[q][0]=cmat[i][1];
    ctmat[q][1]=cmat[i][0];
    ctmat[q][2]=cmat[i][2];
    h[cmat[i][1]]++;
     }


for(int i=0; i<t+1 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            printf(" %d " , ctmat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int m , n , mat[10][10] , choice , cmat[10][10] , ctmat[10][10];
printf("Enter the number of rows \n");
scanf("%d" , &m );
printf("Enter the number of columns \n");
scanf("%d" , &n );
do
{
printf("Choose: \n 1Accept \n 2Display \n 3Compact matrix \n 4Simple transpose \n 5Fast transpose  ");
printf("\nEnter your choice");
scanf("%d" , &choice);
switch(choice)
{
case 1:
accept(mat , m , n);
break ;
case 2 :
display(mat , m , n);
break ;

case 3 :
compact( mat , m , n ,  cmat);

break;
case 4:
	printf("The simple transpose matrix is:\n");

    simple_transpose( cmat ,ctmat, m , n  );
break ;

case 5 :
    printf("The fast transpose matrix is:\n");
    fast_transpose(cmat,ctmat);
    break;
}
}while(choice!=6);
return 0;
}

/*

OUTPUT:

Enter the number of rows 
3
Enter the number of columns 
2
Choose: 
 1Accept 
 2Display 
 3Compact matrix 
 4Simple transpose 
 5Fast transpose  
Enter your choice1
Enter the elements 2
4
6
8
6
4
Choose: 
 1Accept 
 2Display 
 3Compact matrix 
 4Simple transpose 
 5Fast transpose  
Enter your choice2
 2  4 
 6  8 
 6  4 
Choose: 
 1Accept 
 2Display 
 3Compact matrix 
 4Simple transpose 
 5Fast transpose  
Enter your choice3
 3  2  6 
 0  0  2 
 0  1  4 
 1  0  6 
 1  1  8 
 2  0  6 
 2  1  4 
Choose: 
 1Accept 
 2Display 
 3Compact matrix 
 4Simple transpose 
 5Fast transpose  
Enter your choice4
The simple transpose matrix is:
 2  3  6 
 0  0  2 
 0  1  6 
 0  2  6 
 1  0  4 
 1  1  8 
 1  2  4 
Choose: 
 1Accept 
 2Display 
 3Compact matrix 
 4Simple transpose 
 5Fast transpose  
Enter your choice5
The fast transpose matrix is:
 2  3  6 
 0  0  2 
 0  1  6 
 0  2  6 
 1  0  4 
 1  1  8 
 1  2  4 
 
*/
