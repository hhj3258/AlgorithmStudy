#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// map�� second ��: vector<Songs>
// Songs(������ȣ, ���Ƚ��)
// pair�� ���������� ��ü�� ����� �����ϴ� ���� �� ��������
class Songs
{
public:
    int num;   // ������ȣ
    int plays; // ���Ƚ��

    Songs(int plays, int num)
    {
        this->num = num;
        this->plays = plays;
    }
};

// vector<Songs> ����: ��������
// �帣�� ���Ƚ���� ���� 2 ������� �̾��ֱ� ����
// ���Ƚ���� ������ ������ȣ�� ���� ��, �� �ܿ��� ���Ƚ���� ���� ��
bool cmp(Songs &a, Songs &b)
{
    if (a.plays == b.plays)
        return a.num < b.num;
    else
        return a.plays > b.plays;
}

// order_v ����: �帣�� ���Ƚ�� ���� ��������
// �帣���� ���Ƚ���� ���� ū ������ �����ϱ� ����
bool cmp2(pair<int, unordered_map<string, vector<Songs>>::iterator> &a,
          pair<int, unordered_map<string, vector<Songs>>::iterator> &b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    //map�� ���� ����� ������ ���� ������ �� ���� Ž���� ������ unordered_map ���
    //album[�帣��, [������ȣ, �帣�� ���Ƚ��]]
    unordered_map<string, vector<Songs>> album;

    //genres ���Ϳ��� ���Ƚ���� ������ȣ�� ã�� album�� �־���
    for (int i = 0; i < genres.size(); i++)
        album[genres[i]].push_back(Songs(plays[i], i));

    //album�� �帣 ������ŭ ���鼭 �帣�� vector<Songs> �� �������� ����
    for (auto iter = album.begin(); iter != album.end(); iter++)
        sort((*iter).second.begin(), (*iter).second.end(), cmp);

    //���� �� album ���� �׽�Ʈ ���
    cout << "<sorted>" << endl;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        cout << "[" << (*iter).first << "]" << endl;
        for (int i = 0; i < (*iter).second.size(); i++)
        {
            cout << "num: " << (*iter).second[i].num << "\t// ";
            cout << "plays: " << (*iter).second[i].plays;
            cout << endl;
        }
        cout << endl;
    }

    // order_v[�帣�� ���Ƚ�� ��, �帣�� �ݺ���]
    vector<pair<int, unordered_map<string, vector<Songs>>::iterator>> order_v;
    for (auto iter = album.begin(); iter != album.end(); iter++)
    {
        //songs_vec == vector<Songs>
        auto songs_vec = (*iter).second;
        int plays_sum = 0;
        for (int i = 0; i < songs_vec.size(); i++)
            plays_sum += songs_vec[i].plays;

        order_v.push_back(make_pair(plays_sum, iter));
    }

    //order_v�� �帣�� ���Ƚ���� �������� �������� ����
    sort(order_v.begin(), order_v.end(), cmp2);

    //���� �� order_v ���� �׽�Ʈ ���
    cout << "<sorted_order_v>" << endl;
    for (int i = 0; i < order_v.size(); i++)
    {
        cout << "i: " << i << " // " << order_v[i].first << endl;
    }
    cout << endl;

    //order_v[i].second == album�� iterator
    //(*order_v[i].second).second[j] == vector<Songs>
    //answer ���Ϳ� �帣���� �ִ� 2������� �־���
    for (int i = 0; i < order_v.size(); i++)
    {
        for (int j = 0; j < (*order_v[i].second).second.size(); j++)
        {
            //�帣�� �� ������ �ִ� 2��������
            if (j == 2)
                break;

            //������ȣ�� �־���
            answer.push_back((*order_v[i].second).second[j].num);
        }
    }

    return answer;
}

//�׽�Ʈ ���̽� ���
int main()
{
    vector<string> genres1 = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays1 = {500, 600, 150, 800, 2500};

    vector<string> genres2 = {"classic", "pop", "classic", "classic", "pop", "rap", "kpop", "kpop"};
    vector<int> plays2 = {500, 600, 150, 800, 2500, 50, 3000, 10};

    vector<string> genres3 = {"classic", "pop", "pop"};
    vector<int> plays3 = {500, 600, 650};

    vector<int> answer = solution(genres1, plays1);

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ", ";
    }
    cout << endl;
}