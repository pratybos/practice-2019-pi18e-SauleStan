 #include <stdio.h>

int main()
{
	int a, b, c;
	int abc, a3b3c3;
	int count;

	count = 0;
  a = 0;
	b = 0;
	c = 0;
  
	while(1)
	{
		abc = a * 100 + b * 10 + c;
		a3b3c3 = a*a*a + b*b*b + c*c*c;

		if (abc > 999)
		{
			break;
		}

		if (abc == a3b3c3)
		{
			count = count + 1;
			printf("Armstrong number %d : %d\n", count, abc);
		}
    
		c++;
    
		if (c == 9)
		{
			c = 0;
			b++;
		}

		if (b == 9)
		{
			b = 0;
			a++;
		}
	}

	system("PAUSE");
	return 0;
}
