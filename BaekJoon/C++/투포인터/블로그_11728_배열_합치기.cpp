#include <bits/stdc++.h>
using namespace std;

int N, M;

void TwoPointer(vector<int> &A, vector<int> &B)
{
    // �迭 A�� B ����
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ptrA = 0; // �迭 A ������
    int ptrB = 0; // �迭 B ������

    // answer: A�迭�� B�迭�� ������ �迭
    vector<int> answer(N + M);
    // �迭 answer ������(�ε����� ���� ������)
    int idx = 0;

    //�迭 A �����Ͱ� N���� �۰� �迭 B �����Ͱ� M���� ���� ������ �ݺ�
    while (ptrA < N && ptrB < M)
    {
        // A�� �������� ���� B�� �������� ������ �۴ٸ�
        if (A[ptrA] < B[ptrB])
        {
            // A �������� ���� �־��ش�
            answer[idx++] = A[ptrA];
            // A ������ + 1
            ptrA++;
        }
        // �� ���� ���
        else
        {
            // B �������� ���� �־��ش�
            answer[idx++] = B[ptrB];
            // B ������ + 1
            ptrB++;
        }
    }

    // A �迭�� ��� Ž������ ���ߴٸ�
    while (ptrA < N)
        // A �迭�� ���� ��� �־��ش�
        answer[idx++] = A[ptrA++];

    // B �迭�� ��� Ž������ ���ߴٸ�
    while (ptrB < M)
        // B �迭�� ���� ��� �־��ش�
        answer[idx++] = B[ptrB++];

    for (int i : answer)
        cout << i << ' ';
}

int main()
{
    // �Է� �ӵ� ����
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // �迭 A ũ�� >> �迭 B ũ��
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    TwoPointer(A, B);
}