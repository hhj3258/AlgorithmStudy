#include <iostream>
using namespace std;

int main(void) {
	int num = 0;			//1��
	int result = 0;		//���� true ����
	string test1[100];

	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> test1[i];

	for (int j = 0; j < num; j++) {
		int cnt = 0;
		bool chk = true;
		char temp1[100] = {};
		temp1[0] = test1[j].at(0);

		for (int i = 0; i < test1[j].length(); i++) {
			if (temp1[cnt] != test1[j].at(i)) 			//��Ƴ��� ����(temp1)�� i ��° ����(test1)�� �ٸ��ٸ�
				temp1[++cnt] = test1[j].at(i);		//temp1 �� ���� �ε����� i ��° ���� ����
		}

		for (int i = 0; i < cnt; i++) {
			char xx = temp1[i];
			int y = i + 1;
			while (temp1[y] != '\0') {
				if (temp1[y] == xx) {
					chk = false;
					break;
				}
				y++;
			}
		}

		if (chk) result++;

	}

	cout << result;
}