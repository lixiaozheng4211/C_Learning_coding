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
2025��3��12��17:37:19
�õ��������ǿ��ĵ��ܽ�ʱ�䣺
���������Ŀ�ĵĹ���Ͳ��ö�����������������Ĺ������ѡ�ֱ���Ҫ�ȴ򵽹涨�ķ�������
11����21����ô���ڴﵽ��11����21����Ҫ�������ֵķֲ����ս����
��������Ŀ������֮��ͻᷢ������⻹��ͦ�򵥵ģ���ô���ڵĺ������������ͳ�Ƴ�
��������ģ�����Ĵ����ʵ����ֱ��ȫ������ȡ
string str,game;
while(cin >> str) {
  game += str;
}
�����Ļ��Ϳ��Խ�����ȫ������Ȼ����д������������ص���Ǻ�������ƣ�ֱ���÷�Χѭ��
��ʵ�ֶ����ݵĶ�ȡֻҪ��ȡ����������E��ô��ֱ�������������أ������������˵ķֲ��������ֲ�������֮�е�һ�˴ﵽ�˹涨��11�ֻ�����21�֣��Ϳ���ֱ�ӷ��ؽ����
����ĵ���Ƕ��⻹�ж��ַ����Ĵ���
*/