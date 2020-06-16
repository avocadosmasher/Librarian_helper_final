#include "book.h"
#include "member.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void book::chained_modify_member(string name, string c_number, string new_name, string new_c_num){ // ȸ���� ������ �����ʿ� ���� ���������� �� å�� �������� ȸ���� �����鵵 ���� ����
	vector<string>::iterator wname = find(renter_name.begin(), renter_name.end(), name);
	vector<string>::iterator wc_num = find(renter_c_num.begin(), renter_c_num.end(), c_number);
	if (wname == renter_name.end() && wc_num == renter_c_num.end()) return;
	renter_name.insert(wname,new_name);
	renter_c_num.insert(wc_num,new_c_num);
	return;
}
void book::reduce_num(){ // å�� �� ����.
	num--;
}
bool book::get_returned(string name,string c_num){ // ������ �ٽ� ���������� ����� ����Լ�(����� �Ű������� ���޹��� ȸ���� ��� �ֹι�ȣ�� ���� �� ȸ���� �ش�å�� �������� ���¸� �����ִ� ���. )
	vector<string>::iterator wname = find(renter_name.begin(),renter_name.end(),name);
	vector<string>::iterator wc_num = find(renter_c_num.begin(),renter_c_num.end(),c_num);
	if(wname == renter_name.end() && wc_num == renter_c_num.end()) return false;
	renter_name.erase(wname);   // �����޾����� �ش� ȸ���� �̸��� �����ݴϴ�.
	renter_c_num.erase(wc_num); // �ֹι�ȣ��
	rent--; // �ݳ��޾����� �������� ���� --
	return true;
}
void book::get_renter_info(string name,string c_num){ // �������� ������ �޾ƿɴϴ�.
	renter_name.push_back(name);
	renter_c_num.push_back(c_num);
	return;
}

book::book(){ // �ʱ�ȭ.
	title = "";
	author = "";
	genre = "";
	publisher = "";
	num = 0;
	rent = 0;
	location = "";
}

void book::new_book(string title,string author,string genre,string publisher,int num, int rent, string location){ //���� ���� å�� ������ �������ݽô�(����� �׳� å�� ������ �������ִ� �뵵 ���� �� å��....)
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->publisher = publisher;
	this->num = num;
	this->rent = rent;
	this->location =location;
}
void book::book_info(){ // å�� ���� ���
	cout << "����:" << title << endl;
	cout << "����:" << author<< endl;
	cout << "�帣:" << genre << endl;
	cout << "���ǻ�:" << publisher << endl;
	cout << "å�� ��:" << num << endl;
	cout << "���� ��:" << rent << endl;
	cout << "��ġ:" << location << endl;
	
	int i;
	cout << "������ ���:"; // ���� ������ ����� ������ֱ� �����Դϴ�.
	
	for(i=0;i<rent;i++){
		cout << "(" << renter_name[i] << "," << renter_c_num[i] << ")";
	}
	
	if(i==0){
		cout << " ���� " << endl;
	
	}
	else cout << endl;
}
// ������� ���� ����Լ����� ȣ��ÿ��� ���� +�� -�� ���ְ� �ش� �Լ��� ȣ���ص� �������� �ƴ�����
// LibraryŬ������ ����Լ� �κп��� �մϴ�. ������ �ſ� �����ϹǷ� ������ �ѱ⵵�� �մϴ�. 
void book::rentbook(){
	rent++;
}
void book::returnbook(){
	rent--;
}
void book::deletebook(){ // inline���� �ٲ��� 
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
