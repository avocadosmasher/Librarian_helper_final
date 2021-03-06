#include "login.h"
#include <iostream>
#include <string>
#include <algorithm>

Login::Login(){
	password = "970426"; // 초기비밀번호는 제가 임의로 설정하였습니다.
	pStack = 0;
	qStack = 0;
	question = "내 이니셜은?"; // 질문도 제가 임의로
	answer = "kyw"; // 제 이니셜로 답변을 설정
}

void Login::ChangePassword(){ // 비밀번호 변경을 위한 멤버함수.
	string user1; // 사용자가 처음 입력한 비밀번호를 입력 받을 객체
	string user2; // 사용자가 비밀번호 확인을 위해 입력한 문자열을 입력받을 객체
	 
	while(1){ // 이미 main에서 나만의 Q&A에 대한 검사가 모두 완료된후 올바른 사용자라 판별되었을때 호출됨으로 바로 진행합니다.
		cout << "현 기능의 종료를 원할시에는 exit이라고 입력해 주세요." << endl;
		cout << "새로운 비밀번호 : ";
		getline(cin,user1);
		
		if(user1 == "exit") break; // 현 기능을 종료하고 싶다면 exit을 통해 나갑니다.
		
		else if(user1.size() == 6){ // 비밀번호 변경 진행. 
			try{
				for(int i = 0; i<6; i++){
					if(user1[i] == ' '){ // 공백이 입력되어 있으면 오류임.
						throw "공백은 비밀번호에 포함될 수 없습니다."; // 비밀번호는 공백이 올 수 없습니다.
					}
				}
				cout << "비밀번호 확인 : "; // 비밀번호를 확인해달라는 요청.
				getline(cin,user2);
				if(user1 == user2){ //변경완료입니다.
					password = user1;
					cout << "비밀번호 변경이 완료되었습니다." << endl; // 
					break;
				}
				else{ // 비밀번호가 일치하지 않다면 비밀번호 변경을 처음부터 다시 진행합니다.
					cout << "입력하신 비밀번호가 일치하지 않습니다."<< endl;
					cout << "비밀번호 변경을 처음부터 다시 진행합니다." << endl;
				}
			}
			catch(const char * s){ // 예외처리를 합시다.
				cout << s << endl;	
			}
		}
		else{ // 만약 size가 6자리가 되지 않는다면 비밀번호의 형식을 지키지 않았기 때문에 비밀번호의 형식을 알려주고 다시 진행합니다.
			cout << "비밀번호는 공백을 포함하지 않는 6자리 이어야 합니다.(문자,숫자 둘다 가능)" << endl; 
			continue;
		}
	}
}

bool Login::CheckPassword(string enter){ // 비밀번호가 맞는지 확인하는 부분.
	if(enter == password){ // 만약 맞다 그러면 나만의 질문 스택도 비밀번호 오류 스택도 전부 초기화해줍니다.
		pStack = 0; // 비번을 맞췃으니 다시 0으로 리셋 
		qStack = 0; // Q&A도 스택도 0으로 초기화 시켜줍시다.(결국 비밀번호를 맞춘거니 올바른 사용자가 맞다고 판단.) 
		return true;
	}
	else{ // 틀렸으니 스택 ++
		pStack++; // pStack을 ++해줌으로써 틀린 횟수를 증가. 
		return false;
	}
}
bool Login::CheckQnA(string enter){ // 나만의 질문 답변 확인
	
	if(enter == answer){ // 답변의 일치를 확인합니다.
		qStack = 0; // 맞췄으니 초기화 
		pStack = 0; // 나만의 질문에 대한 답변을 맞추었으니 향후에 비번을 바꾸던 말던 상관없이 일단 올바른 사용자임을 확인. 
		return true; // true를 반환
	}
	else{ // 답변이 불일치
		qStack++; // 나만의 질문 답변 틀린횟수 증가. 
		return false; // false 반환
	}
}
int Login::ShowpStack(){ // 현 Password 오류 스택을 반환
	return pStack;
} 
int Login::ShowqStack(){ // 현 나만의 질문 오류 스택을 반환
	return qStack;
}
void Login::ShowQuestion(){ // 나만의 질문을 보여줍니다.
	cout << question << endl;
}

void Login::ChangeQnA(){ // 나만의 질문 변경기능
	string new_question; // 새로운 질문이 저장될 변수
	string new_answer;   // 그 질문에 대한 답변이 저장될 변수
	string yn; // yes or no
	try {
		while (1) { // 기본적으로 그냥 새 질문을 입력하고 그 질문이 맞는지 확인한 후 하는 식의(새 답변도 동일한 형식) 진행방식입니다.
			cout << "새로운 질문 입력 : ";
			getline(cin, new_question);

			cout << "입력하신 질문이 []안의 질문이 맞습니까? (yes/no)" << endl <<"--종료를 원할 시 다른 아무키나 입력해주세요.--" << endl << "[" << new_question << "]" << endl;
			getline(cin, yn);
			transform(yn.begin(), yn.end(), yn.begin(), ::toupper); // 이부분만 특이하니 설명합니다. transform을 통해 대소문자 입력을 구분하지않고 그대로 받아들여 다 대문자화 해줍니다.
			if (yn == "YES");

			else if (yn == "NO") {
				cout << "다시 진행합니다." << endl;
				continue;
			}
			else {
				throw "메인메뉴로 돌아갑니다.";
			}

			while (1) { // 위와 동일
				cout << "새로운 답변 입력 : ";
				getline(cin, new_answer);

				cout << "입력하신 답변이 []안의 답변이 맞습니까? (yes/no)" << endl << "-- 종료를 원할 시 다른 아무키나 입력해주세요.--" << endl << "[" << new_answer << "]" << endl;
				getline(cin, yn);
				transform(yn.begin(), yn.end(), yn.begin(), ::toupper);

				if (yn == "YES") {
					question = new_question;
					answer = new_answer;
					cout << "Q&A 변경이 완료되었습니다." << endl;
					break;
				}
				else if (yn == "NO") {
					continue;
				}
				else {
					throw "메인메뉴로 돌아갑니다.";
				}
			}
			break;
		}
	}
	catch (const char* s) { // 예외처리.
		cout << s << endl;
	}
}
