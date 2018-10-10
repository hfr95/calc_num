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

double function_zero(double t){
	return 1 - 7*exp(-0.88*t);
  //return 1.94591014906-0.88*t;//9-(9-2)*e^(-0.88t) -> ln(1-7*e^(-0.88*t))=0 -> ln(7) + (-0.88t)=0
}

double derivative_zero(double t){
  return 0.88*7*exp(-0.88*t);
  //return -0.88;
}
 	
double derivative(double x){
	double cs=9.0;
	double c0=2.0;
	double ka=0.88;
	double t=x;

	return (ka)*(cs-c0)*exp(-ka*t);
}

double newton_raphson_core(double x0){
	double x1=0;
    x1=x0 - function_zero(x0)/derivative_zero(x0);
	return x1;	
}

double newton_raphson(double x0, double tolerance){
	double x1=0;
	double error=tolerance * 2;	
	int iteration=0;
    
	while( error > tolerance && iteration < MAX_ITERATIONS ){
		x1=newton_raphson_core(x0);
		error=fabs(x1-x0);
        printf("x0:%lf. x1:%lf. erro:%lf.funcao %lf\n",x0,x1,error,function(x1));
		x0=x1;
		iteration++;
	}
	
	if(iteration >= MAX_ITERATIONS){
	  printf("Não ficou dentro da tolerância de erro em %d iterações.\n", MAX_ITERATIONS);
    }
    
    return x1;
}

int main(int argc, char** argv){

  printf("\nt = 1 dia\n");
  printf("resultado = %lf\n\n", newton_raphson(1.0, 10E-6));
  printf("t = 5 dias\n");
  printf("resultado = %lf\n\n", newton_raphson(5.0, 10E-6));
  printf("t = 10 dias\n");
  printf("resultado = %lf\n\n", newton_raphson(10.0, 10E-6));
	
}
