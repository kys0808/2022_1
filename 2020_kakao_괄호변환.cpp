#include <string>
#include <vector>
#include <iostream>
using namespace std;
string answer = "";

bool check_right(string p) {
    string tmp = "";
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            tmp += '(';
        }
        if (p[i] == ')') {
            if (tmp.empty())
                return false;
            else {
                tmp.pop_back();
            }
        }
    }
    cout << endl;
    return true;
}

string solution(string p) {
    if (p.empty()) {
        return p;
    }
    string u = "";
    string v = "";
    int open_count = 0;
    int close_count = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            open_count++;
        }
        else {
            close_count++;
        }
        if (open_count == close_count && open_count != 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            //cout << u <<" - " << v <<endl;
            string tmp = "";
            if (check_right(u)) {
                //cout << u <<endl;
                return (u + solution(v));
            }
            else {
                tmp += '(';
                tmp += solution(v);
                tmp += ')';
                string tmp_u = u.substr(1);
                tmp_u.pop_back();
                for (int k = 0; k < tmp_u.size(); k++) {
                    if (tmp_u[k] == '(') {
                        tmp_u[k] = ')';
                    }
                    else {
                        tmp_u[k] = '(';
                    }
                }
                return tmp + tmp_u;
            }
        }
    }

    return answer;
}