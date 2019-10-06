#include <iostream>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t  = 1;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[3][n],crr[3][3],brr[3][n];
        for(ll i=0;i<3;i++)
        {
            for(ll j=0;j<n;j++)
                cin>>arr[i][j];
        }
        brr[0][0]=brr[1][0]=brr[2][0]=1;
        for(ll i=1;i<n;i++)
        {
            for(ll k=0;k<3;k++)
            {
                for(ll j=0;j<3;j++)
                {
                    if(brr[j][i-1]==i)
                    {    
                        if(arr[k][i]>=arr[j][i-1])
                            crr[k][j]=brr[j][i-1]+1;
                        else
                         crr[k][j]=brr[j][i-1];
                    }
                    else
                        crr[k][j]=brr[j][i-1];
                }
            }
            // for(ll i=0;i<3;i++)
            // {
            //      for(ll j=0;j<n;j++)
            //         cout<<crr[i][j]<<" ";
            //     cout<<endl;
            // }
            // cout<<endl<<"manik"<<endl;
            ll max1=0,sum=0;
            ll drr[3][1]={arr[0][i],arr[1][i],arr[2][i]};
            for(ll j=0;j<3;j++)
            {
                sum=crr[0][j];
                if(sum+(crr[1][(j+1)%3]+crr[2][(j+2)%3])>max1 and sum+(crr[1][(j+2)%3]+crr[2][(j+1)%3])<sum+(crr[1][(j+1)%3]+crr[2][(j+2)%3]))
                {
                    brr[j][i]=sum;
                    brr[(j+1)%3][i]=crr[1][(j+1)%3];
                    brr[(j+2)%3][i]=crr[2][(j+2)%3];
                    arr[j][i]=drr[0][0];
                    arr[(j+1)%3][i]=drr[1][0];
                    arr[(j+2)%3][i]=drr[2][0];
                    max1=sum+(crr[1][(j+1)%3]+crr[2][(j+2)%3]);
                }
                else if(sum+(crr[1][(j+2)%3]+crr[2][(j+1)%3])>max1 and sum+(crr[1][(j+2)%3]+crr[2][(j+1)%3])>sum+(crr[1][(j+1)%3]+crr[2][(j+2)%3]))
                {
                    brr[0][i]=sum;
                    brr[(j+1)%3][i]=crr[1][(j+2)%3];
                    brr[(j+2)%3][i]=crr[2][(j+1)%3];
                    arr[j][i]=drr[0][0];
                    arr[(j+2)%3][i]=drr[2][0];
                    arr[(j+1)%3][i]=drr[1][0];
                    max1=sum+(crr[1][(j+1)%3]+crr[2][(j+2)%3]);
                }
            }
        //        for(ll i=0;i<3;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //         cout<<brr[i][j]<<" ";
        //     cout<<endl;
        // }
        // }
        // for(ll i=0;i<3;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //         cout<<arr[i][j]<<"  ";
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        // for(ll i=0;i<3;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //         cout<<crr[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        // for(ll i=0;i<3;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //         cout<<brr[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        }
         for(ll i=0;i<3;i++)
        {
            for(ll j=0;j<n;j++)
                cout<<arr[i][j]<<"  ";
            cout<<endl;
        }
        cout<<max({brr[0][n-1]+brr[1][n-1],brr[1][n-1]+brr[2][n-1],brr[0][n-1]+brr[2][n-1]});

    }
    return 0;
}