#include "book.h"
#include "member.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void book::chained_modify_member(string name, string c_number, string new_name, string new_c_num){ // 회원의 정보가 수정됨에 따른 도서에서의 현 책을 대출중인 회원의 정보들도 같이 변경
	vector<string>::iterator wname = find(renter_name.begin(), renter_name.end(), name);
	vector<string>::iterator wc_num = find(renter_c_num.begin(), renter_c_num.end(), c_number);
	if (wname == renter_name.end() && wc_num == renter_c_num.end()) return;
	renter_name.insert(wname,new_name);
	renter_c_num.insert(wc_num,new_c_num);
	return;
}
void book::reduce_num(){ // 책의 수 감소.
	num--;
}
bool book::get_returned(string name,string c_num){ // 도서를 다시 돌려받을때 사용할 멤버함수(사실은 매개변수로 전달받은 회원의 명과 주민번호를 통해 그 회원이 해당책을 대출중인 상태를 없애주는 기능. )
	vector<string>::iterator wname = find(renter_name.begin(),renter_name.end(),name);
	vector<string>::iterator wc_num = find(renter_c_num.begin(),renter_c_num.end(),c_num);
	if(wname == renter_name.end() && wc_num == renter_c_num.end()) return false;
	renter_name.erase(wname);   // 돌려받았으니 해당 회원의 이름을 지워줍니다.
	renter_c_num.erase(wc_num); // 주민번호도
	rent--; // 반납받았으니 대출중인 수도 --
	return true;
}
void book::get_renter_info(string name,string c_num){ // 대출자의 정보를 받아옵니다.
	renter_name.push_back(name);
	renter_c_num.push_back(c_num);
	return;
}

book::book(){ // 초기화.
	title = "";
	author = "";
	genre = "";
	publisher = "";
	num = 0;
	rent = 0;
	location = "";
}

void book::new_book(string title,string author,string genre,string publisher,int num, int rent, string location){ //새로 들어온 책의 정보를 세팅해줍시다(사실은 그냥 책의 정보를 새팅해주는 용도 궂이 새 책은....)
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->publisher = publisher;
	this->num = num;
	this->rent = rent;
	this->location =location;
}
void book::book_info(){ // 책의 정보 출력
	cout << "제목:" << title << endl;
	cout << "저자:" << author<< endl;
	cout << "장르:" << genre << endl;
	cout << "출판사:" << publisher << endl;
	cout << "책의 수:" << num << endl;
	cout << "대출 수:" << rent << endl;
	cout << "위치:" << location << endl;
	
	int i;
	cout << "대출자 명단:"; // 밑은 대출자 명단을 출력해주기 위함입니다.
	
	for(i=0;i<rent;i++){
		cout << "(" << renter_name[i] << "," << renter_c_num[i] << ")";
	}
	
	if(i==0){
		cout << " 없음 " << endl;
	
	}
	else cout << endl;
}
// 여기부터 밑의 멤버함수들은 호출시에는 값의 +나 -만 해주고 해당 함수를 호출해도 괜찮은지 아닌지는
// Library클래스의 멤버함수 부분에서 합니다. 때문에 매우 심플하므로 설명을 넘기도록 합니다. 
void book::rentbook(){
	rent++;
}
void book::returnbook(){
	rent--;
}
void book::deletebook(){ // inline으로 바꾸자 
	num--;
}
void book::addbook(){
	num++; 
}

int book::showNumofbook(){
	return num;
}

int book::showRentbook(){
	return rent;
}

string book::showLocation(){
	return location;
}
string book::showTitle(){
	return title;
}
string book::showAuthor(){
	return author;
}
