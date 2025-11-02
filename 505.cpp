#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 105;
const int M = 10;

int n, m, k;
struct Student{
    int scores[M];
    int id;
}students[N];
bool cmp1(const Student &a, const Student &b){
    return a.scores[k] > b.scores[k];
}
bool cmp2(const Student &a, const Student &b){
    return a.id < b.id;
}
int main(){
    cin >> n >> m >> k;
    int total_score = 0;
    for(int i = 1; i <= n; i++){
        cin >> students[i].id;
        for(int j = 1; j <= m; j++){
            cin >> students[i].scores[j];
        }
        total_score += students[i].scores[k];
    }
    stable_sort(students + 1, students + n + 1, cmp2);
    stable_sort(students + 1, students + n + 1, cmp1);
    int index = (n + 1) / 2;
    int median = students[index].scores[k];
    double average = (double)total_score / n;
    printf("%.1f %d\n", average, median);
    while(index >1 and students[index-1].scores[k] == median){
        index--;
    }
    while(index <= n and students[index].scores[k] == median){
        cout << students[index].id << " ";
        for(int j = 1; j <= m; j++){
            cout << students[index].scores[j] << (j == m ? '\n' : ' ');
        }
        index++;
    }
    return 0;
}
