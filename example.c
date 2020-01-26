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
#include <stdio.h>
#include <string.h>

#include "docbr.h"


static int invalid_cpf[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1};
static int valid_cpf[11] = {5, 9, 5, 9, 9, 2, 4, 9, 1, 9, 4};
static int invalid_cnpj[14] = {5, 2, 4, 7, 2, 7, 7, 1, 0, 0, 0, 1, 8, 1};
static int valid_cnpj[14] = {5, 2, 4, 7, 2, 7, 7, 1, 0, 0, 0, 1, 8, 5};
static int invalid_ddd = 100;
static int valid_ddd = 16;

int
main(int argc, char *argv[])
{
	int status = 0;

	if ((status = cpf_isvalid(invalid_cpf)) == -1)
		printf("CPF is invalid\n");
	if  ((status = cpf_isvalid(valid_cpf)) != -1)
		printf("CPF is valid\n");
	if  ((status = cnpj_isvalid(invalid_cnpj)) == -1)
		printf("CNPJ is invalid\n");
	if  ((status = cnpj_isvalid(valid_cnpj)) != -1)
		printf("CNPJ is valid\n");
	if  ((status = ddd_isvalid(invalid_ddd)) == -1)
		printf("DDD is invalid\n");
	if  ((status = ddd_isvalid(valid_ddd)) != -1)
		printf("DDD is valid\n");
	return (0);
}
