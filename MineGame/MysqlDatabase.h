#pragma once
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "libmysql.lib")
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include "Player.h"
#include "global.h"
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0407"
#define DB_NAME "minegame_db"
#define CHOP(x) x[strlen(x)-1] = ' '

using namespace std;

class MysqlDatabase
{
private:

public:
	static void create_account(); //ȸ�������� �ϰ� id, password, money�� ������ ���̽��� ����. id�� �ߺ� x
	static void ranking_print();//���� ���� ȸ�������� ���
	static bool login();//test
	static void moneySave(char* money);
	static void playerInit(Player& player);
};

