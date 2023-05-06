#include<iostream>
#include<math.h>
#include<locale.h>

using namespace std;

int main(){
	setlocale(LC_CTYPE, "Spanish"); //Tildes y ñ
	float f(float x);
	float eps, x, a, b, z, x_ant; //Declarando variables
	int i=0;

	cout<<"Metodo de Biseccion"<<endl<<endl;

	//solicitar valores de entrada

	cout<<"ingrese a de su intervalo [a,b]: ";cin>>a;
	cout<<"ingrese b de su intervalo [a,b]: ";cin>>b;
	cout<<"ingrese el valor de epsilon: ";cin>>eps;
	cout<<endl<<endl;

	x=(a+b)/2;

	//bucle - iteración

	do{
		f(a); f(x);
		z=f(a)*f(x);
	 	if(z<0){
	 		b=x;
		}
		else if(z>0){
			a=x;
		}
		x_ant=x;
		x=(a+b)/2;
		i++;
		cout<<"Iteracion "<<i<<", la raiz aproximada es: "<<x<<endl;

	}while(fabs(x-x_ant)>=eps);

	//Salida de resultadooooos

	cout<<"\nLa cantidad de iteraciones que se realizaron es: "<<i<<endl;
	cout<<"La raiz es igual a "<<x<<endl;

	return 0;

}

float f(float x){

	float y= exp(2*x)+(3*x)-4;
	return y;
}
