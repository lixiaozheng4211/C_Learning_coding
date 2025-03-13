#include <bits/stdc++.h>
using namespace std;
double fun(double x , int n);
int main() {
  double x;
  int n;
  cin >> x >> n;
  cout << format("{:.2f}",fun(x, n));
}
double fun (double x, int n) {
  if (n == 1) return x / (x  + 1);
  return x / ( n  + fun(x, n - 1));
}
/*
特别注意这里的题目条件是第一个数是x是实数，n是整数
那么在这里x要被定义为double ，n被定义为整型
*/