#include "member.h"
#include <iostream>
#include <string>

using namespace std;

string member::show_renting_title(int user){ // 입력받은 위치의 대출중인 도서의 제목을 반환
	return renting[0][user-1];
}
string member::show_renting_author(int user){ // 위와 동일한 형태로 도서의 저자를 반환.
	return renting[1][user-1];
}


int member::show_renting(){ // 대출중인 도서의 도서명과 저자명을 반환해줍니다.
	int a;
	for(a= 0;a<renting_num;a++){
		cout << "*******************구분******************" << endl;
		cout << "[" << a+1 << "]" << endl;
		cout << "도서명: ";
		cout << renting[0][a] << endl;
		cout << "저자명: ";
		cout << renting[1][a] << endl;
	}
	cout << "*******************구분******************" << endl;
	return a;
}
bool member::getRenting(string title,string author){ // 도서대출받을때 사용될 멤버함수.
	 // renting_num이 배열의 저장 열의 위치를 알려줄거임.
	if(renting_num == 5){ // 이미 5권을 대출중이라면 더 이상 대출 불가능 합니다.
		cout << "이미 5권을 대출중이십니다." << endl;
		return false;
	}
	for(int a = 0;a<5;a++){
		if(renting[0][a] == title && renting[1][a] == author){ // 해당책을 이미 대출중이라면 이 또한 불가능 합니다.(한 책당 1권씩 빌릴 수 있음.)
			cout << "해당책을 이미 1권 대출중이십니다. 책당 1권씩만 대출 가능하십니다." << endl;
			return false;
		}
	}
	renting[0][renting_num] = title; // 도서를 빌립니다.(회원이 대출중인 도서정보 갱신)
	renting[1][renting_num] = author; // 도서를 빌립니다.(회원이 대출중인 도서정보 갱신)
	renting_num++; // 대출중인 도서의 수 ++
	return true;
}
void member::returnRenting(string title, string author){
	
	if(renting_num ==0){
		cout <<"현재 대출중이신 책이 없습니다." << endl;
		return;
	}
	for(int a= 0;a<5;a++){
		if(renting[0][a] == title && renting[1][a] == author){
			renting[0][a] = "";
			renting[1][a] = "";
			for(;a<4;a++){
				renting[0][a] = renting[0][a+1]; // 책들을 한칸씩 당겨준다. 
				renting[1][a] = renting[0][a+1]; // 책들을 한칸씩 당겨준다. 
			}
			renting_num--;
			return;
		}
	}
}
int member::showRenting_num(){
	return renting_num;
}

member::member(){ // 회원의 초기 세팅.
	name ="";
	c_number ="";
	age = 0;
	phone = "";
	renting_num = 0; 
} 

void member::set_member(string name, string c_number ,int age, string phone) // 회원의 정보를 입력해줍니다.
{
	this->name = name;
	this->c_number = c_number;
	this->age = age;
	this->phone = phone;
}

void member::member_info() // 해당 회원의 정보를 출력합니다.
{
	cout.setf(ios::left, ios::adjustfield); // 이쁜 출력을 위함.
	cout << "  이 름  : "<< name << endl;    // 이름 출력
	cout << " 주민번호: "<< c_number << endl;        // 주민등록 번호 출력 
	cout << "  나 이  : "<< age << endl;     // 나이 출력
	cout << " 전화번호: " << phone << endl; // 전화번호 출력
	cout << " 대출도서: ";
	for(int i =0;i<renting_num;i++){ // 대출중인 도서목록도 반환(도서명,저자명)의 형태
		cout << "(" << renting[0][i] << "," << renting[1][i] << ")";
	}
	cout << endl;
}
// 밑의 함수들은 매우 간단... 설명이 불필요 하다 생각합니다.
string member::showName()
{
	return name;
}
string member::showCnum()
{
	return c_number;
}
int member::showAge()
{
	return age;
}
string member::showPhone()
{
	return phone;
}

