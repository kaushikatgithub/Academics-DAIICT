#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){

    return (a>b?a:b);
}

int main(){
    vector<pair<int,int>>job;
    int n;
    cout<<"ENTER THE NUMBERS OF JOB : ";
    cin>>n;
   
    for(int i=0;i<n;i++){
        int s;
        int f;
        cout<<"Enter si of "<<i+1<<" : ";
        cin>>s;
        cout<<"Enter fi of "<<i+1<<" : ";
        cin>>f;
        job.push_back(make_pair(s,+1));
        job.push_back(make_pair(f,-1));
    }

    sort(job.begin(),job.end());

    int machine=0;
    int curr=0;
   
    for(int i=0;i<job.size();i++){
        curr+=job[i].second;
        machine=max(curr,machine);
    }
    cout<<endl;
    cout<<"Number of Machines required is : "<<machine;
    cout<<endl;
    cout<<"End of program !";
   
}
