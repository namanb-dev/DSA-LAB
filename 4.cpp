#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- (a) Concatenate two strings ---
void concatenateStrings() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin.ignore();
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    str1.append(str2);
    
    cout << "Concatenated string: " << str1 << endl;
}

// --- (b) Reverse a string ---
void reverseString() {
    string str;
    cout << "Enter a string to reverse: ";
    cin.ignore();
    getline(cin, str);
    
    string reversed_str = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed_str += str[i];
    }
    
    cout << "Reversed string: " << reversed_str << endl;
}

// --- (c) Delete all vowels from the string ---
void deleteVowels() {
    string str;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);
    
    string result = "";
    string vowels = "aeiouAEIOU";
    
    for (char c : str) {
        bool is_vowel = false;
        for (char vowel : vowels) {
            if (c == vowel) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            result += c;
        }
    }
    
    cout << "String without vowels: " << result << endl;
}

// --- (d) Sort strings in alphabetical order ---
void sortStrings() {
    int n;
    cout << "How many strings do you want to sort? ";
    cin >> n;
    
    vector<string> strings(n);
    cout << "Enter " << n << " strings:" << endl;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "String " << i + 1 << ": ";
        getline(cin, strings[i]);
    }
    
    // Manual bubble sort implementation
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strings[j] > strings[j + 1]) {
                string temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
    
    cout << "Sorted strings:" << endl;
    for (const auto& s : strings) {
        cout << s << endl;
    }
}

// --- (e) Convert a character from uppercase to lowercase ---
void convertToLowercase() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    
    char lower_ch = ch;
    if (ch >= 'A' && ch <= 'Z') {
        lower_ch = ch + 32; // ASCII conversion: 'a' - 'A' = 32
    }
    
    cout << "The lowercase character is: " << lower_ch << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---" << endl;
        cout << "1. Concatenate strings" << endl;
        cout << "2. Reverse a string" << endl;
        cout << "3. Delete all vowels" << endl;
        cout << "4. Sort strings alphabetically" << endl;
        cout << "5. Convert to lowercase" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                deleteVowels();
                break;
            case 4:
                sortStrings();
                break;
            case 5:
                convertToLowercase();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}