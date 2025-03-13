#include <bits/stdc++.h>
using namespace std;
void dfs(auto & matrix,int x,int y ,int size);
int main( ){
  int n;
  cin >> n;
  int length = pow(2,n);
  auto board = vector(length ,vector(length,1));
  dfs(board,0 , 0 ,length);  
  for (auto & line : board) {
    for (auto & y : line) {
      cout << y << "  ";
    }
    cout << endl;
  }
}

void dfs(auto&matrix,int x, int y, int size) {
  if (size == 1) return;
  int half = size / 2 ;
  //�ȱ������ϽǵĲ���
  for (int i = x ; i < x +half ; i++) {
    for (int j = y ; j < y + half ; j++) {
      matrix[i][j] = 0;
    }
  }
  //�ٱ���������������
  dfs(matrix , x, y + half ,half);
  dfs(matrix , x + half , y , half);
  dfs(matrix ,x + half , y + half ,half);
}


/*

*/