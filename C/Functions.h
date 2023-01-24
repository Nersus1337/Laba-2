#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define MAX 100

struct Book//�������� ���������
{
	char title[100];//��������
	char description[1000];//��������
	char author[50];//�����
	char date[11];//���� ������
	char style[50];//����
	int number;//����� �����
};

//struct Book book[MAX];//���������� ��������� Book � �������
//struct Book journal[MAX];//���������� ��������� Book � ���������
//struct Book newspaper[MAX];//���������� ��������� Book � ��������
//struct Book article[MAX];//���������� ��������� Book �� ��������
//struct Book comic[MAX];//���������� ��������� Book � ���������

struct Ticket//������������ �����
{
	int id;//����� ������������� ������

	struct Client//������
	{
		char name[100];//��� �������
		char passport_data[100];//���������� ������
		int number_taken_document;//����� ������� ���������
	}client[MAX];
};

//������� ��� ������ � ��������� �����������
void adding(struct Book, int type);// ������� ���������� ��������� ���������
void info(struct Book, int type, int number);//������� ������ ���������� �� ����� �������� ���������
void deleted(struct Book, int type, int number);//������� �������� ��������� ���������
int counter(struct Book, int type);//������� �������� ���������� �������� ����������
void info_all(struct Book, int type);//������� ������ ���� ����������
void edit(struct Book, int type, int number);//������� �������������� ������ ���������
void init(struct Book, int type);//������� ��������� �������������

//������� ��� ������ � ��������
void add_ticket(struct Ticket, int id);//������� ���������� ������������� ������ � ������� � ����
void give_document(struct Ticket, int id);//������� ������ ��������� �������
void info_client(struct Ticket, int id);//������� ��������� ���������� � �������