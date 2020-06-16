#ifndef login_h
#define login_h
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Login{
	string password; // 비밀번호 6자리 내의 아무 문자나 다 가능. (공백 불가) 
	int pStack; // 비밀번호를 잘못 입력한 횟수... 3스택까지 올라갔을 시 비번입력 불가. 
	int qStack; // 질문에 대한 답변을 잘못 입력했을시 그 잘못 입력했던 횟수를 저장해 놓을 변수 
	string question; // 비번을 바꿀때 사용하기 위한 질문이 저장될 string형 변수. 
	string answer; // 질문에 대한 답이 저장될 string 변수 
	
	public:
		Login(); // 생성자. password는 제 주민 앞자리인 970426로 초기화, 질문은 "내 이니셜은?" 답변은 "KYW"로 초기화 합니다. 
		~Login(){} //기본 소멸자.
		void ChangePassword(); // 비번을 바꿀때 사용할 함수. 두번의 입력을 통해 비번의 확인또한 할 예정임. 무사히 종료되기 전 pStack과 qStack 0으로 리셋 
		// 비밀번호는 6자리로 제한. (문자, 숫자, 특수문자 다됨. 6자리 내라면 다 가능.)
		// string 클래스의 멤버함수인 size()를 이용하여 6자리를 넘는 비밀번호 입력 시 다시 입력을 받는것으로 하자.
		// 비밀번호 확인 기능을 사용하여 처음 입력했던 비밀번호를 그대로 입력하지 못하면 다시 처음부터 입력받는 형식으로 진행.

		bool CheckPassword(string enter); // 사용자가 입력한 비번과 저장된 비번이 일치하는지 확인. 의미는 없지만 비밀번호 맞추면 pStack, qStack 0으로 리셋. 
		bool CheckQnA(string enter); // 사용자가 입력한 질문에 대한 답이 저장된 답변과 일치하는지 확인. 
		int ShowpStack(); // 비번을 틀린 횟수를 반환.
		int ShowqStack(); // 질문에 대한 답변을 틀린 횟수를 반환.
		void ShowQuestion(); // 문제를 출력 

		void ChangeQnA(); // 질문과 답변을 바꿀때 사용할 함수. 이 기능은 로그인하고 들어갔을 때 사용가능한 기능이다.
		// 따라서 사용자는 이미 올바른 사용자라는 판단하에 별다른 판별은 필요하지 않다. 
};
#endif
