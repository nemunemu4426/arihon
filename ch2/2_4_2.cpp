// 二分探索木 (set, map の練習)
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    set<int>::iterator ite1;
    ite1 = s.find(1);
    if (ite1 == s.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    ite1 = s.find(2);
    if (ite1 == s.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    s.erase(3);
    if (s.count(3) != 0) cout << "found" << endl;
    else cout << "not found" << endl;
    for (ite1 = s.begin(); ite1 != s.end(); ++ite1) {
        cout << *ite1 << endl;
    }

    map<int, const char*> m;
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";
    map<int, const char*>::iterator ite2;
    ite2 = m.find(1);
    cout << ite2->second << endl;
    ite2 = m.find(2);
    if (ite2 == m.end()) cout << "not found" << endl;
    else cout << ite2->second << endl;
    cout << m[10] << endl;
    m.erase(10);
    for (ite2 = m.begin(); ite2 != m.end(); ++ite2) {
        cout << ite2->first << " " << ite2->second << endl;
    }
}