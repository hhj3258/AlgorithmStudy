#include <bits/stdc++.h>
using namespace std;

int N;

void Solve(vector<int> &A)
{
    stack<int> myStack;

    // ���� A�� ũ�⸸ŭ �ݺ�
    for (int i = 0; i < N; i++)
    {
        // ������ ������� �ʰ�, A[myStack.top()]�� A[i]���� ���� ��
        while (!myStack.empty() && A[myStack.top()] < A[i])
        {
            A[myStack.top()] = A[i];
            myStack.pop();
        }

        // �� ���� ��쿡�� �ε��� i �� ���ÿ� push
        myStack.push(i);
    }

    // ��ū���� ã�� ���� ���Ҵ� -1�� ����
    while (!myStack.empty())
    {
        A[myStack.top()] = -1;
        myStack.pop();
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}