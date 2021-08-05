#include <iostream>
#include <vector>
using namespace std;

int N;          //�Է�: 1 �� N < 15
int answer = 0; //���

//ü���� �迭
vector<int> visited(15, -1);

// ������ ���� �Ǵ�
// qCnt: ���� ��ġ�� ���� ��
bool Check(int qCnt)
{
    // 0��° ����� qCnt ����� �ݺ�
    for (int i = 0; i < qCnt; i++)
    {
        // ��ġ�ߴ� ����� ���� ��ġ�Ϸ��� ���� ���� ������ �� �ִٸ� return 0
        // ������(��) �Ǵ�: ���� ��ġ�� ���� �� == ��ġ�ߴ� ���� �� ||
        // �밢�� �Ǵ�:     ���� ��ġ�� ���� �� - ��ġ�ߴ� ���� �� == ���밪(���� ��ġ�� ���� �� - ��ġ�ߴ� ���� ��)
        if (visited[qCnt] == visited[i] || qCnt - i == abs(visited[qCnt] - visited[i]))
            return 0;
    }

    //���� ���� ��ġ�� �� �ִٸ� return 1
    return 1;
}

void N_Queen(int qCnt)
{
    // ���� ��ġ�� ���� ������ �Է°�(N)�� ���ٸ� Ż��
    if (qCnt == N)
    {
        //���(�ش�)++
        answer++;

        //���̽� �׽�Ʈ ���
        cout << "<case " << answer << ">\n";
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] != -1)
                cout << "[" << i << ", " << visited[i] << "]\n";
        }
        cout << "\n";

        return;
    }

    // 0��° ����� N ����� �ݺ�
    for (int j = 0; j < N; j++)
    {
        // [qCnt, j] �� ��ġ�غ���
        visited[qCnt] = j;

        // ��ġ�� �� �ִٸ�
        if (Check(qCnt))
            // ���� ���� + 1 �ϰ� ���� ���� ��ġ�غ���.
            N_Queen(qCnt + 1);
    }
}

int main()
{
    cin >> N;
    N_Queen(0);
    cout << "answer: " << answer;
}