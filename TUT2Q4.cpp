//4(a)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    cout << "Concatenated: " << s1 + s2;
    return 0;
}

//4(b)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s = "OpenAI";
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s;
    return 0;
}

//4(c)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";
    string result = "";
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            result += c;
    }
    cout << "Without vowels: " << result;
    return 0;
}

//4(d)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> arr = {"banana", "apple", "cherry", "date"};
    sort(arr.begin(), arr.end());
    cout << "Sorted strings: ";
    for (string s : arr) cout << s << " ";
    return 0;
}

//4(e)
#include <iostream>
using namespace std;

int main() {
    char c = 'H';
    if (c >= 'A' && c <= 'Z') c = c + 32;
    cout << "Lowercase: " << c;
    return 0;
}
