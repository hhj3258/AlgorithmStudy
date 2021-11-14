#include <bits/stdc++.h>
using namespace std;

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b)
{
    // �� ����� �θ� ���� �־��ش�
    a = getParent(parent, a);
    b = getParent(parent, b);

    // �� ���� ���� ū ���� �θ� ��尡 �ȴ�
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// ���� �θ� �������� Ȯ��
int findParent(int parent[], int a, int b)
{
    // �� ����� �θ� ���� �־��ش�
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    int parent[11];

    // ������ ������ 10�� ����
    for (int i = 1; i < 11; i++)
        parent[i] = i;

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);

    unionParent(parent, 5, 6);
    unionParent(parent, 7, 8);

    bool isGroup = findParent(parent, 1, 5);

    if (isGroup)
        cout << "�׷�";
    else
        cout << "�׷��� �ƴ�";
}