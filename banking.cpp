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
    
    //int flag=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    cout<<"need matrix done"<<endl;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    set<int> s;
    vector<int> ans;
    int flag=1;
    int i=0;
    while(s.size()!=p)
    {
    	if(i==2)
    	{
    		//cout<<"Breakpoint"<<endl;
		}
    	if(s.count(i)==0)
    	{
    		for(int j=0;j<r;j++)
	    	{
	    		if(need[i][j]>available[j])
	    		{
	    			flag=0;
	    			break;
				}
			}
			if(flag==1)
			{
				for(int k=0;k<r;k++)
				{
					available[k]=need[i][k]+available[k];
				}
				s.insert(i);
				ans.push_back(i);
				//cout<<"Done "<<i<<endl;
			}
			
		}
		i=i+1;
			if(i==p)
			{
				i=0;
			}
		flag=1;
	}
    cout << "To avoid deadlock process should be executed as: " << endl;
	for(int i=0;i<p;i++)
	{
		cout<<"P"<<ans[i]<<" ";
	} 
	 
   
}
