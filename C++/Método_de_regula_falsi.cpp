#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main(){

 //Variables

 float f(float x);
 float x, a, b, x_ant, eps;
 int i=0;

 cout<<"Metodo de regula falsi"<<endl<<endl;

 //solicitar valores
 cout<<"Ingrese el valor del a del intervalo [a,b]: ";cin>>a;
 cout<<"\nIngrese el valor del b del intervalo [a,b]: ";cin>>b;
 cout<<"\nIngrese el valor de epsilon: ";cin>>eps;

 x=(a*f(b)-b*f(a))/(f(b)-f(a));

 //iteraciones
 do{
   if ((f(a)*f(x))<0){
     b=x;
   }
   else if ((f(a)*f(x))>0){
     a=x;
   }
   x_ant=x;
   x=(a*f(b)-b*f(a))/(f(b)-f(a));
   i++;
   cout<<"Iteracion "<<i<<", la raiz aproximada es: "<<x<<endl;
 }while(fabs(x-x_ant)>=eps);

 //Salida de resultadooooos

 cout<<"\nLa cantidad de iteraciones que se realizaron es: "<<i<<endl<<endl;
 cout<<"La raiz es igual a "<<x<<endl;

  getch ();
  return 0;
}

float f(float x){
  float y=exp(-(pow(x,2)))-cos(x);
  return y;
}
