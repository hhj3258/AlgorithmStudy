#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void Solve(vector<int> A)
{
    vector<int> vec(1, 0);

    for (int i = 0; i < N; i++)
    {
        //�ְ����ϴ� ���� vec�� ������ ������ ũ�ٸ� �־��ش�.
        if (A[i] > vec.back())
            vec.push_back(A[i]);
        //�ְ����ϴ� ���� vec�� ������ ������ �۰ų� ���ٸ�
        else
        {
            //temp�� ���� vec�ȿ��� ã�ƺ���.
            //temp�� �ִٸ� �� iter�� ������ ���̰�, ���ٸ� temp���� ū ������ ���� ó�� ���� iter�� ��ȯ���ش�.
            auto low = lower_bound(vec.begin(), vec.end(), A[i]);
            //�ش� iter�� �ش�Ǵ� vec ���� �������ش�.
            *low = A[i];
        }
    }

    //�ʱⰪ���� �־��� 0�� ������ vec�� ���̰� ���� �� �����ϴ� �κ� ������ ���̰� �ȴ�.
    cout << vec.size() - 1 << endl;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}