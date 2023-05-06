#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main (){
 //Variables
 float f(float x), df(float x);
 float x, eps, x_ant;
 int i;

 cout<<"Metodo de Newton"<<endl<<endl;
 //Entrada de datos
 cout<<"Ingrese el valor de x: ";cin>>x;
 cout<<"Ingrese el valor de epsilon: ";cin>>eps;cout<<endl;

//iteraciones
 do{
  f(x);
  x_ant=x;
  x=x_ant-(f(x)/df(x));
  i++;
  cout<<"Iteracion numero "<<i<<", la raiz aproximada es: "<<x<<endl;
  }while(fabs((x-x_ant))>=eps);

  //resultadooooos
  cout<<"\nEl numero de iteraciones realizadas fue "<<i<<endl;
  cout<<"La raiz es igual a "<<x<<endl;

  getch ();
  return 0;
}

 float f(float x){
  float y=exp(2*x)+3*x-4;
  return y;
 }

 float df(float x){
    float dy=2*exp(2*x)+3;
    return dy;
 }
