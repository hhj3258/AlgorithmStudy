#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//���� ����
bool cmp(vector<float> a, vector<float> b)
{
    // �·��� ���ٸ� -> 2�� ����
    if (a[0] == b[0])
    {
        // �ڽź��� ���ſ� ��� �̱� Ƚ���� ���ٸ� -> 3�� ����
        if (a[1] == b[1])
        {
            // �����԰� ���ٸ� -> 4�� ����
            if (a[2] == b[2])
                // 4. ��ȣ�� ���� �� (��ȣ�� ���� ��찡 ����)
                return a[3] < b[3];
            // 3. �����԰� ū ��
            else
                return a[2] > b[2];
        }
        // 2. 1�� ���ٸ� -> �ڽź��� ���ſ� ��� �̱� Ƚ��
        else
            return a[1] > b[1];
    }
    // 1. �·�
    else
        return a[0] > b[0];
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<int> answer(weights.size());

    // �� ����: input���� �޾��� weights.size() -> ���� ��
    // ��: [�·�, �ڽź��� ���ſ� ��� �̱� Ƚ��, ������, ��ȣ]
    vector<vector<float>> all(weights.size(), vector<float>(4));

    //���� ����ŭ �ݺ�
    for (int i = 0; i < all.size(); i++)
    {
        float lose = 0;
        float win = 0;
        int bigger_win = 0; //�ڽź��� ���ſ� ��� �̱� Ƚ��

        //�� ������ head2head ��ŭ �ݺ�
        for (int k = 0; k < head2head[i].size(); k++)
        {
            if (head2head[i][k] == 'W')
            {
                //�̱� Ƚ�� + 1
                win++;

                //ex) head2head[i].size()=4��, i=0�̶��
                //ex) weights[0~4] > weights[0]
                if (weights[k] > weights[i])
                    //�ڽź��� ���ſ� ��� �̱� Ƚ�� + 1
                    bigger_win++;
            }

            if (head2head[i][k] == 'L')
                //�� Ƚ�� + 1
                lose++;
        }

        //��� ���� 0���� ũ�ٸ� all[i][0] = �·� = �̱� Ƚ��/(�̱� Ƚ�� + �� Ƚ��)
        //��� ���� 0�� ���ٸ� all[i][0] = �·� = 0% -> ������ 1�� ���ǿ��� ���
        all[i][0] = (win + lose) > 0 ? win / (win + lose) : 0;

        //all[i][1] = �ڽź��� ���ſ� ��� �̱� Ƚ��
        all[i][1] = bigger_win;

        //all[i][2] = ������
        all[i][2] = weights[i];

        //all[i][3] = ���� ��ȣ
        all[i][3] = i + 1;
    }

    cout << "[���� ��]\n";
    cout << "�·�      BigWin  ������  ��ȣ\n";
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << "     ";
        cout << endl;
    }
    cout << endl;

    // ������ ���� ���ǿ� ���� ����
    sort(all.begin(), all.end(), cmp);

    cout << "[���� ��]\n";
    cout << "�·�      BigWin  ������  ��ȣ\n";
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
            cout << all[i][j] << "     ";
        cout << endl;
    }
    cout << endl;

    //return �� = ���� ��ȣ = all[i][3]
    for (int i = 0; i < answer.size(); i++)
        answer[i] = all[i][3];

    return answer;
}

int main()
{
    vector<int> weights1 = {50, 82, 75, 120};
    vector<string> head2head1 = {"NLWL", "WNLL", "LWNW", "WWLN"};

    vector<int> weights2 = {145, 92, 86};
    vector<string> head2head2 = {"NLW", "WNL", "LWN"};

    vector<int> weights3 = {60, 70, 60};
    vector<string> head2head3 = {"NNN", "NNN", "NNN"};

    vector<int> answer = solution(weights1, head2head1);

    cout << "answer: ";
    for (int i : answer)
        cout << i << ", ";
}