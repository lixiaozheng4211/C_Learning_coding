#include <bits/stdc++.h>
#include <format>
using namespace std;
string change(int P,int base);
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n ; i++) {
    for (int j = 1; j <= i ; j++) {
      cout << format("{}*{}={}",change(n,i),change(n,j),change(n,i*j)) << ' ';
    }
    cout << endl;
  }
}
string change(int P, int base) {
  string str;
  while (base) {
    int mod = base % P;
    str += (mod < 10 ? mod + '0' : mod - 10 + 'A');
    base /= P;
  }
  reverse(str.begin(), str.end());
  return str;
}

/*
好的下面就到了总结的时间：
首先是这个进制转换的问题，我们把进制装换拓展一下到n进制
#include <bits/stdc++.h>
using namespace std;
string toBase(int number, int P);
int main()
{
  int number, P;
  cin >> number >> P;
  cout << toBase(number, P);
}
string toBase(int number, int P)
{
  string str;
  while (number)
  {
    int mod = number % P;
    str += (mod < 10 ? mod + '0' : mod - 10 + 'A') ;
    number /= P;
  }
  reverse(str.begin(), str.end());
  return str;
}

那么下次的时候就可直接用这个模板，看情况来定，就是 看看这行要输入的数
据有没有更改
*/