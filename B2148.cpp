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
�ر�ע���������Ŀ�����ǵ�һ������x��ʵ����n������
��ô������xҪ������Ϊdouble ��n������Ϊ����
*/