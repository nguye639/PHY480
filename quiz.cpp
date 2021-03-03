#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


double F(double t)
{ 
    if (-2 < t and t < 0)
    { 
        double F0=50;
        return F0;
    }
    return 0;
}

int main()
{
    ofstream output;
    output.open("quiz.dat");

    const int Ntsteps= 100;
    double x[Ntsteps+1], dt=.01 ,k= 1.6*M_PI*M_PI, m=.1, b=3, v0=0;
    x[0] = 0.0;
    x[1] = v0*dt-0.5*b*v0/m;
    output << 0 << "    " <<  x[0]<< endl;
    output << 1 << "    " <<  x[1]<< endl;


	for(int it=1; it < Ntsteps; it++)
	{
	    x[it+1] = ((2.0*m/(dt*dt))-k)*x[it] + F(it*dt-2) +( (0.5*b/dt)*x[it-1]) / (m/(dt*dt) + 0.5*b/dt);
	    output << it + 1 << "    " <<  x[it+1]<< endl;
	    
	}

    cout << x[Ntsteps];
    output.close();

    return 0;
}

