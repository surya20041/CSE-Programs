#include <bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
    string result = "";

    int n = b.length();

    for (int i = 1; i < n; i++) 
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string mod2div(string dividend, string divisor)
{
    int pick = divisor.length();

    string tmp = dividend.substr(0, pick);

    int n = dividend.length();

    while (pick < n) 
    {
        if (tmp[0] == '1')
            tmp = xor1(divisor, tmp) + dividend[pick];
        else
            tmp = xor1(string(pick, '0'), tmp)+ dividend[pick];

        pick += 1;
    }
    //for last n bits
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(string(pick, '0'), tmp);

    return tmp;
}

void encodeData(string data, string key)
{
    int l_key = key.length();

    // Appends n-1 zeroes at end of data
    string appended_data
        = (data + string(l_key - 1, '0'));

    string remainder = mod2div(appended_data, key);

    // Append remainder in the original data
    string codeword = data + remainder;
    cout << "Remainder : " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :" << codeword
        << "\n";
}

// Function used at the receiver side to decode
void check(string recv, string key)
{
    string tmp=mod2div(recv,key);
    if(tmp==string(tmp.length(),'0'))
    {
        cout<<"Correct message received"<<endl;
    }
    else
    {
        cout<<"Wrong message received"<<endl;
    }
}
int main()
{
    string data;
    string key;
    cout<<"Enter data:";
    cin>>data;
    cout<<"Enter key:";
    cin>>key;
    cout << "Sender side..." << endl;
    encodeData(data, key);

    cout << "\nReceiver side..." << endl;
    string recv;
    cout<<"Enter receiver data:";
    cin>>recv;

    check(recv,key);
    return 0;
}
