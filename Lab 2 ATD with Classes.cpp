#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#define MAX 100
using namespace std;

class library//�������� �����, �� �������� ����������� 5 �������
{
public:
	library(string title, string description, string author, string date, string style)//����������� ����������� (�������������)
	{
		this->title = title;
		this->description = description;
		this->author = author;
		this->date = date;
		this->style = style;
	}
protected://���� �������������
	string title;//��������
	string description;//��������
	string author;//�����
	string date;//���� ������
	string style;//����

	void adding()//������� ����������
	{
		cout << "������� ��������: ";
		cin >> title;
		cout << "������� ��������: ";
		cin >> description;
		cout << "������� ������: ";
		cin >> author;
		cout << "������� ���� ������: ";
		cin >> date;
		cout << "������� ����: ";
		cin >> style;
	};

	void info()//������� ��������� ����������
	{
		cout << "��������: " << title << endl;
		cout << "��������: " << description << endl;
		cout << "�����: " << author << endl;
		cout << "���� ������: " << date << endl;
		cout << "����: " << style << endl;
	}

	void deleted()//������� ��������
	{
		title = "";
		description = "";
		author = "";
		date = "";
		style = "";
	}

	void edit()//������� ��������������
	{
		int parametr;
		cout << "\n������� ����� ��������� ��� �������������� (1 - ��������, 2 - ��������, 3 - �����, 4 - ���� ������, 5 - ����): ";
		cin >> parametr;
		switch (parametr)
		{
		case 1:
			cout << "������� ����� ��������: ";
			cin >> title;
			break;
		case 2:
			cout << "������� ����� ��������: ";
			cin >> description;
			break;
		case 3:
			cout << "������� ������ ������: ";
			cin >> author;
			break;
		case 4:
			cout << "������� ����� ���� ������: ";
			cin >> date;
			break;
		case 5:
			cout << "������� ����� ����: ";
			cin >> style;
			break;
		default:
			break;
		}
	}
};
class book : public library//������������� ����� ����
{
public:
	using library::library;

	void adding_book()
	{
		printf("\n������� ���������� �����.\n");
		adding();
	}
	void info_book()
	{
		printf("\n...�����...\n");
		info();
	}
	void deleted_book()
	{
		deleted();
		cout << "\n����� ���� �������\n";
	}
	void edit_book()
	{
		printf("\n\n������� �������������� �����.");
		info_book();
		edit();
	}
};
class journal : public library//������������� ����� ��������
{
public:
	using library::library;
	void adding_journal()
	{
		printf("\n������� ���������� �������.\n");
		adding();
	}
	void info_journal()
	{
		printf("\n...������...\n");
		info();
	}
	void deleted_journal()
	{
		deleted();
		cout << "\n������ ��� ������\n";
	}
	void edit_journal()
	{
		printf("\n\n������� �������������� �������.");
		info_journal();
		edit();
	}
};
class newspaper : public library//������������� ����� �����
{
public:
	using library::library;
	void adding_newspaper()
	{
		printf("\n������� ���������� ������.\n");
		adding();
	}
	void info_newspaper()
	{
		printf("\n...������...\n");
		info();
	}
	void deleted_newspaper()
	{
		deleted();
		cout << "\n������ ���� �������\n";
	}
	void edit_newspaper()
	{
		printf("\n\n������� �������������� ������.");
		info_newspaper();
		edit();
	}
};
class article : public library//������������� ����� ������
{
public:
	using library::library;
	void adding_article()
	{
		printf("\n������� ���������� ������.\n");
		adding();
	}
	void info_article()
	{
		printf("\n...������...\n");
		info();
	}
	void deleted_article()
	{
		deleted();
		cout << "\n������ ���� �������\n";
	}
	void edit_article()
	{
		printf("\n\n������� �������������� ������.");
		info_article();
		edit();
	}
};
class comic : public library//������������� ����� ��������
{
public:
	using library::library;
	void adding_comic()
	{
		printf("\n������� ���������� �������.\n");
		adding();
	}
	void info_comic()
	{
		printf("\n...������...\n");
		info();
	}
	void deleted_comic()
	{
		deleted();
		cout << "\n������ ��� ������\n";
	}
	void edit_comic()
	{
		printf("\n\n������� �������������� �������.");
		info_comic();
		edit();
	}
};

class Ticket//����� � ������������� ��������, ���������� ����� � ������� �������
{
public:
	Ticket(int id, string name, string passport_data, int number_taken_document)//����������� �������������
	{
		this->id = id;
		client[id].name = name;
		client[id].passport_data = passport_data;
		client[id].number_taken_document = number_taken_document;
	}

	class Client//��������� ����� � ������� �������
	{
	public:
		string name;//��� �������
		string passport_data;//���������� ������
		int number_taken_document;//����� ������� ���������
	}client[MAX];

	int id;

	void add_ticket(int id)
	{
		cout << "������������ ����� id " << id << endl;
		cout << "������� ��� ������: ";
		cin >> client[id].name;
		cout << "������� ���������� ������ �������: ";
		cin >> client[id].passport_data;
		this->id = id;
		cout << "������������ ����� id " << id << " ��������"<<endl<<endl;
	}

	void give_book(int id)
	{
		cout << "������������ ����� id " << id << endl;
		cout << "������� ����� �����, ������� ������ ������: ";
		cin >> client[id].number_taken_document;
		cout << "����� ������"<<endl<<endl;
	}

	void give_journal(int id)
	{
		cout << "������������ ����� id " << id << endl;
		cout << "������� ����� �������, ������� ������ ������: ";
		cin >> client[id].number_taken_document;
		cout << "������ �����" << endl << endl;
	}

	void info_client(int id)
	{
		cout << "\n������������ ����� id " << id << endl;
		cout << "��� ������: " << client[id].name<<endl;
		cout << "���������� ������ ������: " << client[id].passport_data<<endl;
		cout << "�������� ��������: � "<< client[id].number_taken_document<<endl;
		//book[client[id].number_taken_document].info_book();
	}
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	system("color F0");
	book book("title c", "desk c", "author c", "date c", "style constructor");
	//book book[100];
	//journal journal[100];
	//newspaper newspaper[100];
	//article article[100];
	//comic comic[100];
	Ticket ticket(1,"q", "q", 1);
	ticket.info_client(1);
	//book1.info_book();
	//ticket[0].add_ticket(0);
	//ticket[0].give_book(0);
	//book[0].adding_book();
	//ticket[0].info_client(0);

	//book1[0].adding_book();
	//book1[0].info_book();
	/*
	book1[0].deleted_book();
	book1[0].info_book();
	book1[0].adding_book();
	book1[0].edit_book();
	book1[0].info_book();*/
	//journal[0].info_journal();

	/*journal[0].adding_journal();
	journal[0].info_journal();
	journal[0].deleted_journal();
	journal[0].info_journal();
	journal[0].adding_journal();
	journal[0].edit_journal();
	journal[0].info_journal();*/

	//while (getchar() != '\n');
}