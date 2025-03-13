#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int Judge_uesd(int a, int b, int c, vector<string> &str);
int Judge_alone(int a, int b, int c, vector<string> &str);
int Judge_double(int a, int b, int c, vector<string> &str);
void isWin(vector<vector<int>> &board, int *alone_win, int *double_win, vector<string> &str);
int Judge(int a, int b, int c);
int main()
{
  int *alone_win, *double_win;
  int x = 0, y = 0;
  alone_win = &x, double_win = &y;
  int n = 3;
  string str;
  auto board = vector(3, vector(3, -1)); // ��ʼ������
  while (n--)
  {
    string input_char;
    cin >> input_char;
    str += input_char;
  }
  for (int i = 0; i < 9; i++)
  {
    int x = i / 3, y = i % 3;
    board[x][y] = str[i] - 'A';
  }
  //����Ҫ���¿�һ����������ʾʹ�ù�����ţ
  vector<string> used_cows;
  isWin(board, alone_win, double_win,used_cows);
  cout << x << '\n'
       << y << endl;
}
void isWin(vector<vector<int>> &board, int *alone_win, int *double_win , vector<string> &str)
{
  for (int i = 0; i < 3; i++) {
    *alone_win += Judge_alone(board[i][0], board[i][1], board[i][2],str);
    *alone_win += Judge_alone(board[0][i], board[1][i], board[2][i], str);
    *double_win += Judge_double(board[i][0], board[i][1], board[i][2], str);
    *double_win += Judge_double(board[0][i], board[1][i], board[2][i], str);
  }
  *alone_win += Judge_alone(board[0][0], board[1][1], board[2][2], str);
  *alone_win += Judge_alone(board[0][2], board[1][1], board[2][0], str);
  *double_win += Judge_double(board[0][0], board[1][1], board[2][2], str);
  *double_win += Judge_double(board[0][2], board[1][1], board[2][0], str);
}

int Judge_alone(int a, int b, int c,vector<string> &str)
{
  if (a == b && b == c ) {
    if (!Judge_uesd(a, b, c, str))
      return 0;
    return 1;
  }
  else
    return 0;
}
int Judge_double(int a, int b, int c, vector<string> &str)
{
  if ((a == b && a != c) || (a == c && a != b) || (c == b && a != c)) {
    if (!Judge_uesd(a, b, c, str))
      return 0;
    return 1;
  }
  else
    return 0;
}
int Judge_uesd(int a, int b, int c, vector<string> &str)
{
  vector<int> numbers;
  numbers.push_back(a);
  numbers.push_back(b);
  numbers.push_back(c);
  sort(numbers.begin(),numbers.end());
  string str1;
  for (int i = 0; i < 3; i++)
  {
    char n = numbers[i] + 'A';
    str1 += n;
  }
  str1.erase(unique(str1.begin(), str1.end()), str1.end());
  for (auto &x:str) {
    if (x == str1){
      return 0;
    }
  }
  str.push_back(str1);
  return 1;
}

/*
�õ��������������δ�����ѧϰ���Ķ��������Ⱦ���ָ���ⲿ�֣��ڳ�ʼ���Ĺ����п��԰�ָ��ֱ�Ӹ�ֵ��0�����ʾ���ǿ�ָ��
���о���ָ�����ȷ�÷�������Ҫ�������Ȼ�������ָ�������������������ʵ����ָ����൱��һ�������ı���
            int n = 0;
            int * p = &n;
���������������д��
            int * p = 0;
�����Ļ����ǽ����ָ���ɿ�ָ��
���о��Ƕ������õ������������������һ���﷨�ǣ�������Ҫ���þ��Ƕ���һ��ֻ��ָ��һ��������ָ�룬��ô֮��Ĳ������
ָ���ֻ�ܲ�����һ���������൱��const;
Ȼ�����һЩ���庯��ʱ��С���ɣ���������������д�����if else����䣬��ô��ÿһ����if-else �����涼Ҫ����return
Ҫ��Ȼ�ͻ���������棬����һ���취���ǽ���������ٿ�ʼ��ʱ������ó�void���ͣ������Ļ��Ͳ����з������ͳ��������
�������Ҫ�������acwing�����������ɾ������Ԫ�ص����
    str.erase(unique(str.begin(),str.end()),str.end());
����������¸���������������ɢ���д�������

*/