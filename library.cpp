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
void library::addMember() // 새로운 멤버에 대한 추가를 하는 멤버함수입니다.
{
	vector<member>::iterator imember; // 현 함수에서 사용할 iterator
	string name;                      // 이름을 저장.
	string c_number;                  // 주민번호를 저장.
	int age;                          // 나이를 저장.
	string phone;                     // 휴대폰 번호를 저장.
	string command;                   // 사용자의 입력을 받아 처리하기 위한 변수.
	int duplicate = 1;                // 이 변수의 값이 2가되면 중복이 발생한 것.
	
	cout<<" 이  름 :";
	getline(cin,name);
	cout<<"주민번호:";
	getline(cin,c_number);
	// 중복된 회원의 정보를 입력하려는지 판단합니다.
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if((*imember).showName() == name && (*imember).showCnum() == c_number){
			duplicate++;
			if(duplicate == 2){
				cout << "이미 존재하는 회원입니다." << endl;
				cout << "메인메뉴얼로 돌아갑니다." << endl;
				return;
			}
		} 
	}
	// 중복이 발생하않는 정상적인 회원의 입력이라면 계속 진행합니다.
	cout<<" 나  이 :";
	cin >> age;
	//회원의 나이가 혹시 잘못된 값을 입력한다면 예외처리 해줍니다. ex) 문자
	if(cin.fail()){
		cin.clear();
		cin.ignore(20,'\n'); // 무시할 문자의 수는 자유롭게 조정 가능합니다. 사용자가 실수로 입력할 수 있는 문자가 아무리 많아야 20문자를 넘지 않을거라 생각해 20으로 주었습니다.
		cout << "잘못된 입력입니다. 메인메뉴로 돌아갑니다." << endl;
		return;
	}
	// 이상이 없을시 계속 진행.
	cin.ignore(20,'\n'); // 혹시나 띄어쓰기 후 이상한 문자를 입력할때를 대비(솔직히 누가 그러겠습니까...)
	cout<<" 전화번호:";
	getline(cin,phone);
	
	cout << "입력하시려는 정보가 아래가 맞습니까?" << endl;
	cout << " 이 름 :" << name << endl << "주민번호:" << c_number << endl << " 나  이 :" << age << endl << "전화번호:" << phone << endl;
	cout << "맞으면 1 틀리면 1외의 아무키나 입력해 주세요.";
	
	getline(cin,command);
	
	if(command =="1"){
		vmember.push_back(member()); // 새로운 멤버를 형성
		imember = vmember.end()-1;   // iterator값을 받고
		(*imember).set_member(name,c_number,age,phone); // 멤버의 정보를 입력합니다.
	}
	else{
		cout << "메인메뉴얼로 돌아갑니다." << endl;
		return; 
	}
}
void library::addBook() // 새로운 책을 추가해줍니다.
{// 크게 특별한 부분은 없고 이미 존재하는 책의 입력시 개수만 추가해 줍니다.
	string title;
	string author;
	vector<book>::iterator ibook; 
	int uenter;                    // user enter의 약자로서 사용자의 입력을(정확히는 프로그램 진행해 관련된 입력을) 받습니다.
	
	cout << " 제 목 :";
	getline(cin,title);
	cout << " 저 자 :";
	getline(cin,author);
	// 이미 존재하는 책인지 확인.
	for(ibook=vbook.begin();ibook != vbook.end();ibook++){
		if((*ibook).showTitle() == title && (*ibook).showAuthor() == author){
			cout << "이미 해당책이 존재함으로 자동으로 개수를 추가하겠습니다." << endl;
			(*ibook).addbook();
			return;
		}
	}
	// 아예 새로운 책임을 확인. 계속 진행합니다.
	string genre;	
	string publisher;
	string location; 
	
	cout << " 장 르 :";
	getline(cin,genre);
	cout << " 출판사 :";
	getline(cin,publisher);
	cout << " 위 치 :";
	getline(cin,location);
		
	cout <<"아래의 정보대로 입력을 진행하시겠습니까?" << endl;
	cout <<" 제 목 : "<< title << endl << " 저 자 : "<< author << endl << " 장 르 : "<< genre << endl << "  출판사 :" << publisher << endl << " 위 치 : "<< location << endl;
	cout << "맞을시 1 아니면 1을 제외한 아무키나 눌러주세요." << endl;
	cin >> uenter;
	// 예외처리
	if(cin.fail() || uenter != 1){
		cin.clear();
		cin.ignore(20,'\n'); //잘못된 값을 입력하는 사람은 없을것이라 판단해 20으로 했습니다. 
		cout << "메인메뉴로 돌아갑니다." << endl; 
	}
	// 이상 없으면 계속 진행
	else if(uenter == 1){
		vbook.push_back(book());
		ibook = vbook.end()-1; 
		(*ibook).new_book(title,author,genre,publisher,1,0,location); 
	}
}
void library::searchMember() // 회원을 검색하기 위한 멤버 함수.
{
	string name;
	string c_number;
	vector<member>::iterator imember;
	vector<member> temp;                // 회원의 정보를 담아둘 임시 vector
	int count = 0;                      // 중복되는 회원이 존재하는지 확인하기 위함.

	cout << "조회 회원명:";
	getline(cin,name);
	// 검색시 count의 값에따라 동일인물이 존재하는지, 아닌지, 아니면 회원이 아예 존재하지 않는 회원인지 확인합니다.
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if ((*imember).showName() == name) {
			temp.push_back(*imember); // 임시로 회원들의 정보를 담아두었습니다.
			count++;
		}
	}
	// 검색을 통해 count의 값이 정해졌습니다.

	if(count == 0){ // count 0 이 의미하는 바는 해당 회원명을 가진 회원은 존재하지 않는다는 의미입니다.
		cout << "해당회원은 존재하지 않습니다." << endl;
		return;
	}
	else if(count >= 2){ // cout가 값이 2 이상이라면 해당 회원명을 가진 회원들이 복수 존재한다는 의미입니다.
		
		cout << "동명의 회원들이 존재합니다." << endl << "해당 회원의 주민번호를 입력해 주세요." << endl;
		
		cout << "조회 회원 주민등록번호:"; // 주민등록번호도 받음으로써 회원을 한번더 확인.
		
		getline(cin,c_number);
		for(imember = temp.begin();imember != temp.end();imember++){ // 이번에는 temp를 통해서만 검색을 진행해도 되겠죠?
			if((*imember).showCnum() == c_number){
				(*imember).member_info();
				return;
			}
		}
		// 여기까지 왔다는것은 동명이인이 존재함을 확인했지만 주민번호를 잘못입력해 해당 회원을 찾지 못했다는것을 의미합니다.
		cout << "해당회원은 존재하지 않습니다." << endl;
		cout << "메인 메뉴얼로 돌아갑니다." << endl;
		return;
	}
	else{// 여기까지 왔다는것은 해당 회원명을 가진 인물은 단 한명 존재한다는 것을 의미합니다.
		temp.at(0).member_info(); // 현재 temp에는 하나의 값만 입력되어 있습니다. 그러므로 해당 회원의 정보를 출력해줍니다.
		return;
	}
}

void library::searchBook(){ // 도서의 검색을 담당하는 멤버함수.
	string title;
	string author;
	vector<book>::iterator ibook;
	
	// 도서부분에서는 해당 무조건적으로 도서의 명과 저자명을 받도록 하였습니다. 그 이유는
	// 회원의 경우에는 개인정보 보안 차원에서 어쩔수 없는 상황이 아니라면 이름만으로 처리할 수 있도록 하였지만
	// 도서의 경우에는 딱히 그럴 필요도 없고 보통 도서의 대출시 도서명과 저자명 확인은 무척 간단하므로
	// 아래와 같이 디자인 했습니다.

	cout << "검색할 도서 명: ";
	getline(cin,title);
	cout << "도서의 저자 명: ";
	getline(cin,author);
		
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){ 
		if(((*ibook).showTitle() == title) && ((*ibook).showAuthor() == author)){ // 해당 도서의 정보를 출력
			(*ibook).book_info();
			cout << endl;
			return; // 같은 도서명과 저자명을 지닌 도서는 단 한권만 존재 가능함으로 여기서 return을 해 불필요한 검색을 피합니다.
		}
	}
}

void library::modifyMember(){ // 회원정보 수정을 담당합니다.
	string name;
	string c_number;
	vector<member>::iterator imember;
	vector<book>::iterator ibook;
	// 변수들의 정보는 간단하므로 건너 뛰도록 하겠습니다.

	// 개인정보의 수정은 어차피 회원에 대한 모든 정보가 필요하니 굳이 개인정보 보호 차원에서 회원명을
	// 먼저 받고 거기서 중복이 없는지 있는지 하는 귀찮은 단계를 밟지 않습니다.
	cout << "변경 회원명:";
	getline(cin,name);
	cout << "변경 회원 주민등록번호:";
	getline(cin,c_number);

	
	for(imember = vmember.begin();imember != vmember.end();imember++){
		if((*imember).showName() == name && (*imember).showCnum() == c_number){
			// 해당 위치에서 변수를 선언한 이유는 여기서만 쓰고 버릴 변수들이기 때문입니다.
			string new_name;
			string new_c_num;
			int age;
			string phone;
			// 여기까지가 변수
			
			// 새로운 정보 입력 시작.
			cout << "[새로운 정보를 입력해 주세요.]" << endl;
			cout<<" 이  름 :";
			getline(cin,new_name);
			cout<<"주민번호:";
			getline(cin,new_c_num);

			// 이미 존재하는 회원의 정보로 변경하려는것인지 먼저 판단합니다.
			for (vector<member>::iterator justfornow = vmember.begin(); justfornow != vmember.end(); justfornow++) {
				if ((*justfornow).showName() == new_name && (*justfornow).showCnum() == new_c_num) {
					cout << "이미 같은 이름과 주민번호를 가진 회원이 존재합니다. 잘못된 입력입니다." << endl;
					return;
				}
			}
			// 올바른 변경이라면 계속 진행합니다.

			cout<<" 나  이 :";
			cin >> age;
			cin.get();
			cout<<" 전화번호:";
			getline(cin,phone);

			(*imember).set_member(new_name,new_c_num,age,phone);
			for(ibook = vbook.begin();ibook != vbook.end();ibook++){
				(*ibook).chained_modify_member(name,c_number,new_name,new_c_num); // 해당 회원의 정보가 변경되었으니 회원이 빌렸던 책들에 저장된 대출중인 회원들의 목록 정보도 변경을 합니다.
			}
			return;
		}
	}
	cout << "해당 회원은 존재하지 않습니다." << endl; // 해당회원이 없으면 이를 반환.
}

void library::rentBook(){ // 대출을 담당하는 멤버함수.
	string name; 
	string c_num;
	string title;
	string author; // 이 둘을 사용하는 이유는 일반적으로 제목과 저자만으로도 책을 하나하나 구분할 수 있기 때문!
	vector<member>::iterator imember;
	vector<book>::iterator ibook;
	map<int,vector<book>::iterator> temp_book;     // 여기서는 map을 임시로 사용하였는데 그 이유는 검색이 간편하고 사용자의 입력과 직접적으로 그 관련 값을 연관짓기 쉽기 때문입니다.
	map<int,vector<member>::iterator> temp_member; // 또한 value값으로 iterator를 준 이유는 iterator형태로 저장해놓았다가 위의 imember와 ibook 옮겨 값에 접근하기 위함.
	int where=1; // map에 매핑시 해당 회원의 정보를 담는 칸의 key값을 저장.
	
	try{
			if(vbook.begin() == vbook.end()){
				throw "책장이 비어있습니다.";
			}
			
			int count=0;
			
			cout << "대출자 명 : ";
			getline(cin,name);
			// 회원의 명을 먼저 입력받고 해당 회원과 동명의 회원이 존재하는지 점검.
			for(imember = vmember.begin();imember != vmember.end();imember++){
				if((*imember).showName() == name)
				count++;
				temp_member.insert(make_pair(count,imember)); // 이렇게 pair를 만들어주면 처음의 원소가 굳이 0의 키값을 가질필요없으니 1,2,3,4 ... 같은 느낌으로 정렬이 가시적으로 확인 가능해집니다.
			}
			// count값이 2 이상이면 동명이인 회원들이 존재.

			if(count == 0){ // count 0 은 해당 회원의 부재를 의미.
				throw "해당 회원은 존재하지 않습니다.";  // 예외처리.
			}
			if(count > 1){ // 동명이인 존재하니 주민번호도 받읍시다.
				cout << "동명이인이 존재하여 구분이 어렵습니다. 주민번호도 입력해주세요." << endl;
				cout << "대출자 주민번호 : ";
				getline(cin,c_num);
				for(int i = 1;i <= count;i++){
					if(c_num == (*temp_member.at(i)).showCnum()){
						where = i; // 해당 회원의 위치를 저장해 둡시다.(iterator가 아니라 원소값)
						break;
					} 
					else if(i == count){ // 만약 i와 count값이 같다면 이는 해당회원이 존재하지 않음을 의미.
						throw "해당 회원은 존재하지 않습니다."; // 예외처리.
					}
				}
			}
			// 대출할 도서명으 받읍시다.
			cout << "대출할 도서명 :";
			getline(cin,title);
			
			count = 0; // count를 재사용하기 위해 0으로 초기화.
			
			// 해당도서명의 도서들을 검색해 temp_book에 넣어줍시다.

			for(ibook = vbook.begin();ibook != vbook.end();ibook++){
				if((*ibook).showTitle() == title){
					temp_book.insert(make_pair(count+1,ibook));
					count++;
				}
			}
			if(count == 0){ // 도서가 존재하지 않네요.
				throw "해당 도서는 존재하지 않습니다."; // 예외처리.
			}
			else{ // 해당 도서명의 도서들의 목록을 보여줍시다.
				cout << "아래중 어느 도서의 대출을 하는지 골라주세요." << endl;

				for(int i =1; i <= count; i++){ // i를 1로 초기화해서 재사용.
					ibook = temp_book.at(i);
					cout << "***************** 구분 *********************" << endl;
					cout << i << ". 제목: " << (*ibook).showTitle() << ", 저자: " << (*ibook).showAuthor() << ", 대출 가능 권수:" << (*ibook).showNumofbook()-(*ibook).showRentbook() << endl;
				}
			}
			try{
				int user=0; // 사용자의 선택을 봅시다.
				
				cout << "입력:"; 
				cin >> user;
				
				// 사용자의 입력이 올바른지 확인.
				if(cin.fail() || user <=0 || user >count){ // 선택지 범위 외의 수나 문자같은 이상한값 입력시 예외처리.
					cin.clear();
					cin.ignore(20,'\n'); // 이전에 본 부분들과 동일한 이유로 20설정.
					throw"비정상 입력입니다. 메인메뉴로 돌아갑니다."; // 예외처리를 통해 빠져나갑니다.
				}
				// 여기까지 도달시에는 사용자의 입력은 정상적이었음을 확인.
				else{
					ibook = temp_book.at(user); // 사용자가 입력한 위치에 값이 뭔지 확인하기 위해 iterator값을 받아오고 (value값이 iterator형임.)
					if(((*ibook).showNumofbook()-(*ibook).showRentbook()) == 0){ // 일단 모든책이 대출중인지 확인합니다.(서내의 권수를 통한 확인.)
						throw "이미 모두 대출중 입니다."; // 모두 대출중임으로 예외처리.
					}
					author = (*ibook).showAuthor(); // title값은 이미 처음에 대출도서명 입력할때 받아서 상관없지만 author값은 따로 받지 않았었죠? 그러므로 받아 저장해놓았다가....
					// 대출을 진행하도록 합니다. 
					if((*temp_member.at(where)).getRenting(title,author)){ // 여기서 값을 입력해 확인. 해당 회원이 이미 해당 책을 1권 대출중이거나 아니면 이미 5권을 대출중이라면 false를 반환해 대출이 불가함을 알려줍니다.
						cout << "대출 진행중" << endl;
						(*ibook).rentbook(); // 대출중인 수를 증가.
						(*ibook).get_renter_info((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum()); // 대출한 회원의 정보를 받아와 해당책에 저장.
					}
					
				}
			}
			catch(const char* s){ // 예외처리를 받아 처리.
				cout << s << endl;
			}
		}
		catch(const char* s){ // 예외처리를 받아 처리.
			cout << s << endl;
		}
} 

void library::returnBook(){ // 책을 반환합니다.
	// 책의 반환을 위해 필요한 도서명,저자명,회원명,회원주민번호를 저장해놓을 변수들
	string title;
	string author;
	string name;
	string c_num;
	vector<book>::iterator ibook;
	vector<member>::iterator imember;
	map<int,vector<member>::iterator> temp_member; // 임시로 멤버들의 정보를 매핑해놓을 것입니다.(정확히는 iterator값을 저장해 놓습니다)
	int count=0; // count를 통해 언제나처럼 중복을 확인.
	int where=1; // 도서대출부분의 where과 동일. 1로 초기화 한 이유는 사용자가 입력한 회원명의 회원이 단 한명만 존재할때를 처리하기 위함.
	
	cout << "반납자 : ";
	getline(cin,name);
	
	try{	
		for(imember = vmember.begin();imember != vmember.end();imember++){
			if((*imember).showName() == name)
			count++;
			temp_member.insert(make_pair(count,imember)); 
		}
		if(count == 0){ // 해당회원은 존재하지 않습니다. count가 0이니까
			throw "해당 회원은 존재하지 않습니다.";
		}
		if(count > 1){ // 동명이인의 구분.
			cout << "동명이인이 존재하여 구분이 어렵습니다. 주민번호도 입력해주세요." << endl;
			cout << "반납자 주민번호 : ";
			getline(cin,c_num);
			for(int i = 1;i <= count;i++){
				if(c_num == (*temp_member.at(i)).showCnum()){
					where = i; // 해당 회원의 정보를 가르키는 iterator가 담긴 map의 칸의 key값을 저장.
					break;
				} 
				else if(i == count){
					throw "해당 회원은 존재하지 않습니다.";
				}
			}
		}
		// count가 1인 경우의 처리가 없는 이유는 이미 temp_member에 해당 회원이 저장되어있고 만약 count가 1이었다면
		// where의 값은 처음 초기화된 1 그대로겠죠?
	}
	catch(const char* s){
		cout << s << endl;
		return;
	}
	// 해당 회원이 존재한다면 여기까지 도달했을 것입니다.

	if((*temp_member.at(where)).showRenting_num() == 0){ // 해당 회원이 대출중인 책의 수를 보고 대출중인 책의 여부를 먼저 파악합니다.
		cout << "해당 회원은 대출중이신 책이 없습니다." << endl;
		return;
	}
	// 대출중인 책들이 있다면 아래를 통해 그 목록을 봅시다.
	cout << "아래중 반납하실 책의 번호를 골라주세요." << endl;
	count = (*temp_member.at(where)).show_renting(); // 현 회원이 대출중인 책들의 정보를 보여줍니다. 반환값으로는 대출중인 책의 수를 반환후 count로 받습니다.
	
	int user = 0;
	
	cin >> user;
	
	if(cin.fail() || user <1 || user > count){ // 사용자가 선택한 값이 대출중인 도서의 최대값보다 크거나 1보다 작다면 예외처리를 해줍시다.
		cin.clear();
		cin.ignore(20,'\n');
		cout << "잘못된 입력입니다." << endl;
		return;
	}
	title = (*temp_member.at(where)).show_renting_title(user);   // 반환할 책의 제목과
	author = (*temp_member.at(where)).show_renting_author(user); // 저자명을 받아옵니다.
	
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){
		if((*ibook).showTitle() == title && (*ibook).showAuthor() == author){
			(*temp_member.at(where)).returnRenting(title,author);                                           // 도서의 반납(member에서 처리)
			(*ibook).get_returned((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum()); // 도서의 반납(book에서 처리)
		}
	}
	
}

void library::showBook(){ // 책들의 정보를 봅니다.
	vector<book>::iterator ibook;
	
	if(vbook.begin() == vbook.end()){ // 책이 존재하지 않는다면 예외처리를 해줍니다.
		cout << "책장이 비어있습니다." << endl;
		return;
	}
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){ // 모든 책들의 정보를 출력합니다.
		(*ibook).book_info(); // ibook은 iterator 이 값을 증가시켜가며 vector의 요소에 접근해 책 하나하나의 정보를 출력합니다.
	}
}
void library::showMember(){ // 회원들의 정보를 봅니다.
	vector<member>::iterator imember;
	if(vmember.begin() == vmember.end()){
		cout << "회원목록이 비어있습니다." << endl;
		return;
	}
	for(imember = vmember.begin();imember != vmember.end();imember++){
		(*imember).member_info(); // showBook과 매우 유사함
	}
}
void library::deleteMember(){ // 멤버의 삭제를 위한 멤버함수.
	string name;     // 삭제할 회원의 이름을 저장할 변수
	string c_number; // 삭제할 회원의 주민번호를 저장할 변수
	vector<member>::iterator imember; // member에 접근할때 사용하기 위한 iterator
	map<int,vector<member>::iterator> temp_member; // map을 사용함으로써 이미 앞에서 언급한대로 사용자가 보는 가시적인 번호를 통해 해당 회원에 접근할 수 있도록 함.
	int count = 0; // 매우 유사한
	int where = 1; // 부분입니다.
	
	cout << "제거할 회원의 정보를 입력해주세요" << endl;
	cout << " 이  름 : ";
	getline(cin,name);
	 
	try{	
		for(imember = vmember.begin();imember != vmember.end();imember++){ // 제거할 회원명의 중복여부 확인.
			if((*imember).showName() == name)
			count++;
			temp_member.insert(make_pair(count,imember));
		}
		if(count == 0){ // count 0 은 해당 회원명을 가진 회원은 존재하지 않다는 의미.
			throw "해당 회원은 존재하지 않습니다.";
		}
		if(count > 1){ // 동명이인이 존재하니 주민번호를 받아 이를통해 구분합시다.
			cout << "동명이인이 존재하여 구분이 어렵습니다. 주민번호도 입력해주세요." << endl;
			cout << "반납자 주민번호 : ";
			getline(cin,c_number);
			for(int i = 1;i <= count;i++){
				if(c_number == (*temp_member.at(i)).showCnum()){
					where = i; //해당 회원의 map의 key값을 받아옵시다.
					break;
				} 
				else if(i == count){
					throw "해당 회원은 존재하지 않습니다.";
				}
			}
		}
	}
	catch(const char* s){
		cout << s << endl;
		return;
	}
	// count가 1이상이면 여기까지 왔겠죠? 그리고 where의 key값에 존재하는 value값(iterator)이 제거할 회원의 iterator
	
	if((*temp_member.at(where)).showRenting_num() > 0){ // 해당 회원이 혹여나 대출중인 책이 있다면 그래도 제거를 계속할지 질의합니다.
		cout << "해당회원은 대출중인 책들이 있습니다. 그래도 삭제를 계속 진행하시겠습니까?" << endl;
		cout << "1. 진행" << ", 1외의 키 입력시 메인메뉴로 돌아갑니다.";
		int choice = 0;
		cout << ">> ";
		cin >> choice;
		
		if(cin.fail()||choice !=1){ // 1외의 값의 입력을 받았으므로 해당 기능을 중단하고 메인메뉴로 복귀합니다.
			cin.clear();
			cin.ignore(20,'\n');
			cout << "메인메뉴로 돌아갑니다." << endl;
			return;
		}
		else{ // 1의 입력을 받았습니다. 그러니 해당 회원이 대출중이던 책은 제거가 될것입니다.(여러개라면 1개 제거.)
			vector<book>::iterator ibook; // 여기서 굳이 선언한 이유는 그 전에는 필요없었지만 여기서부터는 book 객체들이 저장된 vector에 접근해야하니 선언해 주었습니다..
			for(ibook = vbook.begin();ibook != vbook.end();){
				if((*ibook).get_returned((*temp_member.at(where)).showName(),(*temp_member.at(where)).showCnum())){ // 해당 회원명과 주민번호의 회원의 값이 저장된 책에서 그 책을 반환하는 처리를 하고
					(*ibook).reduce_num();//책의 수를 줄여줍니다. How come? 그야 해당 회원의 정보를 제거할꺼니까!.
					if((*ibook).showNumofbook() == 0){ //만약 이때 책의 수가 0가 된 경우라면 책의 정보를 지워주어야겠죠?
						ibook = vbook.erase(ibook); // 제거합니다. ibook에 erase의 반환값(삭제하고나서 그 다음 원소의 iterator값을 반환해줌.)을 저장해줍니다.
						continue; // vector에서 erase사용시 여러 주의점들이 있는데 for문에서 사용시 ibook++문을 erase문과 분리시켜주어야합니다.(erase하고 나면 ++를 해주면 안된다는 뜻.)
					}
				}
				ibook++; // erase문의 사용때문에 for문의 증감식 부분이 아니라 여기에 둠으로써 ibook++를 해줍니다.(erase하고나면 자동으로 ibook은 그 다음 원소를 가르키도록 했으니.)
			}
			// 여기까지 왔다는것은 제거대상이 되는 회원이 빌렸던 책들에도 접근해서 해당 회원과 관련된 정보도 지우고
			// 그 책들또한 1개씩 제거했음을 의미 그러므로 이제 마지막으로 해당 회원의 제거에 들어갑니다.
			vmember.erase(temp_member.at(where));
		}
	}
	else{ // 해당회원이 대출했던 책이 없었다면 그냥 바로 없애줍니다.
		vmember.erase(temp_member.at(where));
		return;
	}
}
void library::listBook(){ // 모든 책들에 대한 정보를 보여주는 기능. 
	vector<book>::iterator ibook;
	int count=1;// 도서 목록 보여줄때를 도서별 번호를 매김.
	
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){
		cout<< "***************** 구분 *********************" << endl;
		cout << "[도서" << count << "]:";
		(*ibook).book_info();
		count++;
	}
	if(count == 1){ // count가 증가하지 않았다는것은 도서의 목록이 비었다는 뜻.
		cout << "도서 명단이 비어있습니다." << endl;
	}
}
void library::listMember(){ // 모든 멤버들에 대한 정보를 보여주는 기능. 그냥 뭐...listbook이랑 거의 같습니다. 
	vector<member>::iterator imember;
	int count=1;
	
	for(imember = vmember.begin();imember != vmember.end();imember++){
		cout<< "***************** 구분 *********************" << endl;
		cout << "[" <<" 회 원 " <<count << "]" << endl;
		(*imember).member_info();
		count++;
	}
	if(count == 1){
		cout << "회원 명단이 비어있습니다." << endl;
	}
}
void library::deleteBook(){ // 도서의 삭제를 진행합시다. 대출중인 책은 제거 불가능합니다.(회원의 정보를 제거하는과정으로 삭제는 가능하지만 여기서는 안됩니다.)
	// 그 이유는 회원이 대출중인 책이 있지만 회원의 삭제를 진행하는 경우는 보통 해당 회원이 그 책을 빌린채로 반납하지 않은채로
	// 다신 돌아오지 않는 그런 경우를 상정하였기에 그런처리를 하였지만 여기서는 누군가 대출중인 책을 갑자기 여기서 없앨필요는 없겠죠?
	// 그런 이유입니다.
	string title;  // 도서 명
	string author; // 저자 명
	int ndumping;
	
	vector<book>::iterator ibook;
	
	cout << "폐기할 책의 제목과 저자를 입력해주세요." << endl; 
	cout <<"책 제목:";
	getline(cin,title);
	cout <<"책 저자:";
	getline(cin,author);
	// 폐기할 책의 정보를 받았으니 해당 책을 찾아봅시다.
	for(ibook = vbook.begin();ibook != vbook.end();ibook++){

		if(((*ibook).showTitle() == title) && ((*ibook).showAuthor() == author)){
			int How_many = (*ibook).showNumofbook()-(*ibook).showRentbook(); // 서내에 존재하는 책의 수량.
			
			if(How_many == 0){ // How_many == 0이 의미하는 바는 서내에 해당책은 존재하지 않음(모두 대출중)
				cout << "해당책은 모두 대출중이라 폐기할 수 없습니다." << endl;
			}
			else{
				// 모두 대출중이 아니라면 서내에 있는 책들은 폐기가 가능합니다.
				cout << "해당 책은 현재 서 내에 "<< How_many << "권 있습니다." << endl;
				cout << "총 몇권 폐기하십니까?";// 몇권을 폐기할까요?
				
				cin >> ndumping;
				if(cin.fail() || How_many < ndumping || ndumping < 0){ // 예외처리를 해줍시다.
					cin.clear();
					cin.ignore(20,'\n');
					cout << "잘못된 입력입니다." << endl << "메인메뉴얼로 돌아갑니다." << endl; 
				}
				else
				{
					for(int i = 0;i<ndumping;i++){ // ndumping에는 몇권을 폐기할지 저장되어 있으니 그 만큼 폐기를 진행하게 됩니다.
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
	cout << "해당 책은 존재하지 않습니다." << endl; 
}
