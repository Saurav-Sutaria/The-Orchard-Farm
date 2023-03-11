#include<bits/stdc++.h>
using namespace std;

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("./input-small.txt", "r", stdin);
    // freopen("./output-small.txt", "w", stdout);
    // #endif

    #ifndef ONLINE_JUDGE
    freopen("./input-large.txt", "r", stdin);
    freopen("./output-large.txt", "w", stdout);
    #endif

    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;

        //tree date : income from that tree - days to grow fruit
        vector<vector<int>> v = {
            {12000,10}, {10000,6},{27500,15},{7500,5},{8000,15}
        };

        vector<int> incomePerTree; //income of tree during 'd' days
        
        //finding total income from each tree during 'd' days
        for(auto i:v){
            long long income = i[0]*(d/i[1]);
            incomePerTree.push_back(income);
        }

        sort(incomePerTree.begin(),incomePerTree.end(),greater<int>());

        long long totalIncome = 0;
        int treeLeft = n;
        //adding one tree each(compulsory condition)
        for(auto i:incomePerTree){
            totalIncome += i;
            treeLeft--;
        }
        //adding the max income given trees
        int maxPlantation = (n * 0.4) - 1;
        int idx = 0;
        while(treeLeft > 0){
            if(treeLeft > maxPlantation){
                totalIncome += (incomePerTree[idx]*maxPlantation);
                treeLeft -= maxPlantation;
            }else{
                totalIncome += (incomePerTree[idx]*treeLeft);
                treeLeft = 0;
                break;
            }
            idx++;
        }
        cout<<"Case #"<<i<<": "<<totalIncome<<endl;
    }
    return 0;
}