#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 1 �� N < 15

int answer;
void N_Queen(int N, int qCnt, vector<vector<bool>> visited)
{
    if (qCnt == N)
    {
        answer++;
        return;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    int i = 1;
    int j = 3;
    if (!visited[i][j])
    {
        //������
        for (int k = 0; k < N; k++)
            visited[i][k] = true;
        //������
        for (int k = 0; k < N; k++)
            visited[k][j] = true;
        // �밢��(\)
        for (int n = min(i, j);; n--)
        {
            visited[i - n][j - n] = true;

            if (i - n == N || j - n == N)
                break;
        }

        for (int n = min(i, j);; n--)
        {
            visited[i - n][j + n] = true;

            if (i - n == N || j + n == N)
                break;
        }
    }
    //     }
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{

    cin >> N;
    vector<vector<bool>> visited(N, vector<bool>(N)); // N*N

    N_Queen(N, 0, visited);
}