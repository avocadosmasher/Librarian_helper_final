#include "login.h"
#include <iostream>
#include <string>
#include <algorithm>

Login::Login(){
	password = "970426"; // ÃÊ±âºñ¹Ğ¹øÈ£´Â Á¦°¡ ÀÓÀÇ·Î ¼³Á¤ÇÏ¿´½À´Ï´Ù.
	pStack = 0;
	qStack = 0;
	question = "³» ÀÌ´Ï¼ÈÀº?"; // Áú¹®µµ Á¦°¡ ÀÓÀÇ·Î
	answer = "kyw"; // Á¦ ÀÌ´Ï¼È·Î ´äº¯À» ¼³Á¤
}

void Login::ChangePassword(){ // ºñ¹Ğ¹øÈ£ º¯°æÀ» À§ÇÑ ¸â¹öÇÔ¼ö.
	string user1; // »ç¿ëÀÚ°¡ Ã³À½ ÀÔ·ÂÇÑ ºñ¹Ğ¹øÈ£¸¦ ÀÔ·Â ¹ŞÀ» °´Ã¼
	string user2; // »ç¿ëÀÚ°¡ ºñ¹Ğ¹øÈ£ È®ÀÎÀ» À§ÇØ ÀÔ·ÂÇÑ ¹®ÀÚ¿­À» ÀÔ·Â¹ŞÀ» °´Ã¼
	 
	while(1){ // ÀÌ¹Ì main¿¡¼­ ³ª¸¸ÀÇ Q&A¿¡ ´ëÇÑ °Ë»ç°¡ ¸ğµÎ ¿Ï·áµÈÈÄ ¿Ã¹Ù¸¥ »ç¿ëÀÚ¶ó ÆÇº°µÇ¾úÀ»¶§ È£ÃâµÊÀ¸·Î ¹Ù·Î ÁøÇàÇÕ´Ï´Ù.
		cout << "Çö ±â´ÉÀÇ Á¾·á¸¦ ¿øÇÒ½Ã¿¡´Â exitÀÌ¶ó°í ÀÔ·ÂÇØ ÁÖ¼¼¿ä." << endl;
		cout << "»õ·Î¿î ºñ¹Ğ¹øÈ£ : ";
		getline(cin,user1);
		
		if(user1 == "exit") break; // Çö ±â´ÉÀ» Á¾·áÇÏ°í ½Í´Ù¸é exitÀ» ÅëÇØ ³ª°©´Ï´Ù.
		
		else if(user1.size() == 6){ // ºñ¹Ğ¹øÈ£ º¯°æ ÁøÇà. 
			try{
				for(int i = 0; i<6; i++){
					if(user1[i] == ' '){ // °ø¹éÀÌ ÀÔ·ÂµÇ¾î ÀÖÀ¸¸é ¿À·ùÀÓ.
						throw "°ø¹éÀº ºñ¹Ğ¹øÈ£¿¡ Æ÷ÇÔµÉ ¼ö ¾ø½À´Ï´Ù."; // ºñ¹Ğ¹øÈ£´Â °ø¹éÀÌ ¿Ã ¼ö ¾ø½À´Ï´Ù.
					}
				}
				cout << "ºñ¹Ğ¹øÈ£ È®ÀÎ : "; // ºñ¹Ğ¹øÈ£¸¦ È®ÀÎÇØ´Ş¶ó´Â ¿äÃ».
				getline(cin,user2);
				if(user1 == user2){ //º¯°æ¿Ï·áÀÔ´Ï´Ù.
					password = user1;
					cout << "ºñ¹Ğ¹øÈ£ º¯°æÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl; // 
					break;
				}
				else{ // ºñ¹Ğ¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê´Ù¸é ºñ¹Ğ¹øÈ£ º¯°æÀ» Ã³À½ºÎÅÍ ´Ù½Ã ÁøÇàÇÕ´Ï´Ù.
					cout << "ÀÔ·ÂÇÏ½Å ºñ¹Ğ¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù."<< endl;
					cout << "ºñ¹Ğ¹øÈ£ º¯°æÀ» Ã³À½ºÎÅÍ ´Ù½Ã ÁøÇàÇÕ´Ï´Ù." << endl;
				}
			}
			catch(const char * s){ // ¿¹¿ÜÃ³¸®¸¦ ÇÕ½Ã´Ù.
				cout << s << endl;	
			}
		}
		else{ // ¸¸¾à size°¡ 6ÀÚ¸®°¡ µÇÁö ¾Ê´Â´Ù¸é ºñ¹Ğ¹øÈ£ÀÇ Çü½ÄÀ» ÁöÅ°Áö ¾Ê¾Ò±â ¶§¹®¿¡ ºñ¹Ğ¹øÈ£ÀÇ Çü½ÄÀ» ¾Ë·ÁÁÖ°í ´Ù½Ã ÁøÇàÇÕ´Ï´Ù.
			cout << "ºñ¹Ğ¹øÈ£´Â °ø¹éÀ» Æ÷ÇÔÇÏÁö ¾Ê´Â 6ÀÚ¸® ÀÌ¾î¾ß ÇÕ´Ï´Ù.(¹®ÀÚ,¼ıÀÚ µÑ´Ù °¡´É)" << endl; 
			continue;
		}
	}
}

bool Login::CheckPassword(string enter){ // ºñ¹Ğ¹øÈ£°¡ ¸Â´ÂÁö È®ÀÎÇÏ´Â ºÎºĞ.
	if(enter == password){ // ¸¸¾à ¸Â´Ù ±×·¯¸é ³ª¸¸ÀÇ Áú¹® ½ºÅÃµµ ºñ¹Ğ¹øÈ£ ¿À·ù ½ºÅÃµµ ÀüºÎ ÃÊ±âÈ­ÇØÁİ´Ï´Ù.
		pStack = 0; // ºñ¹øÀ» ¸Â­ŸÀ¸´Ï ´Ù½Ã 0À¸·Î ¸®¼Â 
		qStack = 0; // Q&Aµµ ½ºÅÃµµ 0À¸·Î ÃÊ±âÈ­ ½ÃÄÑÁİ½Ã´Ù.(°á±¹ ºñ¹Ğ¹øÈ£¸¦ ¸ÂÃá°Å´Ï ¿Ã¹Ù¸¥ »ç¿ëÀÚ°¡ ¸Â´Ù°í ÆÇ´Ü.) 
		return true;
	}
	else{ // Æ²·ÈÀ¸´Ï ½ºÅÃ ++
		pStack++; // pStackÀ» ++ÇØÁÜÀ¸·Î½á Æ²¸° È½¼ö¸¦ Áõ°¡. 
		return false;
	}
}
bool Login::CheckQnA(string enter){ // ³ª¸¸ÀÇ Áú¹® ´äº¯ È®ÀÎ
	
	if(enter == answer){ // ´äº¯ÀÇ ÀÏÄ¡¸¦ È®ÀÎÇÕ´Ï´Ù.
		qStack = 0; // ¸ÂÃèÀ¸´Ï ÃÊ±âÈ­ 
		pStack = 0; // ³ª¸¸ÀÇ Áú¹®¿¡ ´ëÇÑ ´äº¯À» ¸ÂÃß¾úÀ¸´Ï ÇâÈÄ¿¡ ºñ¹øÀ» ¹Ù²Ù´ø ¸»´ø »ó°ü¾øÀÌ ÀÏ´Ü ¿Ã¹Ù¸¥ »ç¿ëÀÚÀÓÀ» È®ÀÎ. 
		return true; // true¸¦ ¹İÈ¯
	}
	else{ // ´äº¯ÀÌ ºÒÀÏÄ¡
		qStack++; // ³ª¸¸ÀÇ Áú¹® ´äº¯ Æ²¸°È½¼ö Áõ°¡. 
		return false; // false ¹İÈ¯
	}
}
int Login::ShowpStack(){ // Çö Password ¿À·ù ½ºÅÃÀ» ¹İÈ¯
	return pStack;
} 
int Login::ShowqStack(){ // Çö ³ª¸¸ÀÇ Áú¹® ¿À·ù ½ºÅÃÀ» ¹İÈ¯
	return qStack;
}
void Login::ShowQuestion(){ // ³ª¸¸ÀÇ Áú¹®À» º¸¿©Áİ´Ï´Ù.
	cout << question << endl;
}

void Login::ChangeQnA(){ // ³ª¸¸ÀÇ Áú¹® º¯°æ±â´É
	string new_question; // »õ·Î¿î Áú¹®ÀÌ ÀúÀåµÉ º¯¼ö
	string new_answer;   // ±× Áú¹®¿¡ ´ëÇÑ ´äº¯ÀÌ ÀúÀåµÉ º¯¼ö
	string yn; // yes or no
	try {
		while (1) { // ±âº»ÀûÀ¸·Î ±×³É »õ Áú¹®À» ÀÔ·ÂÇÏ°í ±× Áú¹®ÀÌ ¸Â´ÂÁö È®ÀÎÇÑ ÈÄ ÇÏ´Â ½ÄÀÇ(»õ ´äº¯µµ µ¿ÀÏÇÑ Çü½Ä) ÁøÇà¹æ½ÄÀÔ´Ï´Ù.
			cout << "»õ·Î¿î Áú¹® ÀÔ·Â : ";
			getline(cin, new_question);

			cout << "ÀÔ·ÂÇÏ½Å Áú¹®ÀÌ []¾ÈÀÇ Áú¹®ÀÌ ¸Â½À´Ï±î? (yes/no)" << endl <<"--Á¾·á¸¦ ¿øÇÒ ½Ã ´Ù¸¥ ¾Æ¹«Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä.--" << endl << "[" << new_question << "]" << endl;
			getline(cin, yn);
			transform(yn.begin(), yn.end(), yn.begin(), ::toupper); // ÀÌºÎºĞ¸¸ Æ¯ÀÌÇÏ´Ï ¼³¸íÇÕ´Ï´Ù. transformÀ» ÅëÇØ ´ë¼Ò¹®ÀÚ ÀÔ·ÂÀ» ±¸ºĞÇÏÁö¾Ê°í ±×´ë·Î ¹Ş¾Æµé¿© ´Ù ´ë¹®ÀÚÈ­ ÇØÁİ´Ï´Ù.
			if (yn == "YES");

			else if (yn == "NO") {
				cout << "´Ù½Ã ÁøÇàÇÕ´Ï´Ù." << endl;
				continue;
			}
			else {
				throw "¸ŞÀÎ¸Ş´º·Î µ¹¾Æ°©´Ï´Ù.";
			}

			while (1) { // À§¿Í µ¿ÀÏ
				cout << "»õ·Î¿î ´äº¯ ÀÔ·Â : ";
				getline(cin, new_answer);

				cout << "ÀÔ·ÂÇÏ½Å ´äº¯ÀÌ []¾ÈÀÇ ´äº¯ÀÌ ¸Â½À´Ï±î? (yes/no)" << endl << "-- Á¾·á¸¦ ¿øÇÒ ½Ã ´Ù¸¥ ¾Æ¹«Å°³ª ÀÔ·ÂÇØÁÖ¼¼¿ä.--" << endl << "[" << new_answer << "]" << endl;
				getline(cin, yn);
				transform(yn.begin(), yn.end(), yn.begin(), ::toupper);

				if (yn == "YES") {
					question = new_question;
					answer = new_answer;
					cout << "Q&A º¯°æÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
					break;
				}
				else if (yn == "NO") {
					continue;
				}
				else {
					throw "¸ŞÀÎ¸Ş´º·Î µ¹¾Æ°©´Ï´Ù.";
				}
			}
			break;
		}
	}
	catch (const char* s) { // ¿¹¿ÜÃ³¸®.
		cout << s << endl;
	}
}
