#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main (){
 //Variables
 float f(float x), df;
 float x_1, eps, x_0, x_00;
 int i=0;

 cout<<"Metodo de la secante"<<endl<<endl;
 //Entrada de datos
 cout<<"Ingrese el valor de x_0: ";cin>>x_0;
 cout<<"Ingrese el valor de x_1: ";cin>>x_1;
 cout<<"Ingrese el valor de epsilon: ";cin>>eps;cout<<endl;

//iteraciones
 do{
  x_00=x_0;
  f(x_1); f(x_0);
  df=((f(x_1)-f(x_0))/(x_1-x_0));
  x_0=x_1;
  x_1=x_00-(f(x_00)/df);
  i++;
  cout<<"Iteracion numero "<<i<<", la raiz aproximada es: "<<x_1<<endl;
  }while(fabs((x_1-x_0))>=eps); //criterio de parada

  //resultadooooos
  cout<<"\nEl numero de iteraciones realizadas fue "<<i<<endl;
  cout<<"La raiz es igual a "<<x_1<<endl;

  getch ();
  return 0;
}
  float f(float x){
  float y=pow(x,3)-5*pow(x,2)+ 3*x -7;
  return y;
 }
