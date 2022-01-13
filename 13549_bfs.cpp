#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n; int k;
int t;
int visit[100001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> k;
	// pq �������� ���� -- first�� �ð����� �ΰ� 2��¥���� �ð���� �����ϱ� ���� �켱������ ������
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	t = 0;
	q.push({ t,n });
	visit[n] = 1;
	while (!q.empty()) {
		//bfs 
		int c_t = q.top().first;
		int c_n = q.top().second;
		if (c_n == k) {
			cout << c_t << '\n';
			return 0;
		}
		q.pop();
		// 2��
		if (c_n * 2 < 100001 && c_n > 0) {
			if (!visit[c_n * 2]) {
				visit[c_n * 2] = 1;
				q.push({ c_t,c_n * 2 });
			}
		}
		// +1
		if (c_n + 1 < 100001 && c_n + 1 >= 0) {
			if (!visit[c_n + 1]) {
				visit[c_n + 1] = 1;
				q.push({ c_t + 1,c_n + 1 });
			}
		}

		// -1
		if (c_n - 1 < 100001 && c_n - 1 >= 0) {
			if (!visit[c_n - 1]) {
				visit[c_n - 1] = 1;
				q.push({ c_t + 1,c_n - 1 });
			}
		}
	}

}
