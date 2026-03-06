#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) 
    {
        int k;
        cin >> k; 
        a[i].resize(k); 
        for (int j = 0; j < k; j++) 
        {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < q; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;
    }

    return 0;
}
