#include <bits/stdc++.h>

using namespace std;

vector<int> pascalsTriangle(int n){
    vector<int> v = {1};
    if (n == 1)
        return v;
    v = pascalsTriangle(n - 1);
    vector<int> v1(n,1);
    for (int i = 0; i < n - 1; i++)
        v1[i + 1] = v[i + 1] + v[i];
    v1[n - 1] = 1;
    return v1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v = pascalsTriangle(n);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << v[i] * v[j] << " ";
        }
        cout << "\n";
    }
}