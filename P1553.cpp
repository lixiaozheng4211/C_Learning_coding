#include <bits/stdc++.h>
using namespace std;
void reverse(string str);
int main () {
  string str;
  cin >> str;
  string delimiters = "./";
  for (auto &delimiter:delimiters) {
    if (size_t pos = str.find(delimiter); pos != string::npos) {
      reverse(str.substr(0, pos));
      cout << delimiter;
      reverse(str.substr(pos + 1));
      return 0;
    }
  }
  if (str.back() == '%') {
    str.pop_back();
    reverse(str);
    cout << '%' << endl;
    return 0;
  }
  reverse(str);
  cout << endl;
}
void reverse(string str){
  int left = 0, right = str.size() - 1;
  while(left < right && str[left] == '0')left++;//这样的话两边的都不包含0
  while (left < right && str[right] == '0') right--;
  if(left > right) {
    cout << '0';
    return ;
  }
  for (int i = right ; i >= left ; i--) {
    cout << str[i];
  }
}
