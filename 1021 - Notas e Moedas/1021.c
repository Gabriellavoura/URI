#include <stdio.h>

int main()
{
	int integer, decimal, mod, n1, n2, n3, n4, n5, n6;
	
	scanf("%d.%d", &integer, &decimal);

	n1 = integer / 100;
	mod = (integer % 100);
	
	n2 = mod / 50;
	mod = (mod % 50);
	
	n3 = mod / 20; 
	mod = (mod % 20); 
	
	n4 = mod / 10;
	mod = (mod % 10);
	
	n5 = mod / 5;
	mod = (mod % 5);
	
	n6 = mod / 2;
	mod = (mod % 2);

	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", n1);
	printf("%d nota(s) de R$ 50.00\n", n2);
	printf("%d nota(s) de R$ 20.00\n", n3);
	printf("%d nota(s) de R$ 10.00\n", n4);
	printf("%d nota(s) de R$ 5.00\n", n5);
	printf("%d nota(s) de R$ 2.00\n", n6);

	int m1, m2, m3, m4, m5, m6;

	m1 = mod / 1; // 1
	mod = (mod % 1); // 0
	
	m2 = decimal / 50; // 1
	mod = (decimal % 50); // 23
	
	m3 = mod / 25;  // 1
	mod = (mod % 25);  // 23
	
	m4 = mod / 10; // 2
	mod = (mod % 10);  // 3
	
	m5 = mod / 5; // 0
	mod = (mod % 5); // 3
	
	m6 = mod / 1; // 3

	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", m1);
	printf("%d moeda(s) de R$ 0.50\n", m2);
	printf("%d moeda(s) de R$ 0.25\n", m3);
	printf("%d moeda(s) de R$ 0.10\n", m4);
	printf("%d moeda(s) de R$ 0.05\n", m5);
	printf("%d moeda(s) de R$ 0.01\n", m6);
	

  // end
	return 0;
}
