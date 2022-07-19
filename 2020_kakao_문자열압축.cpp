#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 100001;

int solution(string s) {
    if (s.length() == 1) return 1;
    for (int i = 1; i <= s.size() / 2; i++) {
        int start = 0;
        int cmp_start = start + i;
        int count = 1;
        string tmp_s = "";
        while (cmp_start < s.size()) {
            string first_s = "";
            string second_s = "";
            first_s = s.substr(start, i);
            second_s = s.substr(cmp_start, i);
            //cout << first_s <<" "<<second_s <<endl;
            if (first_s == second_s) {
                count++;
                cmp_start += i;
            }
            else {
                //정산 하고
                if (count >= 2) {
                    tmp_s += to_string(count) + first_s;
                    count = 1;
                }
                else {
                    tmp_s += first_s;
                }
                start = cmp_start;
                cmp_start = start + i;
                //댜음 검사 (끝에 다 왔는지 -- 잔여분 부족 하면 다 채우기)
            }
        }
        if (cmp_start >= s.size() - 1) {
            if (count == 1) {
                tmp_s += s.substr(start);
            }
            else {
                tmp_s += to_string(count) + s.substr(start, i);
            }
        }
        //cout <<tmp_s<<endl;
        if (answer > tmp_s.length()) {
            answer = tmp_s.length();
        }
    }
    return answer;
}