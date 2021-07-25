#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BlackJack(int N, int M, vector<int> card)
{
    //ī����� �������� ����
    sort(card.begin(), card.end());

    //�������� ���ĵ� �켱���� ť ����
    priority_queue<int, vector<int>, less<int>> answer_q;

    //���� ū 3�� ī���� index
    int big_idx = card.size() - 1;
    int mid_idx = card.size() - 2;
    int sml_idx = card.size() - 3;

    int sum_temp;

    //3���� ī���� ���� ���ؾ��ϹǷ�
    //sml_idx=0, mid_idx=1, big_idx=2 �� ������ �ݺ�
    while (big_idx > 1)
    {
        //ī�� 3���� ��
        sum_temp = card[sml_idx] + card[mid_idx] + card[big_idx];

        //���� ���
        cout << "idx: [" << sml_idx << " " << mid_idx << " " << big_idx << "] ,  ";
        cout << card[sml_idx] << " + " << card[mid_idx] << " + " << card[big_idx] << " = ";
        cout << sum_temp << endl;

        //ī�� 3���� ���� M���� ������ answer_q�� �־���
        if (sum_temp <= M)
            answer_q.push(sum_temp);

        //sml_idx ==> card.size()-3 ~ 0
        if (sml_idx > 0)
        {
            sml_idx--;
        }
        //mid_idx ==> card.size()-2 ~ 1
        else if (mid_idx > 1)
        {
            mid_idx--;
            sml_idx = mid_idx - 1;
        }
        //big_idx ==> card.size()-1 ~ 2
        else
        {
            big_idx--;
            mid_idx = big_idx - 1;
            sml_idx = mid_idx - 1;
        }
    }

    //���� ���
    cout << "answer: " << answer_q.top() << endl;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> card(N);

    for (int i = 0; i < card.size(); i++)
    {
        cin >> card[i];
    }

    BlackJack(N, M, card);
}