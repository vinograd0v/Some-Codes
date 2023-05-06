
#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

int main (){
//variables
    float v(float x);
    float f(float x);
    float x, a, b, x_ant, eps, w, z;
    int i=0;
cout<<"Metodo del punto fijo"<<endl<<endl;
//Entrada de valores
cout<<"Ingrese a del intervalo [a,b]: ";cin>>a;
cout<<"Ingrese b del intervalo [a,b]: ";cin>>b;
cout<<"Ingrese el valor de epsilon: ";cin>>eps;

x=(a+b)/2;
z=v(x);
//Verificación de convergercia
if ((abs(z))<1) {
  do{
    x_ant=x;
    x=f(x);
    i++;
    cout<<"Iteracion "<<i<<", la raiz aproximada es :"<<x<<endl;
    w=x-x_ant;
  }while (fabs(w)>=eps);
}
else{
  cout<<"El método no converge, verifique el intervalo"<<endl;
}
  return 0;
}

//Función

float f(float x){
  float y=cos(x);
  return y;
}
float v(float x){
  float dy=-sin(x);
  return dy;
}
