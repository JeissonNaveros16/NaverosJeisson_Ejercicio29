#include <iostream>
#include <cmath>
using namespace std;

// variable constantes globales
const double D = 1.0;
const int Nx = 30;
const double DeltaX = 2/(double(Nx)-1);

// declaracion de funciones
void avance(double *p, double deltaT);
void imprimir(double *p, double *x, double t);

int main(int argc, char **argv)
{
	double DeltaT;
	if(atoi(argv[1]) == 1)
		DeltaT = DeltaX*DeltaX/4;
	else
		DeltaT = 0.0001;
    
    double time;
    
    //Espacio
	double *x = new double[Nx];
    
    for(int i = 0; i<Nx; i++)
    {
        *(x+i) = -1.0 + double(i)*DeltaX;
    }
    
    //Función objetivo phi.
	double *p = new double[Nx];
	
    //double *p1 = NULL;
    //p1 = new double[Nx];
    //double *p = p1;
    
    for(int i = 0; i<Nx; i++)
    {
        *(p+i) = 0.0;
    }
	
    for(time = 0; time <= 1; time += DeltaT)
    {
		imprimir(p, x, time);
        avance(p, DeltaT);
    }
    
    delete[] x;
	delete[] p;
    
    return 0;
}

void avance(double *p, double deltaT)
{
    for(int i = 0; i<Nx; i++)
    {
        double act = *(p+i);
        if( i == 0 )
        {
            double sig = *(p+i+1);
            double temp = act + (D*deltaT/(DeltaX*DeltaX))*(-2.0*act + sig) + deltaT;
            *(p+i) = temp;
        }
        else if( i == Nx-1 )
        {
            double ant = *(p+i-1);
            double temp = act + (D*deltaT/(DeltaX*DeltaX))*(ant - 2.0*act) + deltaT;
            *(p+i) = temp;
        }
        else
        {
            double ant = *(p+i-1);
            double sig = *(p+i+1);
            double temp = act + (D*deltaT/(DeltaX*DeltaX))*(ant - 2.0*act + sig) + deltaT;
            *(p+i) = temp;
        }
    }
}

void imprimir(double *p, double *x, double t)
{
    for(int i = 0; i<Nx; i++)
    {
        cout << t << "\t" << *(x+i) << "\t" << *(p+i) << endl;
    }
}