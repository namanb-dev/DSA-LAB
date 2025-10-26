// String Related Programs
// (a) Write a program to concatenate one string to another string.
// (b) Write a program to reverse a string.
// (c) Write a program to delete all the vowels from the string.
// (d) Write a program to sort the strings in alphabetical order.
// (e) Write a program to convert a character from uppercase to lowercase.

#include <iostream>
using namespace std;

string Concatenting(string name, string surname)
{
    string Fullname = name + " " + surname;
    return Fullname;
}

int Reversing(string Fullname)
{
    int i, j, size = Fullname.length(), temp;
    for (i = 0; i < size / 2; i++)
    {
        temp = Fullname[i];
        Fullname[i] = Fullname[size - i - 1];
        Fullname[size - i - 1] = temp;
    }
    cout << "Reverse: " << Fullname << "\n";

    return size;
}

void Removing_vowels(string Fullname, int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        if(Fullname[i] == 'a' || Fullname[i] == 'e' || Fullname[i] == 'i' || Fullname[i] == 'o' || Fullname[i] == 'u')
        {
            for(j=i; j<size; j++)
            {
                Fullname[j] = Fullname[j+1];
            }
        }
    }

    cout<<"Without any vowel: "<<Fullname<<endl;
}

// alphabatically sorting only smaller case alphabats
void Alphabatical_sorting(string Fullname, int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(Fullname[i] > Fullname[j])
            {
                char temp = Fullname[i];
                Fullname[i] = Fullname[j];
                Fullname[j] = temp;
            }
        }
    }

    cout<<"after alphabatically sorted: "<<Fullname;
}

void converting_lower_to_upercase(string Fullname, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        
    }
}


int main()
{
    string name, surname;
    cout << "Frontname: ";
    getline(cin, name);
    cout << "Surname: ";
    getline(cin, surname);
    
    cout<<endl;

    // (a) concatenating one string to another string
    string Fullname = Concatenting(name, surname);
    cout << "Full name: " << Fullname << endl;

    cout << endl;

    // (b) reversing the string
    int size = Reversing(Fullname);
    
    cout << endl;

    // (c) deleting all the vowels from the string
    Removing_vowels(Fullname, size);

    cout<<endl; 

    // (d) sorting the strings in alphabetical order.
    Alphabatical_sorting(Fullname, size);

    // (e) converting a character from uppercase to lowercase.


    return 0;
}
