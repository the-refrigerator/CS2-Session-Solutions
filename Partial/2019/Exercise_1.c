#include <stdio.h>

// Part 1
float ABS(float x){
    if (x>=0){
        return x;
    }
    return -1*x;
}

// Part 2
float POW(float X, int Y){
    int i;
    float prod = 1;
    for (i = 0; i < Y; i++){
        prod = prod*X;
    }
    return prod;

}

// Part 3
float SQRT(float A){
    float un1 = 1;
    float un = 0.5*((A/un1) + un1);
    do{
        un1=un;
        un = 0.5*((A/un1) + un1);
    } while (ABS(un-un1) > 0.00001);

    return un;
}

// Part 4
int QUAD (float a,float b,float c,float *x1,float *x2){
    int roots;
    float delta = POW(b,2)-4*a*c;

    if (delta < 0) roots = 0;
    else if (delta == 0) { 
        roots = 1;
        *x1 = (-b)/(2*a);
        *x2 = (-b)/(2*a);
    }
    else {
        roots = 2; 
        *x1=(-b+SQRT(delta))/(2*a);
        *x2=(-b-SQRT(delta))/(2*a); 
    }
    return roots;
}

// Part 5
int main(void){
    float a = 1,b = 0,c = -1,x1,x2;
    printf("Enter the coefficients of the quadratic equation:");
    scanf("%f%f%f",&a,&b,&c);
    int roots = QUAD(a,b,c,&x1,&x2);

    if (roots == 2) printf("We have 2 solutions:\nx1 = %f\nx2 = %f\n",x1,x2);
    else if (roots == 1) printf("We have one solution:\nx = %f\n",x1);
    else printf("There are no solutions\n");
    
    return 0;
}