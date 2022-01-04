#include "MysqlDatabase.h"

sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::ResultSet* res;

int query_stat;


void MysqlDatabase::create_account() {
	//회원가입을 하고 id, password, money를 데이터 베이스에 저장. id는 중복 x

	//아이디는 최대 20까지, 한글X, 영어나 숫자만을 이용하여 만들기
	//비밀번호도 영어나 숫자만을 이용하여 만들기 최대 20
	char query[255];
	char id[50] = { 0, };
	char pw[50] = { 0, };
	bool idAndPwCheck;

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

	try {
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", DB_USER, DB_PASS);
		/* Connect to the MySQL test database */
		con->setSchema(DB_NAME);

		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
		while (res->next()) {
			cout << "\t... MySQL replies: ";
			/* Access column data by alias or column name */
			cout << res->getString("_message") << endl;
			cout << "\t... MySQL says it again: ";
			/* Access column data by numeric offset, 1 is the first column */
			cout << res->getString(1) << endl;
		}


		stmt = con->createStatement();
		sprintf(query, "insert into playeraccount values ('%s', '%s', '10000')", id, pw);
		stmt->executeUpdate(query);

		
		//mysql 계정 다시 연결하고 광물 갯수 0으로 초기화 -----			광물부분
		sprintf(query, "insert into mineralCount(id) values('%s')", id);//minegame_db.mineralCount
		stmt->executeUpdate(query);


		//mysql 계정 다시 연결하고 광물 갯수 0으로 초기화 -----			광물부분END


		cout << "계정 생성 완료" << endl;

		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException& e) {
		cout << "이미 존재하는 아이디입니다." << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	//db에 정보 저장(Id, password, money) END
}

void MysqlDatabase::ranking_print() {
	//돈이 많은 회원순으로 출력
	char query[255];

	try {
		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", DB_USER, DB_PASS);
		/* Connect to the MySQL test database */
		con->setSchema(DB_NAME);

		stmt = con->createStatement();

		//select쿼리문
		sprintf(query, "SELECT id, FORMAT(money, 0) FROM playerAccount ORDER BY(money) DESC");//money가 많은순(내림차순)으로 정렬
		res = stmt->executeQuery(query);
		int ranking = 1;
		while (res->next()) {
			printf("%d. ID : %-20s MONEY : %-20s \\ \n", ranking++, res->getString(0), res->getString(1)); //0번 : id, 2번 : money
			//		printf("%d. ID : %-20s MONEY : %-20s \\ \n", ranking++, sql_row[0], sql_row[1]); //0번 : id, 2번 : money
		}

		//mysql 계정 다시 연결하고 광물 갯수 0으로 초기화 -----			광물부분END


		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException& e) {
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}
/*
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
	
	//char* query = new char[strlen("SELECT * FROM ") * strlen("playeraccount")];
	//strcpy_s(query, strlen("SELECT * FROM playeraccount"), "SELECT * FROM playeraccount");
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

void MysqlDatabase::playerMoneySave(unsigned long playerMoney, const char* playerId) {

	char query[255];
	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//쿼리
	sprintf(query, "UPDATE playeraccount SET money=%d WHERE id='%s'", playerMoney, playerId);//minegame_db.playeraccount에 데이터 저장

	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
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
	mysql_close(connection);
}

void MysqlDatabase::MineInfoSave(Mine& mine, int id) {
	//순서대로
	//price
	//name
	//produce
	//delete
	//percentageS
	

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

	sprintf(query, "SELECT `mine_name`, `mineral_produce`, `mineral_delete`, "
		"`yellow_percentage`, `violet_percentage`, `red_percentage`, `green_percentage`, "
		"`blue_percentage`, `skyblue_percentage` FROM mineinfo where id = '%d'", id);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//결과 출력
	int idx = 0;
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		name = new char[strlen(sql_row[idx]) + 1];
		strcpy(name, sql_row[idx++]);
		produceSec = atoi(sql_row[idx++]);
		deleteSec = atoi(sql_row[idx++]);
		percentages[DARK_YELLOW] = atoi(sql_row[idx++]);
		percentages[DARK_VIOLET] = atoi(sql_row[idx++]);
		percentages[DARK_RED] = atoi(sql_row[idx++]);
		percentages[DARK_GREEN] = atoi(sql_row[idx++]);
		percentages[DARK_BLUE] = atoi(sql_row[idx++]);
		percentages[DARK_SKYBLUE] = atoi(sql_row[idx++]);
	}


	mine.SetMineInfo(name, produceSec, deleteSec, percentages);
	mysql_close(connection);
}

int MysqlDatabase::GetEntrancePrice(int id) {
	char query[255];

	//초기화
	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return NULL;
	}

	sprintf(query, "SELECT `entrance_price` FROM mineinfo where id = '%d'", id);

	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return NULL;
	}

	//결과 출력
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		return atoi(sql_row[0]);
	}

	return NULL;

	mysql_close(connection);
}


void MysqlDatabase::Market(Player& player) {
	//상점
	char query[455];
	char* mineralName[MINERAL_MAX] = {0, };
	int mineralCount[MINERAL_MAX] = {0,};
	long mineralPrice[MINERAL_MAX] = {0,};
	int mineralIdx = 0;

	mysql_init(&conn);

	//DB연결
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//select쿼리문. 미네랄 이름들 불러와서 저장
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

	//select쿼리문. 상품 갯수를 저장
	sprintf(query, "SELECT `▲ 스캐폴라이트`, `◈ 스미스소나이트`, `◎ 시트린`, `◆ 플루라이트`, `● 아메지스트`, `▤ 래피도라이트`,"
		"`▣ 스피넬`, `◐ 루비`, `□ 가넷`, `＠ 터키석`, `＃ 페리도트`, `▶ 에메랄드`, `◀ 아쿠아마린`, `■ 아주라이트`, `¤ 사파이어`,"
		"`▽ 다이아몬드`, `○ 그란디디어라이트`, `◇ 배니토아이트` FROM mineralCount WHERE id = 'itemCount'");
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//광물들의 갯수들을 저장
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		for (mineralIdx = 0; mineralIdx < MINERAL_MAX; mineralIdx++) {
			mineralCount[mineralIdx] = atoi(sql_row[mineralIdx]);
		}
	}

	//select쿼리문. 상품 가격을 저장
	sprintf(query, "SELECT `▲ 스캐폴라이트`, `◈ 스미스소나이트`, `◎ 시트린`, `◆ 플루라이트`, `● 아메지스트`, `▤ 래피도라이트`,"
		"`▣ 스피넬`, `◐ 루비`, `□ 가넷`, `＠ 터키석`, `＃ 페리도트`, `▶ 에메랄드`, `◀ 아쿠아마린`, `■ 아주라이트`, `¤ 사파이어`,"
		"`▽ 다이아몬드`, `○ 그란디디어라이트`, `◇ 배니토아이트` FROM mineralCount WHERE id = 'price'");
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
		return;
	}

	//광물들의 가격들을 저장
	mineralIdx = 0;
	sql_result = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		for (mineralIdx = 0; mineralIdx < MINERAL_MAX; mineralIdx++) {
			mineralPrice[mineralIdx] = atoi(sql_row[mineralIdx]);
		}
	}

	//모두 출력(상품 정보들)
	for (int i = 0; i < MINERAL_MAX; i++) {
		printf("%d. 상품명 : %-30s 갯수 : %-20d 가격 : %-20d\n", (i+1), mineralName[i], mineralCount[i], mineralPrice[i]);
	}

	int sel; //선택용 변수
	const char* selProduct = "";
	
	while (true) {
		gotoXY(0, 80);
		cout << "현재 금액 : " << player.getMoney() <<"원"<<endl;
		gotoXY(0, 81);
		cout << "판매할 상품 번호 선택(나가려면 0번 선택) : ";
		cin >> sel;
		if (sel == 0) {
			return;
		}
		else if (sel <= MINERAL_MAX) {
			selProduct = mineralName[sel - 1]; //미네랄 이름 저장
			if (player.RemoveMineral((char*)selProduct)) {
				player.increaseMoney(mineralPrice[sel - 1]);
				sprintf(query, "UPDATE mineralCount SET `%s`=%d WHERE id='%s'", selProduct, player.GetMineralCount((char*)selProduct), player.getId());//광물 갯수 업데이트
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
					return;
				}
				sprintf(query, "UPDATE playeraccount SET money=%d WHERE id='%s'", player.getMoney(), player.getId());//플레이어 돈 업데이트
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
					return;
				}
				sprintf(query, "UPDATE mineralCount SET `%s`=%d WHERE id='itemCount'", selProduct, (mineralCount[sel-1]+player.GetMineralCount((char*)selProduct)));//광물 전체 갯수 업데이트
				query_stat = mysql_query(connection, query);
				if (query_stat != 0)
				{
					fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
					return;
				}
				gotoXY(0, 80);
				cout << "1개 판매 완료" << endl;
				gotoXY(0, 81);
				cout << "                                            " << endl;

			}
			else {
				gotoXY(0, 80);
				cout << "소유하지 않은 광물" << endl;
				gotoXY(0, 81);
				cout << "                                            " << endl;
			}
		}

		
	}
	

	mysql_free_result(sql_result);

	//DB 연결 닫기
	mysql_close(connection);

}
*/