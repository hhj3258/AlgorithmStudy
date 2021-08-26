#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool check(vector<int> answer, int subset)
{
    //�ּҼ� �˻�
    //���ݱ��� ���� answer�� ���ϼ� �˻縦 ����� subset�� �κ��������� Ȯ��
    for (int i = 0; i < answer.size(); i++)
    {
        //�κ������̶�� �ּҼ� �˻� ����
        if ((answer[i] & subset) == answer[i])
            return false;
    }

    return true;
}

int solution(vector<vector<string>> relation)
{
    vector<int> answer;
    //�������� �κ������� ����� �� = 1 << relation[0].size()
    for (int i = 1; i < (1 << relation[0].size()); i++)
    {
        set<string> mySet;
        //���ϼ� �˻�
        //��� ���� ���� �˻�
        for (int j = 0; j < relation.size(); j++)
        {
            string temp = "";

            for (int k = 0; k < relation[0].size(); k++)
            {
                // (1<<k) = 0001,0010,0100,1000
                // i = 0001,0010,0011,0100,0101 ...
                if (i & (1 << k))
                    temp += relation[j][k];
            }

            mySet.insert(temp);
        }

        //���ϼ� �˻縦 ����ߴٸ�
        if (mySet.size() == relation.size())
        {
            //�ּҼ� �˻縦 ����ߴٸ�
            if (check(answer, i))
                //answer�� �ϳ� �÷���
                answer.push_back(i);
        }
    }

    return answer.size();
}

int main()
{
    vector<vector<string>> relation = {{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};

    cout << solution(relation);
}