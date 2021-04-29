#include <iostream>
using namespace std;

void PrimeChk(int in_num, bool* p_chk);

int main()
{
    int t_case = 0;
    cin >> t_case;

    int MAX = 0;
    int* in_num = new int[t_case];

    for (int i = 0; i < t_case; i++) //�׽�Ʈ ���̽���ŭ �Է�
    {
        cin >> in_num[i];
        if (in_num[i] > MAX)
            MAX = in_num[i];
    }

    bool* p_chk = new bool[MAX];

    PrimeChk(MAX, p_chk); //�Ҽ� üũ�� ���̽��� ���� ū ���θ� �� ���� ������ ��

    for (int i = 0; i < t_case; i++)
    {
        int fir_n = in_num[i] / 2;
        int sec_n = in_num[i] / 2;

        while (!p_chk[fir_n] || !p_chk[sec_n])
        {
            fir_n--;
            sec_n++;
        }

        cout << fir_n;
        cout << " " << sec_n << endl;
    }

    return 0;
}

void PrimeChk(int in_num, bool* p_chk) //�����佺�׳׽��� ü
{
    for (int i = 0; i <= in_num; i++)
        p_chk[i] = 1; //true

    p_chk[0] = 0;
    p_chk[1] = 0;

    for (int i = 2; i <= in_num; i++) // �迭 ī��Ʈ
    {
        if (i * i >= in_num) // p^2 > n
            break;

        for (int j = 2; i * j <= in_num; j++) // ������ ����
            p_chk[i * j] = false;
    }
}