#include <iostream>
#include <vector>

using namespace std;

string triplet_to_word(int triplet)
{
    string word[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tens_word[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"};
    string special_word[] = {"", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
    string res;
    res = triplet / 100 ? word[triplet / 100] + " hundred" : "";
    triplet %= 100;
    if(triplet < 20 && triplet > 10)
    {
        res += special_word[triplet % 10];
    }
    else
    {
        res += triplet / 10 ? " " + tens_word[triplet / 10] : "";
        triplet %= 10;
        res += triplet ? " " + word[triplet] : "";
    }
    
    return res;
}

string num_to_word(int n)
{
    vector <int>triplets;
    string res;
    string places[] = {"", "thousand", "million", "billion", "trillion"};
    int n_ = n;
    while(n_)
    {
        triplets.push_back(n_ % 1000);
        n_ /= 1000;
    }

    for(int i = 0; i < triplets.size(); i++)
    {
        res = triplet_to_word(triplets[i]) + " " + places[i] + " " + res;
    }

    return res;
}

int main()
{
    int n, n_;
    cin >> n;
    cout << num_to_word(n) << endl;
}