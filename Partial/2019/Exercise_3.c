#include <stdio.h>

// Part 1
typedef struct{
    int group,individial,product;
    float necessity,packaging,acceptable_price,total;
} assesment;

// Part 2
void READ(assesment *A){
    printf("Reading grades for product of:\nGroup Number:%d\nIndividual Number:%d\nProduct Number:%d\n",A->group,A->individial,A->product);
    
    do{
        printf("Give this product a score out of 10 for it's necessity: ");
        scanf("%f",&A->necessity);  
    }while (A->necessity>10||A->necessity<0);

    do{
        printf("Give this product a score out of 10 for it's packaging: ");
        scanf("%f",&A->packaging); 
    }while (A->packaging>10||A->packaging<0); 

    do{
        printf("Give this product a score out of 10 for it's price: ");
        scanf("%f",&A->acceptable_price);  
    }while (A->acceptable_price>10||A->acceptable_price<0);

    A->total = (A->acceptable_price + A->necessity + A->packaging)/3;
    printf("\n");
}

// Part 3
void FILL(assesment A[120]) { // Here we have 6 groups, 5 individuals, 4 products so the max number of needed assesments is 6*5*4=120
    int i;
    int grp = 1;
    int ind = 1;
    int prod = 1;
    for (i = 0; i < 120 ; i++){
        if (ind == 6){
            ind = 1;
            prod++;
            if(prod == 5){
                prod = 1;
                grp++;
            }
        }
        A[i].individial = ind;
        A[i].group = grp;
        A[i].product = prod;
        READ(&A[i]);
        ind++;
    }
}

// Part 4
void CALCULATE_GROUP(assesment A[120], assesment B[20],int grp){ 
    int prod,i,offset = (grp-1)*4;
    float sum;
    for (prod=1;prod<5;prod++){
        sum=0;
        B[offset].group = grp;
        B[offset].product = prod;
        for (i=0;i<120;i++){
            if (A[i].group == grp && A[i].product == prod){
                sum += A[i].total;
            }
        }
        B[offset].total = total;
        offset++;
        
    }

}

// Part 5
void CALCULATE_PRODUCT(assesment A[24],assesment B[4]){
    int prod,i;
    float sum;
    for (i = 1; prod < 5; prod++){
        sum=0;
        for (i = 0; i < 24; i++){
            if(A[i].product == prod){
                sum += A[i].total;
            }
        }
        B[prod-1].product = prod;
        B[prod-1].total = sum;
        
    }
    
}


int main(void){
    return 0;

}