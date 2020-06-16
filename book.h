#ifndef book_h
#define book_h
#include "member.h"
#include <iostream>
#include <string>
#include <vector>

class book{
	string title;    // ������ ����(�̸�). 
	string author;   // ������ ����. 
	string genre;    // ������ �帣
	string publisher;// ������ ���ǻ�.  
	int num;         // ������ ��
	int rent;        // ���� �Ǿ��ִ� ������ ��.
	string location; // ������ ��ġ.
	vector<string> renter_name; // �������� �̸� 
	vector<string> renter_c_num; // �������� �ֹι�ȣ 
	
	
	public:
		book();  // �⺻ ������.
		~book(){} // �⺻ �Ҹ���. 
		void new_book(string title,string author,string genre,string publisher,int num, int rent, string location); // ���ο� å(�ƿ� ó�� ���� �Ż� å) �߰� 
		void book_info();  // å�� ���� ������ ������. 
		void rentbook();   // å�� ������. 
		void returnbook(); // �ش� å�� �ݳ���. 
		void deletebook(); // �ش� å�� ���ó���ؼ� ����. 
		void addbook();    // �ش� å�� ���� �ø�. (���� å�� ����)
		string showTitle();    // ���� ��ȯ
		string showAuthor();   // �۰� ��ȯ 
		int showNumofbook();  // �ش� å�� �� ��ȯ.
		int showRentbook();    // �������� å�� �� ��ȯ.
		string showLocation(); // �ش� å�� ��ġ�� ��ȯ 
		void get_renter_info(string name,string c_num); // �����ڿ� ���� ���� �Է�.
		bool get_returned(string name, string c_num); // �ݳ��� ó��.
		void chained_modify_member(string name,string c_number,string new_name,string new_c_num); // ȸ������ ������ �����Ͽ� ���� ��ȭ�� ������� �ֱ� ����.
		void reduce_num(); // å�� �� ����
};
#endif
