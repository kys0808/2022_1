#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

map<string, int> mp;    // string 이 몇번 나왔는가
int check[21];
set<string> ss;

void back(string s, int target, string input, int start) {
    if (target == input.size()) {
        mp[input]++;
        check[target] = max(check[target], mp[input]);
        //cout <<input << " "<<mp[input] <<" "<<check[target]<<endl;
        ss.insert(input);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        input += s[i];
        back(s, target, input, i + 1);
        input.pop_back();
    }

}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            sort(orders[j].begin(), orders[j].end());
            back(orders[j], course[i], "", 0);
        }
    }
    for (int i = 0; i < course.size(); i++) {
        for (auto a : ss) {
            if (mp[a] == check[course[i]] && mp[a] >= 2) {
                if (a.size() == course[i]) {
                    //cout <<a <<" " << mp[a]<<" "<<check[course[i]]<<endl;
                    answer.push_back(a);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}