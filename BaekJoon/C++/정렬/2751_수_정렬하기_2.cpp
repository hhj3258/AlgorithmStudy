#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, arr2;

//����
void merge(int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;    //���ҵ� ���� �迭 ù��° �ε���
    int j = mid + 1; //���ҵ� ���� �迭 ù��° �ε���
    int k = left;
    //������ ��� Ž���ϰ� && ������ ��� Ž���� ������
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
            arr2[k++] = arr[j++];
    }

    int temp = i > mid ? j : i;

    while (k <= right)
    {
        arr2[k++] = arr[temp++];
    }

    for (int i = left; i <= right; i++)
        arr[i] = arr2[i];
}

//����
void partition(int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid + 1, right);
        merge(left, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        arr2.push_back(0);
    }

    partition(0, arr.size() - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}