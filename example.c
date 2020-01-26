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
#include <stdlib.h>
#include <string.h>

#include "docbr.h"

int
main(int argc, char *argv[])
{
	int cpf_number[11] = {0};
	int cpf_len = 0, cpf_status = 0;
	char p;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <cpf_number>\n", argv[0]);
		exit(1);
	}

	cpf_len = strlen(argv[1]);
	if (cpf_len != 11) {
		fprintf(stderr, "invalid cpf number, eg: 12345678911\n");
		exit(1);
	}

	for (size_t i = 0; i < strlen(argv[1]); i++) {
		p = argv[1][i];
		cpf_number[i] = atoi(&p);
	}

	if ((cpf_status = cpf_isvalid(cpf_number)) != -1) {
		printf("CPF is valid\n");
		return (EXIT_SUCCESS);
	}
	printf("CPF: %s is invalid\n", argv[1]);
	return (EXIT_FAILURE);
}
