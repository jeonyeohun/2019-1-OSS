#include "user.h"
#include "menu.h"

void clearBuff (){ // 입력버퍼 초기화를 위한 함수
	while(getchar() != '\n');
}

void print_list (LOGIN* userlist[], int count){ // 저장되어 있는 데이터들을 리스트화해서 보여주기
	printf("UserID\tPassword\n");
	for (int i=0 ; i<count ; i++){
		printf("%s\t%s\n", userlist[i]->id, userlist[i]->password);
	}
}

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
	int menu_flag; // 사용자가 입력한 메뉴가 제공하는 메뉴에 있는지 확인. 있으면 1, 없으면 0;
	char options [4][10] = {"login", "join", "list", "exit"}; // 프로그램에서 제공하는 메뉴
	char user_input [50]; // 사용자가 입력하는 메뉴
	char prompt [3]; // 프롬포트 모양 생성

	// 파일이름이 입력되지 않은 경우 에러 //
	if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
	}
	int count = load_file(userlist, argv[1]); // 파일에 저장된 정보의 개수 읽어오기

	while (1) {
		#ifdef DEBUG_MODE
			printf("\n\nCOUNT: %d\n", count);
			printf("IS_LOGIN: %d\n", is_login);
		#endif

		menu_flag=0; // 루프를 한번 돌때 마다 플래그를 초기화. 사용자가 계속 다른 메뉴를 입력하기 때문

		// 로그인 여부에 따라 프롬프트 모양 바꿔주기 //
		if (is_login == 0){
			ask_menu(is_login);
			strcpy(prompt, "> \0");
		}
		else if (is_login == 1){
			ask_menu(is_login);
			strcpy(prompt, "# \0");
		}
		printf("%s", prompt);

		// 사용자에게 메뉴 입력받기. 공백을 포함한 문자열이 들어 올 수 있기 때문에 fgets로 입력받기 //
		fgets(user_input, sizeof(user_input), stdin);
		user_input[strlen(user_input)-1] = '\0'; // 문자열의 마지막 문자를 개행문자에서 널문자로 바꿔줌

		// 프로프트의 모양이 "# " (로그인 되어있을 때)
		if (!strcmp(prompt, "# ")){
			//사용자가 logout을 입력한 경우에만 logout 함수를 호출한다.//
			if (!strcmp(user_input, "logout")){
				logout(&is_login);
				continue;
			}
			// logout 외의 나머지 커맨드는 모두 그대로 출력해준다 //
			else{
				printf("%s\n", user_input);
				continue;
			}
		}
		// 프롬프트의 모양이 "> " (로그인이 안되어있을 때) //
		else{
			for (int i=0 ; i<4 ; i++){
				// 사용자가 입력한 명령어가 프로그램에서 기능을 제공하는 명령어라면 menu_flag 를 1로 바꾼다. //
				if (!strncmp (options[i], user_input, strlen(options[i])-1)){
					menu_flag = 1;
					break;}}
		}

		// 로그인이 되어있지 않고, 사용자가 입력한 명령어가 지원되지 않는 명령어라면 에러메세지 출력 //
		if (is_login == 0 && menu_flag == 0){printf("No such command!\n");}

		else {
			// login 이 입력되었을 때 //
			if (!strncmp("login", user_input, strlen(user_input)-1)){
				if(is_login==0)	is_login = login(userlist, count);
				clearBuff();
			}
			// join 이 입력되었을 때 //
			else if (!strncmp("join", user_input, strlen(user_input)-1)){
				join(userlist, count);
				count++;
				clearBuff();
			}
			// list 가 입력되었을 때 //
			else if (!strncmp("list", user_input, strlen(user_input)-1)){
				print_list(userlist, count);
			}
			// exit이 입력되었을때 //
			else if (!strncmp("exit", user_input, strlen(user_input)-1)){
				break;
				}
			}
	}
  save_file(userlist, count, argv[1]);
	printf("Good Bye~!\n");
  return 0;
}
