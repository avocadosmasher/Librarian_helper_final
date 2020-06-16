#ifndef library_h
#define library_h
#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
#include <map>
#include "book.h"

class library
{
	vector <member> vmember; // 책들이 저장될 vector
	vector <book> vbook;     // 도서가 저장될 vector

	public:
        library(){} // 기본생성자.
        ~library(){} // 기본소멸자.
        void addMember();    // 회원추가
 	    void addBook();      // 도서추가
 	    void searchMember(); // 회원검색
 	    void searchBook();   // 도서검색
 	    void modifyMember(); // 회원정보 수정
 	    void rentBook();     // 대출기능
 	    void returnBook();   // 반납기능
 	    void listBook();     // 도서의 리스트를 보여줌
 	    void listMember();   // 회원의 리스트를 보여줌.
 	    void showBook();     // 해당 책에 대한 정보를 보여주는 함수.
	    void showMember();   // 해당 회원에 대한 정보를 보여주는 함수.
	    void deleteMember(); // 해당 회원에 대한 정보를 제거.
	    void deleteBook();   // 해당 책에 대한 정보를 제거 함.
};
#endif
