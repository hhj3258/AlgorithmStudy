#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &vec, int left, int right)
{
    // �־��� ��쿡�� ���� ���� : �������� �߰����� �ٲ۴�.
    int mid = (left + right) / 2;
    swap(vec[mid], vec[left]);

    int pivot = left;

    while (left < right)
    {
        while (vec[right] >= vec[pivot] && left < right)
            right--;

        while (vec[left] <= vec[pivot] && left < right)
            left++;

        swap(vec[left], vec[right]);
    }

    swap(vec[pivot], vec[left]);

    return left;
}

void QuickSort(vector<int> &vec, int left, int right)
{
    // ���������� �߸��� ���
    if (left >= right)
    {
        return;
    }

    int pivot = Partition(vec, left, right);

    // pivot ����
    QuickSort(vec, left, pivot - 1);
    // pivot ����
    QuickSort(vec, pivot + 1, right);
}

int main()
{
    srand((unsigned int)time(0));

    vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.emplace_back(rand() % 10);
        cout << vec[i] << ' ';
    }
    cout << endl;

    QuickSort(vec, 0, vec.size() - 1);

    for (auto &item : vec)
        cout << item << ' ';
}