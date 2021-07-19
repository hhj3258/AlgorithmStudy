#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(string numbers)
{
    int answer = 0;
    set<int> my_set; //�ߺ����� �����ϱ� ���� set ���

    //��� ���� ������ ���ϱ� ���� �������� ����
    sort(numbers.begin(), numbers.end());

    cout << "������ ����� ��" << endl;
    do
    {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            my_set.insert(stoi(temp));
            cout << temp << ", ";
        }
        cout << endl;

    } while (next_permutation(numbers.begin(), numbers.end()));
    cout << endl;

    cout << "������� ���� �� �ߺ��� ����" << endl;
    for (auto iter = my_set.begin(); iter != my_set.end(); iter++)
    {
        cout << *iter << ", ";
    }
    cout << endl
         << endl;

    //*my_set.rbegin() ==> my_set�� ���� ������ ��(���� ū ��)
    int max_num = *my_set.rbegin();
    //�Ҽ� �Ǻ� ���͸� ���� ū ���� ũ�⸸ŭ �ʱ�ȭ
    vector<bool> isPrime(max_num, true);
    //���� 0,1�� �Ҽ��� �ƴϹǷ� false
    isPrime[0] = false;
    isPrime[1] = false;

    cout << "�����佺�׳׽��� ü" << endl;
    for (int i = 2; i * i <= max_num; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= max_num; j += i)
                isPrime[j] = false;
    }

    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            cout << i << ", ";
    }
    cout << endl
         << endl;

    //iter�� my_set�� ��ȸ�ϸ鼭 isPrime[*iter]�� �Ҽ���� answer++
    for (auto iter = my_set.begin(); iter != my_set.end(); iter++)
    {
        if (isPrime[*iter])
            answer++;
    }

    return answer;
}

int main()
{
    string numbers1 = "17";  //1,7,17,71
    string numbers2 = "101"; //0,1,10,11,101,110

    int answer = solution(numbers2);
    cout << "answer: " << answer << endl;
}