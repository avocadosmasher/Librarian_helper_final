#include "library.h"
#include "login.h"
void showManual() { // �� ���α׷� ������� ��� ���ǻ��� manual�� �����ִ� �Լ��Դϴ�.
	cout << "�� ���α׷��� ������ �缭�� ����ϵ��� ����� �������� ���α׷��Դϴ�." << endl;
	cout << "�⺻���� ��������� �Ź� �������� ������ �״�� �����Ͻñ⸸ �ϸ� �˴ϴ�." << endl;
	cout << "Ư������ ��� �����帮�ڽ��ϴ�." << endl;
	cout << "1. �������� å�� �ִ� ȸ���� ������ �������� å�� ���� ȸ�� �Ұ����ϴ� �Ǵ��Ͽ� �ش� å�鵵 �������  �˴ϴ�." << endl;
	cout << "2. ȸ������ ���� ������ ���׵��� �������� å�鿡�Ե� �ݿ��� �˴ϴ�." << endl;
	cout << "3. ���ϸ��� ȸ���� �������� ������ ȸ���������� ȸ���� �˻��� �����մϴ�." << endl;
	cout << "4. 3�� ������ �Ҹ����� �ֹι�ȣ�� �Է��ؾ� �մϴ�." << endl;
	cout << "5. ��ȭ��ȣ�� -�� �����ؼ� �Է��� �ּ���(010-0161-1515)" << endl;
	cout << "�̻��Դϴ�." << endl;

}
int main()
{
	Login A;      // Login�� ���� ��ü
	string enter; // ������� �Է��� �޾� ó���� ����.
	
	while(1) // �⺻������ ��й�ȣ 3ȸ ������ ������ �����ǰ�, ������ ��й�ȣ���� 3ȸ Ʋ�� �������Ѵٸ� �׶��� ���α׷��� �ڵ����� ���ε˴ϴ�.
	{
		if(A.ShowpStack() == 3 && A.ShowqStack() == 3) // �� â���� �ƹ��͵� �Ҽ� �ִ°� ���ٸ� �״�� ���α׷��� �����մϴ�.
		{
			cout <<"��й�ȣ 3ȸ �Է� ���� & ������ ���� �亯 3ȸ �Է� ������ ����� �� �ִ� ����� �����ϴ�." << endl << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		cout << "�������� ���α׷� Book_Manager�� ���Ű��� ȯ���մϴ�." << endl;
		cout << "1. ��й�ȣ �Է�." << endl << "2. ��й�ȣ�� �ؾ�����̳���?" << endl;
		cout << "���α׷��� ���Ḧ ���Ͻø� 1, 2 ���� �ƹ�Ű�� �Է��� �ּ���." << endl;
		
		getline(cin,enter);
		 
		if(enter == "1")
		{
			if(A.ShowpStack() == 3){ // Ȥ���� ��й�ȣ 3ȸ������ ���¿��� �ٽ� ��й�ȣ�� �Է��Ϸ��� �� �� �� ������ �����ϴ�.
				cout << "��й�ȣ 3ȸ ������ ���� ������ ����ֽ��ϴ�. ��й�ȣ�� ������ �ּ���.";
			}
			else{
				cout << "�Է� : ";
				getline(cin,enter);  // ��й�ȣ�� �Է��� �ް�
				if(A.CheckPassword(enter)){ // Ȯ���� �����մϴ�.
					break;	// ��й�ȣ�� �¾� true���� ��ȯ�Ǿ��ٸ� �̴�� �������� �����ϱ� ���� break�� �մϴ�.
				}
				else{ // ���� ��й�ȣ�� Ʋ�Ⱦ��ٸ� ��й�ȣ�� ��ȸ ��������. 3ȸ������� 3ȸ ������� ��ȯ���ݴϴ�.
					switch(A.ShowpStack()){
						case 1: case 2:
							cout << "��й�ȣ �Է� " << A.ShowpStack() << "ȸ �����Դϴ�." << endl;
							break;						
						case 3:
							cout << "��й�ȣ �Է� " << A.ShowpStack() << "ȸ ������ ������ ��Ȱ��ȭ �մϴ�." << endl;
						}
				}
			}
		}
		else if(enter == "2")
		{
			if(A.ShowqStack() == 3){ // ������ Q&A 3ȸ ������ ���� �Ұ���.
				cout << "�亯 3ȸ ������ ���� �� ����� �� �̻� ��� �Ұ��� �մϴ�." << endl;
			}
			else{ // 3ȸ���� ���� �Ȱ��ٸ� ������ ���
				A.ShowQuestion();
				getline(cin,enter);  // ������ ���� �亯�� �ް�

				if(A.CheckQnA(enter)){ // ������ ���� �亯 üũ.
					A.ChangePassword(); // ���� �����ߴٸ� ��й�ȣ�� �ٲ��ݴϴ�. �׿� ���ÿ� ��й�ȣ �������¸� 0���� ���� �����ݴϴ�.
				}
				else{
					switch(A.ShowqStack()){ // �հ� ������ �ڵ��Դϴ�.
						case 1: case 2:
							cout << "�亯 �Է� " << A.ShowqStack() << "ȸ �����Դϴ�." << endl;
							break;
						
						case 3:
							cout << "�亯 �Է� " << A.ShowqStack() << "ȸ ������ �� ����� ��Ȱ��ȭ �մϴ�." << endl;
						}
				}
			}
		}
		else{ // ���� �Է��ߴ� ���� 1�� 2�� �ƴ϶�� �״�� ���α׷��� ��������ݴϴ�.
			cout << "���α׷��� �����մϴ�. �̿����ּż� �����մϴ�." << endl;
			return 0;
		}
	}
	
	int key; // ������� �Է��� �޾��ݴϴ�.
	library Database; // �� ���α׷��� �ٽ��� �缭���α׷��� ���������� �����ϱ����� ��ü
	
	while(1)
	{
		cout << "\n�Ʒ��� �޴��󿡼� ���ϴ� ����� �����ϼ��� \n \n";
		cout << " 1. ��뼳����" << endl; // ���� �������� ����� �˷��ݴϴ�.
		cout << " 2. ȸ�� �߰�" << endl; // ȸ���� �߰�
		cout << " 3. ȸ�� ����" << endl; // ȸ���� ����
		cout << " 4. ȸ�� ��������" << endl; // ȸ���� ���� ���� 
		cout << " 5. ȸ�� �˻�" << endl; // ȸ���� �˻�
		cout << " 6. ȸ�� ���" << endl; // ȸ���� ���
		cout << " 7. ���� �߰�" << endl; // ���ο� ������ �߰��մϴ�.(���ϸ��� ���� �۰��� ������ ���������� ����Ͽ� ������ ���� ���ϱ⸦ �մϴ�.)
		cout << " 8. ���� ����" << endl; // �����ڿ� ���⵵���� ������ �ް� ������ ������ �����մϴ�.
		cout << " 9. ���� �ݳ�" << endl; // �ݳ����� ������ �ް� �ش� ȸ���� �������� �������� ����� ������ �ݳ�ó�� �մϴ�.
		cout << "10. ���� �˻�" << endl; // ������ �˻��մϴ�.
		cout << "11. ���� ���" << endl; // �������� ����� ���ϴ�.
		cout << "12. ���� ����" << endl; // ������ �����մϴ�.
		cout << "13. ������ ���� ����" << endl; // ������ Q&A�� ������ �����մϴ�.
		cout << " ���Ḧ ���� �� 1-13���� Ű�� ������ �Է����ּ���. " << endl; // ����� 1~13���� Ű�� �Է��ϸ� ����˴ϴ�.
		cout << " >> ";
		
		cin >> key; // �Է��� �ް�
		try
		{
			if(cin.fail() || key >13 || key <1){
				throw "���α׷��� �����ϵ��� �ϰڽ��ϴ�."; // ���� �̻��� ���� �Է��߾��ų� 1~13���� ���� �Դٸ� throw�� ���ݴϴ�.
			}
			cin.ignore(20,'\n'); // Ȥ���� �̻��� ���� �� ������ �Ծ��ٸ� �ʱ�ȭ�� ���ֱ� ����.
			
			switch(key) // switch���� ���� �� ����Լ��� ȣ�� ������ ��޵� ��ȣ���� �Լ��� ����� ���״�� �� ��ɵ��� �����մϴ�.
			{
				case 1:
					showManual();
					break;

				case 2:
	   				Database.addMember();
	   				break;
	
	  			case 3:
	   				Database.deleteMember();
	   				break;
	
	  			case 4:
	  				Database.modifyMember();
	   				break;
	
	  			case 5:
	  			 	Database.searchMember();
	   				break;
	   			
				case 6:
	   				Database.listMember();
	   				break;
	   				
				case 7:
					Database.addBook();
					break;
					
	  			case 8:
	  			 	Database.rentBook();
	  			 	break;
	
	  			case 9:
	  				Database.returnBook();
	   				break;
	
	 			case 10:
	   				Database.searchBook();
	   				break;
	   				
	   			case 11:
					Database.listBook();
					break;
	 			case 12:
	   				Database.deleteBook();
	   				break;
				case 13:
					A.ChangeQnA();
					break;
			}
		}
		catch(const char * s){ // 1~13���� ���𰡰� �ԷµǾ��������� ����ó�� ���ݴϴ�.
			cout << s << endl;
			return 0;
		}
	}
}