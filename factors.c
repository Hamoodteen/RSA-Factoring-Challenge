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
	size_t n, i, fact1 = 1, fact2 = 2;
	char line[256];
	FILE *f;

	(void)argc;
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (1);
	while (fgets(line, sizeof(line), f) != NULL)
	{
		n = atoi(line);
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				fact1 = i;
				fact2 = n / i;
				break;
			}
		}
		printf("%s=%zu*%zu\n", line, fact1, fact2);
	}
	fclose(f);
	return (0);
}
