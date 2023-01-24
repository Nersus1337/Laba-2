#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Functions.h"
#define MAX 100

//Бумажные документы
extern struct Book book[MAX];//Переменная структуры Book с книгами
extern struct Book journal[MAX];//Переменная структуры Book с журналами
extern struct Book newspaper[MAX];//Переменная структуры Book с газетами
extern struct Book article[MAX];//Переменная структуры Book со статьями
extern struct Book comic[MAX];//Переменная структуры Book с комиксами

//Билет
extern struct Ticket ticket[MAX];

//Функции для работы с клиентами
void add_ticket(struct Ticket, int id)//Функция добавления читательского билета и клиента в базу
{
	printf("\nЧитательский билет id %d", id);
	ticket[id].id = id;
	printf("\nВведите ФИО клиента № %d: ", id);
	gets_s(ticket[id].client[id].name);
	printf("Введите паспортные данные клиента: ");
	gets_s(ticket[id].client[id].passport_data);
	printf("\nЧитательский билет id %d добавлен", id);
}

void give_document(struct Ticket, int id)//Функция выдачи документа клиенту
{
	printf("\n\nЧитательский билет id %d\n", id);
	printf("Введите номер книги, которую хотите выдать: ");
	scanf("%d", &ticket[id].client[id].number_taken_document);
	//book[(ticket[id].client[id].number_taken_document)].number=id;
	printf("Книга выдана");
}

void info_client(struct Ticket, int id)//Функция получения информации о читательском билете
{
	printf("\n\nЧитательский билет id %d\n", id);
	printf("ФИО клиента: %s\n", ticket[id].client[id].name);
	printf("Паспортные данные клиента: %s", ticket[id].client[id].passport_data);
	printf("\nВыданная книга:\n");
	info(book[1], 1, ticket[id].client[id].number_taken_document);
}

//Функции для работы с документами
void adding(struct Book, int type)//Функция добавления бумажного документа (type - вид бумажного документа (1 - книга, 2 - журнал, 3 - газета, 4 - статья, 5 - комикс))
{
	int i;
	switch (type)
	{
	case 1:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(book[i].title, "") == 0)//Проверка на существование книги под заданным номером
			{
				printf("\nФункция добавления книги.");
				printf("\n...Книга №%d...", i);

				printf("\nВведите название книги: ");
				gets_s(book[i].title);
				printf("Введите описание книги: ");
				gets_s(book[i].description);
				printf("Введите автора книги: ");
				gets_s(book[i].author);
				printf("Введите дату выхода книги: ");
				gets_s(book[i].date);
				printf("Введите жанр книги: ");
				gets_s(book[i].style);
				book[i].number = i;//Изменено
				break;
			}
		}
		break;
	case 2:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(journal[i].title, "") == 0)
			{
				printf("\nФункция добавления журнала.");
				printf("\n...Журнал №%d...", i);

				printf("\nВведите название журнала: ");
				gets_s(journal[i].title);
				printf("Введите описание журнала: ");
				gets_s(journal[i].description);
				printf("Введите автора журнала: ");
				gets_s(journal[i].author);
				printf("Введите дату выхода журнала: ");
				gets_s(journal[i].date);
				printf("Введите жанр журнала: ");
				gets_s(journal[i].style);
				break;
			}
		}
		break;
	case 3:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(newspaper[i].title, "") == 0)
			{
				printf("\nФункция добавления газеты.");
				printf("\n...Газета №%d...", i);

				printf("\nВведите название газеты: ");
				gets_s(newspaper[i].title);
				printf("Введите описание газеты: ");
				gets_s(newspaper[i].description);
				printf("Введите автора газеты: ");
				gets_s(newspaper[i].author);
				printf("Введите дату выхода газеты: ");
				gets_s(newspaper[i].date);
				printf("Введите жанр газеты: ");
				gets_s(newspaper[i].style);
				break;
			}
		}
		break;
	case 4:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(article[i].title, "") == 0)
			{
				printf("\nФункция добавления статьи.");
				printf("\n...Статья №%d...", i);

				printf("\nВведите название статьи: ");
				gets_s(article[i].title);
				printf("Введите описание статьи: ");
				gets_s(article[i].description);
				printf("Введите автора статьи: ");
				gets_s(article[i].author);
				printf("Введите дату выхода статьи: ");
				gets_s(article[i].date);
				printf("Введите жанр статьи: ");
				gets_s(article[i].style);
				break;
			}
		}
		break;
	case 5:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(comic[i].title, "") == 0)
			{
				printf("\nФункция добавления комикса.");
				printf("\n...Комикс №%d...", i);

				printf("\nВведите название комикса: ");
				gets_s(comic[i].title);
				printf("Введите описание комикса: ");
				gets_s(comic[i].description);
				printf("Введите автора комикса: ");
				gets_s(comic[i].author);
				printf("Введите дату выхода комикса: ");
				gets_s(comic[i].date);
				printf("Введите жанр комикса: ");
				gets_s(comic[i].style);
				break;
			}
		}
		break;
	default:
		break;
	}
}

void info(struct Book, int type, int number)//Функция вывода информации об одном бумажном документе по его номеру (type - вид документа, number - номер бумажного документа (0, 1, 2, 3...))
{
	switch (type)
	{
	case 1:
		if (strcmp(book[number].title, "") != 0)
		{
			printf("\n...Книга №%d...", number);
			printf("\nНазвание книги: %s\n", book[number].title);
			printf("Описание книги: %s\n", book[number].description);
			printf("Автор книги: %s\n", book[number].author);
			printf("Дата выхода книги: %s\n", book[number].date);
			printf("Жанр книги: %s\n", book[number].style);
		}
		break;
	case 2:
		if (strcmp(journal[number].title, "") != 0)
		{
			printf("\n...Журнал №%d...", number);
			printf("\nНазвание журнала: %s\n", journal[number].title);
			printf("Описание журнала: %s\n", journal[number].description);
			printf("Автор журнала: %s\n", journal[number].author);
			printf("Дата выхода журнала: %s\n", journal[number].date);
			printf("Жанр журнала: %s\n", journal[number].style);
		}
		break;
	case 3:
		if (strcmp(newspaper[number].title, "") != 0)
		{
			printf("\n...Газета №%d...", number);
			printf("\nНазвание газеты: %s\n", newspaper[number].title);
			printf("Описание газеты: %s\n", newspaper[number].description);
			printf("Автор газеты: %s\n", newspaper[number].author);
			printf("Дата выхода газеты: %s\n", newspaper[number].date);
			printf("Жанр газеты: %s\n", newspaper[number].style);
		}
		break;
	case 4:
		if (strcmp(article[number].title, "") != 0)
		{
			printf("\n...Статья №%d...", number);
			printf("\nНазвание статьи: %s\n", article[number].title);
			printf("Описание статьи: %s\n", article[number].description);
			printf("Автор статьи: %s\n", article[number].author);
			printf("Дата выхода статьи: %s\n", article[number].date);
			printf("Жанр статьи: %s\n", article[number].style);
		}
		break;
	case 5:
		if (strcmp(comic[number].title, "") != 0)
		{
			printf("\n...Комикс №%d...", number);
			printf("\nНазвание комикса: %s\n", comic[number].title);
			printf("Описание комикса: %s\n", comic[number].description);
			printf("Автор комикса: %s\n", comic[number].author);
			printf("Дата выхода комикса: %s\n", comic[number].date);
			printf("Жанр комикса: %s\n", comic[number].style);
		}
		break;
	default:
		break;
	}
}

void deleted(struct Book, int type, int number)//Функция удаления бумажного документа (type - вид, number - номер)
{
	printf("\nФункция удаления.");
	switch (type)
	{
	case 1:
		book[number] = book[MAX + 1];
		printf("\nКнига №%d удалена\n", number);
		break;
	case 2:
		journal[number] = journal[MAX + 1];
		printf("\nЖурнал №%d удален\n", number);
		break;
	case 3:
		newspaper[number] = newspaper[MAX + 1];
		printf("\nГазета №%d удалена\n", number);
		break;
	case 4:
		article[number] = article[MAX + 1];
		printf("\nСтатья №%d удалена\n", number);
		break;
	case 5:
		comic[number] = comic[MAX + 1];
		printf("\nКомикс №%d удален\n", number);
		break;
	default:
		break;
	}
}

int counter(struct Book, int type)//Функция подсчета количества бумажных документов выбранного типа
{
	int i, count = 0;
	switch (type)
	{
	case 1:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(book[i].title, "") != 0)
			{
				count++;
			}
		}
		break;
	case 2:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(journal[i].title, "") != 0)
			{
				count++;
			}
		}
		break;
	case 3:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(newspaper[i].title, "") != 0)
			{
				count++;
			}
		}
		break;
	case 4:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(article[i].title, "") != 0)
			{
				count++;
			}
		}
		break;
	case 5:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(comic[i].title, "") != 0)
			{
				count++;
			}
		}
		break;
	default:
		break;
	}
	return count;
}

void info_all(struct Book, int type)//Функция вывода всех документов заданного типа
{
	int i, number;
	switch (type)
	{
	case 1:
		printf("\nФункция вывода книг.");
		number = counter(book[1], 1);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 1, i);
		}
		break;
	case 2:
		printf("\nФункция вывода журналов.");
		number = counter(book[1], 2);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 2, i);
		}
		break;
	case 3:
		printf("\nФункция вывода газет.");
		number = counter(book[1], 3);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 3, i);
		}
		break;
	case 4:
		printf("\nФункция вывода статей.");
		number = counter(book[1], 4);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 4, i);
		}
		break;
	case 5:
		printf("\nФункция вывода комиксов.");
		number = counter(book[1], 5);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 5, i);
		}
		break;
	default:
		break;
	}
}

void edit(struct Book, int type, int number)//Функция редактирования одного параметра заданного документа
{
	int parametr;
	switch (type)
	{
	case 1://Книги
		printf("\n\nФункция редактирования книг.");
		info(book[1], type, number);
		printf("\nВведите номер параметра для редактирования (1 - название, 2 - описание, 3 - автор, 4 - дата выхода, 5 - жанр): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("Введите новое название: ");
			gets_s(book[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите новое описание: ");
			gets_s(book[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите нового автора: ");
			gets_s(book[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите новую дату выхода: ");
			gets_s(book[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("Введите новый жанр: ");
			gets_s(book[number].style);
			break;
		default:
			break;
		}
		break;

	case 2://Журналы
		printf("\n\nФункция редактирования журналов.");
		info(book[1], type, number);
		printf("\nВведите номер параметра для редактирования (1 - название, 2 - описание, 3 - автор, 4 - дата выхода, 5 - жанр): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("Введите новое название: ");
			gets_s(journal[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите новое описание: ");
			gets_s(journal[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите нового автора: ");
			gets_s(journal[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите новую дату выхода: ");
			gets_s(journal[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("Введите новый жанр: ");
			gets_s(journal[number].style);
			break;
		default:
			break;
		}
		break;

	case 3://Газеты
		printf("\n\nФункция редактирования газет.");
		info(book[1], type, number);
		printf("\nВведите номер параметра для редактирования (1 - название, 2 - описание, 3 - автор, 4 - дата выхода, 5 - жанр): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("Введите новое название: ");
			gets_s(newspaper[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите новое описание: ");
			gets_s(newspaper[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите нового автора: ");
			gets_s(newspaper[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите новую дату выхода: ");
			gets_s(newspaper[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("Введите новый жанр: ");
			gets_s(newspaper[number].style);
			break;
		default:
			break;
		}
		break;

	case 4://Статьи
		printf("\n\nФункция редактирования статей.");
		info(book[1], type, number);
		printf("\nВведите номер параметра для редактирования (1 - название, 2 - описание, 3 - автор, 4 - дата выхода, 5 - жанр): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("Введите новое название: ");
			gets_s(article[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите новое описание: ");
			gets_s(article[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите нового автора: ");
			gets_s(article[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите новую дату выхода: ");
			gets_s(article[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("Введите новый жанр: ");
			gets_s(article[number].style);
			break;
		default:
			break;
		}
		break;

	case 5://Комиксы
		printf("\n\nФункция редактирования комиксов.");
		info(book[1], type, number);
		printf("\nВведите номер параметра для редактирования (1 - название, 2 - описание, 3 - автор, 4 - дата выхода, 5 - жанр): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("Введите новое название: ");
			gets_s(comic[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("Введите новое описание: ");
			gets_s(comic[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("Введите нового автора: ");
			gets_s(comic[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Введите новую дату выхода: ");
			gets_s(comic[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("Введите новый жанр: ");
			gets_s(comic[number].style);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void init(struct Book, int type)//Функция начальной инициализации для заданного вида документа
{
	switch (type)
	{
	case 1:
		strcpy(book[0].title, "First book");
		strcpy(book[0].description, "It's the first book");
		strcpy(book[0].author, "Maksim Priamonosov");
		strcpy(book[0].date, "1997");
		strcpy(book[0].style, "Thriller");
		book[0].number = 0;//Изменено
		strcpy(book[1].title, "Second book");
		strcpy(book[1].description, "It's the second book");
		strcpy(book[1].author, "Maksim Priamonosov");
		strcpy(book[1].date, "1986");
		strcpy(book[1].style, "Action");
		book[1].number = 1;//Изменено
		strcpy(book[2].title, "Third club");
		strcpy(book[2].description, "It's the third book");
		strcpy(book[2].author, "Maksim Priamonosov");
		strcpy(book[2].date, "2000");
		strcpy(book[2].style, "Fantasy");
		book[2].number = 2;//Изменено
		break;
	case 2:
		strcpy(journal[0].title, "First journal");
		strcpy(journal[0].description, "It's the first journal");
		strcpy(journal[0].author, "Maksim Priamonosov");
		strcpy(journal[0].date, "1997");
		strcpy(journal[0].style, "Thriller");
		strcpy(journal[1].title, "Second journal");
		strcpy(journal[1].description, "It's the second journal");
		strcpy(journal[1].author, "Maksim Priamonosov");
		strcpy(journal[1].date, "1986");
		strcpy(journal[1].style, "Action");
		strcpy(journal[2].title, "Third journal");
		strcpy(journal[2].description, "It's the third journal");
		strcpy(journal[2].author, "Maksim Priamonosov");
		strcpy(journal[2].date, "2000");
		strcpy(journal[2].style, "Fantasy");
		break;
	case 3:
		strcpy(newspaper[0].title, "First newspaper");
		strcpy(newspaper[0].description, "It's the first newspaper");
		strcpy(newspaper[0].author, "Maksim Priamonosov");
		strcpy(newspaper[0].date, "1997");
		strcpy(newspaper[0].style, "Thriller");
		strcpy(newspaper[1].title, "Second newspaper");
		strcpy(newspaper[1].description, "It's the second newspaper");
		strcpy(newspaper[1].author, "Maksim Priamonosov");
		strcpy(newspaper[1].date, "1986");
		strcpy(newspaper[1].style, "Action");
		strcpy(newspaper[2].title, "Third newspaper");
		strcpy(newspaper[2].description, "It's the third newspaper");
		strcpy(newspaper[2].author, "Maksim Priamonosov");
		strcpy(newspaper[2].date, "2000");
		strcpy(newspaper[2].style, "Fantasy");
		break;
	case 4:
		strcpy(article[0].title, "First article");
		strcpy(article[0].description, "It's the first article");
		strcpy(article[0].author, "Maksim Priamonosov");
		strcpy(article[0].date, "1997");
		strcpy(article[0].style, "Thriller");
		strcpy(article[1].title, "Second article");
		strcpy(article[1].description, "It's the second article");
		strcpy(article[1].author, "Maksim Priamonosov");
		strcpy(article[1].date, "1986");
		strcpy(article[1].style, "Action");
		strcpy(article[2].title, "Third article");
		strcpy(article[2].description, "It's the third article");
		strcpy(article[2].author, "Maksim Priamonosov");
		strcpy(article[2].date, "2000");
		strcpy(article[2].style, "Fantasy");
		break;
	case 5:
		strcpy(comic[0].title, "First comic");
		strcpy(comic[0].description, "It's the first comic");
		strcpy(comic[0].author, "Maksim Priamonosov");
		strcpy(comic[0].date, "1997");
		strcpy(comic[0].style, "Thriller");
		strcpy(comic[1].title, "Second comic");
		strcpy(comic[1].description, "It's the second comic");
		strcpy(comic[1].author, "Maksim Priamonosov");
		strcpy(comic[1].date, "1986");
		strcpy(comic[1].style, "Action");
		strcpy(comic[2].title, "Third comic");
		strcpy(comic[2].description, "It's the third comic");
		strcpy(comic[2].author, "Maksim Priamonosov");
		strcpy(comic[2].date, "2000");
		strcpy(comic[2].style, "Fantasy");
		break;
	default:
		break;
	}
}