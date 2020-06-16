#include "member.h"
#include <iostream>
#include <string>

using namespace std;

string member::show_renting_title(int user){ // �Է¹��� ��ġ�� �������� ������ ������ ��ȯ
	return renting[0][user-1];
}
string member::show_renting_author(int user){ // ���� ������ ���·� ������ ���ڸ� ��ȯ.
	return renting[1][user-1];
}


int member::show_renting(){ // �������� ������ ������� ���ڸ��� ��ȯ���ݴϴ�.
	int a;
	for(a= 0;a<renting_num;a++){
		cout << "*******************����******************" << endl;
		cout << "[" << a+1 << "]" << endl;
		cout << "������: ";
		cout << renting[0][a] << endl;
		cout << "���ڸ�: ";
		cout << renting[1][a] << endl;
	}
	cout << "*******************����******************" << endl;
	return a;
}
bool member::getRenting(string title,string author){ // ������������� ���� ����Լ�.
	 // renting_num�� �迭�� ���� ���� ��ġ�� �˷��ٰ���.
	if(renting_num == 5){ // �̹� 5���� �������̶�� �� �̻� ���� �Ұ��� �մϴ�.
		cout << "�̹� 5���� �������̽ʴϴ�." << endl;
		return false;
	}
	for(int a = 0;a<5;a++){
		if(renting[0][a] == title && renting[1][a] == author){ // �ش�å�� �̹� �������̶�� �� ���� �Ұ��� �մϴ�.(�� å�� 1�Ǿ� ���� �� ����.)
			cout << "�ش�å�� �̹� 1�� �������̽ʴϴ�. å�� 1�Ǿ��� ���� �����Ͻʴϴ�." << endl;
			return false;
		}
	}
	renting[0][renting_num] = title; // ������ �����ϴ�.(ȸ���� �������� �������� ����)
	renting[1][renting_num] = author; // ������ �����ϴ�.(ȸ���� �������� �������� ����)
	renting_num++; // �������� ������ �� ++
	return true;
}
void member::returnRenting(string title, string author){
	
	if(renting_num ==0){
		cout <<"���� �������̽� å�� �����ϴ�." << endl;
		return;
	}
	for(int a= 0;a<5;a++){
		if(renting[0][a] == title && renting[1][a] == author){
			renting[0][a] = "";
			renting[1][a] = "";
			for(;a<4;a++){
				renting[0][a] = renting[0][a+1]; // å���� ��ĭ�� ����ش�. 
				renting[1][a] = renting[0][a+1]; // å���� ��ĭ�� ����ش�. 
			}
			renting_num--;
			return;
		}
	}
}
int member::showRenting_num(){
	return renting_num;
}

member::member(){ // ȸ���� �ʱ� ����.
	name ="";
	c_number ="";
	age = 0;
	phone = "";
	renting_num = 0; 
} 

void member::set_member(string name, string c_number ,int age, string phone) // ȸ���� ������ �Է����ݴϴ�.
{
	this->name = name;
	this->c_number = c_number;
	this->age = age;
	this->phone = phone;
}

void member::member_info() // �ش� ȸ���� ������ ����մϴ�.
{
	cout.setf(ios::left, ios::adjustfield); // �̻� ����� ����.
	cout << "  �� ��  : "<< name << endl;    // �̸� ���
	cout << " �ֹι�ȣ: "<< c_number << endl;        // �ֹε�� ��ȣ ��� 
	cout << "  �� ��  : "<< age << endl;     // ���� ���
	cout << " ��ȭ��ȣ: " << phone << endl; // ��ȭ��ȣ ���
	cout << " ���⵵��: ";
	for(int i =0;i<renting_num;i++){ // �������� ������ϵ� ��ȯ(������,���ڸ�)�� ����
		cout << "(" << renting[0][i] << "," << renting[1][i] << ")";
	}
	cout << endl;
}
// ���� �Լ����� �ſ� ����... ������ ���ʿ� �ϴ� �����մϴ�.
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

