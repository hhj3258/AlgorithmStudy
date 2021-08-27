#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id)
{

    for (int i = 0; i < new_id.size(); i++)
    {
        //1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = new_id[i] + 32;
            continue;
        }

        //2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
        }
        else
        {
            new_id.erase(new_id.begin() + i);
            i--;
            continue;
        }
    }

    //3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
    int dot_cnt = 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] != '.')
            dot_cnt = 0;
        else if (new_id[i] == '.')
        {
            dot_cnt++;
            if (dot_cnt >= 2)
            {
                new_id.erase(new_id.begin() + i);
                i--;
            }
        }
    }

    //4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
    if (new_id[0] == '.')
        new_id.erase(new_id.begin());
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.end() - 1);

    //5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
    if (new_id.size() == 0)
        new_id += "a";

    //6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
    //���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
    while (new_id.size() >= 16)
        new_id.pop_back();

    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();

    //7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
    while (new_id.size() <= 2)
        new_id += new_id[new_id.size() - 1];

    return new_id;
}

int main()
{
    string new_id1 = "...!@BaT#*..y.abcdefghijklm";
    string result = "bat.y.abcdefghi";

    string new_id2 = "=.=";
    string result2 = "aaa";

    string answer = solution(new_id2);

    cout << "answer: " << answer << endl;
    cout << "result: " << result2 << endl;

    if (answer == result2)
        cout << "���";
    else
        cout << "�ٽ�";
}