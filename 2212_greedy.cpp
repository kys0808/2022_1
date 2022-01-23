#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n;
int k;

int main() {
	cin >> n >> k;
	// n�� �� k�� ���߱�
	// ���� ���� : n-1 �� �� (n-k)�� ����(�Ÿ� ������)

	vector<int> v;	// �� ���� ����
	vector<int> sub;	// �� ���� ���� �Ÿ�
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		//cout << v[i] << " ";
//		cout << v[i + 1] - v[i] << " ";
		sub.push_back(v[i + 1] - v[i]);
	}
	//	cout << endl;
	sort(sub.begin(), sub.end());	// ���� ���̰Ÿ� ����
	int cnt = 0;
	int ans = 0;
	if (n <= k) {
		cout << ans;
	}
	else {
		for (int i = 0; i < n - k; i++) {
			ans += sub[i];
		}
		cout << ans << '\n';
	}

}