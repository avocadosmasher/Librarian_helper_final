#ifndef book_h
#define book_h
#include "member.h"
#include <iostream>
#include <string>
#include <vector>

class book{
	string title;    // 도서의 제목(이름). 
	string author;   // 도서의 저자. 
	string genre;    // 도서의 장르
	string publisher;// 도서의 출판사.  
	int num;         // 도서의 수
	int rent;        // 대출 되어있는 도서의 수.
	string location; // 도서의 위치.
	vector<string> renter_name; // 대출자의 이름 
	vector<string> renter_c_num; // 대출자의 주민번호 
	
	
	public:
		book();  // 기본 생성자.
		~book(){} // 기본 소멸자. 
		void new_book(string title,string author,string genre,string publisher,int num, int rent, string location); // 새로운 책(아예 처음 들어온 신상 책) 추가 
		void book_info();  // 책에 대한 정보를 보여줌. 
		void rentbook();   // 책을 대출함. 
		void returnbook(); // 해당 책을 반납함. 
		void deletebook(); // 해당 책을 폐기처분해서 없앰. 
		void addbook();    // 해당 책의 수를 늘림. (같은 책이 들어옴)
		string showTitle();    // 제목 반환
		string showAuthor();   // 작가 반환 
		int showNumofbook();  // 해당 책의 수 반환.
		int showRentbook();    // 대출중인 책의 수 반환.
		string showLocation(); // 해당 책의 위치를 반환 
		void get_renter_info(string name,string c_num); // 대출자에 대한 정보 입력.
		bool get_returned(string name, string c_num); // 반납자 처리.
		void chained_modify_member(string name,string c_number,string new_name,string new_c_num); // 회원정보 수정에 반응하여 같은 변화를 적용시켜 주기 위함.
		void reduce_num(); // 책의 수 감소
};
#endif
