#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int count = 0;
int n;
int board[15];
int cnt = 0;
// �������� �Ǵ��ϴ� �Լ�
int promising(int cdx)
{
    // ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
    for (int i = 0; i < cdx; i++)
    {
        if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
        {
            return 0;
        }
    }
    return 1;
}
time_t s, e;
int sum = 0;
// nqueen �˰��� ����
void nqueen(int cdx)
{

    // cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
    if (cdx == n)
    {
        count++;
        //cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {

        board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.
        // ���� �� �࿡ �� �Ϳ� ���� �������� �Ǵ��Ѵ�.
        if (!promising(cdx))
            continue;
        // �� �ڸ��� �ξ �����Ҵٸ�,
        s = clock();
        //cout << "[" << cdx << " " << board[cdx] << "]\n";
        nqueen(cdx + 1); // �� ���� �࿡ ���� ���� ���� ���� �� ����.

        e = clock();
        sum += e - s;
    }

    cnt++;
}

int main()
{

    scanf("%d", &n);
    time_t start = clock();
    nqueen(0);
    printf("\n%d\n", count);

    time_t end = clock();
    double result_time = (double)(end - start);
    printf("time: %f ms\n", result_time);
    printf("sum: %d\n", sum);
    printf("cnt: %d", cnt);
}