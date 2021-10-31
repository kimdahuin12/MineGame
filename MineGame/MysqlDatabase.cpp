#include "MysqlDatabase.h"

MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;
int query_stat;


void MysqlDatabase::create_account() {
	//ȸ�������� �ϰ� id, password, money�� ������ ���̽��� ����. id�� �ߺ� x

	//���̵�� �ִ� 20����, �ѱ�X, ��� ���ڸ��� �̿��Ͽ� �����
	//��й�ȣ�� ��� ���ڸ��� �̿��Ͽ� ����� �ִ� 20
	char query[255];
	char id[50] = { 0, };
	char pw[50] = { 0, };
	bool idAndPwCheck;

	//mysql ���� ����
	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

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
		while (id[0] == 0) {
			cout << "���̵� �Է� : "; fgets(id, 50, stdin); CHOP(id);
		}
		while (pw[0] == 0) {
			cout << "��й�ȣ �Է� : "; fgets(pw, 50, stdin); CHOP(pw);
		}

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

	//db�� ���� ����(Id, password, money) //money�� ó���� ���� ����
	sprintf(query, "insert into playeraccount values ('%s', '%s', '10000')",id, pw);//minegame_db.playeraccount�� ������ ����

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		//fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		cout << "�̹� �����ϴ� ���̵��Դϴ�." << endl;
		return;
	}

	mysql_close(connection);

	//mysql ���� �ٽ� �����ϰ� ���� ���� 0���� �ʱ�ȭ -----			�����κ�
	mysql_init(&conn);
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	sprintf(query, "insert into mineralCount(id) values('%s')", id);//minegame_db.mineralCount

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	mysql_close(connection);
	//mysql ���� �ٽ� �����ϰ� ���� ���� 0���� �ʱ�ȭ -----			�����κ�END

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
	sprintf(query, "SELECT id, FORMAT(money, 0) FROM playerAccount ORDER BY(money) DESC");//money�� ������(��������)���� ����
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//��� ���
	sql_result = mysql_store_result(connection);
	int ranking = 1;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%d. ID : %-20s MONEY : %-20s \\ \n", ranking++, sql_row[0], sql_row[1]); //0�� : id, 2�� : money
	}
	mysql_free_result(sql_result);

	//DB ���� �ݱ�
	mysql_close(connection);
	//DB��

}

bool MysqlDatabase::login(char* id, unsigned long& money) {
	char query[255];
	char id_c[50] = { 0, };
	char pw_c[50] = { 0, };
	bool id_being = false;

	gotoXY(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	cout << "�α���" << endl;
	
	while (id_c[0] == 0) {
		cout << "���̵� : "; fgets(id_c, 50, stdin); CHOP(id_c);
	}
	while (pw_c[0] == 0) {
		cout << "��й�ȣ : "; fgets(pw_c, 50, stdin); CHOP(pw_c);
	}

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	sprintf(query, "SELECT * FROM playeraccount where id = '%s'", id_c);
	//select������
	//char* query = new char[strlen("SELECT * FROM playeraccount where id = \"")+strlen(id_c)+strlen("\"") + 1];
	//strcpy(query, "SELECT * FROM playeraccount where id = \"");
	//strcat(query, id_c);
	//strcat(query, "\"");
	
	/*char* query = new char[strlen("SELECT * FROM ") * strlen("playeraccount")];
	strcpy_s(query, strlen("SELECT * FROM playeraccount"), "SELECT * FROM playeraccount");*/
	//strcpy_s(query + strlen("SELECT * FROM "), strlen("playeraccount"), "playeraccount");
	
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	//��� ���
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		if (strcmp(id_c, sql_row[0])==0) { //id�� ����
			id_being = true;
			if (strcmp(pw_c, sql_row[1])==0) { //����� ����
				//�α��� ����
				money = atoi(sql_row[2]);//money ����
			}
			else { //����� �ٸ���
				gotoXY(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
				cout << "�α��� ����" << endl;
				reverseScene();
				mysql_free_result(sql_result);
				//DB ���� �ݱ�
				mysql_close(connection);
				return false;
			}
		}
	}

	if (id_being == false) {
		cout << "���̵� �������� ����" << endl;
		reverseScene();
		mysql_free_result(sql_result);
		//DB ���� �ݱ�
		mysql_close(connection);
		return false;
	}

	reverseScene();
	
	mysql_free_result(sql_result);
	//DB ���� �ݱ�
	mysql_close(connection);

	//player���� �Ѱ��� id
	id_c[strlen(id_c) - 1] = 0;
	strcpy(id, id_c);


	return true;
}

void MysqlDatabase::playerInit(Player* player) {
	char query[455];
	char* mineralName[MINERAL_MAX];
	int mineralCount[MINERAL_MAX];
	int mineralIdx = 0;
	
	//�ʱ�ȭ
	for (int i = 0; i < MINERAL_MAX; i++) {
		mineralName[i] = 0; mineralCount[i] = 0;
	}

	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//select������. �̳׶� �̸��� �ҷ�����
	sprintf(query, "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'mineralCount' AND column_name not in('id')");
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//�̳׶� �̸����� �����Ѵ�.
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		mineralName[mineralIdx] = new char[strlen(sql_row[0]) + 1];
		strcpy(mineralName[mineralIdx++], sql_row[0]);
	}

	//select������
	sprintf(query, "SELECT `�� ��ĳ������Ʈ`, `�� ���̽��ҳ���Ʈ`, `�� ��Ʈ��`, `�� �÷����Ʈ`, `�� �Ƹ�����Ʈ`, `�� ���ǵ�����Ʈ`,"
		"`�� ���ǳ�`, `�� ���`, `�� ����`, `�� ��Ű��`, `�� �丮��Ʈ`, `�� ���޶���`, `�� ����Ƹ���`, `�� ���ֶ���Ʈ`, `�� �����̾�`,"
		"`�� ���̾Ƹ��`, `�� �׶��������Ʈ`, `�� ��������Ʈ` FROM mineralCount WHERE id = '%s'", player->getId());
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//��� ��� //�̸��� �°� ���� ����
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		//mineralIdx�� ������ ��ȣ��� ����
		for (mineralIdx = 0; mineralIdx < MINERAL_MAX; mineralIdx++) {
			for (; mineralCount[mineralIdx] < atoi(sql_row[mineralIdx]); mineralCount[mineralIdx]++) {
				//������ ������ db�� ����� ������ ������ ������������ ��� ������ �ø���, player�� ������ �ְ��Ѵ�.
				player->AddMineral(mineralName[mineralIdx]);
			}
		}
	}
	mysql_free_result(sql_result);

	//DB ���� �ݱ�
	mysql_close(connection);
}

void MysqlDatabase::playerMineralSave(MyItem** items, int itemsCount, const char* playerId) {

	char query[255];
	for (int i = 0; i < itemsCount; i++) {
		//�ʱ�ȭ
		mysql_init(&conn);

		//DB����
		connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
		if (connection == NULL) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			return;
		}

		//����
		//const char* itemCount = to_string(items[i]->getCount());
		sprintf(query, "UPDATE mineralCount SET `%s`=%d WHERE id='%s'", items[i]->getName(), items[i]->getCount(), playerId);//minegame_db.playeraccount�� ������ ����

		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			return;
		}
	}
	mysql_close(connection);
}

int MysqlDatabase::MineralCondition(int id) {
	//������ ���� ���ǿ� �´� ���� ������ return
	char query[255];

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 0;
	}

	sprintf(query, "SELECT `entrance_condition` FROM mineinfo where id = '%d'", id);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return 0;
	}

	//��� ���
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		return atoi(sql_row[0]);
	}

}

void MysqlDatabase::MineInfoSave(Mine& mine, int id) {
	//�������
		/*
	price
	name
	produce
	delete
	percentageS
	*/

	int price = 0;
	char* name = 0;
	int produceSec = 0;
	int deleteSec = 0;
	float percentages[MINERAL_ITEM_COUNT + 1];

	char query[255];

	//�ʱ�ȭ
	mysql_init(&conn);

	//DB����
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	sprintf(query, "SELECT `entrance_price`, `mine_name`, `mineral_produce`, `mineral_delete`, "
		"`yellow_percentage`, `violet_percentage`, `red_percentage`, `green_percentage`, "
		"`blue_percentage`, `skyblue_percentage` FROM mineinfo where id = '%d'", id);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//��� ���
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		price = atoi(sql_row[0]);
		name = new char[strlen(sql_row[1]) + 1];
		strcpy(name, sql_row[1]);
		produceSec = atoi(sql_row[2]);
		deleteSec = atoi(sql_row[3]);
		percentages[DARK_YELLOW] = atoi(sql_row[4]);
		percentages[DARK_VIOLET] = atoi(sql_row[5]);
		percentages[DARK_RED] = atoi(sql_row[6]);
		percentages[DARK_GREEN] = atoi(sql_row[7]);
		percentages[DARK_BLUE] = atoi(sql_row[8]);
		percentages[DARK_SKYBLUE] = atoi(sql_row[9]);
	}


	mine.SetMineInfo(price, name, produceSec, deleteSec, percentages);

}