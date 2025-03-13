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
  auto board = vector(3, vector(3, -1)); // 初始化棋盘
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
  //现在要重新开一个容器俩表示使用过的奶牛
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
好的下面就是我在这段代码中学习到的东西，首先就是指针这部分，在初始化的过程中可以把指针直接赋值成0，这表示的是空指针
还有就是指针的正确用法，先是要定义变量然后就是用指针练操作这个变量，其实这里指针就相当于一个变量的别名
            int n = 0;
            int * p = &n;
而不是下面的这种写法
            int * p = 0;
这样的话就是将这个指针变成空指针
还有就是对于引用的理解首先明白引用是一个语法糖，它的主要作用就是定义一个只能指向一个变量的指针，那么之后的操作这个
指针就只能操作者一个变量，相当于const;
然后就是一些定义函数时的小技巧，首先如果函数中有大量的if else的语句，那么在每一条的if-else 语句后面都要跟上return
要不然就会编译器警告，还有一个办法就是将这个函数再开始的时候就设置成void类型，这样的话就不会有返回类型出错的问题
今天的重要的语句是acwing里的排序过后就删除多余元素的语句
    str.erase(unique(str.begin(),str.end()),str.end());
这条语句重新更新了容器，在离散化中存在优势

*/