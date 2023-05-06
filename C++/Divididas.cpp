#include <iostream>
#include <conio.h>

#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	int i, j;
	float A[5][6];
	
	cout<<"INtrducir cinc valores de x"<<endl;
	for (i=0; i<=4; i++)    //i es numer de fila 
	     { cout<<"A["<<i<<"][0]=";
		 cin>>A[i][0];	//intr os x
	     	
		 }
cout<<"INtrducir cinc valores de y"<<endl;
	for (j=0; j<=4; j++)    //j es numero de fila
	     { A[j][1]= cos(j); //complemar..llenar segunda columan de valores y
	      	 	
		 }

for (i=0; i<=4; i++)   
       {for (j=0; j<=1; j++) 
         cout<<A[i][j]<<" ";
         cout<<endl;
	   }
		 
//empezams armar a matriz
for (i=0; i<=4; i++)   
       for (j=2; j<=5; j++) 
	     { if ((i<j) && (i!=j-1)) A[i][j]=0;
	          else
		        A[i][j]=(A[i][j-1]-A[i-1][j-1])/( A[i][0]-A[i-j+1][0]); //complemar..llenar segunda columan de valores y


      }

// Imprimir la matriz A
for (i=0; i<=4; i++)   
       {for (j=0; j<=5; j++) 
         cout<<"   A["<<i<<"]["<<j<<"]="<<A[i][j];
         cout<<endl;
	   }
}



