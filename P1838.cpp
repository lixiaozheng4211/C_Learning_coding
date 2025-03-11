/*
2025年3月11日23:40:59;
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
    int x = pos / 3, y = pos % 3; // 这是很常见的坐标转化方式要注意的点就是下标的开始时0
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
下面就是我从上面的代码中学到的东西

首先就是这个容器的声明这是之前没有用到的，还有就是这个坐标的映射，非常的巧妙

容器的声明：
这个是C++17的新特性就是可以直接推导变量的类型
这里的代码是：auto board = vector(3, vector (3,-1));
这样的写法等价于：vector<vector <int>> board = vector(3, vector (3,-1));
但是上面的写法更加的简洁且高效

坐标的映射
首先这里的字符运算就需要理解：在C++中字符的运算实质上是ASCII码值的运算，因为这个
char类型的数据的本质就是整型，所以在进行字符的运算时就会自动升级为整型变量，所以现在返回的就是一个整形的值
所以上面的str[i] - '1';实质上是把字符转换成数字。
那么现在理解下标就很容易了 首先是转换到0--9的数字，然后就是x的值是0,1,2 y的值是0,1,2
下面解释一下为什么横坐标要除以3，纵坐标要取模3：
首先在上一步中已经将1--9的ASCII码值转换成了从0 -- 8 的数字那么现在对这些数字取模3就只会得到
0 1 2这三个数
由于x的坐标是是固定的0 1 2所以进行整除使得0-2的数为0,3-5为1,6-8的数为2
所以上面的操作完成了坐标的映射


那么上面的坐标映射n维的棋盘计算的方面是相同的都是
int x = pos / n;
int y = pos % n;
这样的话就相当于进行了一个拓展
*/