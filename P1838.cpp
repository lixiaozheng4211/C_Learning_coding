/*
2025��3��11��23:40:59;
*/
#include <bits/stdc++.h>
using namespace std;
bool isSame(int x, int a, int b, int c);
bool isWin(vector<vector<int>> &board, int x);
int judge(vector<int> &player);
int main()
{
  string str;
  cin >> str;
  auto board = vector(3, vector(3, -1));
  for (size_t i = 0; i < str.size(); i++)
  {
    int pos = str[i] - '1';
    int x = pos / 3, y = pos % 3; // ���Ǻܳ���������ת����ʽҪע��ĵ�����±�Ŀ�ʼʱ0
    board[x][y] = i % 2;
  }
  if (isWin(board, 0))
    cout << "xiaoa wins.";
  else if (isWin(board, 1))
    cout << "uim wins.";
  else
    cout << "drew.";
}
bool isWin(vector<vector<int>> &board, int x)
{
  for (int i = 0; i < 3; i++)
  {
    if (isSame(x, board[i][0], board[i][1], board[i][2]))
      return true;
    if (isSame(x, board[0][i], board[1][i], board[2][i]))
      return true;
  }
  if (isSame(x, board[0][0], board[1][1], board[2][2]))
    return true;
  if (isSame(x, board[0][2], board[1][1], board[2][0]))
    return true;
  else
    return false;
}
bool isSame(int x, int a, int b, int c)
{
  return a == x && b == x && c == x;
}
/*
��������Ҵ�����Ĵ�����ѧ���Ķ���

���Ⱦ��������������������֮ǰû���õ��ģ����о�����������ӳ�䣬�ǳ�������

������������
�����C++17�������Ծ��ǿ���ֱ���Ƶ�����������
����Ĵ����ǣ�auto board = vector(3, vector (3,-1));
������д���ȼ��ڣ�vector<vector <int>> board = vector(3, vector (3,-1));
���������д�����ӵļ���Ҹ�Ч

�����ӳ��
����������ַ��������Ҫ��⣺��C++���ַ�������ʵ������ASCII��ֵ�����㣬��Ϊ���
char���͵����ݵı��ʾ������ͣ������ڽ����ַ�������ʱ�ͻ��Զ�����Ϊ���ͱ������������ڷ��صľ���һ�����ε�ֵ
���������str[i] - '1';ʵ�����ǰ��ַ�ת�������֡�
��ô��������±�ͺ������� ������ת����0--9�����֣�Ȼ�����x��ֵ��0,1,2 y��ֵ��0,1,2
�������һ��Ϊʲô������Ҫ����3��������Ҫȡģ3��
��������һ�����Ѿ���1--9��ASCII��ֵת�����˴�0 -- 8 ��������ô���ڶ���Щ����ȡģ3��ֻ��õ�
0 1 2��������
����x���������ǹ̶���0 1 2���Խ�������ʹ��0-2����Ϊ0,3-5Ϊ1,6-8����Ϊ2
��������Ĳ�������������ӳ��


��ô���������ӳ��nά�����̼���ķ�������ͬ�Ķ���
int x = pos / n;
int y = pos % n;
�����Ļ����൱�ڽ�����һ����չ
*/