#ifndef member_h
#define member_h
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class member
{
	string name;// 회원의 이름
	string c_number; // 회원의 주민등록 번호 
	int age;      // 회원의 나이
	string phone; // 회원의 전화번호
	string renting[2][5]; // 대출중인 도서명, 저자명 저장.
	int renting_num; // 대출중인 도서들의 수. 최대 5권만 빌릴 수 있음. 
	
	public:
		member(); // 기본 생성자
		~member(){}// 기본 소멸자
		void set_member(string name, string c_number ,int age, string phone); // 회원을 추가/수정할때 사용할 함수. 
		void member_info(); // 회원의 정보 출력.
		string showName(); // 이름 반환
		string showCnum(); // 주민번호 반환
		int showAge();     // 나이 반환
		string showPhone();// 전화번호 반환.
		bool getRenting(string title,string author); // 대출받아온 책의 도서명,저자명을 회원에게도 저장해줍니다.
		void returnRenting(string title,string author);  // 반납합니다.
		int showRenting_num(); // 대출중인 책의 수 반환
		int show_renting();    // 대출중인 책의 정보를 반환. 거기에 대해 그 수도 반환해줍니다.(왜 궂이 위의 대출중인 책의 수 반환이 있는데 따로 반환값을 만들었는가 하면 이렇게 사용하면 훨씬 편리하기 때문입니다.)
		string show_renting_title(int user); // 대출중인 책의 제목만 반환. 매개변수로 그 위치의 값을 받아(배열의 위치) 접근
		string show_renting_author(int user); // 대출중인 책의 저자명만 반환. 매개변수로 그 위치의 값을 받아(배열의 위치) 접근
};
#endif
