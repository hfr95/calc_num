#include <stdio.h>
#include <math.h>
#define MAX_ITERATIONS 100
double function(double x){
	double cs=9.0;
	double c0=2.0;
	double ka=0.88;
	double t=x;

	return cs-(cs-c0)*exp(-ka*t);
}
 	
double derivative(double x){
	double cs=9.0;
	double c0=2.0;
	double ka=0.88;
	double t=1;

	return -(-ka)*(cs-c0)*exp(-ka*t);
}

double newton_raphson_core(double x0){
	


	double x1=0;
	x1=x0-(function(x0))/(derivative(x0));
	return x1;	
}

double newton_raphson(double x0, double tolerance){
	double x1=0;
	double error=0;	
	int iteration=0;
	while(error<tolerance&&iteration<MAX_ITERATIONS){
		x1=newton_raphson_core(x0);
		error=x1-x0;
		x0=x1;
		x1=0;
		iteration++;
	}	
}

int main(int argc, char** argv){
	printf("%lf", derivative(1.0));
	
}
