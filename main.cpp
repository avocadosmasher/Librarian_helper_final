#include "library.h"
#include "login.h"
void showManual() { // 이 프로그램 사용전의 몇가지 주의사항 manual을 보여주는 함수입니다.
	cout << "이 프로그램은 도서관 사서가 사용하도록 설계된 도서관리 프로그램입니다." << endl;
	cout << "기본적인 사용방법들은 매번 설명란이 나오니 그대로 따라하시기만 하면 됩니다." << endl;
	cout << "특이점만 몇가지 설명드리겠습니다." << endl;
	cout << "1. 대출중인 책이 있는 회원의 삭제는 대출중인 책들 또한 회수 불가능하다 판단하여 해당 책들도 사라지게  됩니다." << endl;
	cout << "2. 회원들의 정보 변경의 사항들은 대출중인 책들에게도 반영이 됩니다." << endl;
	cout << "3. 동일명의 회원이 존재하지 않으면 회원명만으로 회원의 검색이 가능합니다." << endl;
	cout << "4. 3번 사항이 불만족시 주민번호도 입력해야 합니다." << endl;
	cout << "5. 전화번호는 -를 포함해서 입력해 주세요(010-0161-1515)" << endl;
	cout << "이상입니다." << endl;

}
int main()
{
	Login A;      // Login시 사용될 객체
	string enter; // 사용자의 입력을 받아 처리할 변수.
	
	while(1) // 기본적으로 비밀번호 3회 오류시 계정이 정지되고, 나만의 비밀번호까지 3회 틀려 정지당한다면 그때는 프로그램이 자동으로 종로됩니다.
	{
		if(A.ShowpStack() == 3 && A.ShowqStack() == 3) // 현 창에서 아무것도 할수 있는게 없다면 그대로 프로그램을 종료합니다.
		{
			cout <<"비밀번호 3회 입력 오류 & 질문에 대한 답변 3회 입력 오류로 사용할 수 있는 기능이 없습니다." << endl << "프로그램을 종료합니다." << endl;
			return 0;
		}
		cout << "도서관리 프로그램 Book_Manager에 오신것을 환영합니다." << endl;
		cout << "1. 비밀번호 입력." << endl << "2. 비밀번호를 잊어버리셨나요?" << endl;
		cout << "프로그램의 종료를 원하시면 1, 2 외의 아무키나 입력해 주세요." << endl;
		
		getline(cin,enter);
		 
		if(enter == "1")
		{
			if(A.ShowpStack() == 3){ // 혹여나 비밀번호 3회오류인 상태에서 다시 비밀번호를 입력하려고 할 시 그 접근을 막습니다.
				cout << "비밀번호 3회 오류로 인해 계정이 잠겨있습니다. 비밀번호를 변경해 주세요.";
			}
			else{
				cout << "입력 : ";
				getline(cin,enter);  // 비밀번호를 입력을 받고
				if(A.CheckPassword(enter)){ // 확인을 진행합니다.
					break;	// 비밀번호가 맞아 true값이 반환되었다면 이대로 다음으로 진행하기 위해 break를 합니다.
				}
				else{ // 만약 비밀번호가 틀렸었다면 비밀번호가 몇회 오류인지. 3회오류라면 3회 오류라고 반환해줍니다.
					switch(A.ShowpStack()){
						case 1: case 2:
							cout << "비밀번호 입력 " << A.ShowpStack() << "회 오류입니다." << endl;
							break;						
						case 3:
							cout << "비밀번호 입력 " << A.ShowpStack() << "회 오류로 계정을 비활성화 합니다." << endl;
						}
				}
			}
		}
		else if(enter == "2")
		{
			if(A.ShowqStack() == 3){ // 나만의 Q&A 3회 오류시 접근 불가능.
				cout << "답변 3회 오류로 인해 이 기능은 더 이상 사용 불가능 합니다." << endl;
			}
			else{ // 3회까진 아직 안갔다면 접근을 허용
				A.ShowQuestion();
				getline(cin,enter);  // 질문에 대한 답변을 받고

				if(A.CheckQnA(enter)){ // 질문에 대한 답변 체크.
					A.ChangePassword(); // 만약 성공했다면 비밀번호를 바꿔줍니다. 그와 동시에 비밀번호 오류상태를 0으로 리셋 시켜줍니다.
				}
				else{
					switch(A.ShowqStack()){ // 앞과 유사한 코드입니다.
						case 1: case 2:
							cout << "답변 입력 " << A.ShowqStack() << "회 오류입니다." << endl;
							break;
						
						case 3:
							cout << "답변 입력 " << A.ShowqStack() << "회 오류로 현 기능을 비활성화 합니다." << endl;
						}
				}
			}
		}
		else{ // 만약 입력했던 값이 1도 2도 아니라면 그대로 프로그램을 종료시켜줍니다.
			cout << "프로그램을 종료합니다. 이용해주셔서 감사합니다." << endl;
			return 0;
		}
	}
	
	int key; // 사용자의 입력을 받아줍니다.
	library Database; // 현 프로그램의 핵심인 사서프로그램을 실질적으로 진행하기위한 객체
	
	while(1)
	{
		cout << "\n아래의 메뉴얼에서 원하는 기능을 선택하세요 \n \n";
		cout << " 1. 사용설명서" << endl; // 사용시 주의점들 몇가지를 알려줍니다.
		cout << " 2. 회원 추가" << endl; // 회원의 추가
		cout << " 3. 회원 삭제" << endl; // 회원의 삭제
		cout << " 4. 회원 정보수정" << endl; // 회원의 정보 변경 
		cout << " 5. 회원 검색" << endl; // 회원의 검색
		cout << " 6. 회원 목록" << endl; // 회원의 목록
		cout << " 7. 도서 추가" << endl; // 새로운 도서를 추가합니다.(동일명과 동일 작가의 도서는 같은도서로 취급하여 도서의 수에 더하기를 합니다.)
		cout << " 8. 도서 대출" << endl; // 대출자와 대출도서의 정보를 받고 도서의 대출을 진행합니다.
		cout << " 9. 도서 반납" << endl; // 반납자의 정보를 받고 해당 회원이 대출중인 도서들의 목록중 선택해 반납처리 합니다.
		cout << "10. 도서 검색" << endl; // 도서를 검색합니다.
		cout << "11. 도서 목록" << endl; // 도서들의 목록을 봅니다.
		cout << "12. 도서 삭제" << endl; // 도서를 삭제합니다.
		cout << "13. 나만의 질문 변경" << endl; // 나만의 Q&A의 내용을 변경합니다.
		cout << " 종료를 원할 시 1-13외의 키를 눌러서 입력해주세요. " << endl; // 종료는 1~13외의 키를 입력하면 종료됩니다.
		cout << " >> ";
		
		cin >> key; // 입력을 받고
		try
		{
			if(cin.fail() || key >13 || key <1){
				throw "프로그램을 종료하도록 하겠습니다."; // 만약 이상한 값을 입력했었거나 1~13외의 수가 왔다면 throw를 해줍니다.
			}
			cin.ignore(20,'\n'); // 혹여나 이상한 값이 이 다음에 왔었다면 초기화를 해주기 위함.
			
			switch(key) // switch문을 통한 각 멤버함수의 호출 위에서 언급된 번호별로 함수의 기능은 말그대로 그 기능들을 수행합니다.
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
		catch(const char * s){ // 1~13외의 무언가가 입력되었었을때를 예외처리 해줍니다.
			cout << s << endl;
			return 0;
		}
	}
}
