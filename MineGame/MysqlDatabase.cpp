#include "MysqlDatabase.h"

MYSQL* connection = NULL, conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;
int query_stat;


void MysqlDatabase::create_account() {
	//회원가입을 하고 id, password, money를 데이터 베이스에 저장. id는 중복 x

	//아이디는 최대 20까지, 한글X, 영어나 숫자만을 이용하여 만들기
	//비밀번호도 영어나 숫자만을 이용하여 만들기 최대 20
	char query[255];
	char id[50] = { 0, };
	char pw[50] = { 0, };
	bool idAndPwCheck;

	//mysql 계정 연결
	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

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
		while (id[0] == 0) {
			cout << "아이디 입력 : "; fgets(id, 50, stdin); CHOP(id);
		}
		while (pw[0] == 0) {
			cout << "비밀번호 입력 : "; fgets(pw, 50, stdin); CHOP(pw);
		}

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

	//db에 정보 저장(Id, password, money) //money는 처음에 만원 지급
	sprintf(query, "insert into playeraccount values ('%s', '%s', '10000')",id, pw);//minegame_db.playeraccount에 데이터 저장

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		//fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		cout << "이미 존재하는 아이디입니다." << endl;
		return;
	}

	mysql_close(connection);

	//mysql 계정 다시 연결하고 광물 갯수 0으로 초기화 -----			광물부분
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
	//mysql 계정 다시 연결하고 광물 갯수 0으로 초기화 -----			광물부분END

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
	sprintf(query, "SELECT id, FORMAT(money, 0) FROM playerAccount ORDER BY(money) DESC");//money가 많은순(내림차순)으로 정렬
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//결과 출력
	sql_result = mysql_store_result(connection);
	int ranking = 1;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%d. ID : %-20s MONEY : %-20s \\ \n", ranking++, sql_row[0], sql_row[1]); //0번 : id, 2번 : money
	}
	mysql_free_result(sql_result);

	//DB 연결 닫기
	mysql_close(connection);
	//DB끝

}

bool MysqlDatabase::login(char* id, unsigned long& money) {
	char query[255];
	char id_c[50] = { 0, };
	char pw_c[50] = { 0, };
	bool id_being = false;

	gotoXY(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	cout << "로그인" << endl;
	
	while (id_c[0] == 0) {
		cout << "아이디 : "; fgets(id_c, 50, stdin); CHOP(id_c);
	}
	while (pw_c[0] == 0) {
		cout << "비밀번호 : "; fgets(pw_c, 50, stdin); CHOP(pw_c);
	}

	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return false;
	}

	sprintf(query, "SELECT * FROM playeraccount where id = '%s'", id_c);
	//select쿼리문
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

	//결과 출력
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		if (strcmp(id_c, sql_row[0])==0) { //id가 같고
			id_being = true;
			if (strcmp(pw_c, sql_row[1])==0) { //비번이 같다
				//로그인 성공
				money = atoi(sql_row[2]);//money 저장
			}
			else { //비번이 다르다
				gotoXY(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
				cout << "로그인 실패" << endl;
				reverseScene();
				mysql_free_result(sql_result);
				//DB 연결 닫기
				mysql_close(connection);
				return false;
			}
		}
	}

	if (id_being == false) {
		cout << "아이디가 존재하지 않음" << endl;
		reverseScene();
		mysql_free_result(sql_result);
		//DB 연결 닫기
		mysql_close(connection);
		return false;
	}

	reverseScene();
	
	mysql_free_result(sql_result);
	//DB 연결 닫기
	mysql_close(connection);

	//player한테 넘겨줄 id
	id_c[strlen(id_c) - 1] = 0;
	strcpy(id, id_c);


	return true;
}

void MysqlDatabase::playerInit(Player* player) {
	char query[455];
	char* mineralName[MINERAL_MAX];
	int mineralCount[MINERAL_MAX];
	int mineralIdx = 0;
	
	//초기화
	for (int i = 0; i < MINERAL_MAX; i++) {
		mineralName[i] = 0; mineralCount[i] = 0;
	}

	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//select쿼리문. 미네랄 이름들 불러오기
	sprintf(query, "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'mineralCount' AND column_name not in('id')");
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//미네랄 이름들을 저장한다.
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		mineralName[mineralIdx] = new char[strlen(sql_row[0]) + 1];
		strcpy(mineralName[mineralIdx++], sql_row[0]);
	}

	//select쿼리문
	sprintf(query, "SELECT `▲ 스캐폴라이트`, `◈ 스미스소나이트`, `◎ 시트린`, `◆ 플루라이트`, `● 아메지스트`, `▤ 래피도라이트`,"
		"`▣ 스피넬`, `◐ 루비`, `□ 가넷`, `＠ 터키석`, `＃ 페리도트`, `▶ 에메랄드`, `◀ 아쿠아마린`, `■ 아주라이트`, `¤ 사파이어`,"
		"`▽ 다이아몬드`, `○ 그란디디어라이트`, `◇ 배니토아이트` FROM mineralCount WHERE id = '%s'", player->getId());
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//결과 출력 //이름에 맞게 갯수 저장
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		//mineralIdx는 광물의 번호라고 생각
		for (mineralIdx = 0; mineralIdx < MINERAL_MAX; mineralIdx++) {
			for (; mineralCount[mineralIdx] < atoi(sql_row[mineralIdx]); mineralCount[mineralIdx]++) {
				//광물의 갯수가 db에 저장된 광물의 갯수과 같아질때까지 계속 갯수를 늘리고, player에 광물을 주가한다.
				player->AddMineral(mineralName[mineralIdx]);
			}
		}
	}
	mysql_free_result(sql_result);

	//DB 연결 닫기
	mysql_close(connection);
}

void MysqlDatabase::playerMineralSave(MyItem** items, int itemsCount, const char* playerId) {

	char query[255];
	for (int i = 0; i < itemsCount; i++) {
		//초기화
		mysql_init(&conn);

		//DB연결
		connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
		if (connection == NULL) {
			fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
			return;
		}

		//쿼리
		//const char* itemCount = to_string(items[i]->getCount());
		sprintf(query, "UPDATE mineralCount SET `%s`=%d WHERE id='%s'", items[i]->getName(), items[i]->getCount(), playerId);//minegame_db.playeraccount에 데이터 저장

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
	//광산의 입장 조건에 맞는 광물 갯수를 return
	char query[255];

	//초기화
	mysql_init(&conn);

	//DB연결
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

	//결과 출력
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		return atoi(sql_row[0]);
	}

}

void MysqlDatabase::MineInfoSave(Mine& mine, int id) {
	//순서대로
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

	//초기화
	mysql_init(&conn);

	//DB연결
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

	//결과 출력
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