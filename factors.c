#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <gmp.h>

/**
 * main - f
 * @argc: argc
 * @argv: argv
 * Return: int
*/
int main(int argc, char *argv[])
{
	mpz_t n, i, fact1, fact2;
	size_t cnt;
	__ssize_t l;
	char *line = NULL;
	FILE *f;

	(void)argc;
	mpz_inits(n, i, fact1, fact2, NULL);
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (1);
	while ((l = getline(&line, &cnt, f)) != -1)
	{
        mpz_set_str(n, line, 10);
        mpz_set_ui(fact1, 1);
        mpz_set_ui(fact2, 1);
		for (mpz_set_ui(i, 2); mpz_cmp(i, n) <= 0; mpz_add_ui(i, i, 1))
		{
            mpz_t rem;
            mpz_init(rem);
            mpz_mod(rem, n, i);
            if (mpz_cmp_ui(rem, 0) == 0)
            {
                mpz_set(fact1, i);
                mpz_tdiv_q(fact2, n, i);
                mpz_clear(rem);
                break;
            }
            mpz_clear(rem);
		}
		gmp_printf("%Zd=%Zd*%Zd\n", n, fact1, fact2);
	}
	mpz_clears(n, i, fact1, fact2, NULL);
	fclose(f);
	return (0);
}
