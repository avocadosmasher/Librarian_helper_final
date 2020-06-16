#include "login.h"
#include <iostream>
#include <string>
#include <algorithm>

Login::Login(){
	password = "970426"; // �ʱ��й�ȣ�� ���� ���Ƿ� �����Ͽ����ϴ�.
	pStack = 0;
	qStack = 0;
	question = "�� �̴ϼ���?"; // ������ ���� ���Ƿ�
	answer = "kyw"; // �� �̴ϼȷ� �亯�� ����
}

void Login::ChangePassword(){ // ��й�ȣ ������ ���� ����Լ�.
	string user1; // ����ڰ� ó�� �Է��� ��й�ȣ�� �Է� ���� ��ü
	string user2; // ����ڰ� ��й�ȣ Ȯ���� ���� �Է��� ���ڿ��� �Է¹��� ��ü
	 
	while(1){ // �̹� main���� ������ Q&A�� ���� �˻簡 ��� �Ϸ���� �ùٸ� ����ڶ� �Ǻ��Ǿ����� ȣ������� �ٷ� �����մϴ�.
		cout << "�� ����� ���Ḧ ���ҽÿ��� exit�̶�� �Է��� �ּ���." << endl;
		cout << "���ο� ��й�ȣ : ";
		getline(cin,user1);
		
		if(user1 == "exit") break; // �� ����� �����ϰ� �ʹٸ� exit�� ���� �����ϴ�.
		
		else if(user1.size() == 6){ // ��й�ȣ ���� ����. 
			try{
				for(int i = 0; i<6; i++){
					if(user1[i] == ' '){ // ������ �ԷµǾ� ������ ������.
						throw "������ ��й�ȣ�� ���Ե� �� �����ϴ�."; // ��й�ȣ�� ������ �� �� �����ϴ�.
					}
				}
				cout << "��й�ȣ Ȯ�� : "; // ��й�ȣ�� Ȯ���ش޶�� ��û.
				getline(cin,user2);
				if(user1 == user2){ //����Ϸ��Դϴ�.
					password = user1;
					cout << "��й�ȣ ������ �Ϸ�Ǿ����ϴ�." << endl; // 
					break;
				}
				else{ // ��й�ȣ�� ��ġ���� �ʴٸ� ��й�ȣ ������ ó������ �ٽ� �����մϴ�.
					cout << "�Է��Ͻ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�."<< endl;
					cout << "��й�ȣ ������ ó������ �ٽ� �����մϴ�." << endl;
				}
			}
			catch(const char * s){ // ����ó���� �սô�.
				cout << s << endl;	
			}
		}
		else{ // ���� size�� 6�ڸ��� ���� �ʴ´ٸ� ��й�ȣ�� ������ ��Ű�� �ʾұ� ������ ��й�ȣ�� ������ �˷��ְ� �ٽ� �����մϴ�.
			cout << "��й�ȣ�� ������ �������� �ʴ� 6�ڸ� �̾�� �մϴ�.(����,���� �Ѵ� ����)" << endl; 
			continue;
		}
	}
}

bool Login::CheckPassword(string enter){ // ��й�ȣ�� �´��� Ȯ���ϴ� �κ�.
	if(enter == password){ // ���� �´� �׷��� ������ ���� ���õ� ��й�ȣ ���� ���õ� ���� �ʱ�ȭ���ݴϴ�.
		pStack = 0; // ����� �­����� �ٽ� 0���� ���� 
		qStack = 0; // Q&A�� ���õ� 0���� �ʱ�ȭ �����ݽô�.(�ᱹ ��й�ȣ�� ����Ŵ� �ùٸ� ����ڰ� �´ٰ� �Ǵ�.) 
		return true;
	}
	else{ // Ʋ������ ���� ++
		pStack++; // pStack�� ++�������ν� Ʋ�� Ƚ���� ����. 
		return false;
	}
}
bool Login::CheckQnA(string enter){ // ������ ���� �亯 Ȯ��
	
	if(enter == answer){ // �亯�� ��ġ�� Ȯ���մϴ�.
		qStack = 0; // �������� �ʱ�ȭ 
		pStack = 0; // ������ ������ ���� �亯�� ���߾����� ���Ŀ� ����� �ٲٴ� ���� ������� �ϴ� �ùٸ� ��������� Ȯ��. 
		return true; // true�� ��ȯ
	}
	else{ // �亯�� ����ġ
		qStack++; // ������ ���� �亯 Ʋ��Ƚ�� ����. 
		return false; // false ��ȯ
	}
}
int Login::ShowpStack(){ // �� Password ���� ������ ��ȯ
	return pStack;
} 
int Login::ShowqStack(){ // �� ������ ���� ���� ������ ��ȯ
	return qStack;
}
void Login::ShowQuestion(){ // ������ ������ �����ݴϴ�.
	cout << question << endl;
}

void Login::ChangeQnA(){ // ������ ���� ������
	string new_question; // ���ο� ������ ����� ����
	string new_answer;   // �� ������ ���� �亯�� ����� ����
	string yn; // yes or no
	try {
		while (1) { // �⺻������ �׳� �� ������ �Է��ϰ� �� ������ �´��� Ȯ���� �� �ϴ� ����(�� �亯�� ������ ����) �������Դϴ�.
			cout << "���ο� ���� �Է� : ";
			getline(cin, new_question);

			cout << "�Է��Ͻ� ������ []���� ������ �½��ϱ�? (yes/no)" << endl <<"--���Ḧ ���� �� �ٸ� �ƹ�Ű�� �Է����ּ���.--" << endl << "[" << new_question << "]" << endl;
			getline(cin, yn);
			transform(yn.begin(), yn.end(), yn.begin(), ::toupper); // �̺κи� Ư���ϴ� �����մϴ�. transform�� ���� ��ҹ��� �Է��� ���������ʰ� �״�� �޾Ƶ鿩 �� �빮��ȭ ���ݴϴ�.
			if (yn == "YES");

			else if (yn == "NO") {
				cout << "�ٽ� �����մϴ�." << endl;
				continue;
			}
			else {
				throw "���θ޴��� ���ư��ϴ�.";
			}

			while (1) { // ���� ����
				cout << "���ο� �亯 �Է� : ";
				getline(cin, new_answer);

				cout << "�Է��Ͻ� �亯�� []���� �亯�� �½��ϱ�? (yes/no)" << endl << "-- ���Ḧ ���� �� �ٸ� �ƹ�Ű�� �Է����ּ���.--" << endl << "[" << new_answer << "]" << endl;
				getline(cin, yn);
				transform(yn.begin(), yn.end(), yn.begin(), ::toupper);

				if (yn == "YES") {
					question = new_question;
					answer = new_answer;
					cout << "Q&A ������ �Ϸ�Ǿ����ϴ�." << endl;
					break;
				}
				else if (yn == "NO") {
					continue;
				}
				else {
					throw "���θ޴��� ���ư��ϴ�.";
				}
			}
			break;
		}
	}
	catch (const char* s) { // ����ó��.
		cout << s << endl;
	}
}
