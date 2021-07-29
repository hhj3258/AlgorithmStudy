#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define DATA_SIZE 20 //�����ؾߵ� ���� ����
#define MAX_NUM 10   //������ �ִ밪

int data_arr[DATA_SIZE];  //������ ���� ������ŭ �Ҵ�
int count[MAX_NUM];       //������ �ִ밪��ŭ �Ҵ�
vector<int> sorted_datas; //���ĵ� ���� ���� ����

void CountingSort(int datas[])
{
    //count �迭�� �ߺ��Ǵ� ������ ������ ī������
    for (int i = 0; i < DATA_SIZE; i++)
        count[datas[i]]++;

    cout << "[count]  ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    //count[i]=0�� ���� �������� �ʴ� �����̹Ƿ� �߰��� �ʿ䰡 ����
    //count[i]�� 0�� �ƴϸ� sorted_datas �迭�� count[i]�� ����ŭ �ݺ��ؼ� �߰�
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
                sorted_datas.push_back(i);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int n;

    cout << "[input]  ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        n = rand() % 10;
        data_arr[i] = n;

        cout << n << " ";
    }
    cout << endl;

    CountingSort(data_arr);

    cout << "[output] ";
    for (int i = 0; i < DATA_SIZE; i++)
    {
        cout << sorted_datas[i] << " ";
    }
}