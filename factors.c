#include <stdio.h>
#include <stdlib.h>

/**
 * main - f
 * @argc: argc
 * @argv: argv
 * Return: int
*/
int main(int argc, char *argv[])
{
	unsigned long long int n, i, fact1 = 1, fact2 = 1;
	char line[1024];
	FILE *f;

	(void)argc;
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (1);
	while (fgets(line, sizeof(line), f) != NULL)
	{
		n = atoll(line);
		for (i = 2; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				fact1 = i;
				fact2 = n / i;
				break;
			}
		}
		printf("%llu=%llu*%llu\n", n, fact2, fact1);
	}
	fclose(f);
	return (0);
}
