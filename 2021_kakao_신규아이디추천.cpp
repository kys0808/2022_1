#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = new_id[i] + ('a' - 'A');
        }
    }
    cout << new_id << endl;

    // 2단계
    string res;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z')
            res += new_id[i];
        if (new_id[i] >= '0' && new_id[i] <= '9')
            res += new_id[i];
        if (new_id[i] == '-' || new_id[i] == '_')
            res += new_id[i];
        if (new_id[i] == '.')
            res += new_id[i];
    }
    new_id = res;
    res.clear();
    cout << new_id << endl;

    //3단계
    int start = 0;
    int deli = 0;

    for (deli; deli < new_id.size(); deli++) {
        if (new_id[deli] == '.') {
            int start = deli;
            while (new_id[start] == '.') {
                start++;
            }
            deli = start - 1;
            res += '.';
        }
        else {
            res += new_id[deli];
        }
    }
    new_id = res;
    res.clear();
    cout << new_id << endl;

    // 4단계
    if (new_id[new_id.size() - 1] == '.') {
        new_id.pop_back();
    }
    if (new_id[0] == '.') {
        res = new_id.substr(1, new_id.size() - 1);
        new_id = res;
        res.clear();
    }
    cout << new_id << endl;

    // 5단계
    if (new_id.size() == 0) {
        new_id += 'a';
    }

    //6단계
    if (new_id.size() >= 16) {
        res = new_id.substr(0, 15);
        if (res[res.size() - 1] == '.') {
            res.pop_back();
        }
        new_id = res;
        res.clear();
    }
    cout << new_id << endl;
    //7단계
    if (new_id.size() <= 2) {
        while (new_id.size() < 3) {
            new_id += new_id[new_id.size() - 1];
        }
    }
    answer = new_id;
    return answer;
}