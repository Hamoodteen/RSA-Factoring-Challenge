#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/**
 * is_prime - prime
 * @n: num
 * Return: 1, 0
 */
int is_prime(unsigned long long int n)
{
	if (n <= 1)
		return (0);
	if (n <= 3)
		return (1);
	if ((n % 2 == 0) || (n % 3 == 0))
		return (0);
	for (unsigned long long int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
	}
	return (1);
}

/**
 * main - f
 * @argc: argc
 * @argv: argv
 * Return: int
*/
int main(int argc, char *argv[])
{
	unsigned long long int n, i, fact1 = 1, fact2 = 1;
	size_t cnt;
	__ssize_t l;
	char *line = NULL;
	FILE *f;

	(void)argc;
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (1);
	while ((l = getline(&line, &cnt, f)) != -1)
	{
		n = atoll(line);
		for (i = 2; i <= sqrt(n); i++)
		{
			if ((n % i == 0) && (is_prime(i)) && (is_prime(n / i)))
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
