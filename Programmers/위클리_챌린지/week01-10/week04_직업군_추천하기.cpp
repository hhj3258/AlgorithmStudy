#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#",
                        "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
                        "HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
                        "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
                        "GAME C++ C# JAVASCRIPT C JAVA"};
vector<string> languages = {"PYTHON", "C++", "SQL"};
vector<int> preference = {7, 5, 5};

vector<vector<string>> TableOrganize(vector<string> table);
string FindHighScoreJob(vector<vector<string>> new_table, vector<string> languages, vector<int> preference);

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    //���̺� �籸��
    vector<vector<string>> new_table = TableOrganize(table);

    for (int i = 0; i < new_table.size(); i++)
    {
        for (int j = 0; j < new_table[i].size(); j++)
        {
            cout << new_table[i][j] << ", ";
        }
        cout << endl;
    }

    //���� ���� ������ ���� ������ Ž��
    string answer = FindHighScoreJob(new_table, languages, preference);

    return answer;
}

//{SI, JAVA, JAVASCRIPT, SQL, PYTHON, C#}, ... ���� �������� ���� �߶� �籸��
vector<vector<string>> TableOrganize(vector<string> table)
{
    //�籸���� ���̺� ���ҵ��� ���� 2���� �迭
    vector<vector<string>> new_table(5);

    //table �� ���̸�ŭ �ݺ�
    for (int i = 0; i < table.size(); i++)
    {
        string temp = "";
        //table �� ���̸�ŭ �ݺ�
        for (int j = 0; j < table[i].size(); j++)
        {
            //table[i][j]�� ������ �ƴ϶��
            if (table[i][j] != ' ')
                //temp�� table[i][j]�� ������
                temp += table[i][j];
            else
            {
                //table[i][j]�� �����̶�� ���ο� ���̺� temp�� �־��ְ�
                new_table[i].push_back(temp);
                //temp�� �����
                temp = "";
            }
        }
        //table[i]�� ������ ���Ұ� ������ �ƴϹǷ� ���� 1��¥�� �� �־���
        new_table[i].push_back(temp);
    }

    return new_table;
}

string FindHighScoreJob(vector<vector<string>> new_table, vector<string> languages, vector<int> preference)
{
    vector<int> scores(5);

    //������ ��ŭ �ݺ�
    for (int l = 0; l < languages.size(); l++)
        //5�� ��������ŭ �ݺ�
        for (int i = 0; i < new_table.size(); i++)
            //5�� ��� ������ŭ �ݺ�
            for (int j = 1; j < new_table[i].size(); j++)
                // ex1) new_table[0][4]==languages[0]
                // ex1) PYTHON==PYTHON
                if (new_table[i][j] == languages[l])
                    // ex1) scores[0] += 7 * (6 - 4);
                    scores[i] += preference[l] * (6 - j);

    //maxV = �������� ���� �� ���� ���� ����
    int maxV = *max_element(scores.begin(), scores.end());

    vector<string> temp;
    //���� ���� ������ 2�� �̻��� �� �����Ƿ�
    //5�� ��������ŭ �ݺ��ϸ� maxV�� ���� scores[i] ���� �ִٸ� temp�� ����
    for (int i = 0; i < 5; i++)
        if (scores[i] == maxV)
            temp.push_back(new_table[i][0]);

    //temp�� ����� �� �� ���� ���� ��(���� ������ ���� ���� ������) return
    return *min_element(temp.begin(), temp.end());
}

int main()
{
    cout << solution(table, languages, preference);
}