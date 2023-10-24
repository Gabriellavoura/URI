#include <stdio.h>

int main()
{
    float A, B, C, temp;
    scanf("%f %f %f", &A, &B, &C);

    if (A < B){
        temp = A;
        A = B;
        B = temp;
    }
    if (B < C){
        temp = B;
        B = C;
        C = temp;
    }
    if (A < B){
       temp = A;
       A = B;
       B = temp;
    }

    if (A >= (B+C)){
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    
    float A2, B2, C2;

    A2 = A*A;
    B2 = B*B;
    C2 = C*C;

    if (A2 == (B2+C2)){
        printf("TRIANGULO RETANGULO\n");
        return 0;
    }
    if (A2 > (B2+C2)) {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if (A2 < (B2+C2)){
        printf("TRIANGULO ACUTANGULO\n");
    }

    if (A == B && B == C){
        printf("TRIANGULO EQUILATERO\n");
        return 0;
    }
    if((A == B && B != C) || (B == C && A != C)){
        printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}
