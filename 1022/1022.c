#include <stdio.h>

int main()
{
    int A, B, C, D;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    if((B > C) && (D > A)) //  B>C e C > D
    {
        if((C+D) > (A+B)) // C+D > A+B
        {
            if ( C > 0 && D > 0) // Ambos positivos
            {
                if ( A % 2 == 0) // Par
                {
                    printf("Valores aceitos\n");
                    return 0;
                }
            }
        }
    }
    
    printf("Valores nao aceitos\n");
    return 0;
}