/*
 * Copyright (c) 2020 Murilo Ijanc' <mbsd@m0x.ru>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include "docbr.h"

int
cnpj_isvalid(int *cnpj) 
{
	int 	digito1 = 0; 
	int	digito2 = 0; 
	int	i;
	int 	soma1 = 0;
	int 	soma2 = 0;
	int 	multiplicadores[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

	for (i = 0; i < 12; i++)
		soma1 += (cnpj[i] * multiplicadores[i+1]);
	for (i = 0; i < 13; i++)
		soma2 += (cnpj[i] * multiplicadores[i]);

	digito1 = 11 - (soma1 % 11);
	digito2 = 11 - (soma2 % 11);

	digito1 >= 10 ? digito1 = 0 : digito1;
	digito2 >= 10 ? digito2 = 0 : digito1;

	if (cnpj[12] != digito1 || cnpj[13] != digito2)
		return (-1);
	return (0);
}

int
cpf_isvalid(int *cpf) 
{
	int 	digito1 = 0; 
	int	digito2 = 0; 
	int	i;
	int 	soma1 = 0;
	int 	soma2 = 0;
	int 	multiplicadores[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

	for (i = 0; i < 9; i++)
		soma1 += (cpf[i] * multiplicadores[i+1]);
	for (i = 0; i < 10; i++)
		soma2 += (cpf[i] * multiplicadores[i]);

	digito1 = 11 - (soma1 % 11);
	digito2 = 11 - (soma2 % 11);

	digito1 >= 10 ? digito1 = 0 : digito1;
	digito2 >= 10 ? digito2 = 0 : digito1;

	if (cpf[9] != digito1 || cpf[10] != digito2)
		return (-1);
	return (0);
}
