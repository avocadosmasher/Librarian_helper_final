#include "library.h"
#include "book.h"
#include "member.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
#include <map>

using namespace std;
/*
void library::manual(){
	cout << ""
}
*/
void library::addMember() // ���ο� ����� ���� �߰��� �ϴ� ����Լ��Դϴ�.
{
	vector<member>::iterator imember; // �� �Լ����� ����� iterator
	string name;                      // �̸��� ����.
	string c_number;                  // �ֹι�ȣ�� ����.
	int age;                          // ���̸� ����.
	string phone;                     // �޴��� ��ȣ�� ����.
	string command;                   // ������� �Է��� �޾� ó���ϱ� ���� ����.
	int duplicate = 1;                // �� ������ ���� 2���Ǹ� �ߺ��� �߻��� ��.
	
	cout<<" ��  �� :";
	getline(cin,name);
	cout<<"�ֹι�ȣ:";
	getline(cin,c_number);
	// �ߺ��� ȸ���� ������ �Է��Ϸ����� �Ǵ��մϴ�.
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if((*imember).showName() == name && (*imember).showCnum() == c_number){
			duplicate++;
			if(duplicate == 2){
				cout << "�̹� �����ϴ� ȸ���Դϴ�." << endl;
				cout << "���θ޴���� ���ư��ϴ�." << endl;
				return;
			}
		} 
	}
	// �ߺ��� �߻��Ͼʴ� �������� ȸ���� �Է��̶�� ��� �����մϴ�.
	cout<<" ��  �� :";
	cin >> age;
	//ȸ���� ���̰� Ȥ�� �߸��� ���� �Է��Ѵٸ� ����ó�� ���ݴϴ�. ex) ����
	if(cin.fail()){
		cin.clear();
		cin.ignore(20,'\n'); // ������ ������ ���� �����Ӱ� ���� �����մϴ�. ����ڰ� �Ǽ��� �Է��� �� �ִ� ���ڰ� �ƹ��� ���ƾ� 20���ڸ� ���� �����Ŷ� ������ 20���� �־����ϴ�.
		cout << "�߸��� �Է��Դϴ�. ���θ޴��� ���ư��ϴ�." << endl;
		return;
	}
	// �̻��� ������ ��� ����.
	cin.ignore(20,'\n'); // Ȥ�ó� ���� �� �̻��� ���ڸ� �Է��Ҷ��� ���(������ ���� �׷��ڽ��ϱ�...)
	cout<<" ��ȭ��ȣ:";
	getline(cin,phone);
	
	cout << "�Է��Ͻ÷��� ������ �Ʒ��� �½��ϱ�?" << endl;
	cout << " �� �� :" << name << endl << "�ֹι�ȣ:" << c_number << endl << " ��  �� :" << age << endl << "��ȭ��ȣ:" << phone << endl;
	cout << "������ 1 Ʋ���� 1���� �ƹ�Ű�� �Է��� �ּ���.";
	
	getline(cin,command);
	
	if(command =="1"){
		vmember.push_back(member()); // ���ο� ����� ����
		imember = vmember.end()-1;   // iterator���� �ް�
		(*imember).set_member(name,c_number,age,phone); // ����� ������ �Է��մϴ�.
	}
	else{
		cout << "���θ޴���� ���ư��ϴ�." << endl;
		return; 
	}
}
void library::addBook() // ���ο� å�� �߰����ݴϴ�.
{// ũ�� Ư���� �κ��� ���� �̹� �����ϴ� å�� �Է½� ������ �߰��� �ݴϴ�.
	string title;
	string author;
	vector<book>::iterator ibook; 
	int uenter;                    // user enter�� ���ڷμ� ������� �Է���(��Ȯ���� ���α׷� ������ ���õ� �Է���) �޽��ϴ�.
	
	cout << " �� �� :";
	getline(cin,title);
	cout << " �� �� :";
	getline(cin,author);
	// �̹� �����ϴ� å���� Ȯ��.
	for(ibook=vbook.begin();ibook != vbook.end();ibook++){
		if((*ibook).showTitle() == title && (*ibook).showAuthor() == author){
			cout << "�̹� �ش�å�� ���������� �ڵ����� ������ �߰��ϰڽ��ϴ�." << endl;
			(*ibook).addbook();
			return;
		}
	}
	// �ƿ� ���ο� å���� Ȯ��. ��� �����մϴ�.
	string genre;	
	string publisher;
	string location; 
	
	cout << " �� �� :";
	getline(cin,genre);
	cout << " ���ǻ� :";
	getline(cin,publisher);
	cout << " �� ġ :";
	getline(cin,location);
		
	cout <<"�Ʒ��� ������� �Է��� �����Ͻðڽ��ϱ�?" << endl;
	cout <<" �� �� : "<< title << endl << " �� �� : "<< author << endl << " �� �� : "<< genre << endl << "  ���ǻ� :" << publisher << endl << " �� ġ : "<< location << endl;
	cout << "������ 1 �ƴϸ� 1�� ������ �ƹ�Ű�� �����ּ���." << endl;
	cin >> uenter;
	// ����ó��
	if(cin.fail() || uenter != 1){
		cin.clear();
		cin.ignore(20,'\n'); //�߸��� ���� �Է��ϴ� ����� �������̶� �Ǵ��� 20���� �߽��ϴ�. 
		cout << "���θ޴��� ���ư��ϴ�." << endl; 
	}
	// �̻� ������ ��� ����
	else if(uenter == 1){
		vbook.push_back(book());
		ibook = vbook.end()-1; 
		(*ibook).new_book(title,author,genre,publisher,1,0,location); 
	}
}
void library::searchMember() // ȸ���� �˻��ϱ� ���� ��� �Լ�.
{
	string name;
	string c_number;
	vector<member>::iterator imember;
	vector<member> temp;                // ȸ���� ������ ��Ƶ� �ӽ� vector
	int count = 0;                      // �ߺ��Ǵ� ȸ���� �����ϴ��� Ȯ���ϱ� ����.

	cout << "��ȸ ȸ����:";
	getline(cin,name);
	// �˻��� count�� �������� �����ι��� �����ϴ���, �ƴ���, �ƴϸ� ȸ���� �ƿ� �������� �ʴ� ȸ������ Ȯ���մϴ�.
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if ((*imember).showName() == name) {
			temp.push_back(*imember); // �ӽ÷� ȸ������ ������ ��Ƶξ����ϴ�.
			count++;
		}
	}
	// �˻��� ���� count�� ���� ���������ϴ�.

	if(count == 0){ // count 0 �� �ǹ��ϴ� �ٴ� �ش� ȸ������ ���� ȸ���� �������� �ʴ´ٴ� �ǹ��Դϴ�.
		cout << "�ش�ȸ���� �������� �ʽ��ϴ�." << endl;
		return;
	}
	else if(count >= 2){ // cout�� ���� 2 �̻��̶�� �ش� ȸ������ ���� ȸ������ ���� �����Ѵٴ� �ǹ��Դϴ�.
		
		cout << "������ ȸ������ �����մϴ�." << endl << "�ش� ȸ���� �ֹι�ȣ�� �Է��� �ּ���." << endl;
		
		cout << "��ȸ ȸ�� �ֹε�Ϲ�ȣ:"; // �ֹε�Ϲ�ȣ�� �������ν� ȸ���� �ѹ��� Ȯ��.
		
		getline(cin,c_number);
		for(imember = temp.begin();imember != temp.end();imember++){ // �̹����� temp�� ���ؼ��� �˻��� �����ص� �ǰ���?
			if((*imember).showCnum() == c_number){
				(*imember).member_info();
				return;
			}
		}
		// ������� �Դٴ°��� ���������� �������� Ȯ�������� �ֹι�ȣ�� �߸��Է��� �ش� ȸ���� ã�� ���ߴٴ°��� �ǹ��մϴ�.
		cout << "�ش�ȸ���� �������� �ʽ��ϴ�." << endl;
		cout << "���� �޴���� ���ư��ϴ�." << endl;
		return;
	}
	else{// ������� �Դٴ°��� �ش� ȸ������ ���� �ι��� �� �Ѹ� �����Ѵٴ� ���� �ǹ��մϴ�.
		temp.at(0).member_info(); // ���� temp���� �ϳ��� ���� �ԷµǾ� �ֽ��ϴ�. �׷��Ƿ� �ش� ȸ���� ������ ������ݴϴ�.
		return;
	}
}

void library::searchBook(){ // ������ �˻��� ����ϴ� ����Լ�.
	string title;
	string author;
	vector<book>::iterator ibook;
	
	// �����κп����� �ش� ������������ ������ ��� ���ڸ��� �޵��� �Ͽ����ϴ�. �� ������
	// ȸ���� ��쿡�� �������� ���� �������� ��¿�� ���� ��Ȳ�� �ƴ϶�� �̸������� ó���� �� �ֵ��� �Ͽ�����
	// ������ ��쿡�� ���� �׷� �ʿ䵵 ���� ���� ������ ����� ������� ���ڸ� Ȯ���� ��ô �����ϹǷ�
	// �Ʒ��� ���� ������ �߽��ϴ�.

	cout << "�˻��� ���� ��: ";
	getline(cin,title);
	cout << "������ ���� ��: ";
	getline(cin,author);
		
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){ 
		if(((*ibook).showTitle() == title) && ((*ibook).showAuthor() == author)){ // �ش� ������ ������ ���
			(*ibook).book_info();
			cout << endl;
			return; // ���� ������� ���ڸ��� ���� ������ �� �ѱǸ� ���� ���������� ���⼭ return�� �� ���ʿ��� �˻��� ���մϴ�.
		}
	}
}

void library::modifyMember(){ // ȸ������ ������ ����մϴ�.
	string name;
	string c_number;
	vector<member>::iterator imember;
	vector<book>::iterator ibook;
	// �������� ������ �����ϹǷ� �ǳ� �ٵ��� �ϰڽ��ϴ�.

	// ���������� ������ ������ ȸ���� ���� ��� ������ �ʿ��ϴ� ���� �������� ��ȣ �������� ȸ������
	// ���� �ް� �ű⼭ �ߺ��� ������ �ִ��� �ϴ� ������ �ܰ踦 ���� �ʽ��ϴ�.
	cout << "���� ȸ����:";
	getline(cin,name);
	cout << "���� ȸ�� �ֹε�Ϲ�ȣ:";
	getline(cin,c_number);

	
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if((*imember).showName() == name && (*imember).showCnum() == c_number){
			// �ش� ��ġ���� ������ ������ ������ ���⼭�� ���� ���� �������̱� �����Դϴ�.
			string new_name;
			string new_c_num;
			int age;
			string phone;
			// ��������� ����
			
			// ���ο� ���� �Է� ����.
			cout << "[���ο� ������ �Է��� �ּ���.]" << endl;
			cout<<" ��  �� :";
			getline(cin,new_name);
			cout<<"�ֹι�ȣ:";
			getline(cin,new_c_num);

			// �̹� �����ϴ� ȸ���� ������ �����Ϸ��°����� ���� �Ǵ��մϴ�.
			for (vector<member>::iterator justfornow = vmember.begin(); justfornow != vmember.end(); justfornow++) {
				if ((*justfornow).showName() == new_name && (*justfornow).showCnum() == new_c_num) {
					cout << "�̹� ���� �̸��� �ֹι�ȣ�� ���� ȸ���� �����մϴ�. �߸��� �Է��Դϴ�." << endl;
					return;
				}
			}
			// �ùٸ� �����̶�� ��� �����մϴ�.

			cout<<" ��  �� :";
			cin >> age;
			cin.get();
			cout<<" ��ȭ��ȣ:";
			getline(cin,phone);

			(*imember).set_member(new_name,new_c_num,age,phone);
			for(ibook = vbook.begin();ibook != vbook.end();ibook++){
				(*ibook).chained_modify_member(name,c_number,new_name,new_c_num); // �ش� ȸ���� ������ ����Ǿ����� ȸ���� ���ȴ� å�鿡 ����� �������� ȸ������ ��� ������ ������ �մϴ�.
			}
			return;
		}
	}
	cout << "�ش� ȸ���� �������� �ʽ��ϴ�." << endl; // �ش�ȸ���� ������ �̸� ��ȯ.
}

void library::rentBook(){ // ������ ����ϴ� ����Լ�.
	string name; 
	string c_num;
	string title;
	string author; // �� ���� ����ϴ� ������ �Ϲ������� ����� ���ڸ����ε� å�� �ϳ��ϳ� ������ �� �ֱ� ����!
	vector<member>::iterator imember;
	vector<book>::iterator ibook;
	map<int,vector<book>::iterator> temp_book;     // ���⼭�� map�� �ӽ÷� ����Ͽ��µ� �� ������ �˻��� �����ϰ� ������� �Է°� ���������� �� ���� ���� �������� ���� �����Դϴ�.
	map<int,vector<member>::iterator> temp_member; // ���� value������ iterator�� �� ������ iterator���·� �����س��Ҵٰ� ���� imember�� ibook �Ű� ���� �����ϱ� ����.
	int where=1; // map�� ���ν� �ش� ȸ���� ������ ��� ĭ�� key���� ����.
	
	try{
			if(vbook.begin() == vbook.end()){
				throw "å���� ����ֽ��ϴ�.";
			}
			
			int count=0;
			
			cout << "������ �� : ";
			getline(cin,name);
			// ȸ���� ���� ���� �Է¹ް� �ش� ȸ���� ������ ȸ���� �����ϴ��� ����.
			for(imember = vmember.begin();imember != vmember.end();imember++){
				if((*imember).showName() == name)
				count++;
				temp_member.insert(make_pair(count,imember)); // �̷��� pair�� ������ָ� ó���� ���Ұ� ���� 0�� Ű���� �����ʿ������ 1,2,3,4 ... ���� �������� ������ ���������� Ȯ�� ���������ϴ�.
			}
			// count���� 2 �̻��̸� �������� ȸ������ ����.

			if(count == 0){ // count 0 �� �ش� ȸ���� ���縦 �ǹ�.
				throw "�ش� ȸ���� �������� �ʽ��ϴ�.";  // ����ó��.
			}
			if(count > 1){ // �������� �����ϴ� �ֹι�ȣ�� �����ô�.
				cout << "���������� �����Ͽ� ������ ��ƽ��ϴ�. �ֹι�ȣ�� �Է����ּ���." << endl;
				cout << "������ �ֹι�ȣ : ";
				getline(cin,c_num);
				for(int i = 1;i <= count;i++){
					if(c_num == (*temp_member.at(i)).showCnum()){
						where = i; // �ش� ȸ���� ��ġ�� ������ �ӽô�.(iterator�� �ƴ϶� ���Ұ�)
						break;
					} 
					else if(i == count){ // ���� i�� count���� ���ٸ� �̴� �ش�ȸ���� �������� ������ �ǹ�.
						throw "�ش� ȸ���� �������� �ʽ��ϴ�."; // ����ó��.
					}
				}
			}
			// ������ �������� �����ô�.
			cout << "������ ������ :";
			getline(cin,title);
			
			count = 0; // count�� �����ϱ� ���� 0���� �ʱ�ȭ.
			
			// �ش絵������ �������� �˻��� temp_book�� �־��ݽô�.

			for(ibook = vbook.begin();ibook != vbook.end();ibook++){
				if((*ibook).showTitle() == title){
					temp_book.insert(make_pair(count+1,ibook));
					count++;
				}
			}
			if(count == 0){ // ������ �������� �ʳ׿�.
				throw "�ش� ������ �������� �ʽ��ϴ�."; // ����ó��.
			}
			else{ // �ش� �������� �������� ����� �����ݽô�.
				cout << "�Ʒ��� ��� ������ ������ �ϴ��� ����ּ���." << endl;

				for(int i =1; i <= count; i++){ // i�� 1�� �ʱ�ȭ�ؼ� ����.
					ibook = temp_book.at(i);
					cout << "***************** ���� *********************" << endl;
					cout << i << ". ����: " << (*ibook).showTitle() << ", ����: " << (*ibook).showAuthor() << ", ���� ���� �Ǽ�:" << (*ibook).showNumofbook()-(*ibook).showRentbook() << endl;
				}
			}
			try{
				int user=0; // ������� ������ ���ô�.
				
				cout << "�Է�:"; 
				cin >> user;
				
				// ������� �Է��� �ùٸ��� Ȯ��.
				if(cin.fail() || user <=0 || user >count){ // ������ ���� ���� ���� ���ڰ��� �̻��Ѱ� �Է½� ����ó��.
					cin.clear();
					cin.ignore(20,'\n'); // ������ �� �κе�� ������ ������ 20����.
					throw"������ �Է��Դϴ�. ���θ޴��� ���ư��ϴ�."; // ����ó���� ���� ���������ϴ�.
				}
				// ������� ���޽ÿ��� ������� �Է��� �������̾����� Ȯ��.
				else{
					ibook = temp_book.at(user); // ����ڰ� �Է��� ��ġ�� ���� ���� Ȯ���ϱ� ���� iterator���� �޾ƿ��� (value���� iterator����.)
					if(((*ibook).showNumofbook()-(*ibook).showRentbook()) == 0){ // �ϴ� ���å�� ���������� Ȯ���մϴ�.(������ �Ǽ��� ���� Ȯ��.)
						throw "�̹� ��� ������ �Դϴ�."; // ��� ������������ ����ó��.
					}
					author = (*ibook).showAuthor(); // title���� �̹� ó���� ���⵵���� �Է��Ҷ� �޾Ƽ� ��������� author���� ���� ���� �ʾҾ���? �׷��Ƿ� �޾� �����س��Ҵٰ�....
					// ������ �����ϵ��� �մϴ�. 
					if((*temp_member.at(where)).getRenting(title,author)){ // ���⼭ ���� �Է��� Ȯ��. �ش� ȸ���� �̹� �ش� å�� 1�� �������̰ų� �ƴϸ� �̹� 5���� �������̶�� false�� ��ȯ�� ������ �Ұ����� �˷��ݴϴ�.
						cout << "���� ������" << endl;
						(*ibook).rentbook(); // �������� ���� ����.
						(*ibook).get_renter_info((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum()); // ������ ȸ���� ������ �޾ƿ� �ش�å�� ����.
					}
					
				}
			}
			catch(const char* s){ // ����ó���� �޾� ó��.
				cout << s << endl;
			}
		}
		catch(const char* s){ // ����ó���� �޾� ó��.
			cout << s << endl;
		}
} 

void library::returnBook(){ // å�� ��ȯ�մϴ�.
	// å�� ��ȯ�� ���� �ʿ��� ������,���ڸ�,ȸ����,ȸ���ֹι�ȣ�� �����س��� ������
	string title;
	string author;
	string name;
	string c_num;
	vector<book>::iterator ibook;
	vector<member>::iterator imember;
	map<int,vector<member>::iterator> temp_member; // �ӽ÷� ������� ������ �����س��� ���Դϴ�.(��Ȯ���� iterator���� ������ �����ϴ�)
	int count=0; // count�� ���� ������ó�� �ߺ��� Ȯ��.
	int where=1; // ��������κ��� where�� ����. 1�� �ʱ�ȭ �� ������ ����ڰ� �Է��� ȸ������ ȸ���� �� �Ѹ� �����Ҷ��� ó���ϱ� ����.
	
	cout << "�ݳ��� : ";
	getline(cin,name);
	
	try{	
		for(imember = vmember.begin();imember != vmember.end();imember++){
			if((*imember).showName() == name)
			count++;
			temp_member.insert(make_pair(count,imember)); 
		}
		if(count == 0){ // �ش�ȸ���� �������� �ʽ��ϴ�. count�� 0�̴ϱ�
			throw "�ش� ȸ���� �������� �ʽ��ϴ�.";
		}
		if(count > 1){ // ���������� ����.
			cout << "���������� �����Ͽ� ������ ��ƽ��ϴ�. �ֹι�ȣ�� �Է����ּ���." << endl;
			cout << "�ݳ��� �ֹι�ȣ : ";
			getline(cin,c_num);
			for(int i = 1;i <= count;i++){
				if(c_num == (*temp_member.at(i)).showCnum()){
					where = i; // �ش� ȸ���� ������ ����Ű�� iterator�� ��� map�� ĭ�� key���� ����.
					break;
				} 
				else if(i == count){
					throw "�ش� ȸ���� �������� �ʽ��ϴ�.";
				}
			}
		}
		// count�� 1�� ����� ó���� ���� ������ �̹� temp_member�� �ش� ȸ���� ����Ǿ��ְ� ���� count�� 1�̾��ٸ�
		// where�� ���� ó�� �ʱ�ȭ�� 1 �״�ΰ���?
	}
	catch(const char* s){
		cout << s << endl;
		return;
	}
	// �ش� ȸ���� �����Ѵٸ� ������� �������� ���Դϴ�.

	if((*temp_member.at(where)).showRenting_num() == 0){ // �ش� ȸ���� �������� å�� ���� ���� �������� å�� ���θ� ���� �ľ��մϴ�.
		cout << "�ش� ȸ���� �������̽� å�� �����ϴ�." << endl;
		return;
	}
	// �������� å���� �ִٸ� �Ʒ��� ���� �� ����� ���ô�.
	cout << "�Ʒ��� �ݳ��Ͻ� å�� ��ȣ�� ����ּ���." << endl;
	count = (*temp_member.at(where)).show_renting(); // �� ȸ���� �������� å���� ������ �����ݴϴ�. ��ȯ�����δ� �������� å�� ���� ��ȯ�� count�� �޽��ϴ�.
	
	int user = 0;
	
	cin >> user;
	
	if(cin.fail() || user <1 || user > count){ // ����ڰ� ������ ���� �������� ������ �ִ밪���� ũ�ų� 1���� �۴ٸ� ����ó���� ���ݽô�.
		cin.clear();
		cin.ignore(20,'\n');
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}
	title = (*temp_member.at(where)).show_renting_title(user);   // ��ȯ�� å�� �����
	author = (*temp_member.at(where)).show_renting_author(user); // ���ڸ��� �޾ƿɴϴ�.
	
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){
		if((*ibook).showTitle() == title && (*ibook).showAuthor() == author){
			(*temp_member.at(where)).returnRenting(title,author);                                           // ������ �ݳ�(member���� ó��)
			(*ibook).get_returned((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum()); // ������ �ݳ�(book���� ó��)
		}
	}
	
}

void library::showBook(){ // å���� ������ ���ϴ�.
	vector<book>::iterator ibook;
	
	if(vbook.begin() == vbook.end()){ // å�� �������� �ʴ´ٸ� ����ó���� ���ݴϴ�.
		cout << "å���� ����ֽ��ϴ�." << endl;
		return;
	}
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){ // ��� å���� ������ ����մϴ�.
		(*ibook).book_info(); // ibook�� iterator �� ���� �������Ѱ��� vector�� ��ҿ� ������ å �ϳ��ϳ��� ������ ����մϴ�.
	}
}
void library::showMember(){ // ȸ������ ������ ���ϴ�.
	vector<member>::iterator imember;
	if(vmember.begin() == vmember.end()){
		cout << "ȸ������� ����ֽ��ϴ�." << endl;
		return;
	}
	for(imember = vmember.begin();imember != vmember.end();imember++){
		(*imember).member_info(); // showBook�� �ſ� ������
	}
}
void library::deleteMember(){ // ����� ������ ���� ����Լ�.
	string name;     // ������ ȸ���� �̸��� ������ ����
	string c_number; // ������ ȸ���� �ֹι�ȣ�� ������ ����
	vector<member>::iterator imember; // member�� �����Ҷ� ����ϱ� ���� iterator
	map<int,vector<member>::iterator> temp_member; // map�� ��������ν� �̹� �տ��� ����Ѵ�� ����ڰ� ���� �������� ��ȣ�� ���� �ش� ȸ���� ������ �� �ֵ��� ��.
	int count = 0; // �ſ� ������
	int where = 1; // �κ��Դϴ�.
	
	cout << "������ ȸ���� ������ �Է����ּ���" << endl;
	cout << " ��  �� : ";
	getline(cin,name);
	 
	try{	
		for(imember = vmember.begin();imember != vmember.end();imember++){ // ������ ȸ������ �ߺ����� Ȯ��.
			if((*imember).showName() == name)
			count++;
			temp_member.insert(make_pair(count,imember));
		}
		if(count == 0){ // count 0 �� �ش� ȸ������ ���� ȸ���� �������� �ʴٴ� �ǹ�.
			throw "�ش� ȸ���� �������� �ʽ��ϴ�.";
		}
		if(count > 1){ // ���������� �����ϴ� �ֹι�ȣ�� �޾� �̸����� �����սô�.
			cout << "���������� �����Ͽ� ������ ��ƽ��ϴ�. �ֹι�ȣ�� �Է����ּ���." << endl;
			cout << "�ݳ��� �ֹι�ȣ : ";
			getline(cin,c_number);
			for(int i = 1;i <= count;i++){
				if(c_number == (*temp_member.at(i)).showCnum()){
					where = i; //�ش� ȸ���� map�� key���� �޾ƿɽô�.
					break;
				} 
				else if(i == count){
					throw "�ش� ȸ���� �������� �ʽ��ϴ�.";
				}
			}
		}
	}
	catch(const char* s){
		cout << s << endl;
		return;
	}
	// count�� 1�̻��̸� ������� �԰���? �׸��� where�� key���� �����ϴ� value��(iterator)�� ������ ȸ���� iterator
	
	if((*temp_member.at(where)).showRenting_num() > 0){ // �ش� ȸ���� Ȥ���� �������� å�� �ִٸ� �׷��� ���Ÿ� ������� �����մϴ�.
		cout << "�ش�ȸ���� �������� å���� �ֽ��ϴ�. �׷��� ������ ��� �����Ͻðڽ��ϱ�?" << endl;
		cout << "1. ����" << ", 1���� Ű �Է½� ���θ޴��� ���ư��ϴ�.";
		int choice = 0;
		cout << ">> ";
		cin >> choice;
		
		if(cin.fail()||choice !=1){ // 1���� ���� �Է��� �޾����Ƿ� �ش� ����� �ߴ��ϰ� ���θ޴��� �����մϴ�.
			cin.clear();
			cin.ignore(20,'\n');
			cout << "���θ޴��� ���ư��ϴ�." << endl;
			return;
		}
		else{ // 1�� �Է��� �޾ҽ��ϴ�. �׷��� �ش� ȸ���� �������̴� å�� ���Ű� �ɰ��Դϴ�.(��������� 1�� ����.)
			vector<book>::iterator ibook; // ���⼭ ���� ������ ������ �� ������ �ʿ�������� ���⼭���ʹ� book ��ü���� ����� vector�� �����ؾ��ϴ� ������ �־����ϴ�..
			for(ibook = vbook.begin();ibook != vbook.end();){
				if((*ibook).get_returned((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum())){ // �ش� ȸ����� �ֹι�ȣ�� ȸ���� ���� ����� å���� �� å�� ��ȯ�ϴ� ó���� �ϰ�
					(*ibook).reduce_num();//å�� ���� �ٿ��ݴϴ�. How come? �׾� �ش� ȸ���� ������ �����Ҳ��ϱ�!.
					if((*ibook).showNumofbook() == 0){ //���� �̶� å�� ���� 0�� �� ����� å�� ������ �����־�߰���?
						ibook = vbook.erase(ibook); // �����մϴ�. ibook�� erase�� ��ȯ��(�����ϰ��� �� ���� ������ iterator���� ��ȯ����.)�� �������ݴϴ�.
						continue; // vector���� erase���� ���� ���������� �ִµ� for������ ���� ibook++���� erase���� �и������־���մϴ�.(erase�ϰ� ���� ++�� ���ָ� �ȵȴٴ� ��.)
					}
				}
				ibook++; // erase���� ��붧���� for���� ������ �κ��� �ƴ϶� ���⿡ �����ν� ibook++�� ���ݴϴ�.(erase�ϰ��� �ڵ����� ibook�� �� ���� ���Ҹ� ����Ű���� ������.)
			}
			// ������� �Դٴ°��� ���Ŵ���� �Ǵ� ȸ���� ���ȴ� å�鿡�� �����ؼ� �ش� ȸ���� ���õ� ������ �����
			// �� å����� 1���� ���������� �ǹ� �׷��Ƿ� ���� ���������� �ش� ȸ���� ���ſ� ���ϴ�.
			vmember.erase(temp_member.at(where));
		}
	}
	else{ // �ش�ȸ���� �����ߴ� å�� �����ٸ� �׳� �ٷ� �����ݴϴ�.
		vmember.erase(temp_member.at(where));
		return;
	}
}
void library::listBook(){ // ��� å�鿡 ���� ������ �����ִ� ���. 
	vector<book>::iterator ibook;
	int count=1;// ���� ��� �����ٶ��� ������ ��ȣ�� �ű�.
	
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){
		cout<< "***************** ���� *********************" << endl;
		cout << "[����" << count << "]:";
		(*ibook).book_info();
		count++;
	}
	if(count == 1){ // count�� �������� �ʾҴٴ°��� ������ ����� ����ٴ� ��.
		cout << "���� ����� ����ֽ��ϴ�." << endl;
	}
}
void library::listMember(){ // ��� ����鿡 ���� ������ �����ִ� ���. �׳� ��...listbook�̶� ���� �����ϴ�. 
	vector<member>::iterator imember;
	int count=1;
	
	for(imember = vmember.begin();imember != vmember.end();imember++){
		cout<< "***************** ���� *********************" << endl;
		cout << "[" <<" ȸ �� " <<count << "]" << endl;
		(*imember).member_info();
		count++;
	}
	if(count == 1){
		cout << "ȸ�� ����� ����ֽ��ϴ�." << endl;
	}
}
void library::deleteBook(){ // ������ ������ �����սô�. �������� å�� ���� �Ұ����մϴ�.(ȸ���� ������ �����ϴ°������� ������ ���������� ���⼭�� �ȵ˴ϴ�.)
	// �� ������ ȸ���� �������� å�� ������ ȸ���� ������ �����ϴ� ���� ���� �ش� ȸ���� �� å�� ����ä�� �ݳ����� ����ä��
	// �ٽ� ���ƿ��� �ʴ� �׷� ��츦 �����Ͽ��⿡ �׷�ó���� �Ͽ����� ���⼭�� ������ �������� å�� ���ڱ� ���⼭ �����ʿ�� ������?
	// �׷� �����Դϴ�.
	string title;  // ���� ��
	string author; // ���� ��
	int ndumping;
	
	vector<book>::iterator ibook;
	
	cout << "����� å�� ����� ���ڸ� �Է����ּ���." << endl; 
	cout <<"å ����:";
	getline(cin,title);
	cout <<"å ����:";
	getline(cin,author);
	// ����� å�� ������ �޾����� �ش� å�� ã�ƺ��ô�.
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){

		if(((*ibook).showTitle() == title) && ((*ibook).showAuthor() == author)){
			int How_many = (*ibook).showNumofbook()-(*ibook).showRentbook(); // ������ �����ϴ� å�� ����.
			
			if(How_many == 0){ // How_many == 0�� �ǹ��ϴ� �ٴ� ������ �ش�å�� �������� ����(��� ������)
				cout << "�ش�å�� ��� �������̶� ����� �� �����ϴ�." << endl;
			}
			else{
				// ��� �������� �ƴ϶�� ������ �ִ� å���� ��Ⱑ �����մϴ�.
				cout << "�ش� å�� ���� �� ���� "<< How_many << "�� �ֽ��ϴ�." << endl;
				cout << "�� ��� ����Ͻʴϱ�?";// ����� ����ұ��?
				
				cin >> ndumping;
				if(cin.fail() || How_many < ndumping || ndumping < 0){ // ����ó���� ���ݽô�.
					cin.clear();
					cin.ignore(20,'\n');
					cout << "�߸��� �Է��Դϴ�." << endl << "���θ޴���� ���ư��ϴ�." << endl; 
				}
				else
				{
					for(int i = 0;i<ndumping;i++){ // ndumping���� ����� ������� ����Ǿ� ������ �� ��ŭ ��⸦ �����ϰ� �˴ϴ�.
					    (*ibook).deletebook();	
					}
					if((*ibook).showNumofbook() == 0){
						vbook.erase(ibook);
					}
				}
			}
			return;
		}
	}
	cout << "�ش� å�� �������� �ʽ��ϴ�." << endl; 
}
