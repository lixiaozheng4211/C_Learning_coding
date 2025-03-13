#include <bits/stdc++.h>
using namespace std;
void getScore(string game, int n);
int main() {
  string str,game;
  while (cin >> str) {
    game += str;
  }
  getScore(game, 11);
  cout << endl;
  getScore(game, 21);
}
void getScore(string game, int n) {
  int win = 0, lose = 0;
  for (auto &c:game) {
    if ( c== 'E') {
      cout << win << ':' << lose << endl;
      return;
    }
    else if (c == 'W') {
      win++;
    }
    else {
      lose++;
    }
    if (abs(win - lose) >= 2 && (win >= n || lose >= n))
    {
      cout << win << ':' << lose << endl;
      win = lose = 0;
    }
  }
}
/*
2025年3月12日17:37:19
好的下面又是开心的总结时间：
首先这个题目的的规则就不好读懂，就是这个比赛的规则就是选手必须要先打到规定的分数就是
11或者21，那么现在达到了11或者21就需要拉开两分的分差来终结比赛
这个提的题目读懂了之后就会发现这个题还是挺简单的，那么现在的核心问题是如何统计出
这个个数的，上面的代码的实现是直接全部都读取
string str,game;
while(cin >> str) {
  game += str;
}
这样的话就可以将数据全部读入然后进行处理，接下来的重点就是函数的设计，直接用范围循环
来实现对数据的读取只要读取到的数据是E那么就直接输出结果并返回，或者是两个人的分差来到两分并且两人之中的一人达到了规定的11分或者是21分，就可以直接返回结果了
考察的点就是读题还有对字符串的处理
*/