#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;


int main()

{ //declarar las variables
 int i=0;
 long double eps, x, f, der, a, x1, f1; // x1 es x anterir y f1 su valor de funcion
 
 
 //pedir x, eps
    cout<<"Introduzca punto inicial ";
    cin>>x;
    cout<<endl;

    cout<<"Introduzca la tolerancia para el criterio de parada:  eps=  ";
    cin>>eps;
       cout<<endl;
 
 //empiezan iteraciones Grandes
 f=(x*x)-11;
 while(i<5)
 {i++;
 a=1;
 f1=f;	
 der=2*x;
 x1=x;
 Eti: x=x-(a*f/der);

      cout<<"x1= "<<x1<<"\t"<<"f(x)= "<<f<<"\t"<<"df= "<<der<<"\t"<<"x= "<<x<<"\t"<<"a= "<<a<<endl;
      f=pow(x,2)-11;	
       if (fabs(f)>fabs(f1))
          {x=x1;
           f=f1;
           a=0.5*a;
           goto Eti;
	
   
   }
 
  	
 }
//imprimir x, numero iteracines y fx		
printf("Solucion es x= %f\n", x);
printf("Total hicimos %d iteraciones\n", i);
    getch();	
	
	
	
}
