#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void GameBoardReversing(vector<vector<int>> &my_board);
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> puzzles);
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables);
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> puzzles);
int PuzzleMatching(vector<vector<pair<int, int>>> boardBlanks, vector<vector<pair<int, int>>> puzzles);

vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};

vector<vector<int>> game_board2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 1}};
vector<vector<int>> table2 = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};

vector<vector<int>> game_board3 = {{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
vector<vector<int>> table3 = {{1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1}};

//-------------------------------------------------------------------------------------------------------------

//���� ���� �Լ�
int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    // 1) game_board�� ���ҵ��� ����
    GameBoardReversing(game_board);

    // 2) game_board�� ��ĭ ����� Ž��
    vector<vector<pair<int, int>>> boardBlanks = PuzzleDivision(game_board);

    cout << "<boardBlanks>\n";
    for (int i = 0; i < boardBlanks.size(); i++)
    {
        cout << "�� ĭ ��� " << i + 1 << endl;
        for (int j = 0; j < boardBlanks[i].size(); j++)
            cout << "[" << boardBlanks[i][j].first << "," << boardBlanks[i][j].second << "] ";
        cout << "\n\n";
    }
    cout << "----------------\n\n";

    // 3) table�� ������ Ž��
    vector<vector<pair<int, int>>> puzzles = PuzzleDivision(table);

    cout << "<puzzles>\n";
    for (int i = 0; i < puzzles.size(); i++)
    {
        cout << "���� " << i + 1 << endl;
        for (int j = 0; j < puzzles[i].size(); j++)
            cout << "[" << puzzles[i][j].first << "," << puzzles[i][j].second << "] ";
        cout << "\n\n";
    }
    cout << "----------------\n\n";

    // 4) 3������ ã�� �������� 2������ ã�� ��ĭ��� ���ϸ� ���� ���߱�
    int answer = PuzzleMatching(boardBlanks, puzzles);

    cout << "answer: " << answer << endl;
    return answer;
}

//���Ӻ��� 0-1 ����
void GameBoardReversing(vector<vector<int>> &my_board)
{
    for (int i = 0; i < my_board.size(); i++)
    {
        for (int j = 0; j < my_board[i].size(); j++)
        {
            if (my_board[i][j])
                my_board[i][j] = 0;
            else
                my_board[i][j] = 1;
        }
    }
}

//������ ��ĭ ������ ������� ��ǥ�� [0,0] �������� ����
//PuzzleDivision �Լ��� PuzzleRotation �Լ����� ���
vector<vector<pair<int, int>>> PuzzleReduction(vector<vector<pair<int, int>>> puzzles)
{
    //���� ������ŭ �ݺ�
    for (int i = 0; i < puzzles.size(); i++)
    {
        int minI = 1000;
        int minJ = 1000;

        //�� ���� ���̸�ŭ �ݺ�
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            //minI = min(puzzles[i][0]�� �� �� ~ puzzles[i][������ ��]�� �� ��)
            if (puzzles[i][j].first < minI)
                minI = puzzles[i][j].first;

            //minI = min(puzzles[i][0]�� �� �� ~ puzzles[i][������ ��]�� �� ��)
            if (puzzles[i][j].second < minJ)
                minJ = puzzles[i][j].second;
        }

        //�� ���� ���̸�ŭ �ݺ�
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            //puzzles[i][j]]�� �� �� -= minI
            puzzles[i][j].first -= minI;
            //puzzles[i][j]]�� �� �� -= minJ
            puzzles[i][j].second -= minJ;
        }
    }

    return puzzles;
}

//���� ������
//BFS�� �̿��ؼ� Ž��
vector<vector<pair<int, int>>> PuzzleDivision(vector<vector<int>> &tables)
{
    //return ���� ������ ������ ��
    vector<vector<pair<int, int>>> result;
    //�ߺ� Ž���� �ٿ��� Ž�� ȿ�� ����
    int last_i = 0;

    while (true)
    {
        vector<pair<int, int>> temp; //���� �� ���� �����ϱ� ���� temp
        queue<pair<int, int>> q;     //BFS Ž���� ���� ť

        //������ ù��° ���Ҹ� ã���� ť�� push
        for (int i = last_i; i < tables.size(); i++)
        {
            for (int j = 0; j < tables.size(); j++)
            {
                if (tables[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    tables[i][j] = 0; //��ǲ���� �־��� table�� visited ������� ���
                    last_i = i;       //���������� Ž���� i�� �����Ͽ� �������ʹ� last_i���� Ž��
                    break;
                }
            }

            //������ ù��° ���Ҹ� ã�Ҵٸ� break
            if (!q.empty())
                break;
        }

        //������ ���̻� ���ٸ� Ž�� ����
        if (q.empty())
            break;

        while (!q.empty())
        {
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            temp.push_back(q.front()); //������ ���ҵ��� ����
            q.pop();

            //���� ������ ��,��,��,�츦 Ž���غ��� �����Ѵٸ�
            //ť�� push�ϰ� �湮�� ��ġ ǥ��
            if (cur_i > 0 && tables[cur_i - 1][cur_j]) //��
            {
                q.push(make_pair(cur_i - 1, cur_j));
                tables[cur_i - 1][cur_j] = 0;
            }
            if (cur_i < tables.size() - 1 && tables[cur_i + 1][cur_j]) //��
            {
                q.push(make_pair(cur_i + 1, cur_j));
                tables[cur_i + 1][cur_j] = 0;
            }
            if (cur_j > 0 && tables[cur_i][cur_j - 1]) //��
            {
                q.push(make_pair(cur_i, cur_j - 1));
                tables[cur_i][cur_j - 1] = 0;
            }
            if (cur_j < tables.size() - 1 && tables[cur_i][cur_j + 1]) //��
            {
                q.push(make_pair(cur_i, cur_j + 1));
                tables[cur_i][cur_j + 1] = 0;
            }
        }

        sort(temp.begin(), temp.end());

        //���� �� ���� Ž���� ��ġ�� result�� ����
        result.push_back(temp);
    }

    //��� ������� ��ǥ ����
    result = PuzzleReduction(result);
    return result;
}

//��� ȸ��: -90�� ȸ��(�ݽð����)
//���� �ϳ��� �������� ���簢 ��ķ� ġȯ�Ͽ� ȸ��
//PuzzleMatching �Լ����� ���
vector<vector<pair<int, int>>> PuzzleRotation(vector<vector<pair<int, int>>> puzzles)
{
    for (int i = 0; i < puzzles.size(); i++)
    {
        int N = -1;
        //N = max(puzzles[i][j].first || puzzles[i][j].second)
        for (int j = 0; j < puzzles[i].size(); j++)
        {
            if (puzzles[i][j].first > N)
                N = puzzles[i][j].first;

            if (puzzles[i][j].second > N)
                N = puzzles[i][j].second;
        }

        for (int j = 0; j < puzzles[i].size(); j++)
            //-90�� ȸ���� ����[i, j] = ���� ����[N - puzzles[i][j]�� j, puzzles[i][j]�� i]
            puzzles[i][j] = make_pair(N - puzzles[i][j].second, puzzles[i][j].first);

        sort(puzzles[i].begin(), puzzles[i].end());
    }

    //��� ������� ��ǥ ����
    puzzles = PuzzleReduction(puzzles);
    return puzzles;
}

//���� ���߱�
int PuzzleMatching(vector<vector<pair<int, int>>> boardBlanks, vector<vector<pair<int, int>>> puzzles)
{
    cout << "<PuzzleMatching>\n";
    int temp_cnt = 1;
    int answer = 0; //answer = ä���� ĭ ��

    //ȸ�� 4����ŭ �ݺ�
    for (int r = 0; r < 4; r++)
    {
        //board�� �� ĭ ��� ������ŭ �ݺ�
        for (int i = 0; i < boardBlanks.size(); i++)
        {
            //���� ������ŭ �ݺ�
            for (int j = 0; j < puzzles.size(); j++)
            {
                //�� ĭ ��� ũ��� ���� ũ�Ⱑ ���ٸ� ������ ����
                if (boardBlanks[i].size() == puzzles[j].size())
                {
                    int k = 0;
                    //�� ĭ ��� ũ�⸸ŭ �ݺ�
                    for (k = 0; k < boardBlanks[i].size(); k++)
                        //�� ĭ ��ǥ�� ���� ��ǥ�� �ϳ��� �ٸ��ٸ� break
                        if (boardBlanks[i][k] != puzzles[j][k])
                            break;

                    //��� ��ǥ�� �����ϴٸ�
                    if (k == boardBlanks[i].size())
                    {
                        cout << "ȸ��: " << r * -90 << "��" << endl;
                        cout << "��Ī: boardBlanks " << i + temp_cnt++ << " & puzzle" << endl;
                        cout << "[i,j]: ";
                        for (int x = 0; x < puzzles[j].size(); x++)
                            cout << "[" << puzzles[j][x].first << "," << puzzles[j][x].second << "] ";
                        cout << "\n\n";

                        //�ش� �� ĭ ����� ������ ��Ī�Ǿ����Ƿ� ����
                        boardBlanks.erase(boardBlanks.begin() + i);
                        puzzles.erase(puzzles.begin() + j);
                        i--;

                        answer += k; //answer += ä���� ĭ ��
                        break;
                    }
                }
            } //end_for_j
        }     //end_for_i

        //������ ȸ����Ű�鼭 ��Ī
        puzzles = PuzzleRotation(puzzles);
    } //end_for_r

    return answer;
}

int main()
{
    solution(game_board, table);
}