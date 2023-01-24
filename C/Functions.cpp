#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Functions.h"
#define MAX 100

//�������� ���������
extern struct Book book[MAX];//���������� ��������� Book � �������
extern struct Book journal[MAX];//���������� ��������� Book � ���������
extern struct Book newspaper[MAX];//���������� ��������� Book � ��������
extern struct Book article[MAX];//���������� ��������� Book �� ��������
extern struct Book comic[MAX];//���������� ��������� Book � ���������

//�����
extern struct Ticket ticket[MAX];

//������� ��� ������ � ���������
void add_ticket(struct Ticket, int id)//������� ���������� ������������� ������ � ������� � ����
{
	printf("\n������������ ����� id %d", id);
	ticket[id].id = id;
	printf("\n������� ��� ������� � %d: ", id);
	gets_s(ticket[id].client[id].name);
	printf("������� ���������� ������ �������: ");
	gets_s(ticket[id].client[id].passport_data);
	printf("\n������������ ����� id %d ��������", id);
}

void give_document(struct Ticket, int id)//������� ������ ��������� �������
{
	printf("\n\n������������ ����� id %d\n", id);
	printf("������� ����� �����, ������� ������ ������: ");
	scanf("%d", &ticket[id].client[id].number_taken_document);
	//book[(ticket[id].client[id].number_taken_document)].number=id;
	printf("����� ������");
}

void info_client(struct Ticket, int id)//������� ��������� ���������� � ������������ ������
{
	printf("\n\n������������ ����� id %d\n", id);
	printf("��� �������: %s\n", ticket[id].client[id].name);
	printf("���������� ������ �������: %s", ticket[id].client[id].passport_data);
	printf("\n�������� �����:\n");
	info(book[1], 1, ticket[id].client[id].number_taken_document);
}

//������� ��� ������ � �����������
void adding(struct Book, int type)//������� ���������� ��������� ��������� (type - ��� ��������� ��������� (1 - �����, 2 - ������, 3 - ������, 4 - ������, 5 - ������))
{
	int i;
	switch (type)
	{
	case 1:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(book[i].title, "") == 0)//�������� �� ������������� ����� ��� �������� �������
			{
				printf("\n������� ���������� �����.");
				printf("\n...����� �%d...", i);

				printf("\n������� �������� �����: ");
				gets_s(book[i].title);
				printf("������� �������� �����: ");
				gets_s(book[i].description);
				printf("������� ������ �����: ");
				gets_s(book[i].author);
				printf("������� ���� ������ �����: ");
				gets_s(book[i].date);
				printf("������� ���� �����: ");
				gets_s(book[i].style);
				book[i].number = i;//��������
				break;
			}
		}
		break;
	case 2:
		for (i = 0; i < MAX + 1; i++)
		{
			if (strcmp(journal[i].title, "") == 0)
			{
				printf("\n������� ���������� �������.");
				printf("\n...������ �%d...", i);

				printf("\n������� �������� �������: ");
				gets_s(journal[i].title);
				printf("������� �������� �������: ");
				gets_s(journal[i].description);
				printf("������� ������ �������: ");
				gets_s(journal[i].author);
				printf("������� ���� ������ �������: ");
				gets_s(journal[i].date);
				printf("������� ���� �������: ");
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
				printf("\n������� ���������� ������.");
				printf("\n...������ �%d...", i);

				printf("\n������� �������� ������: ");
				gets_s(newspaper[i].title);
				printf("������� �������� ������: ");
				gets_s(newspaper[i].description);
				printf("������� ������ ������: ");
				gets_s(newspaper[i].author);
				printf("������� ���� ������ ������: ");
				gets_s(newspaper[i].date);
				printf("������� ���� ������: ");
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
				printf("\n������� ���������� ������.");
				printf("\n...������ �%d...", i);

				printf("\n������� �������� ������: ");
				gets_s(article[i].title);
				printf("������� �������� ������: ");
				gets_s(article[i].description);
				printf("������� ������ ������: ");
				gets_s(article[i].author);
				printf("������� ���� ������ ������: ");
				gets_s(article[i].date);
				printf("������� ���� ������: ");
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
				printf("\n������� ���������� �������.");
				printf("\n...������ �%d...", i);

				printf("\n������� �������� �������: ");
				gets_s(comic[i].title);
				printf("������� �������� �������: ");
				gets_s(comic[i].description);
				printf("������� ������ �������: ");
				gets_s(comic[i].author);
				printf("������� ���� ������ �������: ");
				gets_s(comic[i].date);
				printf("������� ���� �������: ");
				gets_s(comic[i].style);
				break;
			}
		}
		break;
	default:
		break;
	}
}

void info(struct Book, int type, int number)//������� ������ ���������� �� ����� �������� ��������� �� ��� ������ (type - ��� ���������, number - ����� ��������� ��������� (0, 1, 2, 3...))
{
	switch (type)
	{
	case 1:
		if (strcmp(book[number].title, "") != 0)
		{
			printf("\n...����� �%d...", number);
			printf("\n�������� �����: %s\n", book[number].title);
			printf("�������� �����: %s\n", book[number].description);
			printf("����� �����: %s\n", book[number].author);
			printf("���� ������ �����: %s\n", book[number].date);
			printf("���� �����: %s\n", book[number].style);
		}
		break;
	case 2:
		if (strcmp(journal[number].title, "") != 0)
		{
			printf("\n...������ �%d...", number);
			printf("\n�������� �������: %s\n", journal[number].title);
			printf("�������� �������: %s\n", journal[number].description);
			printf("����� �������: %s\n", journal[number].author);
			printf("���� ������ �������: %s\n", journal[number].date);
			printf("���� �������: %s\n", journal[number].style);
		}
		break;
	case 3:
		if (strcmp(newspaper[number].title, "") != 0)
		{
			printf("\n...������ �%d...", number);
			printf("\n�������� ������: %s\n", newspaper[number].title);
			printf("�������� ������: %s\n", newspaper[number].description);
			printf("����� ������: %s\n", newspaper[number].author);
			printf("���� ������ ������: %s\n", newspaper[number].date);
			printf("���� ������: %s\n", newspaper[number].style);
		}
		break;
	case 4:
		if (strcmp(article[number].title, "") != 0)
		{
			printf("\n...������ �%d...", number);
			printf("\n�������� ������: %s\n", article[number].title);
			printf("�������� ������: %s\n", article[number].description);
			printf("����� ������: %s\n", article[number].author);
			printf("���� ������ ������: %s\n", article[number].date);
			printf("���� ������: %s\n", article[number].style);
		}
		break;
	case 5:
		if (strcmp(comic[number].title, "") != 0)
		{
			printf("\n...������ �%d...", number);
			printf("\n�������� �������: %s\n", comic[number].title);
			printf("�������� �������: %s\n", comic[number].description);
			printf("����� �������: %s\n", comic[number].author);
			printf("���� ������ �������: %s\n", comic[number].date);
			printf("���� �������: %s\n", comic[number].style);
		}
		break;
	default:
		break;
	}
}

void deleted(struct Book, int type, int number)//������� �������� ��������� ��������� (type - ���, number - �����)
{
	printf("\n������� ��������.");
	switch (type)
	{
	case 1:
		book[number] = book[MAX + 1];
		printf("\n����� �%d �������\n", number);
		break;
	case 2:
		journal[number] = journal[MAX + 1];
		printf("\n������ �%d ������\n", number);
		break;
	case 3:
		newspaper[number] = newspaper[MAX + 1];
		printf("\n������ �%d �������\n", number);
		break;
	case 4:
		article[number] = article[MAX + 1];
		printf("\n������ �%d �������\n", number);
		break;
	case 5:
		comic[number] = comic[MAX + 1];
		printf("\n������ �%d ������\n", number);
		break;
	default:
		break;
	}
}

int counter(struct Book, int type)//������� �������� ���������� �������� ���������� ���������� ����
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

void info_all(struct Book, int type)//������� ������ ���� ���������� ��������� ����
{
	int i, number;
	switch (type)
	{
	case 1:
		printf("\n������� ������ ����.");
		number = counter(book[1], 1);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 1, i);
		}
		break;
	case 2:
		printf("\n������� ������ ��������.");
		number = counter(book[1], 2);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 2, i);
		}
		break;
	case 3:
		printf("\n������� ������ �����.");
		number = counter(book[1], 3);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 3, i);
		}
		break;
	case 4:
		printf("\n������� ������ ������.");
		number = counter(book[1], 4);
		for (i = 0; i < number + 1; i++)
		{
			info(book[1], 4, i);
		}
		break;
	case 5:
		printf("\n������� ������ ��������.");
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

void edit(struct Book, int type, int number)//������� �������������� ������ ��������� ��������� ���������
{
	int parametr;
	switch (type)
	{
	case 1://�����
		printf("\n\n������� �������������� ����.");
		info(book[1], type, number);
		printf("\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(book[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(book[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("������� ������ ������: ");
			gets_s(book[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("������� ����� ���� ������: ");
			gets_s(book[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("������� ����� ����: ");
			gets_s(book[number].style);
			break;
		default:
			break;
		}
		break;

	case 2://�������
		printf("\n\n������� �������������� ��������.");
		info(book[1], type, number);
		printf("\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(journal[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(journal[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("������� ������ ������: ");
			gets_s(journal[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("������� ����� ���� ������: ");
			gets_s(journal[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("������� ����� ����: ");
			gets_s(journal[number].style);
			break;
		default:
			break;
		}
		break;

	case 3://������
		printf("\n\n������� �������������� �����.");
		info(book[1], type, number);
		printf("\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(newspaper[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(newspaper[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("������� ������ ������: ");
			gets_s(newspaper[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("������� ����� ���� ������: ");
			gets_s(newspaper[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("������� ����� ����: ");
			gets_s(newspaper[number].style);
			break;
		default:
			break;
		}
		break;

	case 4://������
		printf("\n\n������� �������������� ������.");
		info(book[1], type, number);
		printf("\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(article[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(article[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("������� ������ ������: ");
			gets_s(article[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("������� ����� ���� ������: ");
			gets_s(article[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("������� ����� ����: ");
			gets_s(article[number].style);
			break;
		default:
			break;
		}
		break;

	case 5://�������
		printf("\n\n������� �������������� ��������.");
		info(book[1], type, number);
		printf("\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ");
		scanf("%d", &parametr);
		switch (parametr)
		{
		case 1:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(comic[number].title);
			break;
		case 2:
			while (getchar() != '\n');
			printf("������� ����� ��������: ");
			gets_s(comic[number].description);
			break;
		case 3:
			while (getchar() != '\n');
			printf("������� ������ ������: ");
			gets_s(comic[number].author);
			break;
		case 4:
			while (getchar() != '\n');
			printf("������� ����� ���� ������: ");
			gets_s(comic[number].date);
			break;
		case 5:
			while (getchar() != '\n');
			printf("������� ����� ����: ");
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

void init(struct Book, int type)//������� ��������� ������������� ��� ��������� ���� ���������
{
	switch (type)
	{
	case 1:
		strcpy(book[0].title, "First book");
		strcpy(book[0].description, "It's the first book");
		strcpy(book[0].author, "Maksim Priamonosov");
		strcpy(book[0].date, "1997");
		strcpy(book[0].style, "Thriller");
		book[0].number = 0;//��������
		strcpy(book[1].title, "Second book");
		strcpy(book[1].description, "It's the second book");
		strcpy(book[1].author, "Maksim Priamonosov");
		strcpy(book[1].date, "1986");
		strcpy(book[1].style, "Action");
		book[1].number = 1;//��������
		strcpy(book[2].title, "Third club");
		strcpy(book[2].description, "It's the third book");
		strcpy(book[2].author, "Maksim Priamonosov");
		strcpy(book[2].date, "2000");
		strcpy(book[2].style, "Fantasy");
		book[2].number = 2;//��������
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