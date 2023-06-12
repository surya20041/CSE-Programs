#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7];
    int c=0;
    cout<<"This works for a message of 4 bits in size.\nEnter message bits one by one:\n";
    cout<<"Enter data to be sent:\n";
    for(int i=0;i<4;i++)
    {
        cin>>arr[i];
    }
    arr[6]=(arr[3]+arr[2]+arr[1])%2;
    arr[5]=(arr[2]+arr[1]+arr[0])%2;
    arr[4]=(arr[3]+arr[2]+arr[0])%2;
    
    cout<<"r2 r1 r0:"<<arr[4]<<arr[5]<<arr[6]<<"\n";
    cout<<"Generated Code: ";
    for(int i=0;i<7;i++)
    {
        cout<<arr[i];
    }

    int arr1[7];
    c=0;
    cout<<"\nEnter Received Code bits:\n";
    for(int i=0;i<7;i++)
    {
        cin>>arr1[i];
    }
    int s2=0,s1=0,s0=0;
    s0=(arr1[6]+arr1[3]+arr1[2]+arr1[1])%2;
    s1=(arr1[5]+arr1[2]+arr1[1]+arr1[0])%2;
    s2=(arr1[4]+arr1[3]+arr1[2]+arr1[0])%2;
    
    cout<<"\nSyndrome:"<<s2<<s1<<s0<<"\n";
    if(s2==0 && s1==0 && s0==0)
    {
        cout<<"No Error";
    }
    else if(s2==0 && s1==0 && s0==1)
    {
        arr1[6]=1-arr1[6];
        cout<<"Error in s0";
    }
    else if(s2==0 && s1==1 && s0==0)
    {
        arr1[5]=1-arr1[5];
        cout<<"Error in s1";
    }
    else if(s2==0 && s1==1 && s0==1)
    {
        arr1[1]=1-arr1[1];
        cout<<"Error in b2";
    }
    else if(s2==1 && s1==0 && s0==0)
    {
        arr1[4]=1-arr1[4];
        cout<<"Error in s2";
    }
    else if(s2==1 && s1==0 && s0==1)
    {
        arr1[3]=1-arr1[3];
        cout<<"Error in b0";
    }
    else if(s2==1 && s1==1 && s0==0)
    {
        arr1[0]=1-arr1[0];
        cout<<"Error in b3";
    }
    else if(s2==1 && s1==1 && s0==1)
    {
        arr1[2]=1-arr1[2];
        cout<<"Error in b1";
    }
    cout<<"\nCorrected Code: ";
    for(int i=0;i<7;i++)
    {
        cout<<arr1[i];
    }
}
