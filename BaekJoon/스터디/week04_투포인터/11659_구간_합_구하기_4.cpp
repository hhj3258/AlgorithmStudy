#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    // ���� ���� >> ���� ���ؾ� �ϴ� Ƚ��
    cin >> N >> M;

    // ���ҵ�
    vector<int> nums(N);
    // ���� ��
    vector<int> sums(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        sums[i + 1] = sums[i] + nums[i];
    }

    // ���� ���ؾ� �ϴ� ����
    vector<pair<int, int>> sections(M);
    int left, right;
    for (int i = 0; i < M; i++)
    {
        cin >> left >> right;
        cout << sums[right] - sums[left - 1] << '\n';
    }
}