#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Functions.h"
#define MAX 100

struct Book book[MAX];
struct Book journal[MAX];
struct Book newspaper[MAX];
struct Book article[MAX];
struct Book comic[MAX];

struct Ticket ticket[MAX];

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color F0");

	///////////////////////
	//adding(book[1], 1, 1);
	//info(book[1], 1, 1);
	//info_all(book[1], 1);
	//deleted(book[1], 1, 2);
	//init(book[1], 1);
	//counter(book[1], 1);
	//edit(book[1], 1, 2)
	///////////////////////

	init(book[1], 1);

	add_ticket(ticket[1], 1);
	give_document(ticket[1], 1);
	info_client(ticket[1], 1);

	//info(book[1], 1, 0);

	//while (getchar() != '\n');
}