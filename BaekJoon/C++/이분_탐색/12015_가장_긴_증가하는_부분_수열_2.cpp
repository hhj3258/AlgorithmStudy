#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void Solve(vector<int> A)
{
    int temp = 0;
    int cnt = 0;
    vector<int> vec(1, 0);

    for (int i = 0; i < N; i++)
    {
        temp = A[i];

        //�ְ����ϴ� ���� vec�� ������ ������ ũ�ٸ� �־��ְ�
        //���� + 1
        if (temp > vec.back())
        {
            vec.push_back(temp);
            cnt++;
        }
        //�ְ����ϴ� ���� vec�� ������ ������ �۰ų� ���ٸ�
        //temp�� ���� vec�ȿ��� ã�ƺ���.
        //temp�� �ִٸ� �� iter�� ������ ���̰�, ���ٸ� temp���� ū ������ ���� ó�� ���� iter�� ��ȯ���ش�.
        //�ش� iter�� �ش�Ǵ� vec ���� �������ش�.
        else
        {
            auto low = lower_bound(vec.begin(), vec.end(), temp);
            *low = temp;
        }
    }

    cout << cnt << endl;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}