#include <stdio.h>

int main()
{
    int T, n;
    int count[10001] = {
        0,
    }; //������ �ִ밪��ŭ �Ҵ�

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        count[n]++;
    }

    for (int i = 0; i < 10001; i++)
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
                printf("%d\n", i);
}