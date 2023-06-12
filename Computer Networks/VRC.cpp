# include<bits/stdc++.h>
using namespace std;
char getparity(string code)
{
    char parity;
    int pn=0;
    int n=code.length(); 
    for(int i=0;i<n;i++)
    {
        if(code[i]=='1')
        {
            pn+=1;
        }
    }
    if(pn%2==0)
    {
        parity='0';
    }
    else
    {
        parity='1';
    }
    return parity;
}

bool checker(string data,string recv)
{
    string sentcode=data+getparity(data);
    cout<<"\nSent codeword is:"<<sentcode;
    if(getparity(recv)=='0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string data;  
    string recv_message; 
    cout<<"Enter data to be sent:";
    cin>>data;
    string code=data+getparity(data);
    cout<<"The code word is:"<<code;
    cout<<"\nEnter message received:";
    cin>>recv_message;
    cout<<data.length();
    if (checker(data,recv_message)) 
    {
        cout << "\nNo Error";
    }
    else {
        cout << "\nError";
    }
    return 0;
}
