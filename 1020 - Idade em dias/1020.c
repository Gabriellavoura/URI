#include <stdio.h>

int main()
{

	int value, days, month, years;
	
	scanf("%d", &value);

	years = value / 365;
	month = (value % 365) / 30;
	days =  (value % 365) % 30;

	printf("%d ano(s)\n", years);
	printf("%d mes(es)\n", month);
	printf("%d dia(s)\n", days);

	
	  // end
	  return 0;
}
