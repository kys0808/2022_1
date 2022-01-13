#include <iostream>
#include <queue>
using namespace std;


int n;
int dist[126][126];		// cost ����
int st[126][126];		// �� ����

int d_i[4] = { 0,0,1,-1 };	// 4���� i
int d_j[4] = { 1,-1,0,0 };	// 4���� j

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;	//first - cost, second - ��ǥ
	pq.push({ -st[0][0],{0,0}});	// ������
	dist[0][0] = st[0][0];

	while (!pq.empty()) {
		int c_cost = -1* pq.top().first;
		int c_i = pq.top().second.first;
		int c_j = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int n_i = c_i + d_i[i];
			int n_j = c_j + d_j[i];
			if (dist[n_i][n_j] > c_cost + st[n_i][n_j]) {	// ���� ���� cost ���� �������� �湮������ Cost�� �� ũ�ٸ� pq ���(�ִ� ���)
				dist[n_i][n_j] = c_cost + st[n_i][n_j];
				pq.push({ -1*dist[n_i][n_j],{n_i,n_j} });
			}
		}
	}
}

int main() {
	int cnt = 0;
	while (1) {
		cnt++;
		cin >> n;
		if (n == 0) {	// ���� ����
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				st[i][j] = tmp;		// ���Ϸ��� �� ����
				dist[i][j] = 99999999;	// ���Ϸ��� �� �ʱ�ȭ
			}
		}
		dijkstra();	// ��������� �������� ���ͽ�Ʈ��
		cout << "Problem "<<cnt<<": " << dist[n-1][n-1] << '\n';
	}
}