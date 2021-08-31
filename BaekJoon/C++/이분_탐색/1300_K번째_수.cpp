#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

void Solve()
{
    int left = 1;
    int right = K;

    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        long long cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            // mid/i = i �࿡�� mid���� ���� j�� ����
            // mid/i > N �� �� ��찡 �����Ƿ� mid/i�� N�� ���� ��
            cnt += min(mid / i, N);
        }

        if (cnt >= K)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer;
}

int main()
{
    cin >> N >> K;
    Solve();
}