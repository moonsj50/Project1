#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	if (p_HPPotion != nullptr) {
		*p_HPPotion -= count;
	}
	else *p_MPPotion -= count;
}

void statusInfo(int* status){
	cout << "=====���� ���� ����=====" << endl;
	cout << "HP: " << status[0] << endl;
	cout << "MP: " << status[1] << endl;
	cout << "���ݷ�: " << status[2] << endl;
	cout << "����: " << status[3] << endl;
	cout << "========================" << endl;
}

void potionInfo(int* potion) {
	cout << "=====���� ���� ����====" << endl;
	cout << "HP����: " << potion[0] << endl;
	cout << "MP����: " << potion[1] << endl;
	cout << "=======================" << endl;
}

int main() {
	int status[4];
	int &hp = status[0];
	int &mp = status[1];
	int &atk = status[2];  // ���ݷ�
	int &def = status[3];  // ����

	int potion[2];
	int &HPPotion = potion[0];
	int &MPPotion = potion[1];
	potion[0] = 5;
	potion[1] = 5;

	bool hpmpSucess = false;
	bool atkdefSucess = false;

	while (!hpmpSucess) {
	cout << "HP,MP�� �Է����ּ��� :" ;
	cin >> hp  >> mp;
	if (hp > 50 && mp > 50) {
		while (!atkdefSucess) {
			cout << "���ݷ°� ������ �Է����ּ��� : ";
			cin >> atk >> def;
			hpmpSucess = true;
			if (atk > 0 && def > 0) {
				atkdefSucess = true;
				cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;
			}	
			else cout << "���ݷ°� ���� �� ���� ��� 0�� �Ѱ� �Է����ּ���." << endl;
		}
	}
	else cout << "HP�� MP �� ���� ��� 50�� �Ѱ� �Է����ּ���." << endl;
	} 

	int numChoice = 0;
	
	while (true) {
		cout << "==============================================" << endl;
		cout << "<���� ���� �ý���>" << endl;
		cout << "1. HP ȸ��" << endl;
		cout << "2. MP ȸ��" << endl;
		cout << "3. HP ��ȭ" << endl;
		cout << "4. MP ��ȭ" << endl;
		cout << "5. ���� ��ų ���" << endl;
		cout << "6. �ʻ�� ���" << endl;
		cout << "7. ���� ���� Ȯ��" << endl;
		cout << "8. ���� ���� �� Ȯ��" << endl;
		cout << "9. ������" << endl;
		cout << "��ȣ�� �������ּ��� : ";
		cin >> numChoice;
		cout << endl;

		switch (numChoice)
		{
		case 1:
			if (HPPotion > 0) {
				hp += 20;
				setPotion(1, &HPPotion, nullptr);
				cout << "HP�� 20 ȸ���Ǿ����ϴ�. HP������ 1�� �����˴ϴ�." << endl;
				cout << "���� HP : " << hp << endl;
				cout << "���� HP���� �� : " << potion[0] << endl;
			}
			else {
				cout << "HP ������ �����ϴ�." << endl;
			}
			break;
		case 2:
			if (MPPotion > 0) {
				mp += 20;
				setPotion(1, nullptr, & MPPotion );
				cout << "MP�� 20 ȸ���Ǿ����ϴ�. MP������ 1�� �����˴ϴ�." << endl;
				cout << "���� MP : " << mp << endl;
				cout << "���� MP���� �� : " << potion[1] << endl;
			}
			else {
				cout << "MP ������ �����ϴ�." << endl;
			}
			break;
		case 3:
				hp *= 2;
				cout << "HP�� 2�� �����Ͽ����ϴ�." << endl;
				cout << "���� HP : " << hp << endl;
			break;
		case 4:
			mp *= 2;
			cout << "MP�� 2�� �����Ͽ����ϴ�." << endl;
			cout << "���� MP : " << mp << endl;
			break;
		case 5:
			if (mp >= 50) {
				mp -= 50;
				cout << "���ݽ�ų�� ����Ͽ� MP�� 50 �Ҹ��Ͽ����ϴ�." << endl;
			}
			else cout << "MP�� �����մϴ�." << endl;
			break;
		case 6:
			if (mp >= 50) {
				mp /= 2;
				cout << "�ʻ�⸦ ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl;
				cout << "���� MP : " << mp << endl;
			}
			else {
				cout << "MP�� �����մϴ�." << endl;
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
			cout << "�߸��� ��ȣ�� �����߽��ϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}