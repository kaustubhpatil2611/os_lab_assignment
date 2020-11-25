#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,r;
    cout<<"Enter the number of processes: ";
    cin>>p;
    cout<<"Enter the number of resources: ";
    cin>>r;
    vector<int> allocation[p];
    vector<int> max[p];
    vector<int> available;
    int need[p][r];
    vector<int> result;
    set<int> done;
    int input;
    cout<<"Enter the alloted resources: "<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"P"<<i<<"-> ";
        for(int j=0;j<r;j++)
        {
            cin>>input;
            allocation[i].push_back(input);
        }

    }
    cout<<"Enter the max resources required: "<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"P"<<i<<"-> ";
        for(int j=0;j<r;j++)
        {
            cin>>input;
            max[i].push_back(input);
        }

    }
    cout<<"Enter the available resources: "<<endl;
    for(int j=0;j<r;j++)
    {
        cin>>input;
        available.push_back(input);
    }
    
    int flag=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    
    int f[p], ans[p], ind = 0; 
    for (int k = 0; k < p; k++) { 
        f[k] = 0; 
    }
    
    int y=0;

    for (int k = 0; k < p; k++) { 
        for (int i = 0; i < p; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (int j = 0; j < r; j++) { 
                    if (need[i][j] > available[j]){ //check if process can go in deadlock
                        flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { //if not in deadlock
                    ans[ind++] = i; 
                    for (y = 0; y < r; y++) 
                        available[y] += allocation[i][y]; //first allot and then release the resources
                    f[i] = 1; 
                } 
            } 
        } 
    } 
    
    cout << "To avoid deadlock process should be executed as: " << endl; 
    for (int i = 0; i < p - 1; i++) {
        cout << " P" << ans[i] << " ->"; 
        cout << " P" << ans[p - 1] <<endl; 
    }    
    
}

