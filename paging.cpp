#include<bits/stdc++.h>
using namespace std;

void FIFO()//first in first out replacement
{
    int n,x,input;
    vector<int> ref;//page refrences vector 
    list<int> pages;//page frames
    cout<<"Enter number of page frames"<<endl;
    cin>>n;
    cout<<"Enter the number of page references"<<endl;
    cin>>x;
    int pagefault=0;//page fault count
    int z=0;
    while(z<x)
    {
        cin>>input;//page reference
        ref.push_back(input);
        z++;
    }
    for(int i=0;i<x;i++)
    {
        auto it=find(pages.begin(),pages.end(),ref[i]);//find page
        if(it==pages.end())
        {
            pagefault++;
            if(pages.size()==n)//if page frame full
            {
                pages.pop_front();//remove front page
            }
            pages.push_back(ref[i]);//push new page
        }
        
    }
    cout<<"Total number of Page Faults are "<<pagefault<<endl;

}

void LRU()//replace least recently used page
{
    int n,x,input;
    vector<int> ref;//page reference vector
    list<int> pages;//page frames
    cout<<"Enter number of page frames"<<endl;
    cin>>n;
    cout<<"Enter the number of page references"<<endl;
    cin>>x;
    int pagefault=0;
    int z=0;
    while(z<x)
    {
        cin>>input;//page reference
        ref.push_back(input);
        z++;
    }
    for(int i=0;i<x;i++)
    {
        auto it=find(pages.begin(),pages.end(),ref[i]);
        if(it==pages.end())//if page not found
        {
            pagefault++;
            if(pages.size()==n)//if page frame full
            {
                pages.pop_front();//remove least recently used
            }
            pages.push_back(ref[i]);//push new page
        }
        else
        {
            pages.erase(it);
            pages.push_back(ref[i]);//push referenced page at most recent position
        }
        
    }
    cout<<"Total number of Page Faults are "<<pagefault<<endl;
    
}

void Optimal()//replace most recently used that is which will not be refrenced sooner
{
    int n,x,input,y;
    vector<int> ref;
    list<int> pages;
    cout<<"Enter number of page frames"<<endl;
    cin>>n;
    cout<<"Enter the number of page references"<<endl;
    cin>>x;
    int pagefault=0;
    int z=0;
    while(z<x)
    {
        cin>>input;//page reference
        ref.push_back(input);
        z++;
    }
    for(int i=0;i<x;i++)
    {
        auto it=find(pages.begin(),pages.end(),ref[i]);
        if(it==pages.end())//if page fault
        {
            pagefault++;
            if(pages.size()==n)//if page frames full
            {
                pages.pop_back();//remove most recently used
            }
            pages.push_back(ref[i]);//push new page
        }
        else
        {
            pages.erase(it);//remove from current position
            pages.push_back(ref[i]);//push back
        }
        
    }
    cout<<"Total number of Page Faults are "<<pagefault<<endl;

}


int main()
{
    int choice,ch=1;
    while(ch)
    {
        cout<<"=============Enter OPTION================"<<endl;
        cout<<"1.FIFO"<<endl;
        cout<<"2.LRU"<<endl;
        cout<<"3.Optimal"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                FIFO();
                break;
            case 2:
                LRU();
                break;
            case 3:
                Optimal();
                break;
            default:
                cout<<"Enter correct option"<<endl;
                break;
        }
        cout<<"Do you want to continue (0|1)"<<endl;
        cin>>ch;

    }
}
