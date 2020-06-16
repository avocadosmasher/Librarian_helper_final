#ifndef member_h
#define member_h
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class member
{
	string name;// ȸ���� �̸�
	string c_number; // ȸ���� �ֹε�� ��ȣ 
	int age;      // ȸ���� ����
	string phone; // ȸ���� ��ȭ��ȣ
	string renting[2][5]; // �������� ������, ���ڸ� ����.
	int renting_num; // �������� �������� ��. �ִ� 5�Ǹ� ���� �� ����. 
	
	public:
		member(); // �⺻ ������
		~member(){}// �⺻ �Ҹ���
		void set_member(string name, string c_number ,int age, string phone); // ȸ���� �߰�/�����Ҷ� ����� �Լ�. 
		void member_info(); // ȸ���� ���� ���.
		string showName(); // �̸� ��ȯ
		string showCnum(); // �ֹι�ȣ ��ȯ
		int showAge();     // ���� ��ȯ
		string showPhone();// ��ȭ��ȣ ��ȯ.
		bool getRenting(string title,string author); // ����޾ƿ� å�� ������,���ڸ��� ȸ�����Ե� �������ݴϴ�.
		void returnRenting(string title,string author);  // �ݳ��մϴ�.
		int showRenting_num(); // �������� å�� �� ��ȯ
		int show_renting();    // �������� å�� ������ ��ȯ. �ű⿡ ���� �� ���� ��ȯ���ݴϴ�.(�� ���� ���� �������� å�� �� ��ȯ�� �ִµ� ���� ��ȯ���� ������°� �ϸ� �̷��� ����ϸ� �ξ� ���ϱ� �����Դϴ�.)
		string show_renting_title(int user); // �������� å�� ���� ��ȯ. �Ű������� �� ��ġ�� ���� �޾�(�迭�� ��ġ) ����
		string show_renting_author(int user); // �������� å�� ���ڸ� ��ȯ. �Ű������� �� ��ġ�� ���� �޾�(�迭�� ��ġ) ����
};
#endif
