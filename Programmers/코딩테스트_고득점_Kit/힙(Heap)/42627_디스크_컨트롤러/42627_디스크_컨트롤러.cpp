#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Work
{
    int start_t, run_t;
};

struct cmp
{
    bool operator()(Work &a, Work &b)
    {
        if (a.run_t == b.run_t)
            return a.start_t > b.start_t;
        else
            return a.run_t > b.run_t;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Work, vector<Work>, cmp> low_run_q;

    int time = 0;
    int index = 0;
    do
    {
        //��û �ð��� ���� �ð����� ������
        if (index < jobs.size() && jobs[index][0] <= time)
        {
            //�켱���� ť�� push
            low_run_q.push({jobs[index][0], jobs[index][1]});
            index++;

            //index�� �ش��ϴ� ��û�ð��� time�� ������ ������ �ݺ�
            continue;
        }

        //���� ť�� ó������ �۾��� �ִٸ�
        if (!low_run_q.empty())
        {
            //����ð� += ���� �۾��� �ҿ�ð�
            time += low_run_q.top().run_t;
            //�۾��� ��û~������� �ɸ� �ð� += ����ð� - ���� �۾��� ��û�ð�
            answer += time - low_run_q.top().start_t;
            low_run_q.pop();
        }
        else
        {
            //���� ť�� ����ٸ�(ó������ �۾��� ���ٸ�)
            //����ð� = ���� ó���� �۾��� ��û�ð�
            time = jobs[index][0];
        }

    } while (index != jobs.size() || !low_run_q.empty());

    answer /= jobs.size();
    return answer;
}

int main()
{
    vector<vector<int>> jobs1 = {{0, 3}, {1, 9}, {2, 6}};
    vector<vector<int>> jobs2 = {{15, 2}, {2, 2}, {0, 3}, {1, 9}, {2, 6}, {4, 20}, {5, 1}};
    vector<vector<int>> jobs3 = {{0, 10}, {4, 10}, {15, 2}, {5, 11}};
    vector<vector<int>> jobs4 = {{300, 1}};

    int answer = solution(jobs4);
    cout << "answer: " << answer << endl;
}