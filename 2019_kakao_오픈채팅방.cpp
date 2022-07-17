#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

map<string, string> mp;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    string order;
    string uid;
    string nick;
    for (string input : record) {
        stringstream ss(input);
        ss >> order;
        ss >> uid;
        if (order != "Leave") {
            ss >> nick;
            mp[uid] = nick;
        }
    }
    for (string input : record) {
        stringstream ss(input);
        ss >> order;
        ss >> uid;
        if (order == "Enter") {
            string tmp;
            tmp = mp[uid] + "���� ���Խ��ϴ�.";
            answer.push_back(tmp);
        }
        if (order == "Leave") {
            string tmp;
            tmp = mp[uid] + "���� �������ϴ�.";
            answer.push_back(tmp);
        }
    }
    return answer;
}