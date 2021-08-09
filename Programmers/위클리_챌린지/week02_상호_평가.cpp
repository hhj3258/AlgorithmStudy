//�������� ���� �ο�(��ȣ��)
//[i, j]=i�� �л��� ���� j�� �л��� ����
//0�� �л��� ���� ����=[0,0~4]
//[0, 0]=0�� �л��� ���� 0�� �л��� ����
//[2, 2]=2�� �л��� ���� 2�� �л��� ����
//�ڱ� �ڽ��� ���� ������ ������ �ְ��� or
//������ �������̸� �����ϰ� ��� ���
//0�� �л� ���=([1,0]+[2,0]+[3,0]+[4,0])/4
//��� ��: "FBABD"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

char Grade(float myScore)
{
    char myGrade;
    if (myScore >= 90)
        myGrade = 'A';
    else if (myScore >= 80)
        myGrade = 'B';
    else if (myScore >= 70)
        myGrade = 'C';
    else if (myScore >= 50)
        myGrade = 'D';
    else
        myGrade = 'F';

    return myGrade;
}

string solution(vector<vector<int>> scores)
{
    string answer = "";
    float aver[10] = {
        0,
    };

    for (int k = 0; k < scores.size(); k++)
    {
        int minV = 101;
        int maxV = -1;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i][k] < minV)
                minV = scores[i][k];
            if (scores[i][k] > maxV)
                maxV = scores[i][k];
        }

        int onlyN = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i][k] == minV)
                onlyN++;
            if (scores[i][k] == maxV)
                onlyN++;
        }

        int divN = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (i == k && onlyN == 1)
                continue;

            aver[k] += scores[i][k];
            divN++;
        }

        aver[k] /= divN;
        answer += Grade(aver[k]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> scores = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}};

    cout << solution(scores) << endl;
}