#include <stdio.h>

int main()
{
    int qtd, resto;
    int n1, d1, n2, d2, num, den, num1, num2;
    char opr;

    scanf("%d", &qtd);

    while(qtd > 0)
    {
        scanf("%d / %d %c %d / %d", &n1, &d1, &opr, &n2, &d2);

        if(opr == '+')
        {
            num = (n1*d2 + n2*d1);
            den = (d1*d2);
        }
        if(opr == '-')
        {
            num = (n1*d2 - n2*d1);
            den = (d1*d2);
        }
        if(opr == '*')
        {
            num = (n1*n2);
            den = (d1*d2);
        }
        if(opr == '/')
        {
            num = (n1*d2);
            den = (n2*d1);
        }
        num1 = num;
        num2 = den;

        if(num1<0)
        {
		    num1 = -num1;
        }
        if(num2<0)
        {
            num2 = -num2;
        }

        do {
            resto = num1 % num2;
            num1 = num2;
            num2 = resto;
        }while(resto != 0);
        
        printf("%d/%d = %d/%d\n", num, den, num/num1, den/num1);

        qtd--;
    }

    return 0;
}