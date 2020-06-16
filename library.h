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
	vector <member> vmember; // å���� ����� vector
	vector <book> vbook;     // ������ ����� vector

	public:
        library(){} // �⺻������.
        ~library(){} // �⺻�Ҹ���.
        void addMember();    // ȸ���߰�
 	    void addBook();      // �����߰�
 	    void searchMember(); // ȸ���˻�
 	    void searchBook();   // �����˻�
 	    void modifyMember(); // ȸ������ ����
 	    void rentBook();     // ������
 	    void returnBook();   // �ݳ����
 	    void listBook();     // ������ ����Ʈ�� ������
 	    void listMember();   // ȸ���� ����Ʈ�� ������.
 	    void showBook();     // �ش� å�� ���� ������ �����ִ� �Լ�.
	    void showMember();   // �ش� ȸ���� ���� ������ �����ִ� �Լ�.
	    void deleteMember(); // �ش� ȸ���� ���� ������ ����.
	    void deleteBook();   // �ش� å�� ���� ������ ���� ��.
};
#endif
