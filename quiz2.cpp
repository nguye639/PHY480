#include <cstdlib>
#include <cmath>
#include <complex>
#include <vector>


const double PI=4.0*atan(1.0);
const double HBARC=197.3269602;

using namespace std;

int main(int argc,char *argv[]){
	double dt=0.001;
	double t0=-2.0,tmax=10.0;
	double f0=2.0,F0=50.0,m=0.1,beta=3.0;
	int Nt=lrint((tmax-t0)/dt);
	double omega0=2.0*PI*f0,F,t;
	double omegaprime=sqrt(omega0*omega0-beta*beta);
	vector<double> x;
	x.resize(Nt+1);
	
	// First do method (c)
	
	x[0]=0.0;
	x[1]=0.5*dt*dt*F0/m;
	for(int it=1;it<Nt;it++){
		t=t0+it*dt;
		if(t<-1.0E-10){
			F=F0;
		}
		else if(t>1.0E-10){
			F=0.0;
		}
		else
			F=0.5*F0;
		x[it+1]=( (2.0-omega0*omega0*dt*dt)*x[it] +(-1.0+beta*dt)*x[it-1] + F*dt*dt/m) / (1.0+beta*dt);
	}
	
	// Now do method (a). For t>0, you can neglect the limits on the integrals,
	// and Ic and Is are independent of t
	double dtprime=0.0001,tprime;
	double Ica=0.0,Isa=0.0,Icb,Isb;
	for(tprime=t0+0.5*dtprime;tprime<0.0;tprime+=dtprime){
		Ica+=dtprime*F0*exp(beta*tprime)*cos(omegaprime*tprime);
		Isa+=dtprime*F0*exp(beta*tprime)*sin(omegaprime*tprime);
	}
	printf("Ica=%g, Isa=%g\n",Ica,Isa);
	// The analytica answers for Ic and Is for part b are:
	double ebt0=exp(beta*t0),cot0=cos(omegaprime*t0),sot0=sin(omegaprime*t0);
	Icb=(F0/(beta*beta+omegaprime*omegaprime))*( beta*(1.0-ebt0*cot0)
		-omegaprime*ebt0*sot0 );
	Isb=(F0/(beta*beta+omegaprime*omegaprime))*( -omegaprime*(1.0-ebt0*cot0) -beta*ebt0*sot0);
	printf("Icb=%g, Isb=%g\n",Icb,Isb);
	
	// Write to file, you can graph on your own
	FILE *fptr=fopen("green.dat","w");
	for(int it=0;it<=Nt;it+=50){
		t=t0+it*dt;
		if(t>-1.0E-5){
			fprintf(fptr,"%5.2f %11.5e %11.5e\n",
			t,x[it],(1.0/(m*omegaprime))*exp(-beta*t)*(Icb*sin(omegaprime*t)
				-Isb*cos(omegaprime*t)));
			printf("%5.2f %11.5e %11.5e\n",
			t,x[it],(1.0/(m*omegaprime))*exp(-beta*t)*(Icb*sin(omegaprime*t)
				-Isb*cos(omegaprime*t)));
		}
		fclose(fptr);
	}
	return 0;
}
