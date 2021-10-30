#include "MysqlDatabase.h"
MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;
int query_stat;


void MysqlDatabase::create_account() {
	//ȸ�������� �ϰ� id, password, money�� ������ ���̽��� ����. id�� �ߺ� x

	//���̵�� �ִ� 20����, �ѱ�X, ��� ���ڸ��� �̿��Ͽ� �����
	//��й�ȣ�� ��� ���ڸ��� �̿��Ͽ� ����� �ִ� 20

	char id[50];
	char pw[50];
	char query[255];
	bool idAndPwCheck;

	//mysql ���� ����
	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST,
		DB_USER, DB_PASS,
		DB_NAME, 3306,
		(char*)NULL, 0);

	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}
	//mysql ���� ���� END

	//���̵�, ��� �Է¹ޱ�
	while (true) {
		idAndPwCheck = true;
		cout << "--------ȸ������--------" << endl << endl;
		cout << "���̵�, ��й�ȣ�� ��� ���� �ҹ��ڿ� ���ڸ��� �̿��Ͽ� ���� �� ������\n�ִ� 50�ڱ��� ���� �����մϴ�." << endl << endl;
		cout << "���̵� �Է� : "; fgets(id, 50, stdin); CHOP(id);
		Sleep(1000);
		cout << "��й�ȣ �Է� : "; fgets(pw, 50, stdin); CHOP(pw);

		//id üũ
		for (int i = 0; id[i] != ' '; i++) {
			if ((id[i] < 'a' || id[i] > 'z') && (id[i] < '0' || id[i] > '9')) { idAndPwCheck = false; break; }
		}
		//pwüũ
		for (int i = 0; pw[i] != ' '; i++) {
			if ((pw[i] < 'a' || pw[i] > 'z') && (pw[i] < '0' || pw[i] > '9')) { idAndPwCheck = false; break; }
		}

		//��� �� �Է��ϸ� while END
		if (idAndPwCheck == true) { break; }

		system("cls"); cout << endl;
		cout << "���̵�� ��й�ȣ�� ���� �ҹ��ڿ� ���ڸ��� �̿��ؼ� ����� �ּ���." << endl << endl;
		system("pause"); system("cls");

	}
	//while END
	//���̵�, ��� �Է¹ޱ� END

	//���� ���� ���� ����
	int sel; //���ÿ� ����
	while (true) {

		system("pause"); system("cls");
		cout << "������ �����Ͻðڽ��ϱ�?" << endl << endl;
		cout << "1. ��" << endl;
		cout << "2. �ƴϿ�" << endl << endl;
		cout << "��ȣ ���� >> "; cin >> sel;

		switch (sel) {
		case 1:
			system("pause"); system("cls");
			cout << "������ �����˴ϴ�." << endl;
			break;
			cout << endl; system("pause"); system("cls");
		case 2:
			system("pause"); system("cls"); cout << endl;
			cout << "���� ȭ������ ���ư��ϴ�." << endl;
			return;
		default:
			cout << endl; system("pause"); system("cls");
		}

		if (sel == 1) break;
	}
	//while END
	//���� ���� ���� ���� END

	//���� ����(db�� ����)
	cout << "id: " << id << endl;

	//db�� ���� ����(Id, password, money)
	sprintf(query, "insert into %s values "
		"('%s', '%s', '10000')", //money�� ó���� ���� ����
		"playeraccount", id, pw);//minegame_db.playeraccount�� ������ ����

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	mysql_close(connection);
	cout << "���� ���� �Ϸ�" << endl;
	//db�� ���� ����(Id, password, money) END
}

void MysqlDatabase::ranking_print() {
	//���� ���� ȸ�������� ���

	char query[255];

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//select������
	sprintf(query, "SELECT * FROM %s ORDER BY `money` DESC",
		"playeraccount");//money�� ������(��������)���� ����
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//��� ���
	sql_result = mysql_store_result(connection);
	int ranking = 1;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%d. ID : %2s MONEY : %2s \\ \n", ranking++, sql_row[0], sql_row[2]); //0�� : id, 2�� : money
	}
	mysql_free_result(sql_result);

	//DB ���� �ݱ�
	mysql_close(connection);
	//DB��

}

bool MysqlDatabase::login() {

	char id_c[50];
	char pw_c[50];
	bool id_being = false;

	gotoXY(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	cout << "�α���" << endl;
	
	cout << "���̵� : "; fgets(id_c, 50, stdin); CHOP(id_c);
	Sleep(500);
	cout << "��й�ȣ : "; fgets(pw_c, 50, stdin); CHOP(pw_c);

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_res;
	MYSQL_ROW sql_row;
	int query_stat;

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	//select������
	char* query = new char[strlen("SELECT * FROM playeraccount where id = \"")+strlen(id_c)+strlen("\"") + 1];
	strcpy(query, "SELECT * FROM playeraccount where id = \"");
	strcat(query, id_c);
	strcat(query, "\"");
	
	/*char* query = new char[strlen("SELECT * FROM ") * strlen("playeraccount")];
	strcpy_s(query, strlen("SELECT * FROM playeraccount"), "SELECT * FROM playeraccount");*/
	//strcpy_s(query + strlen("SELECT * FROM "), strlen("playeraccount"), "playeraccount");
	
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	//��� ���
	sql_res = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_res)) != NULL) {
		id_being = true;
		if (strcmp(id_c, sql_row[0])==0) {
			if (strcmp(pw_c, sql_row[1])) {
				mysql_free_result(sql_res);
				//DB ���� �ݱ�
				mysql_close(connection);
				delete query;
				return false;
			}
		}
	}

	if (id_being == false) {
		cout << "���̵� �������� ����" << endl;
		reverseScene();
		mysql_free_result(sql_res);
		//DB ���� �ݱ�
		mysql_close(connection);
		delete query;
		return false;
	}

	reverseScene();
	
	mysql_free_result(sql_res);
	//DB ���� �ݱ�
	mysql_close(connection);
	delete query;
	
	return true;
	/*
	

	//mysql test
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_res;
	MYSQL_ROW sql_row;
	int query_stat;

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//�ѱ� ����ϱ� ���� �߰��ϱ�
	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	//select������
	char* query = new char[strlen("SELECT * FROM ") * strlen(tableName)];
	strcpy_s(query, strlen("SELECT * FROM "), "SELECT * FROM ");
	strcpy_s(query + strlen("SELECT * FROM "), strlen(tableName), tableName);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//��� ���
	sql_res = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_res)) != NULL) {
		printf("%2s\n", sql_row[0]);
	}
	mysql_free_result(sql_res);

	//DB ���� �ݱ�
	mysql_close(connection);
	delete query;
	//DB��
	*/

}

void MysqlDatabase::playerInit(Player& player) {

}
