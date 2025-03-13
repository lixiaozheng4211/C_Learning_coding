#include <bits/stdc++.h>
using namespace std;
int Ackermann(int m, int n);
int main() {
  int m,n;
  cin >> m >> n;
  int answer = Ackermann(m , n);
  cout << answer << endl;
  return 0;
}
int Ackermann(int m, int n) {
  if (m == 0) return n + 1;
  if (m > 0 && n == 0 ) return Ackermann(m - 1 , 1);
  if (m > 0  && n > 0) return Ackermann(m - 1, Ackermann(m , n - 1));
  if (m < 0 || n < 0) return 0;
}