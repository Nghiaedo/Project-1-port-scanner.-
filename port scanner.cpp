#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n,m;
    int open = 0, closed = 0;
    cin>>n>>m;
    vector<int> count(m+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        count[x]++;
    }
    vector<int> sum(m+1,0);
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]+count[i];
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            if(count[x]!=0){
                cout<<"Scanning port "<<x<<"...\nOPEN\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                open++;
            } else {
                cout<<"Scanning port "<<x<<"...\nCLOSED\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                closed++;
            }
        } else {
            int l,r;
            cin>>l>>r;
            cout<<"Total OPEN ports: "<<sum[r]-sum[l-1]<<"\nScan completed.\n";
            this_thread::sleep_for(chrono::milliseconds(200));
        }

    }
    cout << "\n--- SUMMARY ---\n";
    cout << "OPEN: " << open << "\n";
    cout << "CLOSED: " << closed << "\n";
    return 0;
}

