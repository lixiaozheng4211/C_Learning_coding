#include <bits/stdc++.h>
using namespace std;
int Judge(char player, char Sven);
int main()
{
  string spr = "SPR";
  int turn_number;
  cin >> turn_number;
  string Sven ;
  cin >> Sven;
  int friend_number;
  cin >> friend_number;
  vector<string> players(friend_number);
  for(auto &x: players) cin >> x;
  int normal = 0, score_max = 0;
  for (int i  = 0 ; i < turn_number ;  i++ ){
    vector<int>guetrue(3);
    for (auto &player : players){//上面是范围循环
      normal += Judge(Sven[i],player[i]);
      for (int j = 0 ;  j < 3 ; j++) {
        guetrue[j] += Judge(spr[j],player[i]);
      }
    }
    score_max += max(guetrue[0],max(guetrue[1],guetrue[2]));
  }
  cout << normal << endl << score_max;
}
int Judge(char a, char b) {
  if (a == b) return 1;
  if (a == 'S' && b == 'P') return 2;
  if (a == 'P' && b == 'R') return 2;
  if (a == 'R' && b == 'S') return 2;
  return 0;
}
/*
其中的m是turn_number
mine是Sven
n是friend_number
*/