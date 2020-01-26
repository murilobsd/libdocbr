# libdocbr

Simples biblioteca para validações de alguns documentos do Brasil.

## Lista de documentos suportados

- [x] CNPJ
- [x] CPF
- [x] DDD

## Construção

Isso gera a biblioteca estática e o código de exemplo.

```sh
$ make all
```

## rodando exemplo

O código do arquivo [example](example.c) possui métodos para simples testes 
**unitários** das validações disponíveis.


```sh
$ ./example
```

## Como usar no meu programa?

Linkagem estática:

```sh
$ sudo cp docbr.h /usr/local/include 
$ sudo cp libdocbr.a /usr/local/lib
$ cc -I/usr/local/include -L/usr/local/łib meuprograma.c -ldocbr \
	-o meuprograma
```
