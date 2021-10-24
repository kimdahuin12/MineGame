#pragma once
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "libmysql.lib")
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include "Player.h"
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "0407"
#define DB_NAME "minegame_db"
#define CHOP(x) x[strlen(x)-1] = ' '

using namespace std;

class MysqlDatabase
{
public:
	static void create_account(Player* player); //회원가입을 하고 id, password, money를 데이터 베이스에 저장. id는 중복 x
	static void ranking_print();//돈이 많은 회원순으로 출력
	static void login();//test
	static void moneySave(char* money);

};

