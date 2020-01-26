# libdocbr

Simples biblioteca para validações de alguns documentos do Brasil.

## Construção

Isso gera a biblioteca estática e o código de exemplo.

```sh
$ make all
```

## rodando exemplo

O código do exemplo só exibe a validação do cpf, mas é fácil adaptar para 
cnpj.

```sh
$ ./example <cpf_number> eg.: 12345678911
```

## como usar no meu código
```sh
$ sudo cp docbr.h /usr/local/include 
$ sudo cp libdocbr.a /usr/local/lib
$ cc -I/usr/local/include -L/usr/local/łib meuprograma.c -ldocbr \
	-o meuprograma
```
