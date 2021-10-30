#include "MysqlDatabase.h"
MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;
int query_stat;


void MysqlDatabase::create_account() {
	//회원가입을 하고 id, password, money를 데이터 베이스에 저장. id는 중복 x

	//아이디는 최대 20까지, 한글X, 영어나 숫자만을 이용하여 만들기
	//비밀번호도 영어나 숫자만을 이용하여 만들기 최대 20

	char id[50];
	char pw[50];
	char query[255];
	bool idAndPwCheck;

	//mysql 계정 연결
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
	//mysql 계정 연결 END

	//아이디, 비번 입력받기
	while (true) {
		idAndPwCheck = true;
		cout << "--------회원가입--------" << endl << endl;
		cout << "아이디, 비밀번호는 모두 영어 소문자와 숫자만을 이용하여 만들 수 있으며\n최대 50자까지 설정 가능합니다." << endl << endl;
		cout << "아이디 입력 : "; fgets(id, 50, stdin); CHOP(id);
		Sleep(1000);
		cout << "비밀번호 입력 : "; fgets(pw, 50, stdin); CHOP(pw);

		//id 체크
		for (int i = 0; id[i] != ' '; i++) {
			if ((id[i] < 'a' || id[i] > 'z') && (id[i] < '0' || id[i] > '9')) { idAndPwCheck = false; break; }
		}
		//pw체크
		for (int i = 0; pw[i] != ' '; i++) {
			if ((pw[i] < 'a' || pw[i] > 'z') && (pw[i] < '0' || pw[i] > '9')) { idAndPwCheck = false; break; }
		}

		//모두 잘 입력하면 while END
		if (idAndPwCheck == true) { break; }

		system("cls"); cout << endl;
		cout << "아이디와 비밀번호는 영어 소문자와 숫자만을 이용해서 만들어 주세요." << endl << endl;
		system("pause"); system("cls");

	}
	//while END
	//아이디, 비번 입력받기 END

	//계정 생성 여부 선택
	int sel; //선택용 변수
	while (true) {

		system("pause"); system("cls");
		cout << "계정을 생성하시겠습니까?" << endl << endl;
		cout << "1. 네" << endl;
		cout << "2. 아니오" << endl << endl;
		cout << "번호 선택 >> "; cin >> sel;

		switch (sel) {
		case 1:
			system("pause"); system("cls");
			cout << "계정이 생성됩니다." << endl;
			break;
			cout << endl; system("pause"); system("cls");
		case 2:
			system("pause"); system("cls"); cout << endl;
			cout << "메인 화면으로 돌아갑니다." << endl;
			return;
		default:
			cout << endl; system("pause"); system("cls");
		}

		if (sel == 1) break;
	}
	//while END
	//계정 생성 여부 선택 END

	//계정 생성(db에 저장)
	cout << "id: " << id << endl;

	//db에 정보 저장(Id, password, money)
	sprintf(query, "insert into %s values "
		"('%s', '%s', '10000')", //money는 처음에 만원 지급
		"playeraccount", id, pw);//minegame_db.playeraccount에 데이터 저장

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	mysql_close(connection);
	cout << "계정 생성 완료" << endl;
	//db에 정보 저장(Id, password, money) END
}

void MysqlDatabase::ranking_print() {
	//돈이 많은 회원순으로 출력

	char query[255];

	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//select쿼리문
	sprintf(query, "SELECT * FROM %s ORDER BY `money` DESC",
		"playeraccount");//money가 많은순(내림차순)으로 정렬
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//결과 출력
	sql_result = mysql_store_result(connection);
	int ranking = 1;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%d. ID : %2s MONEY : %2s \\ \n", ranking++, sql_row[0], sql_row[2]); //0번 : id, 2번 : money
	}
	mysql_free_result(sql_result);

	//DB 연결 닫기
	mysql_close(connection);
	//DB끝

}

bool MysqlDatabase::login() {

	char id_c[50];
	char pw_c[50];
	bool id_being = false;

	gotoXY(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	cout << "로그인" << endl;
	
	cout << "아이디 : "; fgets(id_c, 50, stdin); CHOP(id_c);
	Sleep(500);
	cout << "비밀번호 : "; fgets(pw_c, 50, stdin); CHOP(pw_c);

	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_res;
	MYSQL_ROW sql_row;
	int query_stat;

	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	//select쿼리문
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

	//결과 출력
	sql_res = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_res)) != NULL) {
		id_being = true;
		if (strcmp(id_c, sql_row[0])==0) {
			if (strcmp(pw_c, sql_row[1])) {
				mysql_free_result(sql_res);
				//DB 연결 닫기
				mysql_close(connection);
				delete query;
				return false;
			}
		}
	}

	if (id_being == false) {
		cout << "아이디가 존재하지 않음" << endl;
		reverseScene();
		mysql_free_result(sql_res);
		//DB 연결 닫기
		mysql_close(connection);
		delete query;
		return false;
	}

	reverseScene();
	
	mysql_free_result(sql_res);
	//DB 연결 닫기
	mysql_close(connection);
	delete query;
	
	return true;
	/*
	

	//mysql test
	MYSQL* connection = NULL, conn;
	MYSQL_RES* sql_res;
	MYSQL_ROW sql_row;
	int query_stat;

	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//한글 사용하기 위해 추가하기
	mysql_query(connection, "set session character_set_connection=euckr;");
	mysql_query(connection, "set session character_set_results=euckr;");
	mysql_query(connection, "set session character_set_client=euckr;");

	//select쿼리문
	char* query = new char[strlen("SELECT * FROM ") * strlen(tableName)];
	strcpy_s(query, strlen("SELECT * FROM "), "SELECT * FROM ");
	strcpy_s(query + strlen("SELECT * FROM "), strlen(tableName), tableName);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//결과 출력
	sql_res = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_res)) != NULL) {
		printf("%2s\n", sql_row[0]);
	}
	mysql_free_result(sql_res);

	//DB 연결 닫기
	mysql_close(connection);
	delete query;
	//DB끝
	*/

}

void MysqlDatabase::playerInit(Player& player) {

}
