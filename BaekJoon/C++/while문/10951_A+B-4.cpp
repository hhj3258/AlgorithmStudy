#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    //���ǹ��� cin �־��ָ� �������� eof�� ������ bool �� false ����
    while (cin >> num1 >> num2)
        cout << (num1 + num2) << endl;
}