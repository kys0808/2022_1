#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> mp;
    map<string, set<string>> a_repot;

    for (auto a : report) {
        stringstream ss(a);
        string repot;
        string repoted;
        ss >> repot;
        ss >> repoted;
        a_repot[repot].insert(repoted);
    }

    for (auto a : id_list) {
        for (auto b : a_repot[a]) {
            mp[b]++;
        }
    }
    for (auto a : id_list) {
        int count = 0;
        for (auto b : a_repot[a]) {
            if (mp[b] >= k) {
                count++;
            }
        }
        answer.push_back(count);
    }
    return answer;
}