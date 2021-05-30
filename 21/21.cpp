#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <queue>

using namespace std;

int x;
int len = 6;
int result[6] = { 1000,1000,1000,1000,1000,1000 };
bool flag[6] = { false,false,false,false,false,false };

vector <vector<int>> matrix =
{ {0, 11, 0, 14, 0, 0 },
{0, 0, 13, 0, 0, 0 },
{0, 0, 0, 24, 0, 0 },
{0, 0, 0, 0, 5, 0},
{0, 0, 17, 0, 0, 6 },
{1, 0, 0, 0, 0, 0 } };

bool comp(int a, int b)
{
    return matrix[x][a] < matrix[x][b];
}
int main()
{
    setlocale(LC_ALL, "rus");

    queue <int> queue_;
    cout << "¬ведите начальную вершину (1<=x<=" << len << ")\n";
    cin >> x;
    x--;
    result[x] = 0;
    queue_.push(x);
    while (true)
    {
        x = queue_.front();
        vector <int> vec;
        for (int i = 0; i < len; i++) if (matrix[x][i] != 0 && !flag[i]) vec.push_back(i);
        if (vec.size() == 0)
        {
            flag[x] = true;
            queue_.pop();
            if (queue_.size() == 0) break;
            continue;
        }
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < vec.size(); i++)
        {
            result[vec[i]] = min(result[vec[i]], matrix[x][vec[i]] + result[x]);
            queue_.push(vec[i]);
        }
        flag[x] = true;
        queue_.pop();
        if (queue_.size() == 0) break;
    }
    cout << " кратчайшие пути:\n";

    for (int i = 0; i < len; i++)
    {
        if (result[i] == 1000) cout << i + 1 << " error\n";
        else cout << i + 1 << " - " << result[i] << endl;
    }
    system("pause");
}
