//���� 10757 : ū �� A+B
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<char> vec_in_num1, vec_in_num2;
    string str_in_num1, str_in_num2;

    // �ΰ��� ��ǲ�� ' '�� �������� �߶� str�� �޾���
    getline(cin, str_in_num1, ' ');
    getline(cin, str_in_num2);

    //�޾��� str ��ǲ�� �� ���̸� ����
    int str1_size = str_in_num1.size();
    int str2_size = str_in_num2.size();

    //�Է°��� ���� ������Ʈȭ
    for (int i = 0; i < str1_size; i++)
        vec_in_num1.push_back(str_in_num1[i]);
    for (int i = 0; i < str2_size; i++)
        vec_in_num2.push_back(str_in_num2[i]);

    //long_length = 2���� ��ǲ �� �� ���� ����
    int long_length = 0;
    if (str1_size > str2_size)
        long_length = str1_size;
    else
        long_length = str2_size;

    vector<char>::iterator it;
    //this_length = 2���� ��ǲ �� ª�� ���� ����
    int this_length = 0;

    //2���� ��ǲ�� ��ü ���̸� temp �� 0�� �����Ͽ� long_length�� ����
    if (long_length > str1_size)
    {
        this_length = long_length - str1_size;
        for (int i = 0; i < this_length; i++)
        {
            it = vec_in_num1.begin();
            vec_in_num1.insert(it, '0');
        }
    }
    else if (long_length > str2_size)
    {
        this_length = long_length - str2_size;
        for (int i = 0; i < this_length; i++)
        {
            it = vec_in_num2.begin();
            vec_in_num2.insert(it, '0');
        }
    }

    int* p_result_arr = new int[long_length];
    int int_temp1, int_temp2;

    //char ���͸� int�� ����ȯ�ϰ� �� ��ǲ ���� ������
    //p_result_arr[i] = vec_in_num[i] + vec_in_num2[i]
    for (int i = 0; i < long_length; i++)
    {
        int_temp1 = vec_in_num1[i] - '0';
        cout << int_temp1 << endl;
        int_temp2 = vec_in_num2[i] - '0';
        cout << int_temp2 << endl;
        p_result_arr[i] = int_temp1 + int_temp2;
        cout << p_result_arr[i] <<endl<<endl;
    }

    //p_result_arr �迭 �ε��� �� 10 �̻��� �ε����� ��� �ݿø�
    //�迭 0��° �ε����� ��� �ݿø� ������ ���� �ʿ䰡 ����
    for (int i = long_length - 1; i > 0; i--)
    {
        if (p_result_arr[i] > 9)
        {
            p_result_arr[i] -= 10;
            p_result_arr[i - 1] += 1;
        }
    }

    //��ü ���� ������ long_length��ŭ ���
    for (int i = 0; i < long_length; i++)
        cout << p_result_arr[i];

    return 0;
}