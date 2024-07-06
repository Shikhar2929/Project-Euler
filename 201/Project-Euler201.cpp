#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define vt vector
#define as assign
#define rsz resize
#define ub upper_bound
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pil pair<int, ll>
using namespace std;
const int MAX_SIZE = 300000;
ofstream fout("output.txt");
unsigned long long findSum(int set_size, int subset_size) {
	vector<vector<vector<int>>> dp(subset_size + 1, vt<vt<int>>(MAX_SIZE, vector<int>(set_size + 1, 0)));
	vector<vector<int>> maxVisited(subset_size + 1, vector<int>(set_size + 1, 0));
	for (int i = 0; i <= set_size; i++) {
		dp[0][0][i] = 1;
		maxVisited[0][i] = 0;
	}
	//int max_visited = 0;
	for (int j = 1; j <= subset_size; j++) {
		for (int i = 1; i <= set_size; i++) {
			if (j > i) continue;
			for (int k = 0; k <= maxVisited[j - 1][i - 1]; k++) {
				dp[j][k][i] += dp[j][k][i - 1];
				if (dp[j - 1][k][i - 1]) {
					int square = i * i;
					dp[j][square + k][i] += dp[j - 1][k][i - 1];
					dp[j][square + k][i] = min(dp[j][square + k][i], 2);
					maxVisited[j][i] = max(square + k, maxVisited[j][i]);
				}
			}
			for (int k = maxVisited[j - 1][i - 1] + 1; k <= maxVisited[j][i]; k++) {
				dp[j][k][i] += dp[j][k][i - 1];
				maxVisited[j][i] = max(maxVisited[j][i], dp[j][k][i]);
			}
		}
	}
	ll answer = 0;
	for (int i = 0; i <= maxVisited[subset_size][set_size]; i++) {
		if (dp[subset_size][i][set_size] == 1) {
			answer += i;
			//fout << i << endl;
		}
	}
	return answer;
}



int main()
{
	int temp = findSum(100, 50);
	fout << temp << endl;
	cout << temp << endl;
}
