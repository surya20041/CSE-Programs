#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cout<<"Enter number of frames:";
    cin>>r;
    cout<<"Enter number of bits in a frame:";
    cin>>c;
    char b[6][15];
    for (int i=0;i<r;i++)
    {
        cout<<"Enter frame "<<i+1<<":";
        cin>>b[i];
    }
    char parity[c];
    cout<<"Data frames are:\n";
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout<<b[i][j];
        }
        cout<<"\n";
    }
    
    for(int j=0;j<c;j++)
    {
        int p=0;
        for(int i=0;i<r;i++)
        {
            if(b[i][j]=='1')
            {
                p=p^1;
            }
        }
        parity[j]=p+'0';   
    }
    for (int j=0;j<c;j++)
    {
        b[r][j]=parity[j];
    }
    // CREATING REDUNDANT FRAME
    cout<<"Sent code words are:\n";
    for (int i=0;i<=r;i++)
    {
        for (int j=0;j<=c;j++)
        {
            cout<<b[i][j];
        }
        cout<<"\n";
    }
    
    cout<<"Enter received frames\n";
    char cb[6][15];
    for (int i=0;i<=r;i++)
    {
        cout<<"Enter frame "<<i+1<<":";
        cin>>cb[i];
    }
    int flag=0;
    for(int j=0;j<=c;j++)
    {
        int p=0;
        for(int i=0;i<=r;i++)
        {
            if(cb[i][j]=='1')
            {
                p=p^1;
            }
        }
        parity[j]=p+'0';   
    }
    for (int j=0;j<c;j++)
    {
        if(parity[j]=='1')
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"\nThere is error in received data.";
    }
    else
    {
        cout<<"\nThere is no error in received data.";
    }
    return 0;
}
