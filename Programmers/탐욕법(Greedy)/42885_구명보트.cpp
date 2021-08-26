#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while (start < end)
    {
        //2���� ����
        int kg = people[start] + people[end];

        //2���� ���԰� limit���� ũ�� ���ſ� ��� ȥ�� �¿�
        if (kg > limit)
        {
            end--;
        }
        //2���� ���԰� limit���� �۰ų� ������ �� �� �� �¿�
        else if (kg <= limit)
        {
            start++;
            end--;
        }
        //���� ���� + 1
        answer++;
    }

    //����� ���������� ���� ���� + 1
    if (start == end)
    {
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;
    cout << solution(people, limit);
}