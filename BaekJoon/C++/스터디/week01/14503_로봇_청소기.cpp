#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
//d = 0:��, 1:��, 2:��, 3:��

void Solve(vector<vector<int>> &room)
{
    room[r][c] = 2; // �ʱ� ��ġ û��

    while (true)
    {
        // ����� ��� �� ������ �ƴ϶��
        if (room[r][c - 1] != 0 && room[r - 1][c] != 0 && room[r][c + 1] != 0 && room[r + 1][c] != 0)
        {
            //���⿡ ���� ����
            if (d == 0)
                r += 1;
            else if (d == 1)
                c -= 1;
            else if (d == 2)
                r -= 1;
            else
                c += 1;

            //�����ϰ��� ���̶�� ����
            if (room[r][c] == 1)
                break;

            continue;
        }

        //������ ���� �ִٸ�
        if (d == 0)
        {
            //���� ĭ�� �� �����̶��
            if (room[r][c - 1] == 0)
            {
                //���� ĭ û��
                room[r][--c] = 2;
                //û�ұ� ������ �������� ����
                d = 3;
            }
            //���� ĭ�� �� �Ǵ� û���� ���̶��
            else
                //���⸸ ����
                d = 3;
        }
        else if (d == 1)
        {
            if (room[r - 1][c] == 0)
            {
                room[--r][c] = 2;
                d = 0;
            }
            else
                d = 0;
        }
        else if (d == 2)
        {
            if (room[r][c + 1] == 0)
            {
                room[r][++c] = 2;
                d = 1;
            }
            else
                d = 1;
        }
        else if (d == 3)
        {
            if (room[r + 1][c] == 0)
            {
                room[++r][c] = 2;
                d = 2;
            }
            else
                d = 2;
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (room[i][j] == 2)
                answer++;

    cout << answer;
}

int main()
{
    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    Solve(room);
}