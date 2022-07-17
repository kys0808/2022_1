#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, char> mp;

int solution(string s) {
    int answer = 0;
    mp["one"] = '1';
    mp["two"] = '2';
    mp["three"] = '3';
    mp["four"] = '4';
    mp["five"] = '5';
    mp["six"] = '6';
    mp["seven"] = '7';
    mp["eight"] = '8';
    mp["nine"] = '9';
    //    mp["zero"] = '0';

    int deli = 0;
    int start = 0;
    string tmp_answer;
    //    string tmp_s;
    for (; deli < s.size(); deli++) {
        if (s[deli] < '0' || s[deli] >'9') {
            string tmp_s = s.substr(start, deli - start);
            tmp_s += s[deli];
            if (mp.find(tmp_s) != mp.end()) { // °ª ´ëÀÀ ‰Î
                tmp_answer.push_back(mp[tmp_s]);
                start = deli + 1;
                tmp_s.clear();
            }
        }
        else {
            tmp_answer.push_back(s[deli]);
            start = deli + 1;
        }
    }
    answer = stoi(tmp_answer);
    return answer;
}