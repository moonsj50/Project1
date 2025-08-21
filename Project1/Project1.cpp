#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	if (p_HPPotion != nullptr) {
		*p_HPPotion -= count;
	}
	else *p_MPPotion -= count;
}

void statusInfo(int* status){
	cout << "=====현재 스탯 정보=====" << endl;
	cout << "HP: " << status[0] << endl;
	cout << "MP: " << status[1] << endl;
	cout << "공격력: " << status[2] << endl;
	cout << "방어력: " << status[3] << endl;
	cout << "========================" << endl;
}

void potionInfo(int* potion) {
	cout << "=====현재 포션 정보====" << endl;
	cout << "HP포션: " << potion[0] << endl;
	cout << "MP포션: " << potion[1] << endl;
	cout << "=======================" << endl;
}

int main() {
	int status[4];
	int &hp = status[0];
	int &mp = status[1];
	int &atk = status[2];  // 공격력
	int &def = status[3];  // 방어력

	int potion[2];
	int &HPPotion = potion[0];
	int &MPPotion = potion[1];
	potion[0] = 5;
	potion[1] = 5;

	bool hpmpSucess = false;
	bool atkdefSucess = false;

	while (!hpmpSucess) {
	cout << "HP,MP를 입력해주세요 :" ;
	cin >> hp  >> mp;
	if (hp > 50 && mp > 50) {
		while (!atkdefSucess) {
			cout << "공격력과 방어력을 입력해주세요 : ";
			cin >> atk >> def;
			hpmpSucess = true;
			if (atk > 0 && def > 0) {
				atkdefSucess = true;
				cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
			}	
			else cout << "공격력과 방어력 두 스텟 모두 0이 넘게 입력해주세요." << endl;
		}
	}
	else cout << "HP와 MP 두 스텟 모두 50이 넘게 입력해주세요." << endl;
	} 

	int numChoice = 0;
	
	while (true) {
		cout << "==============================================" << endl;
		cout << "<스탯 관리 시스템>" << endl;
		cout << "1. HP 회복" << endl;
		cout << "2. MP 회복" << endl;
		cout << "3. HP 강화" << endl;
		cout << "4. MP 강화" << endl;
		cout << "5. 공격 스킬 사용" << endl;
		cout << "6. 필살기 사용" << endl;
		cout << "7. 현재 스탯 확인" << endl;
		cout << "8. 현재 포션 수 확인" << endl;
		cout << "9. 나가기" << endl;
		cout << "번호를 선택해주세요 : ";
		cin >> numChoice;
		cout << endl;

		switch (numChoice)
		{
		case 1:
			if (HPPotion > 0) {
				hp += 20;
				setPotion(1, &HPPotion, nullptr);
				cout << "HP가 20 회복되었습니다. HP포션이 1개 차감됩니다." << endl;
				cout << "현재 HP : " << hp << endl;
				cout << "남은 HP포션 수 : " << potion[0] << endl;
			}
			else {
				cout << "HP 포션이 없습니다." << endl;
			}
			break;
		case 2:
			if (MPPotion > 0) {
				mp += 20;
				setPotion(1, nullptr, & MPPotion );
				cout << "MP가 20 회복되었습니다. MP포션이 1개 차감됩니다." << endl;
				cout << "현재 MP : " << mp << endl;
				cout << "남은 MP포션 수 : " << potion[1] << endl;
			}
			else {
				cout << "MP 포션이 없습니다." << endl;
			}
			break;
		case 3:
				hp *= 2;
				cout << "HP가 2배 증가하였습니다." << endl;
				cout << "현재 HP : " << hp << endl;
			break;
		case 4:
			mp *= 2;
			cout << "MP가 2배 증가하였습니다." << endl;
			cout << "현재 MP : " << mp << endl;
			break;
		case 5:
			if (mp >= 50) {
				mp -= 50;
				cout << "공격스킬을 사용하여 MP를 50 소모하였습니다." << endl;
			}
			else cout << "MP가 부족합니다." << endl;
			break;
		case 6:
			if (mp >= 50) {
				mp /= 2;
				cout << "필살기를 사용하여 MP가 50% 소모되었습니다." << endl;
				cout << "현재 MP : " << mp << endl;
			}
			else {
				cout << "MP가 부족합니다." << endl;
			}
			break;
		case 7:
			statusInfo(status);
			break;
		case 8:
			potionInfo(potion);
			break;
		case 9:
			return 0;
			break;
		default:
			cout << "잘못된 번호를 선택했습니다. 다시 입력해주세요." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}