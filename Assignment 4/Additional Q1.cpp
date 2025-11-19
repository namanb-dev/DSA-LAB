// Given a function n, write a function that generates and prints all binary numbers with decimal
// values from 1 to n.
// Input: n = 2
// Output: 1, 10

#include <iostream>
using namespace std;

class BinaryGen {
public:
    static void printBinary(int n) {
        for (int i = 1; i <= n; i++) {
            int x = i;
            string s = "";
            for (; x > 0; x /= 2)
                s = char('0' + (x % 2)) + s;
            cout << s << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;
    BinaryGen::printBinary(n);
    return 0;
}
