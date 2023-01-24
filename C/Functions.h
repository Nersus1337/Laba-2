#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define MAX 100

struct Book//Основная структура
{
	char title[100];//Название
	char description[1000];//Описание
	char author[50];//Автор
	char date[11];//Дата выхода
	char style[50];//Жанр
	int number;//Номер книги
};

//struct Book book[MAX];//Переменная структуры Book с книгами
//struct Book journal[MAX];//Переменная структуры Book с журналами
//struct Book newspaper[MAX];//Переменная структуры Book с газетами
//struct Book article[MAX];//Переменная структуры Book со статьями
//struct Book comic[MAX];//Переменная структуры Book с комиксами

struct Ticket//Читательский билет
{
	int id;//Номер читательского билета

	struct Client//Клиент
	{
		char name[100];//ФИО клиента
		char passport_data[100];//Паспортные данные
		int number_taken_document;//Номер взятого документа
	}client[MAX];
};

//Функции для работы с бумажными документами
void adding(struct Book, int type);// Функция добавления бумажного документа
void info(struct Book, int type, int number);//Функция вывода информации об одном бумажном документе
void deleted(struct Book, int type, int number);//Функция удаления бумажного документа
int counter(struct Book, int type);//Функция подсчета количества бумажных документов
void info_all(struct Book, int type);//Функция вывода всех документов
void edit(struct Book, int type, int number);//Функция редактирования одного параметра
void init(struct Book, int type);//Функция начальной инициализации

//Функции для работы с клиентом
void add_ticket(struct Ticket, int id);//Функция добавления читательского билета и клиента в базу
void give_document(struct Ticket, int id);//Функция выдачи документа клиенту
void info_client(struct Ticket, int id);//Функция получения информации о клиенте