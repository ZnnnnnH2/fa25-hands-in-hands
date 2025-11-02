#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 105;

int order[255];

string s[N];
int n;
int len;
int main(){
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < 4;i++){
        order[str[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    len = s[0].size();
    sort(s, s + n, [](const string &a, const string &b){
        for(int i = 0; i < len; i++){
            if(order[a[i]] != order[b[i]]){
                return order[a[i]] < order[b[i]];
            }
        }
        return false;
    });
    for(int i = 0; i < n; i++){
        cout << s[i] << "\n";
    }
}