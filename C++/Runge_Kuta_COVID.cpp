#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

//Trabajo final sobre estadísticas de COVID19 - Modelo SEIIRD

//Empezamos declarando las variables con los valores y unidades que vamos a usar 

//Población susceptible (S), individuos sin inmunidad al agente infeccioso (virus), y que por tanto puede ser infectada si es expuesta al agente infeccioso.
//Población expuesta (E), individuos infectado pero que aún no tienen la capacidad de infectar a los demás.
//Población infectada (I), individuos que están infectados en un momento dado y pueden transmitir la infección a individuos de la población susceptible con la que entran en contacto.Estos se dividen en infectados sintomáticos (I_s) e infectados asintomáticos (I_a) que son menos infecciosos que los sintomáticos
//Población recuperada (R), individuos que se recuperaron después de estar infectados
//Población fallecida (D) (por sus siglas en inglés) son los individuos que no lograron superar la enfermedad.

//Aquí se declara el sistema de ecuaciones diferenciales que define el modelo

long double dS_t(int t, float S_t, float Ia, float Is);
long double dE(int t, float S_t, float Ia, float Is, float E_t);
long double dIa(int t, float E_t, float Ia);
long double dIs(int t, float E_t, float Is);
long double dR(int t, float Is, float Ia);
long double dD(int t, float Is);


int main(){
	
	long double S_t, E_t, Ia, Is, R, N, D;


	//Número total de personas en el día 0 (Estos son los valores iniciales de las ecuaciones diferenciales. Valores conocidos)

	S_t = 9000000; //Número total de la población.
	E_t = 5368.44; //Número inicial de personas expuestas.
	Ia = 1400.0; //Número inicial de personas infectadas asintomáticas.
	Is = 140.0;  //Número inicial de personas infectadas sintomáticas.
	R = 3.486; //Es el número básico reproductivo. Es el número de nuevos infectados producidos por un infectado si toda la población es susceptible
	//R_0 = Beta/u. Si R_0 < 1 entonces la pandemia está controlada.
	D = 0.0; //Numero de muertes en el día 0
	
	
	//Aquí definimos unas listas vacías (vectores en C++) para guardar los datos obtenidos en las iteraciones para poder graficar. El número de listas será el numero de ecuaciones diferenciales que tenemos mas la lista del eje de las x, que en este caso serán los intervalos de tiempo desde cero hasta 366.

	vector<int> Lista_t; //Lista para el eje x. Este es el eje del tiempo.
	vector<float> Lista_S; //Lista para valores de S_t
	vector<float> Lista_E; //Lista para valores de E
	vector<float> Lista_Ia; //Lista para valores de Ia
	vector<float> Lista_Is; //Lista para valores de Is
	vector<float> Lista_R; //Lista para valores de R
	vector<float> Lista_D; //Lista para valores de D
	
	//Aquí declaramos el bloque de código (bucles for) para cada una de las ecuaciones diferenciales para hallar su solución
 
int Iteraciones = 366; //Esta variable nos dice el numero de iteraciones que haremos en el método numérico para hallar la solución de la ecuación diferencial. En este caso, vamos a usar 366, que es el numero de días que se nos pidió usar.
int a = 0; //Cota inferior del intervalo que vamos a usar. En este caso, el intervalo son los días del año. Los días empiezan en el día 0. 
int b = 366; //Cota superior del intervalo. Es el número de días del año.
int h = (b - a)/Iteraciones;

int t = a;

int i;

for(i = 0; i <= Iteraciones; i++){
    
    Lista_t.push_back(i); //Aquí se agrega a la lista el elemento i, que en este caso serán los valores del tiempo en cada iteración.
    Lista_S.push_back(S_t); //Aquí se agrega el valor de S_t iterado.
    Lista_E.push_back(E_t); //Aquí se agrega el valor de E_t iterado.
    Lista_Ia.push_back(Ia); //Aquí se agrega el valor Ia iterado.
    Lista_Is.push_back(Is); //Aquí se agrega el valor Is iterado.
    Lista_R.push_back(R); //Aquí se agrega el valor R iterado.
    Lista_D.push_back(D); //Aquí se agrega el valor D iterado.

	cout <<"Dia = "<<i<<"\t"<<"S = "<<S_t<<"\t"<<"E = "<<E_t<<"\t"<<"I_a = "<<Ia<<"\t"<<"Is = "<<Is<<"\t"<<"R = "<<R<<"\t"<<"D = "<<D<<endl;
    
	float S_1 = dS_t(t,S_t,Ia,Is);
    float E_1 = dE(t,S_t,Ia,Is,E_t);
    float Ia_1 = dIa(t,E_t,Ia);
    float Is_1 = dIs(t,E_t,Is);
    float R_1 = dR(t,Is,Ia);
    float D_1 = dD(t,Is);
        
	float S_2 = dS_t(t + h*0.5, S_t + (h*0.5)*S_1, Ia + (h*0.5)*Ia_1, Is + (h*0.5)*Is_1);
    float E_2 = dE(t + h*0.5, S_t + (h*0.5)*S_1, Ia + (h*0.5)*Ia_1, Is + (h*0.5)*Is_1, E_t + (h*0.5)*E_1);
    float Ia_2 = dIa(t + h*0.5, E_t + (h*0.5)*E_1, Ia + (h*0.5)*Ia_1);
    float Is_2 = dIs(t + h*0.5, E_t + (h*0.5)*E_1, Is + (h*0.5)*Is_1);
    float R_2 = dR(t + h*0.5, Is + (h*0.5)*Is_1, Ia + (h*0.5)*Ia_1);
    float D_2 = dD(t + h*0.5, Is + (h*0.5)*Is_1);
    
    float S_3 = dS_t(t + h*0.5, S_t + (h*0.5)*S_2, Ia + (h*0.5)*Ia_2, Is + (h*0.5)*Is_2);
    float E_3 = dE(t + h*0.5, S_t + (h*0.5)*S_2, Ia + (h*0.5)*Ia_2, Is + (h*0.5)*Is_2, E_t + (h*0.5)*E_2);
    float Ia_3 = dIa(t + h*0.5, E_t + (h*0.5)*E_2, Ia + (h*0.5)*Ia_2);
    float Is_3 = dIs(t + h*0.5, E_t + (h*0.5)*E_2, Is + (h*0.5)*Is_2);
    float R_3 = dR(t + h*0.5, Is + (h*0.5)*Is_2, Ia + (h*0.5)*Ia_2);
    float D_3 = dD(t + h*0.5, Is + (h*0.5)*Is_2);
    
    float S_4 = dS_t(t + h, S_t + (h)*S_3, Ia + (h)*Ia_3, Is + (h)*Is_3);
    float E_4 = dE(t + h, S_t + (h)*S_3, Ia + (h)*Ia_3, Is + (h)*Is_3, E_t + (h)*E_3);
    float Ia_4 = dIa(t + h, E_t + (h)*E_3, Ia + (h)*Ia_3);
    float Is_4 = dIs(t + h, E_t + (h)*E_3, Is + (h)*Is_3);
    float R_4 = dR(t + h, Is + (h)*Is_3, Ia + (h)*Ia_3);
    float D_4 = dD(t + h, Is + (h)*Is_3);
    
    
    S_t = S_t + (h*(S_1 + 2*S_2 + 2*S_3 + S_4)/6);
    E_t = E_t + (h*(E_1 + 2*E_2 + 2*E_3 + E_4)/6);
    Ia = Ia + (h*(Ia_1 + 2*Ia_2 + 2*Ia_3 + Ia_4)/6);
    Is = Is + (h*(Is_1 + 2*Is_2 + 2*Is_3 + Is_4)/6);
    R = R + (h*(R_1 + 2*R_2 + 2*R_3 + R_4)/6);
    D = D + (h*(D_1 + 2*D_2 + 2*D_3 + D_4)/6);
    
    t = a + i*h;
	
	}
	
	return 0;
}

//Definición de las ecuaciones diferenciales del modelo.

long double dS_t(int t, float S_t, float Ia, float Is){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	Beta = 0.166; //1/días //Es la tasa de contagio o transmisión (Agresividad de virus, alimentación, protección, inmunidad de la población)
	r_b = 0.5; //N/A 
	epsilon = 0.2; //1/días //Es la tasa de exposición (supuestamente esas personas que no contagian)
	p_a = 0.8; //probabilidad: N/A #Fracción de las personas que van a ser asintomáticas #(1 - p_a) es la fracción de las personas que van a ser sintomáticas.
	u = 0.04761; //1/días //tasa de recuperación (Tratamientos, tipos de virus, defensas, población) #El periodo medio de recuperación es 1/u
	p_d = 0.03; //probabilidad: N/A //Es la fracción de casos sintomáticos que mueren.
	N = 9000000.0; //Notese que S = N 
	long double Valor = -(Beta*r_b*S_t*(Ia/N) + Beta*S_t*(Is/N));
    return Valor;	
}

long double dE(int t, float S_t, float Ia, float Is, float E_t){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	Beta = 0.166;
	r_b = 0.5;
	epsilon = 0.2;
	p_a = 0.8; 
	u = 0.04761;
	p_d = 0.03;
	N = 9000000.0; 
	long double Valor = Beta*r_b*S_t*(Ia/N) + Beta*S_t*(Is/N) - (epsilon*p_a*E_t + epsilon*(1 - p_a)*E_t);
    return Valor;

}

long double dIa(int t, float E_t, float Ia){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	Beta = 0.166;
	r_b = 0.5;
	epsilon = 0.2;
	p_a = 0.8;
	u = 0.04761;
	p_d = 0.03;
	N = 9000000.0; 
	long double Valor = epsilon*p_a*E_t - u*Ia;
    return Valor;
}

long double dIs(int t, float E_t, float Is){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	Beta = 0.166;
	r_b = 0.5; 
	epsilon = 0.2;
	p_a = 0.8;
	u = 0.04761;
	p_d = 0.03;
	N = 9000000.0; 
	long double Valor = epsilon*(1 - p_a)*E_t - u*(1 - p_d)*Is - u*p_d*Is;
    return Valor;
}

long double dR(int t, float Is, float Ia){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	Beta = 0.166;
	r_b = 0.5;
	epsilon = 0.2;
	p_a = 0.8;
	u = 0.04761;
	p_d = 0.03;
	N = 9000000.0; 

	long double Valor = u*(1 - p_d)*Is + u*Ia;
    return Valor;
}

long double dD(int t, float Is){
	float Beta, r_b, epsilon, p_a, u, p_d,N;
	
	p_a = 0.8;
	u = 0.04761;
	p_d = 0.03;
	
	long double Valor = u*p_d*Is;
    return Valor;
}