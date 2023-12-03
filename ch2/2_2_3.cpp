// Best Cow Line (POJ No.3617)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T = "";
    int left = 0, right = N - 1;
    while (left <= right) {
        if (S[left] < S[right]) {
            T += S[left++];
        } else {
            T += S[right--];
        }
    }
    cout << T << endl;
}